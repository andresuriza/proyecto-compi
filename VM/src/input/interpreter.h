#ifndef INTERPRETER_H
#define INTERPRETER_H


extern char vgraph_live_buffer[256];
extern int live_command_ready;


void interpret_vgraph(const char* unused_path);
void interpret_vgraph_live();
void send_vga_command(const char *command);
static int evaluar_condicion(int lhs, const char *op, int rhs);
static void interpretar_bloque(const char *start, const char *end);
static const unsigned char* ejecutar_condicional(const unsigned char *p, const unsigned char *end);
static const unsigned char* ejecutar_bucle(const unsigned char *p, const unsigned char *end);
static const unsigned char* ejecutar_loop(const unsigned char *p, const unsigned char *end);
static int parse_int_or_var(const char *s);


#endif

