// File: src/input/interpreter.c

#include "../vga/vga.h"    
#include "../vga/vga_color.h"  
#include "../common/stdlib.h" // Para atoi(), atof(), strcmp(), strlen()

extern const unsigned char _binary_ordenes_vg_start[];
extern const unsigned char _binary_ordenes_vg_end[];


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

    // ================================================================
    // 1) Comando: animate_tree x y length angle depth
    //    Debe venir argc == 6 (1 comando + 5 parámetros)
    // ================================================================
    if (strcmp(cmd, "draw") == 0) {
        if(strcmp(cmd2,"pixel") == 0){
          if (argc == 4) {
            int x            = atoi(args[2]);
            int y            = atoi(args[3]);
            draw_pixel(x,y);
          } else {
            println("Error: draw_pixel requiere 2 parámetros\n", 40);
          }
          return;
        }
        if (strcmp(cmd2, "line") == 0) {
          if (argc == 6) {
              int x0            = atoi(args[2]);
              int y0            = atoi(args[3]);
              int x1            = atoi(args[4]);
              int y1            = atoi(args[5]);
              draw_line(x0,y0,x1,y1);
          } else {
              println("Error: draw_line requiere 4 parámetros\n", 40);
          }
          return;
       }
      if (strcmp(cmd2, "rect") == 0) {
        if (argc == 6) {
            int x            = atoi(args[2]);
            int y            = atoi(args[3]);
            int width           = atoi(args[4]);
            int height            = atoi(args[5]);
            draw_rect(x,y,width,height);
        } else {
            println("Error: draw_rect requiere 4 parámetros\n", 40);
        }
        return;
      }
      if (strcmp(cmd2, "circle") == 0) {
        if (argc == 5) {
          int xc           = atoi(args[2]);
          int yc            = atoi(args[3]);
          int r           = atoi(args[4]);
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
              int x      = atoi(args[2]);
              int y      = atoi(args[3]);
              double len = atof(args[4]);
              double ang = atof(args[5]);
              int depth  = atoi(args[6]);
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
              int cx     = atoi(args[2]);
              int cy     = atoi(args[3]);
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
              int cx            = atoi(args[2]);
              int cy            = atoi(args[3]);
              int r          = atoi(args[4]);
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
        if (strcmp(args[1], "black") == 0)          col = COLOR_BLACK;
        else if (strcmp(args[1], "blue") == 0)      col = COLOR_BLUE;
        else if (strcmp(args[1], "green") == 0)     col = COLOR_GREEN;
        else if (strcmp(args[1], "cyan") == 0)      col = COLOR_CYAN;
        else if (strcmp(args[1], "red") == 0)       col = COLOR_RED;
        else if (strcmp(args[1], "magenta") == 0)   col = COLOR_MAGENTA;
        else if (strcmp(args[1], "brown") == 0)     col = COLOR_BROWN;
        else if (strcmp(args[1], "light_gray") == 0)  col = COLOR_LIGHT_GRAY;
        else if (strcmp(args[1], "dark_gray") == 0)   col = COLOR_DARK_GRAY;
        else if (strcmp(args[1], "light_blue") == 0)  col = COLOR_LIGHT_BLUE;
        else if (strcmp(args[1], "light_green") == 0) col = COLOR_LIGHT_GREEN;
        else if (strcmp(args[1], "light_cyan") == 0)  col = COLOR_LIGHT_CYAN;
        else if (strcmp(args[1], "light_red") == 0)   col = COLOR_LIGHT_RED;
        else if (strcmp(args[1], "light_magenta") == 0) col = COLOR_LIGHT_MAGENTA;
        else if (strcmp(args[1], "yellow") == 0)      col = COLOR_YELLOW;
        else if (strcmp(args[1], "white") == 0)       col = COLOR_WHITE;
        else {
            println("Error: color desconocido\n", 24);
            return;
        }

        set_color(col);
    } else {
        println("Error: set_color requiere 1 parámetro\n", 38);
    }
    return;
    }
    
    if (strcmp(cmd, "wait") == 0) {
        if (argc == 2) {
            int s           = atoi(args[1]);
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

// -----------------------------------------------------------------------------
// interpret_vgraph(): recorre los bytes entre _binary_ordenes_txt_start y
// _binary_ordenes_txt_end, agrupa en líneas (sin '\n') y llama a ejecutar_una_linea.
// -----------------------------------------------------------------------------
void interpret_vgraph(const char *unused_path) {
    const unsigned char *p = _binary_ordenes_vg_start;
    const unsigned char *end = _binary_ordenes_vg_end;
    const unsigned char *line_start = p;

    while (p < end) {
        if (*p == '\r') {
            // ignoramos carriage return (CR)
            p++;
            continue;
        }

        // Si encontramos '\n' o estamos justo en el último byte
        if (*p == '\n' || (p == end - 1 && *p != '\n')) {
            // Determinar la longitud de la línea (sin incluir '\n')
            int line_len = 0;
            const unsigned char *q = line_start;
            // Si es el último carácter y no es '\n', lo incluimos
            int include_last = (p == end - 1 && *p != '\n') ? 1 : 0;
            int target_len = (int)(p - line_start) + include_last;

            if (target_len > 0 && target_len < 80) {
                // Copiar la línea en un buffer C (añade '\0')
                char buffer_line[80];
                for (line_len = 0; line_len < target_len; line_len++) {
                    buffer_line[line_len] = (char)line_start[line_len];
                }
                buffer_line[line_len] = '\0';
                // Ejecutar el comando si no es una línea vacía
                ejecutar_una_linea(buffer_line);
            }
            // Avanzar al siguiente posible inicio de línea
            line_start = p + 1;
        }

        p++;
    }
}

