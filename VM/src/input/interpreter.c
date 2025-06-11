// File: src/input/interpreter.c

#include "../vga/vga.h"    
#include "../vga/vga_color.h"  
#include "../common/stdlib.h" // Para parse_int_or_var(), atof(), strcmp(), strlen()

/**
 * trim: elimina espacios y tabs al principio y al final de la cadena s.
 */
static void trim(char *s) {
    char *p = s, *end;
    // 1) saltar espacios iniciales
    while (*p == ' ' || *p == '\t') p++;
    if (p != s) memmove(s, p, strlen(p) + 1);

    // 2) quitar espacios finales
    end = s + strlen(s) - 1;
    while (end >= s && (*end == ' ' || *end == '\t')) {
        *end = '\0';
        end--;
    }
}

extern const unsigned char _binary_ordenes_vg_start[];
extern const unsigned char _binary_ordenes_vg_end[];

// src/input/interpreter.c o kernel.c
char vgraph_live_buffer[256] = {0};
int live_command_ready = 0;  // bandera para ejecución

static int   evaluar_condicion(int lhs, const char *op, int rhs);
static void  interpretar_bloque(const char *start, const char *end);
static const unsigned char* ejecutar_condicional(const unsigned char *p, const unsigned char *end);
static const unsigned char* ejecutar_bucle(const unsigned char *p, const unsigned char *end);
static const unsigned char* ejecutar_loop(const unsigned char *p, const unsigned char *end);
static const unsigned char* ejecutar_frame(const unsigned char *p, const unsigned char *end);
static double parse_number_or_var(const char *s);
static int find_op(const char *cond, int *op_len);
static int eval_condition(const char *cond_str);
static double fmod_approx(double acc, double rhs);

#define MAX_VARS 32
#define MAX_NAME 16

static char  var_types[MAX_VARS][MAX_NAME];
static char  var_names[MAX_VARS][MAX_NAME];
static int   var_values[MAX_VARS];
static int   var_count = 0;
static double var_values_dbl[MAX_VARS];

static double sin_approx(double x) {
    double x2 = x*x;
    return x - x*x2/6.0 + x2*x2/120.0 - x2*x2*x2/5040.0;
}
static double cos_approx(double x) {
    return sin_approx(PI/2 - x);
}

// --- new: parse color names into enum values ---
static int parse_color(const char *s) {
    if (strcmp(s, "black") == 0)          return COLOR_BLACK;
    if (strcmp(s, "blue") == 0)           return COLOR_BLUE;
    if (strcmp(s, "green") == 0)          return COLOR_GREEN;
    if (strcmp(s, "cyan") == 0)           return COLOR_CYAN;
    if (strcmp(s, "red") == 0)            return COLOR_RED;
    if (strcmp(s, "magenta") == 0)        return COLOR_MAGENTA;
    if (strcmp(s, "brown") == 0)          return COLOR_BROWN;
    if (strcmp(s, "light_gray") == 0)     return COLOR_LIGHT_GRAY;
    if (strcmp(s, "dark_gray") == 0)      return COLOR_DARK_GRAY;
    if (strcmp(s, "light_blue") == 0)     return COLOR_LIGHT_BLUE;
    if (strcmp(s, "light_green") == 0)    return COLOR_LIGHT_GREEN;
    if (strcmp(s, "light_cyan") == 0)     return COLOR_LIGHT_CYAN;
    if (strcmp(s, "light_red") == 0)      return COLOR_LIGHT_RED;
    if (strcmp(s, "light_magenta") == 0)  return COLOR_LIGHT_MAGENTA;
    if (strcmp(s, "yellow") == 0)         return COLOR_YELLOW;
    if (strcmp(s, "white") == 0)          return COLOR_WHITE;
    // default
    return COLOR_WHITE;
}




/**
 * eval_expr: evalúa una expresión simple de suma/resta cuyos tokens
 * están en args[start..argc-1]. Retorna el resultado como int.
 */
