#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include <math.h>

double ex(nodeType *p) {
    FILE *f = fopen("VM/src/input/interpreter.c", "w");

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       return p->con.value;
    case typeId: return sym[p->id.i];
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
        case SETCOLOR: printf("Color set to %f \n", ex(p->opr.op[0])); return 0;
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

        //case PRINT:     printf("%d\n", ex(p->opr.op[0])); return 0;
        case ';':       ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case '=':   
                    printf("Assignment = %f \n", ex(p->opr.op[1]));     
                    return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
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
