#ifndef __VGA_H
#define __VGA_H

#define VGA_ADDRESS 0xA0000
#define PI 3.14159265358979323846

void vga_clear_screen();


// Begin copied code
// Source: https://files.osdev.org/mirrors/geezer/osd/graphics/modes.c
// Changes: see vga.c
#define	VGA_AC_INDEX		0x3C0
#define	VGA_AC_WRITE		0x3C0
#define	VGA_AC_READ		    0x3C1
#define	VGA_INSTAT_READ		0x3DA
#define	VGA_MISC_WRITE		0x3C2
#define	VGA_MISC_READ		0x3CC

/*			COLOR emulation		MONO emulation */
#define VGA_CRTC_INDEX		0x3D4		/* 0x3B4 */
#define VGA_CRTC_DATA		0x3D5		/* 0x3B5 */
#define VGA_GC_INDEX 		0x3CE
#define VGA_GC_DATA 		0x3CF
#define VGA_SEQ_INDEX		0x3C4
#define VGA_SEQ_DATA		0x3C5

#define	VGA_NUM_AC_REGS		21
#define	VGA_NUM_CRTC_REGS	25
#define	VGA_NUM_GC_REGS		9
#define	VGA_NUM_SEQ_REGS	5

extern unsigned char g_320x200x256[];
void write_regs(unsigned char *regs);
void io_wait(void);
void tree(int x, int y, double len, double ang, int depth);
void animate_tree(int x, int y, double length, double angle, int max_depth);
void draw_mandala_frame(int cx, int cy,int t);
void animate_mandala(int cx, int cy);
void wait_ticks(int ticks);
void wait_ms(int ms);
void animate_spiral(int cx, int cy, int radius_max);
void draw_spiral_frame(int cx, int cy, int t_max);
void wait(int s);
int cos_deg(int deg);

static double sin_approx(double x);
static double cos_approx(double x);
// end copied code

#endif