static double eval_expr(char *args[], int argc, int start) {
    // 1) Valor inicial
    double acc = parse_number_or_var(args[start]);

    // 2) Recorremos pares (op, operando)
    for (int i = start + 1; i + 1 < argc; i += 2) {
        char *op  = args[i];
        double rhs = parse_number_or_var(args[i+1]);
        if      (strcmp(op, "+") == 0) acc += rhs;
        else if (strcmp(op, "-") == 0) acc -= rhs;
        else if (strcmp(op, "*") == 0) acc *= rhs;
        else if (strcmp(op, "/") == 0) acc /= rhs;
        else if (strcmp(op, "%") == 0) acc = fmod_approx(acc, rhs);
        else {
            print("Error: operador desconocido en expr\n", 33);
        }
    }
    return acc;
}


/** Busca índice de var, o -1 si no existe */
static int find_var(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_names[i], name) == 0) return i;
    }
    return -1;
}

/** Crea o actualiza una variable */
static void set_var(const char *name, int value) {
  int idx = find_var(name);
  if (idx >= 0) {
    var_values[idx] = value;
  } else if (var_count < MAX_VARS) {
      strncpy(var_types[var_count], "int", MAX_NAME);
      strncpy(var_names[var_count], name, MAX_NAME-1);
      var_names[var_count][MAX_NAME-1] = '\0';
      var_values[var_count] = value;
      var_values_dbl[var_count] = 0.0;
      var_count++;
  } else {
      print("Error: tabla de variables llena\n", 31);
  }
}

/** Devuelve el valor de la variable, o 0 si no existe */
static double get_var(const char *name) {
    int idx = find_var(name);
    return (idx >= 0) ? var_values[idx] : 0;
}

static double parse_number_or_var(const char *s) {
    if (strncmp(s, "sin(", 4) == 0) {
        double v = atof(s + 4);  // convierte lo que venga después
        return sin_approx(v);
    }
    if (strncmp(s, "cos(", 4) == 0) {
        double v = atof(s + 4);
        return cos_approx(v);
    }
    // Detectar número (primer carácter dígito o signo+digito)
    if ((s[0] >= '0' && s[0] <= '9') ||
        ((s[0] == '-' || s[0] == '+'|| s[0] == '*' || s[0] == '/' || s[0] == '%') && (s[1] >= '0' && s[1] <= '9'))) {
        return atoi(s);
    }
    return get_var(s);
}



static int evaluar_condicion(int lhs, const char *op, int rhs) {
    if      (strcmp(op, "==") == 0) return lhs == rhs;
    else if (strcmp(op, "!=") == 0) return lhs != rhs;
    else if (strcmp(op, ">=") == 0) return lhs >= rhs;
    else if (strcmp(op, "<=") == 0) return lhs <= rhs;
    else if (strcmp(op, ">")  == 0) return lhs >  rhs;
    else if (strcmp(op, "<")  == 0) return lhs <  rhs;
    return -1; // operador no reconocido
}

static int find_op(const char *cond, int *op_len) {
    const char *ops[] = {"==","!=",">=","<=",">","<"};
    for (int i = 0; i < 6; i++) {
        const char *p = strstr(cond, ops[i]);
        if (p) {
            *op_len = strlen(ops[i]);
            return (int)(p - cond);
        }
    }
    return -1;
}

static int eval_condition(const char *cond_str) {
    int op_len, pos = find_op(cond_str, &op_len);
    if (pos < 0) return -1;

    char lhs_s[64], rhs_s[64], op_s[3];

    // extraer lhs
    memcpy(lhs_s, cond_str, pos);
    lhs_s[pos] = '\0';
    // extraer op
    memcpy(op_s, cond_str + pos, op_len);
    op_s[op_len] = '\0';
    // extraer rhs
    strncpy(rhs_s, cond_str + pos + op_len, sizeof(rhs_s)-1);
    rhs_s[sizeof(rhs_s)-1] = '\0';

    // recortar espacios
    trim(lhs_s);
    trim(rhs_s);

    // ahora sí parsear y comparar
    int lhs = eval_expr((char*[]){lhs_s}, 1, 0);
    int rhs = eval_expr((char*[]){rhs_s}, 1, 0);
    return evaluar_condicion(lhs, op_s, rhs);
}



