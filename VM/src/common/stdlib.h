#ifndef __STDLIB_H
#define __STDLIB_H

#include "types.h"

bool streq(char* string1, int str1len, char* string2, int str2len);
// Copia ‘n’ bytes de src a dst (igual que memcpy de libc).
void *memcpy(void *dst, const void *src, size_t n);

// Llena con byte ‘c’ los primeros ‘n’ bytes de dst.
void *memset(void *dst, int c, size_t n);

// Compara los primeros ‘n’ bytes de a y b. Devuelve 0 si son iguales, <0 si a<b, >0 si a>b.
int memcmp(const void *a, const void *b, size_t n);

// Compara cadenas terminadas en '\0'. Igual que strcmp de libc.
int strcmp(const char *a, const char *b);

// Calcula la longitud de la cadena (sin contar '\0'). Igual que strlen de libc.
size_t strlen(const char *s);

#endif
