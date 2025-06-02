// File: src/input/interpreter.c

#include "../vga/vga.h"       // Aquí debe estar declarado: void print(const char*, int);
#include "../common/stdlib.h" // Para atoi(), atof(), strcmp(), strlen()

extern const unsigned char _binary_ordenes_txt_start[];
extern const unsigned char _binary_ordenes_txt_end[];


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
        // 1) Saltar cualquier espacio o tab
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        if (*p == '\0') break;

        // 2) Este es el inicio de un token
        args[argc++] = p;

        // 3) Avanzar hasta encontrar espacio/tab o fin de cadena
        while (*p != '\0' && *p != ' ' && *p != '\t') {
            p++;
        }
        // 4) Si no es final de línea, reemplazar separador por '\0' y avanzar
        if (*p == ' ' || *p == '\t') {
            *p = '\0';
            p++;
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
    char *args[6];
    int argc = parsear_tokens(buffer, args, 6);

    if (argc == 0) {
        // Línea vacía (solo espacios/tab), nada que hacer
        return;
    }

    // args[0] es el nombre del comando
    char *cmd = args[0];

    // ================================================================
    // 1) Comando: animate_tree x y length angle depth
    //    Debe venir argc == 6 (1 comando + 5 parámetros)
    // ================================================================
    if (strcmp(cmd, "animate_tree") == 0) {
        if (argc == 6) {
            int x      = atoi(args[1]);
            int y      = atoi(args[2]);
            double len = atof(args[3]);
            double ang = atof(args[4]);
            int depth  = atoi(args[5]);
            animate_tree(x, y, len, ang, depth);
        } else {
            print("Error: animate_tree requiere 5 parámetros\n", 37);
        }
        return;
    }

    // ================================================================
    // 2) Comando: animate_mandala cx cy radius petals
    //    Debe venir argc == 5 (1 comando + 4 parámetros)
    // ================================================================
    if (strcmp(cmd, "animate_mandala") == 0) {
        if (argc == 5) {
            int cx     = atoi(args[1]);
            int cy     = atoi(args[2]);
            animate_mandala(cx, cy);
        } else {
            print("Error: animate_mandala requiere 2 parámetros\n", 40);
        }
        return;
    }

    // ================================================================
    // 3) Comando: animate_spiral cx cy radius angle_increment
    //    Debe venir argc == 5 (1 comando + 4 parámetros)
    // ================================================================
    if (strcmp(cmd, "animate_spiral") == 0) {
        if (argc == 5) {
            int cx            = atoi(args[1]);
            int cy            = atoi(args[2]);
            int r          = atof(args[3]);
            animate_spiral(cx, cy, 3);
        } else {
            print("Error: animate_spiral requiere 3 parámetros\n", 40);
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
    const unsigned char *p = _binary_ordenes_txt_start;
    const unsigned char *end = _binary_ordenes_txt_end;
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

