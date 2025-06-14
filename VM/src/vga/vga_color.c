#include "vga_color.h"
#include "vga.h"        // para VGA_ADDRESS y prototipos
#include "../kernel/kernel.h"
enum { VGA_WIDTH = 640, VGA_HEIGHT = 480 };


// Color interno (enlace interno al módulo)
static unsigned char _current_color = COLOR_BLACK;



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
    if ((unsigned)x >= VGA_WIDTH || (unsigned)y >= VGA_HEIGHT)
        return;

    unsigned char *VGA   = (unsigned char*)VGA_ADDRESS;
    unsigned int  index  = (y * VGA_WIDTH + x) >> 3;
    unsigned char mask   = 1 << (7 - (x & 7));
    unsigned char color  = _current_color;

    for (int plane = 0; plane < 4; plane++) {
        // Selecciona el único bitplane
        ioport_out(0x3C4, 0x02);
        ioport_out(0x3C5, 1 << plane);

        unsigned char *dst = &VGA[index];
        if (color & (1 << plane))
            *dst |= mask;
        else
            *dst &= ~mask;
    }

    // Restaurar todos los planos una sola vez al final
    enable_all_planes();
}



void draw_line(int x0, int y0, int x1, int y1) {
    int dx = abs_i(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs_i(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;  // err = dx - dy en valor absoluto

    while (1) {
        draw_pixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) {      // avanza en x
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {      // avanza en y
            err += dx;
            y0 += sy;
        }
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

void draw_rect(int x, int y, int width, int height) {
    if (width <= 0 || height <= 0)
        return;

    int x0 = x;
    int y0 = y;
    int x1 = x + width - 1;
    int y1 = y + height - 1;

    // Línea superior
    draw_line(x0, y0, x1, y0);
    // Línea inferior
    draw_line(x0, y1, x1, y1);
    // Línea izquierda
    draw_line(x0, y0, x0, y1);
    // Línea derecha
    draw_line(x1, y0, x1, y1);
}


void draw_circle(int xc, int yc, int r) {
    if (r <= 0) return;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y) {
        // 8 octantes
        draw_pixel(xc + x, yc + y);
        draw_pixel(xc - x, yc + y);
        draw_pixel(xc + x, yc - y);
        draw_pixel(xc - x, yc - y);
        draw_pixel(xc + y, yc + x);
        draw_pixel(xc - y, yc + x);
        draw_pixel(xc + y, yc - x);
        draw_pixel(xc - y, yc - x);

        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
