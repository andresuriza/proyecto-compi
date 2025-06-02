// vga_color.h
#ifndef VGA_COLOR_H
#define VGA_COLOR_H 


// Colores VGA de 4 bits
#define VGA_ADDRESS 0xA0000
#define COLOR_BLACK   0x0
#define COLOR_BLUE    0x1
#define COLOR_GREEN   0x2
#define COLOR_CYAN    0x3
#define COLOR_RED     0x4
#define COLOR_MAGENTA 0x5
#define COLOR_BROWN   0x6
#define COLOR_LIGHT_GRAY  0x7
#define COLOR_DARK_GRAY   0x8
#define COLOR_LIGHT_BLUE  0x9
#define COLOR_LIGHT_GREEN 0xA
#define COLOR_LIGHT_CYAN  0xB
#define COLOR_LIGHT_RED   0xC
#define COLOR_LIGHT_MAGENTA 0xD
#define COLOR_YELLOW      0xE
#define COLOR_WHITE       0xF
#define COLOR_PURPLE 0xf

// Prototipos de funciones…
void set_color(unsigned char col);
void vga_plot_pixel(int x, int y);
void vga_clear_screen();
void vga_draw_line(int x0, int y0, int x1, int y1);
void draw_rect(int x, int y, int width, int height);
void draw_circle(int xc, int yc, int r);


#endif // VGA_COLOR_H


