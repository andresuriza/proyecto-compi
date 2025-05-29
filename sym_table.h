#ifndef SYM_TABLE_H
#define SYM_TABLE_H

typedef struct sym_entry{
  char const *name; /* Name of the symbol */
  int type; /* Type of symbol */
  union
  {
    float real_value;
    float *array;
  } value; /* Value of symbol */
  struct sym_entry *next; /* Next node */
} sym_entry;

extern sym_entry *sym_table;

sym_entry *sym_table_put_vector(char const *name, float *value);
sym_entry *sym_table_put_scalar(char const *name, float value);
float *sym_table_get_vector(char const *name);
float sym_table_get_scalar(char const *name);
void free_sym_table(void);
#endif