// -----------------------------------------------------------------------------
// parsear_tokens(): Dada una línea en 'buffer', separa palabras por espacios/tab.
// Llena el array 'args' con punteros a cada palabra, y devuelve el número de tokens.
//
//   - buffer: cadena modificable que contiene la línea (sin '\n').
//   - args:   array de punteros (char*) donde guardamos cada token.
//   - max:    tamaño máximo de 'args'.
// -----------------------------------------------------------------------------
static int parsear_tokens(char *buffer, char *args[], int max) {
    int argc = 0;
    char *p = buffer;

    while (*p != '\0' && argc < max) {
        // Saltar espacios y tabs
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        if (*p == '\0' || *p == ';') break;

        // Marcar el inicio del token
        args[argc++] = p;

        // Si empieza con paréntesis, procesar hasta cierre
        if (*p == '(') {
            p++; // saltar el '('
            args[argc - 1] = p; // argumento real empieza después de '('

            while (*p != ')' && *p != '\0' && argc < max) {
                if (*p == ',') {
                    *p = '\0'; // separar el argumento
                    p++;
                    while (*p == ' ' || *p == '\t') p++; // saltar espacios
                    if (*p != ')' && *p != '\0') {
                        args[argc++] = p;
                    }
                } else {
                    p++;
                }
            }

            if (*p == ')') {
                *p = '\0'; // terminar el último argumento
                p++; // avanzar después del ')'
            }
        } else {
            // Avanzar hasta el próximo separador
            while (*p != '\0' && *p != ' ' && *p != '\t' && *p != ';') {
                p++;
            }
            if (*p == ' ' || *p == '\t' || *p == ';') {
                *p = '\0';
                p++;
            }
        }
    }

    return argc;
}


