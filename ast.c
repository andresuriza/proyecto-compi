#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
void yyerror(const char *s);

#define VGA_WIDTH   640
#define VGA_HEIGHT  480

void start_interpreter_file(FILE **out) {
    *out = fopen("VM/src/input/interpreter.c", "w");
    if (!*out) {
        perror("Error creating interpreter.c");
        exit(1);
    }

    fprintf(*out, "#include \"../vga/vga.h\"\n");
    fprintf(*out, "#include \"../vga/vga_color.h\"\n");
    fprintf(*out, "#include \"../common/stdlib.h\"\n\n");
    fprintf(*out, "void interpret_vgraph(const char *unused_path) {\n");
}

void end_interpreter_file(FILE *out) {
    fprintf(out, "}\n");
    fclose(out);
}



Symbol *findSymbol(const char *name) {
    for (Symbol *s = symbolTable; s; s = s->next) {
        if (strcmp(s->name, name) == 0)
            return s;
    }
    return NULL;
}

Symbol *findOrCreateSymbol(const char *name) {
    Symbol *s = findSymbol(name);
    if (s) return s;

    s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = SYM_NUMBER;
    s->value.number = 0;
    s->next = symbolTable;
    symbolTable = s;

    return s;
}

double getSymbolValue(const char *name) {
    Symbol *s = findSymbol(name);
    if (!s) {
        fprintf(stderr, "Variable no existe, debes declararla primero: %s\n", name);
        exit(1);
    }
    if (s->type != SYM_NUMBER) {
        fprintf(stderr, "Error, la variable %s no es un numero \n", name);
        exit(1);
    }
    return s->value.number;
}

void getColor(FILE *out, ColorValue c) {
    switch(c) {
        case ROJO:
            fprintf(out, "set_color(COLOR_RED);\n");
            break;
        case AZUL:
            fprintf(out, "set_color(COLOR_BLUE);\n");
            break;
        case VERDE:
            fprintf(out, "set_color(COLOR_GREEN);\n");
            break;
        case NEGRO:
            fprintf(out, "set_color(COLOR_BLACK);\n");
            break;
        case CYAN:
            fprintf(out, "set_color(COLOR_CYAN);\n");
            break;
        case MAGENTA:
            fprintf(out, "set_color(COLOR_MAGENTA);\n");
            break;
        case CAFE:
            fprintf(out, "set_color(COLOR_BROWN);\n");
            break;
        case GRIS:
             fprintf(out, "set_color(COLOR_DARK_GRAY);\n");
            break;
        case AMARILLO:
             fprintf(out, "set_color(COLOR_YELLOW);\n");
            break;
        case BLANCO:
            fprintf(out, "set_color(COLOR_WHITE);\n");
            break;
        case MARRON:
            fprintf(out, "set_color(COLOR_BROWN);\n");
            break;
    }
}

