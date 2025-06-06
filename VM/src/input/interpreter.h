#ifndef INTERPRETER_H
#define INTERPRETER_H


extern char vgraph_live_buffer[256];
extern int live_command_ready;


void interpret_vgraph(const char* unused_path);
void interpret_vgraph_live();
void send_vga_command(const char *command);


#endif

