#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*
void addPredefinedConstants() {
    Symbol *rojo = malloc(sizeof(Symbol));
    rojo->name = strdup("rojo");
    rojo->type = SYM_COLOR;
    rojo->value.color = COLOR_RED;
    rojo->next = symbolTable;
    symbolTable = rojo;

    // Add blue, etc. the same way
}
*/

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
        printf(stderr, "Variable no existe, debes declararla primero: %s\n", name);
        exit(1);
    }
    if (s->type != SYM_NUMBER) {
        printf(stderr, "Error, la variable %s no es un numero \n", name);
        exit(1);
    }
    return s->value.number;
}

void getColor(ColorValue c) {
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
    }
}

double ex(nodeType *p) {
    FILE *f = fopen("VM/src/input/interpreter.c", "w");

    if (!p) return 0;
    switch(p->type) {
    case typeCon: return p->con.value;
    case typeId: return getSymbolValue(p->id.name);
    case typeOpr:
        switch(p->opr.oper) {
        case LOOP:
                ex(p->opr.op[0]);
                while(ex(p->opr.op[1])) {ex(p->opr.op[3]); ex(p->opr.op[2]);}     
                return 0;
        case IF:        if (ex(p->opr.op[0]))
                            ex(p->opr.op[1]);
                        else if (p->opr.nops > 2)
                            ex(p->opr.op[2]);
                        return 0;
        case SETCOLOR: 
                    Symbol *s = findSymbol(p->opr.op[0]->id.name);
                    printf("Color set to ");
                    getColor(s->value.color); 
                    return 0;
        case WAIT: printf("Waiting: %f \n", ex(p->opr.op[0])); return 0;
        case PIXEL: 
                    printf("drawing at: (%f, %f) \n", ex(p->opr.op[0]), ex(p->opr.op[1])); 
                    return 0;
        case TREE: {
                    fprintf(f,
                        "#include \"../vga/vga.h\" \n"
                        "void interpret_vgraph() { \n"
                        "    animate_tree(160, 190, 40.0, -90.0, 6); \n"
                        "    animate_mandala(160, 100); \n"
                        "    animate_spiral(160, 100, 100); \n"
                        "}; \n"
                    );
                    return 0;
                }
        case ';':       ex(p->opr.op[0]); return ex(p->opr.op[1]);
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
                        getColor(s->value.color);
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                } else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs);
                    printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = rhs->con.value;
                        printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                }
            } 
            else {
                s->type = SYM_NUMBER;
                s->value.number = ex(rhs);
                printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                } else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs);
                    printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = rhs->con.value;
                        printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                }
            } 
            else {
                s->type = SYM_NUMBER;
                s->value.number = ex(rhs);
                printf("Variable equals %f \n", ex(rhs));
            }
        }
            return 0;
        }
        case '=': {
            nodeType *lhs = p->opr.op[0];
            nodeType *rhs = p->opr.op[1];

            Symbol *s = findSymbol(lhs->id.name);

            if (!s) {
                s = findOrCreateSymbol(lhs->id.name);
            
                if (rhs->type == typeCon) { // si es igual a constante
                    s->type = rhs->con.type;
                    if (s->type == SYM_COLOR) {
                        s->value.color = (ColorValue)rhs->con.value;
                        getColor(s->value.color);
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                } else {
                    s->type = SYM_NUMBER;
                    s->value.number = ex(rhs);
                    printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = rhs->con.value;
                        printf("Variable equals %f \n", ex(rhs));
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
                        getColor(s->value.color);
                    }
                    else {
                        s->value.number = r->value.number;
                        printf("Variable equals %f \n", s->value.number);
                    }
                }
            } 
            else {
                s->type = SYM_NUMBER;
                s->value.number = ex(rhs);
                printf("Variable equals %f \n", ex(rhs));
            }
        }

            /*
            nodeType *lhs = p->opr.op[0];
            nodeType *rhs = p->opr.op[1];
            
            Symbol *s = findOrCreateSymbol(lhs->id.name);

            if (rhs->type == typeCon) {
                s->type = rhs->con.type;
                if (s->type == SYM_COLOR) {
                    s->value.color = (ColorValue)rhs->con.value;
                    getColor(s->value.color);
                }
                else {
                    s->value.number = rhs->con.value;
                    printf("Variable equals %f \n", ex(rhs));
                }
            } else if (rhs->type == typeId) {
                Symbol *r = findSymbol(rhs->id.name);
                if (!r) { yyerror("undeclared variable"); exit(1); }
                *s = *r;  // Copy type and value
            } else {
                s->type = SYM_NUMBER;
                s->value.number = ex(rhs);
                printf("Variable equals %f \n", ex(rhs));
            }
            */
            return 0;
        }
        case UMINUS:    return -ex(p->opr.op[0]);
        case COS:       return cos(ex(p->opr.op[0]));
        case SIN:       return sin(ex(p->opr.op[0]));
        case '+':       return ex(p->opr.op[0]) + ex(p->opr.op[1]);
        case '-':       return ex(p->opr.op[0]) - ex(p->opr.op[1]);
        case '*':       return ex(p->opr.op[0]) * ex(p->opr.op[1]);
        case '/':       return ex(p->opr.op[0]) / ex(p->opr.op[1]);
        case '%':       return (int)ex(p->opr.op[0]) % (int)ex(p->opr.op[1]);
        case '<':       return ex(p->opr.op[0]) < ex(p->opr.op[1]);
        case '>':       return ex(p->opr.op[0]) > ex(p->opr.op[1]);
        case GE:        return (ex(p->opr.op[0]) >= ex(p->opr.op[1]));
        case LE:        return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
        case NE:        return ex(p->opr.op[0]) != ex(p->opr.op[1]);
        case EQ:        return ex(p->opr.op[0]) == ex(p->opr.op[1]);
        }
    }
    return 0;
}
