#include "vga.h"
#include "../kernel/kernel.h"
#include "../screen/screen.h"


#define COLOR_BLACK 0x0
#define COLOR_GREEN 0x2
#define COLOR_RED 0x4
#define COLOR_PURPLE 0xf

unsigned char g_320x200x256[] =
{
/* MISC */
	0x63,
/* SEQ */
	0x03, 0x01, 0x0F, 0x00, 0x0E,
/* CRTC */
	0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
	0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x9C, 0x0E, 0x8F, 0x28,	0x40, 0x96, 0xB9, 0xA3,
	0xFF,
/* GC */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
	0xFF,
/* AC */
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x41, 0x00, 0x0F, 0x00,	0x00
};

// =======================
// FUNCIONES AUXILIARES
// =======================

// Convierte grados a miliradianes (1 rad ≈ 57.3°)
int deg_to_millirad(int deg) {
    return deg * 3142 / 180;  // π ≈ 3.142
}

// sin(x) en miliradianes, devuelve sin(x) * 1000
int sin_millirad(int x) {
    int x3 = (x * x / 1000) * x / 1000;
    int x5 = (x3 * x / 1000) * x / 1000;
    return x - x3 / 6 + x5 / 120;
}

// cos(x) en miliradianes, devuelve cos(x) * 1000
int cos_millirad(int x) {
    int x2 = (x * x) / 1000;
    int x4 = (x2 * x2) / 1000;
    return 1000 - x2 / 2 + x4 / 24;
}

int sin_deg(int deg) {
    int rad = deg_to_millirad(deg);
    return sin_millirad(rad);
}

int cos_deg(int deg) {
    int rad = deg_to_millirad(deg);
    return cos_millirad(rad);
}
void vga_test() {
    println("Attempting to switch modes...", 29);
    write_regs(g_320x200x256);
    vga_clear_screen();
    for (int d = 1; d <= 6; d++) {
        vga_clear_screen();

        draw_tree(160, 190, 60, 90, d); // centro inferior, hacia arriba

        // Delay rudimentario
        for (volatile int i = 0; i < 82000000; i++) {}
    }

	// draw rectangle
	//draw_rect(100, 100, 100, 50);
	//draw_circle(160, 100, 40);
	//draw_line(50, 10, 50, 100);
	//draw_tree(160, 180, 40, 90, 5);

	

}

void draw_mandala(int cx, int cy, int radius, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        int angle = i * 360 / num_lines;
        int rad = deg_to_millirad(angle);
        int dx = (radius * cos_millirad(rad)) / 1000;
        int dy = (radius * sin_millirad(rad)) / 1000;
        draw_line(cx, cy, cx + dx, cy - dy);  // Y hacia arriba
    }
}


void draw_circle(int xc, int yc, int r) {
    for (int x = xc - r; x <= xc + r; x++) {
        for (int y = yc - r; y <= yc + r; y++) {
            int dx = x - xc;
            int dy = y - yc;
            if (dx * dx + dy * dy <= r * r) {
                vga_plot_pixel(x, y, COLOR_GREEN);  // o el color que desees
            }
        }
    }
}

void draw_rect(int x, int y, int width, int height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			vga_plot_pixel(x+i, y+j, COLOR_RED);
		}
	}
}

void draw_line(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = dx > dy ? dx : dy;
    if (steps < 0) steps = -steps;
    if (steps == 0) {
        vga_plot_pixel(x0, y0, COLOR_GREEN);
        return;
    }

    for (int i = 0; i <= steps; i++) {
        int x = x0 + (i * dx) / steps;
        int y = y0 + (i * dy) / steps;
        vga_plot_pixel(x, y, COLOR_GREEN);
    }
}

// =======================
// ÁRBOL FRACTAL RECURSIVO
// =======================

void draw_tree(int x1, int y1, int length, int angle, int depth) {
    if (depth == 0 || length <= 0)
        return;

    int dx = (length * cos_deg(angle)) / 1000;
    int dy = (length * sin_deg(angle)) / 1000;

    int x2 = x1 + dx;
    int y2 = y1 - dy;

    draw_line(x1, y1, x2, y2);

    draw_tree(x2, y2, length * 7 / 10, angle - 25, depth - 1);
    draw_tree(x2, y2, length * 7 / 10, angle + 25, depth - 1);
}







void vga_clear_screen() {
    // Note: "clear_screen" name conflicted with something in screen.h
    // Now I see why namespacing is a thing
    for (int i = 0; i < 320; i++) {
        for (int j = 0; j < 200; j++) {
            vga_plot_pixel(i,j,COLOR_BLACK);
        }
    }
}

void vga_plot_pixel(int x, int y, unsigned short color) {
    unsigned short offset = x + 320 * y;
    unsigned char *VGA = (unsigned char*) VGA_ADDRESS;
    VGA[offset] = color;
}

// Begin copied code
// Source: https://files.osdev.org/mirrors/geezer/osd/graphics/modes.c
// Changes:
// - Initial: only grabbed code I thought was relevant to changing mode and displaying our first pixel (`write_regs`)
// - Changed ioport_in, ioport_out funcs to instead point to ioport_in, ioport_out funcs defined in kernel.asm
void write_regs(unsigned char *regs)
{
	unsigned i;

/* write MISCELLANEOUS reg */
	ioport_out(VGA_MISC_WRITE, *regs);
	regs++;
/* write SEQUENCER regs */
	for(i = 0; i < VGA_NUM_SEQ_REGS; i++)
	{
		ioport_out(VGA_SEQ_INDEX, i);
		ioport_out(VGA_SEQ_DATA, *regs);
		regs++;
	}
/* unlock CRTC registers */
	ioport_out(VGA_CRTC_INDEX, 0x03);
	ioport_out(VGA_CRTC_DATA, ioport_in(VGA_CRTC_DATA) | 0x80);
	ioport_out(VGA_CRTC_INDEX, 0x11);
	ioport_out(VGA_CRTC_DATA, ioport_in(VGA_CRTC_DATA) & ~0x80);
/* make sure they remain unlocked */
	regs[0x03] |= 0x80;
	regs[0x11] &= ~0x80;
/* write CRTC regs */
	for(i = 0; i < VGA_NUM_CRTC_REGS; i++)
	{
		ioport_out(VGA_CRTC_INDEX, i);
		ioport_out(VGA_CRTC_DATA, *regs);
		regs++;
	}
/* write GRAPHICS CONTROLLER regs */
	for(i = 0; i < VGA_NUM_GC_REGS; i++)
	{
		ioport_out(VGA_GC_INDEX, i);
		ioport_out(VGA_GC_DATA, *regs);
		regs++;
	}
/* write ATTRIBUTE CONTROLLER regs */
	for(i = 0; i < VGA_NUM_AC_REGS; i++)
	{
		(void)ioport_in(VGA_INSTAT_READ);
		ioport_out(VGA_AC_INDEX, i);
		ioport_out(VGA_AC_WRITE, *regs);
		regs++;
	}
/* lock 16-color palette and unblank display */
	(void)ioport_in(VGA_INSTAT_READ);
	ioport_out(VGA_AC_INDEX, 0x20);
}
// End copied code