// -----------------------------------------------------------------------------
// ejecutar_una_linea(): recibe una línea (sin '\n'), la divide en tokens y
// llama a la función correspondiente con los parámetros convertidos.
// -----------------------------------------------------------------------------
static void ejecutar_una_linea(const char *line) {
    if (*line == '(') {
      // find closing ')'
      const char *r = strchr(line, ')');
      if (r) {
        char typeName[MAX_NAME];
        int tlen = r - line - 1;
        if (tlen >= MAX_NAME) tlen = MAX_NAME-1;
          strncpy(typeName, line+1, tlen);
          typeName[tlen] = '\0';
          // rest of declaration
          const char *rest = r + 1;
          // split by commas
          char buf[80]; strncpy(buf, rest, sizeof(buf)-1); buf[sizeof(buf)-1]='\0';
          // remove trailing ';'
          char *semi = strchr(buf, ';'); if (semi) *semi='\0';
          // tokenize by ','
          char *tok = strtok(buf, ",");
          while (tok) {
            // trim
            trim(tok);
            // check for initialization
            char *eq = strchr(tok, '=');
            if (eq) {
              *eq = '\0';
              char *name = tok;
              trim(name);
              char *val_s = eq + 1;
              trim(val_s);
              // parse value
              int idx = var_count;
              if (idx >= MAX_VARS) break;
                // store type and name
                strncpy(var_types[idx], typeName, MAX_NAME);
                strncpy(var_names[idx], name, MAX_NAME);
                // parse based on type
                if (strcmp(typeName, "double")==0) {
                  var_values_dbl[idx] = atof(val_s);
                } else if (strcmp(typeName, "color")==0) {
                  // map color names to enums
                  var_values[idx] = parse_color(val_s);
                } else { // int default
                  var_values[idx] = atoi(val_s);
                }
                var_count++;
                } else {
                  // declaration without init
                  int idx = var_count;
                  if (idx >= MAX_VARS) break;
                    trim(tok);
                    strncpy(var_types[idx], typeName, MAX_NAME);
                    strncpy(var_names[idx], tok, MAX_NAME);
                    // defaults: zero
                    var_values[idx] = 0;
                    var_values_dbl[idx] = 0.0;
                    var_count++;
                }
                tok = strtok(NULL, ",");
            }
        }
        return;
    }
    // Si es comentario, nada que hacer
    while (*line == ' ' || *line == '\t') line++;
    if (*line == '#' || *line == '\0') return;
    // Hacemos una copia de 'line' a un buffer local (mutable)
    char buffer[80];
    int len = 0;
    while (len < 79 && line[len] != '\0') {
        buffer[len] = line[len];
        len++;
    }
    buffer[len] = '\0';

    // Array para guardar hasta 6 tokens (comando + hasta 5 parámetros)
    char *args[7];
    int argc = parsear_tokens(buffer, args, 7);

    if (argc == 0) {
        // Línea vacía (solo espacios/tab), nada que hacer
        return;
    }

    // args[0] es el nombre del comando
    char *cmd = args[0];
    char *cmd2 = args[1];
    // ——— Asignación simple: var = expr
    if (argc >= 3 && strcmp(args[1], "=") == 0) {
      // args[2..argc-1] contienen la expresión entera
      int val = eval_expr(args, argc, 2);
      set_var(args[0], val);
      return;
    }



    // ================================================================
    // 1) Comando: animate_tree x y length angle depth
    //    Debe venir argc == 6 (1 comando + 5 parámetros)
    // ================================================================
    if (strcmp(cmd, "draw") == 0) {
        if(strcmp(cmd2,"pixel") == 0){
          if (argc == 4) {
            double x            = parse_number_or_var(args[2]);
            double y            = parse_number_or_var(args[3]);
            draw_pixel(x,y);
          } else {
            println("Error: draw_pixel requiere 2 parámetros\n", 40);
          }
          return;
        }
        if (strcmp(cmd2, "line") == 0) {
          if (argc == 6) {
              double x0            = parse_number_or_var(args[2]);
              double y0            = parse_number_or_var(args[3]);
              double x1            = parse_number_or_var(args[4]);
              double y1            = parse_number_or_var(args[5]);
              draw_line(x0,y0,x1,y1);
          } else {
              println("Error: draw_line requiere 4 parámetros\n", 40);
          }
          return;
       }
      if (strcmp(cmd2, "rect") == 0) {
        if (argc == 6) {
            double x            = parse_number_or_var(args[2]);
            double y            = parse_number_or_var(args[3]);
            double width           = parse_number_or_var(args[4]);
            double height            = parse_number_or_var(args[5]);
            draw_rect(x,y,width,height);
        } else {
            println("Error: draw_rect requiere 4 parámetros\n", 40);
        }
        return;
      }
      if (strcmp(cmd2, "circle") == 0) {
        if (argc == 5) {
          double xc           = parse_number_or_var(args[2]);
          double yc            = parse_number_or_var(args[3]);
          double r           = parse_number_or_var(args[4]);
          draw_circle(xc,yc,r);
        } else {
            println("Error: draw_circle requiere 3 parámetros\n", 40);
        }
        return;
      }
    }
    if(strcmp(cmd, "animate") == 0) {
      if (strcmp(cmd2, "tree") == 0) {
          if (argc == 7) {
              double x      = parse_number_or_var(args[2]);
              double y      = parse_number_or_var(args[3]);
              double len = atof(args[4]);
              double ang = atof(args[5]);
              double depth  = parse_number_or_var(args[6]);
              animate_tree(x, y, len, ang, depth);
          } else {
              println("Error: animate_tree requiere 5 parámetros\n", 37);
          }
          return;
      }

      // ================================================================
      // 2) Comando: animate_mandala cx cy radius petals
      //    Debe venir argc == 3 (1 comando + 2 parámetros)
      // ================================================================
      if (strcmp(cmd2, "mandala") == 0) {
          if (argc == 4) {
              double cx     = parse_number_or_var(args[2]);
              double cy     = parse_number_or_var(args[3]);
              animate_mandala(cx, cy);
          } else {
              println("Error: animate_mandala requiere 2 parámetros\n", 40);
          }
          return;
      }

      // ================================================================
      // 3) Comando: animate_spiral cx cy radius angle_increment
      //    Debe venir argc == 4 (1 comando + 3 parámetros)
      // ================================================================
      if (strcmp(cmd2, "spiral") == 0) {
          if (argc == 5) {
              double cx            = parse_number_or_var(args[2]);
              double cy            = parse_number_or_var(args[3]);
              double r          = parse_number_or_var(args[4]);
              animate_spiral(cx, cy, r);
          } else {
              println("Error: animate_spiral requiere 3 parámetros\n", 40);
          }
          return;
      }
    }
    if (strcmp(cmd, "setcolor") == 0) {
      if (argc == 2) {
        unsigned char col;
        const char *arg = args[1];
        // 1) literal color names
        int found = 0;
        const struct { const char *name; unsigned char val; } cmap[] = {
          {"black", COLOR_BLACK}, {"blue", COLOR_BLUE}, {"green", COLOR_GREEN},
          {"cyan", COLOR_CYAN}, {"red", COLOR_RED}, {"magenta", COLOR_MAGENTA},
          {"brown", COLOR_BROWN}, {"light_gray", COLOR_LIGHT_GRAY}, {"dark_gray", COLOR_DARK_GRAY},
          {"light_blue", COLOR_LIGHT_BLUE}, {"light_green", COLOR_LIGHT_GREEN},
          {"light_cyan", COLOR_LIGHT_CYAN}, {"light_red", COLOR_LIGHT_RED},
          {"light_magenta", COLOR_LIGHT_MAGENTA}, {"yellow", COLOR_YELLOW},
          {"white", COLOR_WHITE}
        };
        for (int i = 0; i < (int)(sizeof(cmap)/sizeof(cmap[0])); ++i) {
          if (strcmp(arg, cmap[i].name) == 0) {
            col = cmap[i].val;
            found = 1;
            break;
          }
        }
        // 2) variable holding a color
        if (!found) {
          int idx = find_var(arg);
          if (idx >= 0 && strcmp(var_types[idx], "color") == 0) {
            col = var_values[idx];
            found = 1;
          }
        }
        if (!found) {
          println("Error: color desconocido\n", 24);
          return;
        }
         
        set_color(col);
        return;
      } else {
        println("Error: setcolor requiere 1 parámetro\n", 38);
        return;
      }
    }
    
    if (strcmp(cmd, "wait") == 0) {
        if (argc == 2) {
            double s           = parse_number_or_var(args[1]);
            wait(s);
        } else {
            println("Error: wait requiere 1 parámetros\n", 40);
        }
        return;
    }

    // ================================================================
    // Si llegamos aquí, el comando no coincide con ninguno conocido
    // ================================================================
    print("Comando no reconocido: ", 23);
    print(cmd, strlen(cmd));
    print("\n", 1);
}

