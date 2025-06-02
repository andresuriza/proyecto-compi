#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>
#include <stdbool.h>

/* Prototipos mínimos para strcmp/strlen/atoi/atof. */
int strcmp(const char *a, const char *b);
size_t strlen(const char *s);
int atoi(const char *s);
double atof(const char *s);

/* Comparación de buffers con longitud explícita. */
bool streq(char* string1, int str1len, char* string2, int str2len);

#endif /* STDLIB_H */

