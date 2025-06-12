#include "vga_color.h"
#include "vga.h"        // para VGA_ADDRESS y prototipos
#include "../kernel/kernel.h"
enum { VGA_WIDTH = 640, VGA_HEIGHT = 480 };

#define COLOR_FONDO COLOR_BLACK
#define COLOR_FIGURA COLOR_WHITE

// Color interno (enlace interno al módulo)
static unsigned char _current_color = COLOR_WHITE;



// Selecciona el plano de bits en el Sequencer Map Mask (índice 2).
static inline void write_plane(unsigned char plane) {
    ioport_out(0x3C4, 0x02);
    ioport_out(0x3C5, 1 << plane);
}

// Pone todos los planos activos (máscara completa).
static inline void enable_all_planes(void) {
    ioport_out(0x3C4, 0x02);
    ioport_out(0x3C5, 0x0F);
}

// Devuelve el valor absoluto de un entero.
static inline int abs_i(int x) {
    return x < 0 ? -x : x;
}

static inline int sqrt_int(int n) {
    if (n <= 0) return 0;
    int x = n;
    int y = (x + 1) >> 1;
    while (y < x) {
        x = y;
        y = (x + n / x) >> 1;
    }
    return x;
}

void set_color(unsigned char col) {
    _current_color = col;
}

void draw_pixel(int x, int y) {
    // Clipping rápido
    if ((unsigned)x >= VGA_WIDTH || (unsigned)y >= VGA_HEIGHT)
        return;

    unsigned char *VGA = (unsigned char *)VGA_ADDRESS;
    unsigned int index = (y * VGA_WIDTH + x) >> 3;
    unsigned char mask = 1 << (7 - (x & 7));
    unsigned char color = _current_color;

    for (int plane = 0; plane < 4; plane++) {
        write_plane(plane);
        unsigned char *dst = &VGA[index];
        if (color & (1 << plane))
            *dst |= mask;
        else
            *dst &= ~mask;
    }
    // Restaurar todos los planos (opcional)
    enable_all_planes();
}




void draw_line(int x0, int y0, int x1, int y1) {
    int dx = abs_i(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs_i(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (1) {
        draw_pixel(x0, y0);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = err * 2;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void vga_clear_screen(void) {
    unsigned char *VGA = (unsigned char *)VGA_ADDRESS;
    unsigned int bytes = (VGA_WIDTH * VGA_HEIGHT) >> 3;

    for (int plane = 0; plane < 4; plane++) {
        write_plane(plane);
        // Borra todo el plano en una sola llamada
        for (unsigned int i = 0; i < bytes; i++) {
            VGA[i] = 0x00;
        }
    }
    enable_all_planes();
    set_color(COLOR_BLACK);
}

void fill_rect(int x, int y, int width, int height) {
    // Clipping de seguridad
    if (x < 0) { width += x; x = 0; }
    if (y < 0) { height += y; y = 0; }
    if (x + width > VGA_WIDTH)  width  = VGA_WIDTH  - x;
    if (y + height > VGA_HEIGHT) height = VGA_HEIGHT - y;
    if (width <= 0 || height <= 0) return;

    unsigned char *VGA = (unsigned char *)VGA_ADDRESS;

    for (int plane = 0; plane < 4; plane++) {
        if (!(_current_color & (1 << plane))) continue; // Este plano no debe estar activo para este color

        write_plane(plane);

        for (int j = 0; j < height; j++) {
            int row_y = y + j;
            int offset = (row_y * VGA_WIDTH + x) >> 3;
            int x_start_bit = x & 7;
            int remaining = width;

            // Byte inicial parcial (si no estamos alineados a byte completo)
            if (x_start_bit != 0) {
                unsigned char mask = 0xFF >> x_start_bit;
                if (remaining < (8 - x_start_bit))
                    mask &= 0xFF << (8 - x_start_bit - remaining);
                VGA[offset] |= mask;
                offset++;
                remaining -= (8 - x_start_bit);
            }

            // Bytes completamente llenos
            int full_bytes = remaining >> 3;
            for (int i = 0; i < full_bytes; i++) {
                VGA[offset++] = 0xFF;
            }

            // Byte final parcial
            int final_bits = remaining & 7;
            if (final_bits > 0) {
                unsigned char mask = 0xFF << (8 - final_bits);
                VGA[offset] |= mask;
            }
        }
    }

    enable_all_planes(); // restaurar
}





void draw_rect(int x, int y, int width, int height) {
    // Rellenar píxel por píxel
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
          fill_rect(x, y, width, height);
        }
    }

    // Contorno opcional
    draw_line(x, y, x + width - 1, y);             // arriba
    draw_line(x, y + height - 1, x + width - 1, y + height - 1); // abajo
    draw_line(x, y, x, y + height - 1);            // izquierda
    draw_line(x + width - 1, y, x + width - 1, y + height - 1); // derecha
}


void fill_circle(int xc, int yc, int r) {
    // Clipping r
    if (r <= 0) return;

    unsigned char *VGA = (unsigned char *)VGA_ADDRESS;

    for (int plane = 0; plane < 4; plane++) {
        if (!(_current_color & (1 << plane))) continue;
        write_plane(plane);

        for (int y = -r; y <= r; y++) {
            int py = yc + y;
            if (py < 0 || py >= VGA_HEIGHT) continue;

            int dx = (int)sqrt_int(r * r - y * y);
            int x0 = xc - dx;
            int x1 = xc + dx;

            if (x1 < 0 || x0 >= VGA_WIDTH) continue;
            if (x0 < 0) x0 = 0;
            if (x1 >= VGA_WIDTH) x1 = VGA_WIDTH - 1;

            int width = x1 - x0 + 1;
            int offset = (py * VGA_WIDTH + x0) >> 3;
            int x_start_bit = x0 & 7;
            int remaining = width;

            // Byte inicial parcial
            if (x_start_bit != 0) {
                unsigned char mask = 0xFF >> x_start_bit;
                if (remaining < (8 - x_start_bit))
                    mask &= 0xFF << (8 - x_start_bit - remaining);
                VGA[offset++] |= mask;
                remaining -= (8 - x_start_bit);
            }

            // Bytes completos
            int full_bytes = remaining >> 3;
            for (int i = 0; i < full_bytes; i++) {
                VGA[offset++] = 0xFF;
            }

            // Byte final parcial
            int final_bits = remaining & 7;
            if (final_bits > 0) {
                unsigned char mask = 0xFF << (8 - final_bits);
                VGA[offset] |= mask;
            }
        }
    }

    enable_all_planes();
}


void draw_circle(int xc, int yc, int r) {
    fill_circle(xc, yc, r);
}