void interpret_vgraph_live() {
    if (live_command_ready) {
        ejecutar_una_linea(vgraph_live_buffer);  // Usa tu lógica actual
        live_command_ready = 0; // Limpiar bandera
    }
}

void send_vga_command(const char *command) {
    int i = 0;
    // Copiar hasta 255 caracteres o hasta encontrar el fin de línea
    while (command[i] != '\0' && i < 255) {
        vgraph_live_buffer[i] = command[i];
        i++;
    }
    vgraph_live_buffer[i] = '\0';  // Finaliza como string
    live_command_ready = 1;
}



// -----------------------------------------------------------------------------
// interpret_vgraph(): recorre los bytes entre _binary_ordenes_txt_start y
// _binary_ordenes_txt_end, agrupa en líneas (sin '\n') y llama a ejecutar_una_linea.
// -----------------------------------------------------------------------------
void interpret_vgraph(const char *unused_path) {
    const unsigned char *p = _binary_ordenes_vg_start;
    const unsigned char *end = _binary_ordenes_vg_end;
    const unsigned char *line_start = p;

  while (p < end) {
      if (*p == '\r') { p++; continue; }

      if (*p == '\n') {
          int line_len = (int)(p - line_start);
          if (line_len > 0 && line_len < 80) {
              // 1) Montar línea sin copiar a buffer intermedio
              char *start = (char*)line_start;
              // 1a) Saltar espacios iniciales
              while (*start == ' ' || *start == '\t') {
                  start++;
                  line_len--;
              }
              if (*start == '#') {
                // avanzamos al siguiente carácter tras '\n'
                  line_start = p + 1;
                  continue;
              }
              if (line_len >= 5 && strncmp(start, "frame", 5) == 0 &&
                  (start[5]==' '||start[5]=='\t'||start[5]=='{')) {
                  const unsigned char *newp = ejecutar_frame((unsigned char*)start, end);
                  p = newp;
                  line_start = p;
                  continue;
              }
              // 2) ¿Es un if?
              if (line_len >= 2 && strncmp(start, "if", 2) == 0 &&
                  (start[2] == ' ' || start[2] == '\t' || start[2] == '(')) {
                  // Ejecutamos condicional y obtenemos nuevo p
                  const unsigned char *newp = ejecutar_condicional((unsigned char*)start, end);
                  // avanzamos línea a tras newp
                  p = newp;
                  line_start = p;
                  continue;
              }
              if (line_len >= 4 && strncmp(start, "loop", 4) == 0 &&
                  (start[4]==' '|| start[4]=='\t' || start[4]=='(')) {
                  const unsigned char *newp = ejecutar_loop((unsigned char*)start, end);
                  p = newp;
                  line_start = p;
                  continue;
              }

              if (line_len >= 5 && strncmp(start, "while", 5) == 0 &&
                  (start[5]==' '||start[5]=='\t'||start[5]=='(')) {
                  const unsigned char *newp = ejecutar_bucle((unsigned char*)start, end);
                  p = newp;
                  line_start = p;
                  continue;
              }

              // 3) Línea normal: copiar y ejecutar
              char buffer_line[80];
              memcpy(buffer_line, start, line_len);
              buffer_line[line_len] = '\0';
              ejecutar_una_linea(buffer_line);
          }
          // Preparamos la siguiente línea
          line_start = p + 1;
      }
      p++;
  }
}


