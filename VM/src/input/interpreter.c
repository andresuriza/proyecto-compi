#include "../vga/vga.h"

// Implementación manual de strcmp
int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// Simula el contenido del archivo "ordenes.txt"
const char* ordenes[] = {
    "animate_tree",
    "animate_mandala",
    "animate_spiral"
};

int num_ordenes = 3;

void interpret_vgraph() {
    for (int i = 0; i < num_ordenes; i++) {
        const char* cmd = ordenes[i];

        if (strcmp(cmd, "animate_tree") == 0) {
            animate_tree(160, 190, 40.0, -90.0, 6);
        } else if (strcmp(cmd, "animate_mandala") == 0) {
            animate_mandala(160, 100);
        } else if (strcmp(cmd, "animate_spiral") == 0) {
            animate_spiral(160, 100, 100);
        }
    }
}


