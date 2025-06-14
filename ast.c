#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
void yyerror(const char *s);

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
            printf("Rojo \n");
            break;
        case AZUL:
            printf("Azul \n");
            break;
        case VERDE:
            printf("Verde \n");
            break;
        case NEGRO:
            printf("Negro \n");
            break;
        case CYAN:
            printf("CYAN \n");
            break;
        case MAGENTA:
            printf("MAGENTA \n");
            break;
        case CAFE:
            printf("CAFE \n");
            break;
        case GRIS:
            printf("GRIS \n");
            break;
        case AMARILLO:
            printf("AMARIALLO \n");
            break;
        case BLANCO:
            fprintf(out, "set_color(COLOR_WHITE);\n");
            break;
        case MARRON:
            printf("MARRON \n");
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
                        //fprintf(f, "set_color(%s) \n", getColor(s->value.color));
                        getColor(out, s->value.color);
                        return 0;
            case WAIT: printf("Waiting: %f \n", ex(p->opr.op[0], out)); return 0;
            case FUNC: return 0;
            case PIXEL: 
                        printf("drawing at: (%f, %f) \n", ex(p->opr.op[0], out), ex(p->opr.op[1], out)); 
                        return 0;
            case LINE: 
                        //printf("drawing at: (%f, %f, %f, %f) \n", ex(p->opr.op[0]), ex(p->opr.op[1]), ex(p->opr.op[2]), ex(p->opr.op[3])); 
                        fprintf(out, "draw_line(%f, %f, %f, %f);\n", ex(p->opr.op[0], out), ex(p->opr.op[1], out), ex(p->opr.op[2], out), ex(p->opr.op[3], out));
                        //printf("draw_line(%f, %f, %f, %f);\n", ex(p->opr.op[0]), ex(p->opr.op[1]), ex(p->opr.op[2]), ex(p->opr.op[3]));
                        return 0;
            case CIRCLE: 
                        printf("drawing at: (%f, %f, %f) \n", ex(p->opr.op[0], out), ex(p->opr.op[1], out), ex(p->opr.op[2], out)); 
                        return 0;
            case RECT: 
                        printf("drawing at: (%f, %f, %f, %f) \n", ex(p->opr.op[0], out), ex(p->opr.op[1], out), ex(p->opr.op[2], out), ex(p->opr.op[3], out)); 
                        return 0;
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = rhs->con.value;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    } else if (rhs->type == typeId) { // si es igual a variable
                        Symbol *r = findSymbol(rhs->id.name);
                        if (!r) { yyerror("undeclared variable"); exit(1); }
                        //*s = *r;  // Copy type and value
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = r->value.number;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    } else {
                        s->type = SYM_NUMBER;
                        s->value.number = ex(rhs, out);
                        printf("Variable equals %f \n", ex(rhs, out));
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = rhs->con.value;
                            printf("Variable equals %f \n", ex(rhs, out));
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = r->value.number;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    }
                } 
                else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                    printf("Variable equals %f \n", ex(rhs, out));
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = rhs->con.value;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    } else if (rhs->type == typeId) { // si es igual a variable
                        Symbol *r = findSymbol(rhs->id.name);
                        if (!r) { yyerror("undeclared variable"); exit(1); }
                        //*s = *r;  // Copy type and value
                        s->type = r->type;

                        if (s->type == SYM_COLOR) {
                            s->value.color = r->value.color;
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = r->value.number;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    } else {
                        s->type = SYM_NUMBER;
                        s->value.number = ex(rhs, out);
                        printf("Variable equals %f \n", ex(rhs, out));
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = rhs->con.value;
                            printf("Variable equals %f \n", ex(rhs, out));
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
                            //getColor(s->value.color);
                        }
                        else {
                            s->value.number = r->value.number;
                            printf("Variable equals %f \n", s->value.number);
                        }
                    }
                } 
                else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                    printf("Variable equals %f \n", ex(rhs, out));
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
                        //getColor(s->value.color);
                    } else {
                        s->value.number = rhs->con.value;
                        printf("Variable equals %f \n", s->value.number);
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
                        //getColor(s->value.color);
                    } else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                } else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs, out);
                    printf("Variable equals %f \n", s->value.number);
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