double ex(nodeType *p, FILE *out) {
    if (!p) return 0;
    switch(p->type) {
    case typeCon: return p->con.value;
    case typeId: return getSymbolValue(p->id.name);
    case typeOpr:
        switch(p->opr.oper) {
            case LOOP:
                    ex(p->opr.op[0], out);
                    while(ex(p->opr.op[1], out)) {ex(p->opr.op[3], out); ex(p->opr.op[2], out);}     
                    return 0;
            case IF:        if (ex(p->opr.op[0], out))
                                ex(p->opr.op[1], out);
                            else if (p->opr.nops > 2)
                                ex(p->opr.op[2], out);
                            return 0;
            case SETCOLOR: 
                        Symbol *s = findSymbol(p->opr.op[0]->id.name);
                        getColor(out, s->value.color);
                        return 0;
            case WAIT: fprintf(out, "wait(%f);\n", ex(p->opr.op[0], out)); return 0;
            case FUNC: return 0;
            case PIXEL: {
              double x = ex(p->opr.op[0], out);
              double y = ex(p->opr.op[1], out);
              if (x >= 0 && x < VGA_WIDTH && y >= 0 && y < VGA_HEIGHT) {
                fprintf(out, "draw_pixel(%f, %f);\n", x, y);
              } else {
                fprintf(stderr, "Warning: pixel (%f,%f) fuera de rango\n", x, y);
              }
              return 0;
            }
            case LINE: {
                double x1 = ex(p->opr.op[0], out), y1 = ex(p->opr.op[1], out);
                double x2 = ex(p->opr.op[2], out), y2 = ex(p->opr.op[3], out);
                if ((x1 >= 0 && x1 < VGA_WIDTH && y1 >= 0 && y1 < VGA_HEIGHT) &&
                    (x2 >= 0 && x2 < VGA_WIDTH && y2 >= 0 && y2 < VGA_HEIGHT)) {
                    fprintf(out, "draw_line(%f, %f, %f, %f);\n", x1, y1, x2, y2);
                } else {
                    fprintf(stderr, "Warning: línea [(%.1f,%.1f)-(%.1f,%.1f)] parcialmente o totalmente fuera de rango\n",
                            x1, y1, x2, y2);
                }
                return 0;
            }
            case RECT: {
                double x = ex(p->opr.op[0], out), y = ex(p->opr.op[1], out);
                double w = ex(p->opr.op[2], out), h = ex(p->opr.op[3], out);
                if (x >= 0 && x + w <= VGA_WIDTH && y >= 0 && y + h <= VGA_HEIGHT) {
                    fprintf(out, "draw_rect(%f, %f, %f, %f);\n", x, y, w, h);
                } else {
                    fprintf(stderr, "Warning: rectángulo (x=%f,y=%f,w=%f,h=%f) fuera de rango\n", x, y, w, h);
                }
                return 0;
            }
            case CIRCLE: {
                double xc = ex(p->opr.op[0], out), yc = ex(p->opr.op[1], out);
                double r  = ex(p->opr.op[2], out);
                if (xc - r >= 0 && xc + r < VGA_WIDTH && yc - r >= 0 && yc + r < VGA_HEIGHT) {
                    fprintf(out, "draw_circle(%f, %f, %f);\n", xc, yc, r);
                } else {
                    fprintf(stderr, "Warning: círculo centrado en (%.1f,%.1f) con radio %.1f fuera de rango\n",
                            xc, yc, r);
                }
                return 0;
            }
            case ';':       ex(p->opr.op[0], out); return ex(p->opr.op[1], out);
            case C_DECL: {
                nodeType *lhs = p->opr.op[0];
                nodeType *rhs = p->opr.op[1];

                Symbol *s = findSymbol(lhs->id.name);

                if (!s) {
                    s = findOrCreateSymbol(lhs->id.name);
                
                    if (rhs->type == typeCon) { // si es igual a constante
                        s->type = rhs->con.type;
                        if (s->type == SYM_COLOR) {
                            s->value.color = (ColorValue)rhs->con.value;
                        }
                        else {
                            s->value.number = rhs->con.value;
                        }
                    } else if (rhs->type == typeId) { // si es igual a variable
                        Symbol *r = findSymbol(rhs->id.name);
                        if (!r) { yyerror("undeclared variable"); exit(1); }
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                        }
                        else {
                            s->value.number = r->value.number;
                        }
                    } else {
                        s->type = SYM_NUMBER;
                        s->value.number = ex(rhs, out);
                    }
            }
            else { // si el simbolo ya existe
                if (rhs->type == typeCon) { // si es igual a constante
                    if (s->type != rhs->con.type) {
                        yyerror("Error: assignment between different types \n"); 
                        exit(1);
                    }
                    else {
                        if (s->type == SYM_COLOR) {
                            s->value.color = (ColorValue)rhs->con.value;
                        }
                        else {
                            s->value.number = rhs->con.value;
                        }
                    }
                } 
                else if (rhs->type == typeId) { // si es igual a variable
                    Symbol *r = findSymbol(rhs->id.name);
                    if (!r) { yyerror("undeclared variable"); exit(1); }

                    if (s->type != r->type) {
                        yyerror("Error: assignment between different types \n"); 
                        exit(1);
                    }
                    else {
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                        }
                        else {
                            s->value.number = r->value.number;
                        }
                    }
                } 
                else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                }
            }
                return 0;
            }
            case I_DECL: {
                nodeType *lhs = p->opr.op[0];
                nodeType *rhs = p->opr.op[1];

                Symbol *s = findSymbol(lhs->id.name);

                if (!s) {
                    s = findOrCreateSymbol(lhs->id.name);
                
                    if (rhs->type == typeCon) { // si es igual a constante
                        s->type = rhs->con.type;
                        if (s->type == SYM_COLOR) {
                            s->value.color = (ColorValue)rhs->con.value;
                        }
                        else {
                            s->value.number = rhs->con.value;
                        }
                    } else if (rhs->type == typeId) { // si es igual a variable
                        Symbol *r = findSymbol(rhs->id.name);
                        if (!r) { yyerror("undeclared variable"); exit(1); }
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                        }
                        else {
                            s->value.number = r->value.number;
                        }
                    } else {
                        s->type = SYM_NUMBER;
                        s->value.number = ex(rhs, out);
                    }
            }
            else { // si el simbolo ya existe
                if (rhs->type == typeCon) { // si es igual a constante
                    if (s->type != rhs->con.type) {
                        yyerror("Error: assignment between different types \n"); 
                        exit(1);
                    }
                    else {
                        if (s->type == SYM_COLOR) {
                            s->value.color = (ColorValue)rhs->con.value;
                        }
                        else {
                            s->value.number = rhs->con.value;
                        }
                    }
                } 
                else if (rhs->type == typeId) { // si es igual a variable
                    Symbol *r = findSymbol(rhs->id.name);
                    if (!r) { yyerror("undeclared variable"); exit(1); }

                    if (s->type != r->type) {
                        yyerror("Error: assignment between different types \n"); 
                        exit(1);
                    }
                    else {
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                        }
                        else {
                            s->value.number = r->value.number;
                        }
                    }
                } 
                else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                }
            }
                return 0;
            }
            case '=': {
                nodeType *lhs = p->opr.op[0];
                nodeType *rhs = p->opr.op[1];

                Symbol *s = findSymbol(lhs->id.name);

                if (!s) {
                fprintf(stderr, "Error: variable '%s' usada sin declaración previa\n", lhs->id.name);
                exit(1);
                }

                if (rhs->type == typeCon) { // si es igual a constante
                    if (s->type != rhs->con.type) {
                        yyerror("Error: asignación entre tipos diferentes");
                        exit(1);
                    }
                    if (s->type == SYM_COLOR) {
                        s->value.color = (ColorValue)rhs->con.value;
                    } else {
                        s->value.number = rhs->con.value;
                    }
                } else if (rhs->type == typeId) { // si es igual a variable
                    Symbol *r = findSymbol(rhs->id.name);
                    if (!r) {
                        yyerror("undeclared variable");
                        exit(1);
                    }

                    if (s->type != r->type) {
                        yyerror("Error: asignación entre tipos diferentes");
                        exit(1);
                    }

                    s->type = r->type;
                    if (s->type == SYM_COLOR) {
                        s->value.color = r->value.color;
                    } else {
                        s->value.number = r->value.number;
                    }
                } else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                }
                return 0;
}
            case COS:       return cos(ex(p->opr.op[0], out));
            case SIN:       return sin(ex(p->opr.op[0], out));
            case '+':       return ex(p->opr.op[0], out) + ex(p->opr.op[1], out);
            case '-':       return ex(p->opr.op[0], out) - ex(p->opr.op[1], out);
            case '*':       return ex(p->opr.op[0], out) * ex(p->opr.op[1], out);
            case '/':       return ex(p->opr.op[0], out) / ex(p->opr.op[1], out);
            case '%':       return (int)ex(p->opr.op[0], out) % (int)ex(p->opr.op[1], out);
            case '<':       return ex(p->opr.op[0], out) < ex(p->opr.op[1], out);
            case '>':       return ex(p->opr.op[0], out) > ex(p->opr.op[1], out);
            case GE:        return (ex(p->opr.op[0], out) >= ex(p->opr.op[1], out));
            case LE:        return ex(p->opr.op[0], out) <= ex(p->opr.op[1], out);
            case NE:        return ex(p->opr.op[0], out) != ex(p->opr.op[1], out);
            case EQ:        return ex(p->opr.op[0], out) == ex(p->opr.op[1], out);
        }
    }
        return 0;
}
