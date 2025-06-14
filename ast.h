typedef enum { typeCon, typeId, typeOpr } nodeEnum;
typedef enum { SYM_NUMBER, SYM_COLOR } SymbolType;

typedef enum {
    ROJO,
    VERDE,
    AZUL,
    NEGRO,
    CYAN,
    MAGENTA,
    CAFE,
    GRIS,
    AMARILLO,
    BLANCO,
    MARRON
} ColorValue;

/* constants */
typedef struct {
    double value; 
    SymbolType type;  
} conNodeType;

/* identifiers */
typedef struct {
    char* name;  
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];	/* operands, extended at runtime */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;

typedef struct Symbol {
    char *name;
    SymbolType type;
    union {
        double number;
        ColorValue color;
    } value;
    struct Symbol *next;
} Symbol;

extern Symbol *symbolTable;