// start apunta justo después de '{' y end apunta al '}' correspondiente
static void interpretar_bloque(const char *start, const char *end) {
    char buf[256];
    int len = end - start;
    if (len <= 0) return;
    if (len >= (int)sizeof(buf)) len = sizeof(buf) - 1;
    memcpy(buf, start, len);
    buf[len] = '\0';

    // Recorremos buf buscando newlines
    char *line = buf;
    for (char *q = buf; *q; ++q) {
        if (*q == '\n') {
            *q = '\0';
            // Quitar espacios al inicio
            char *s = line;
            while (*s == ' ' || *s == '\t') s++;
            if (*s) {
                ejecutar_una_linea(s);
            }
            line = q + 1;
        }
    }
    // Última línea, si no acaba en '\n'
    char *s = line;
    while (*s == ' ' || *s == '\t') s++;
    if (*s) {
        ejecutar_una_linea(s);
    }
}


static const unsigned char* ejecutar_frame(const unsigned char *p, const unsigned char *end) {
    // Encontrar '{' del frame
    const unsigned char *b = strchr((const char*)p, '{');
    if (!b || b >= end) return p;
    int depth = 1;
    const unsigned char *q = b + 1;
    while (q < end && depth) {
        if (*q == '{') depth++;
        else if (*q == '}') depth--;
        q++;
    }
    const unsigned char *b_start = b + 1;
    const unsigned char *b_end   = q - 1;

    // Ejecutar dinámicamente el bloque: manejar if/loop/while/frame internos
    const unsigned char *line_p = b_start;
    while (line_p < b_end) {
        // Encontrar fin de línea
        const unsigned char *line_end = line_p;
        while (line_end < b_end && *line_end != '\n') line_end++;
        int line_len = (int)(line_end - line_p);
        if (line_len > 0 && line_len < 80) {
            char *start = (char*)line_p;
            while (*start == ' ' || *start == '\t') { start++; line_len--; }
            if (*start != '#') {
                if (line_len >= 5 && strncmp(start, "frame", 5) == 0 &&
                    (start[5]==' '||start[5]=='\t'||start[5]=='{')) {
                    line_p = ejecutar_frame((unsigned char*)start, b_end);
                    continue;
                } else if (line_len >= 2 && strncmp(start, "if", 2) == 0 &&
                           (start[2]==' '||start[2]=='\t'||start[2]=='(')) {
                    line_p = ejecutar_condicional((unsigned char*)start, b_end);
                    continue;
                } else if (line_len >= 4 && strncmp(start, "loop", 4) == 0 &&
                           (start[4]==' '||start[4]=='\t'||start[4]=='(')) {
                    line_p = ejecutar_loop((unsigned char*)start, b_end);
                    continue;
                } else if (line_len >= 5 && strncmp(start, "while", 5) == 0 &&
                           (start[5]==' '||start[5]=='\t'||start[5]=='(')) {
                    line_p = ejecutar_bucle((unsigned char*)start, b_end);
                    continue;
                } else {
                    // Línea normal
                    char buf[80];
                    memcpy(buf, start, line_len);
                    buf[line_len] = '\0';
                    ejecutar_una_linea(buf);
                }
            }
        }
        // Avanzar a la siguiente línea
        line_p = (line_end < b_end ? line_end + 1 : b_end);
    }

    return b_end + 1;
}



