#include "vga.h"
#include "vga_color.h"
#include "../kernel/kernel.h"
#include "../screen/screen.h"
 


#define TICKS_PER_MS 200

/* Prototipos previos */
void io_wait(void);
void tree(int x, int y, double len, double ang, int depth);
void animate_tree(int x, int y, double length, double angle, int max_depth);
void draw_mandala_frame(int cx, int cy,int t);
void animate_mandala(int cx, int cy);
void wait_ticks(int ticks);
void wait_ms(int ms);
void animate_spiral(int cx, int cy, int radius_max);
void draw_spiral_frame(int cx, int cy, int t_max);


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

#define PI 3.14159265358979323846
static inline double deg2rad(double d) {
    return d * PI / 180.0;
}
static inline int abs_i(int x) { return x < 0 ? -x : x; }
/* Taylor simple para sin/cos */
static double sin_approx(double x) {
    double x2 = x*x;
    return x - x*x2/6.0 + x2*x2/120.0 - x2*x2*x2/5040.0;
}
static double cos_approx(double x) {
    return sin_approx(PI/2 - x);
}

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







unsigned char color_by_depth(int depth) {
    switch (depth % 3) {
        case 0: return COLOR_GREEN;
        case 1: return COLOR_BROWN;
        default: return COLOR_YELLOW;
    }
}

// =======================
// ÁRBOL FRACTAL RECURSIVO
// =======================

void tree(int x1, int y1, double length, double angle, int depth) {
    if (!depth) return;
    double rad = deg2rad(angle);
    int x2 = x1 + (int)(length * cos_approx(rad));
    int y2 = y1 - (int)(length * sin_approx(rad));
    unsigned char col = color_by_depth(depth);
    set_color(color_by_depth(depth));
    draw_line(x1, y1, x2, y2);
    tree(x2, y2, length * 0.7, angle - 25.0, depth - 1);
    tree(x2, y2, length * 0.7, angle + 25.0, depth - 1);
}

void animate_tree(int x, int y, double length, double angle, int max_depth) {
    for (int depth = 1; depth <= max_depth; depth++) {
        vga_clear_screen();
        tree(x, y, length, angle, depth);
        wait_ms(10000);
    }
}

void draw_mandala_frame(int cx, int cy,int t) {
    unsigned char c;
    int r;

    // 1) Círculos concéntricos de radio 20, 40, …, 180
    for (r = 10; r < 200; r += 20) {
        if ((r / 20) % 2 == 0) {
            c = COLOR_YELLOW;
        } else {
            c = COLOR_CYAN;
        }
        set_color(c);
        draw_circle(cx, cy, r);
    }

    // 2) Píxeles radiales giratorios, r = 0..190 paso 10
    for (r = 0; r < 200; r += 10) {
        double ang = deg2rad(t + r);
        int x = cx + (int)(r * cos_approx(ang));
        int y = cy - (int)(r * sin_approx(ang));  // y crece hacia abajo en VGA
        if (r % 30 == 0) {
            c = COLOR_MAGENTA;
        } else {
            c = COLOR_BLACK;
        }
        set_color(c);
        draw_pixel(x, y);
        wait_ms(150);
    }
}

void animate_mandala(int cx, int cy) {
    int t;
    for (t = 0; t < 180; t += 10) {
        vga_clear_screen();
        draw_mandala_frame(cx, cy, t);
        wait_ms(150);
    }
    vga_clear_screen();
    draw_mandala_frame(cx, cy, 350);
   
}


void draw_spiral_frame(int cx, int cy, int r_max) {
    int r;
    int r_min = 2; 
    int r_step = 2;
    unsigned char c;
    for (r = r_max; r >= r_min; r -= r_step) {

        // Asignar color según t % 3
        switch (r % 3) {
            case 0: c = COLOR_RED;    break;
            case 1: c = COLOR_BLUE;   break;
            default: c = COLOR_GREEN; break;
        }
        set_color(c);
        draw_circle(cx, cy,r);
        wait_ms(1);  // pequeño retraso para suavizar
    }
}

/**
 * animate_spiral:
 *   Anima la espiral creciendo hasta radio máximo radius,
 *   limpiando pantalla y redibujando cada paso.
 */
void animate_spiral(int cx, int cy, int radius_max) {
    int t;
    for (t = 0; t <= radius_max; t += 5) {
        vga_clear_screen();
        draw_spiral_frame(cx, cy, t);
        wait_ms(1);  // retardo entre fotogramas
    }
    // Para dejar la espiral completa sin borrar
    draw_spiral_frame(cx, cy, radius_max);
}


void wait_ticks(int ticks) {
    for (volatile int i = 0; i < ticks; i++) {
        io_wait();
    }
}

void wait_ms(int ms) {
    wait_ticks(ms * TICKS_PER_MS);
}


// Implementación de io_wait: un simple retraso por puertos
void io_wait(void) {
    // Los puertos 0x80 suelen usarse para retraso breve en x86
    __asm__ volatile ( "outb %%al, $0x80" : : "a"(0) );
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
