#include "vga_color.h"
#include "vga.h"        // para VGA_ADDRESS y vga_plot_pixel()


// Color interno (enlace interno al módulo)
static unsigned char _current_color = COLOR_BLACK;

static inline int abs_i(int x) { return x < 0 ? -x : x; }

void set_color(unsigned char col) {
    _current_color = col;
}

void draw_line(int x0, int y0, int x1, int y1) {
    int dx = abs_i(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs_i(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        draw_pixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2*err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void draw_pixel(int x, int y) {
    unsigned short offset = x + 320 * y;
    unsigned char *VGA = (unsigned char*)VGA_ADDRESS;
    VGA[offset] = _current_color;
}

void vga_clear_screen() {
    set_color(COLOR_BLACK);
    for (int y = 0; y < 200; y++)
        for (int x = 0; x < 320; x++)
            draw_pixel(x, y);
}

void draw_circle(int xc, int yc, int r) {
    for (int x = xc - r; x <= xc + r; x++) {
        for (int y = yc - r; y <= yc + r; y++) {
            int dx = x - xc;
            int dy = y - yc;
            if (dx * dx + dy * dy <= r * r) {
                draw_pixel(x, y);  
            }
        }
    }
}


void draw_rect(int x, int y, int width, int height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			draw_pixel(x+i, y+j);
		}
	}
}