static const unsigned char* ejecutar_condicional(const unsigned char *p,
                                                const unsigned char *end) {
    // 1) Localizar paréntesis de la condición
    const char *lpar = strchr((const char*)p, '(');
    if (!lpar) return p;
    const char *rpar = strchr(lpar, ')');
    if (!rpar) return p;

    // 2) Extraer la condición en un buffer
    int cond_len = (int)(rpar - lpar - 1);
    if (cond_len > 63) cond_len = 63;
    char cond[64];
    strncpy(cond, lpar + 1, cond_len);
    cond[cond_len] = '\0';

    // 3) Evaluar la condición (0 = falso, 1 = verdadero, <0 error)
    int ok = eval_condition(cond);

    // 4) Encontrar bloque if { … }
    const unsigned char *b1 = strchr((const char*)rpar, '{');
    if (!b1) return p;
    int depth = 1;
    const unsigned char *q = b1 + 1;
    while (q < end && depth) {
        if (*q == '{') depth++;
        else if (*q == '}') depth--;
        q++;
    }
    const unsigned char *b1_end = q - 1;

    // 5) Buscar 'else' o 'else if'
    const unsigned char *scan = b1_end + 1;
    // Saltar espacios y saltos de línea
    while (scan < end && (*scan==' '||*scan=='\t'||*scan=='\r'||*scan=='\n'))
        scan++;

    // Manejo de 'else if'
    if (scan + 7 < end && strncmp((const char*)scan, "else if", 7) == 0) {
        // Llamar recursivamente para manejar 'else if'
        return ejecutar_condicional(scan + 4, end);
    }

    // Manejo de 'else'
    const unsigned char *b2 = NULL, *b2_end = NULL;
    if (scan + 4 < end && strncmp((const char*)scan, "else", 4) == 0) {
        const unsigned char *eb = strchr((const char*)scan+4, '{');
        if (eb) {
            depth = 1;
            q = eb + 1;
            while (q < end && depth) {
                if (*q == '{') depth++;
                else if (*q == '}') depth--;
                q++;
            }
            b2     = eb;
            b2_end = q - 1;
        }
    }

    // 6) Ejecutar solo el bloque correspondiente
    if (ok == 1) {
        // if verdadero
        interpretar_bloque((const char*)b1 + 1, (const char*)b1_end);
    } else if (ok == 0 && b2) {
        // if falso y hay else
        interpretar_bloque((const char*)b2 + 1, (const char*)b2_end);
    } else if (ok < 0) {
        // error de sintaxis
        println("Error: condición inválida\n", 24);
    }

    // 7) Saltar todo lo que venga hasta el final del else (si existe)
    if (b2_end) return b2_end + 1;
    return b1_end + 1;
}

/**
 * ejecutar_bucle: interpreta un bloque while(cond) { … }
 *   p:   puntero al inicio de la línea, que debe comenzar con "while"
 *   end: puntero al final de todo el script
 * Retorna la posición justo después de la '}' que cierra el bloque.
 */
static const unsigned char* ejecutar_bucle(const unsigned char *p,
                                           const unsigned char *end) {
    // 1) Localizar paréntesis de la condición
    const char *lpar = strchr((const char*)p, '(');
    if (!lpar) return p;
    const char *rpar = strchr(lpar, ')');
    if (!rpar) return p;

    // 2) Extraer la condición
    int cond_len = (int)(rpar - lpar - 1);
    if (cond_len > 63) cond_len = 63;
    char cond[64];
    strncpy(cond, lpar + 1, cond_len);
    cond[cond_len] = '\0';

    // 3) Encontrar inicio y fin del bloque { … }
    const unsigned char *b = strchr((const char*)rpar, '{');
    if (!b) return p;
    int depth = 1;
    const unsigned char *q = b + 1;
    while (q < end && depth) {
        if (*q == '{')      depth++;
        else if (*q == '}') depth--;
        q++;
    }
    const unsigned char *b_start = b + 1;
    const unsigned char *b_end   = q - 1;

    // 4) Ejecutar el bloque mientras la condición sea cierta
    while (1) {
        int ok = eval_condition(cond);
        if (ok != 1) break;
        interpretar_bloque((const char*)b_start, (const char*)b_end);
    }

    // 5) Devolver posición tras el '}'
    return b_end + 1;
}

static const unsigned char* ejecutar_loop(const unsigned char *p,
                                          const unsigned char *end) {
    // 1) localizar paréntesis de control
    const char *lpar = strchr((const char*)p, '(');
    if (!lpar) return p;
    const char *rpar = strchr(lpar, ')');
    if (!rpar) return p;

    // 2) extraer toda la parte "init; cond; incr"
    int ctrl_len = (int)(rpar - lpar - 1);
    if (ctrl_len > 255) ctrl_len = 255;
    char ctrl[256];
    strncpy(ctrl, lpar + 1, ctrl_len);
    ctrl[ctrl_len] = '\0';

    // 3) separar en 3 partes por ';'
    char *parts[3] = { NULL, NULL, NULL };
    int part = 0;
    parts[part] = ctrl;
    for (int i = 0; ctrl[i] && part < 2; i++) {
        if (ctrl[i] == ';') {
            ctrl[i] = '\0';
            parts[++part] = ctrl + i + 1;
        }
    }
    // trim en cada parte:
    for (int i = 0; i < 3; i++) {
        if (parts[i]) trim(parts[i]);
    }

    // 4) buscar inicio y fin del bloque { ... }
    const unsigned char *b = strchr((const char*)rpar, '{');
    if (!b) return p;
    int depth = 1;
    const unsigned char *q = b + 1;
    while (q < end && depth) {
        if (*q == '{') depth++;
        else if (*q == '}') depth--;
        q++;
    }
    const unsigned char *b_start = b + 1;
    const unsigned char *b_end   = q - 1;

    // 5) ejecutar init una sola vez
    if (parts[0] && *parts[0]) {
        ejecutar_una_linea(parts[0]);
    }

    // 6) bucle: eval cond, ejecutar cuerpo, ejecutar incr
    while (1) {
        int ok = eval_condition(parts[1]);
        if (ok != 1) break;
        interpretar_bloque((const char*)b_start, (const char*)b_end);
        if (parts[2] && *parts[2]) {
            ejecutar_una_linea(parts[2]);
        }
    }

    // 7) retornar tras el cierre de '}'
    return b_end + 1;
}

static double fmod_approx(double acc, double rhs) {
    int n = (int)(acc / rhs);   // truncamiento = floor para positivos
    return acc - n * rhs;
}


