#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>
#include <stdbool.h>

/* Prototipos mínimos para strcmp/strlen/atoi/atof. */
int strcmp(const char *a, const char *b);
size_t strlen(const char *s);
int atoi(const char *s);
double atof(const char *s);
void *memcpy(void *dst, const void *src, size_t n);
char *strchr(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
int strncmp(const char *a, const char *b, size_t n);
char *strtok(char *s, const char *sep);
size_t strspn(const char *s, const char *accept);
char *strpbrk(const char *s, const char *accept);
/* Comparación de buffers con longitud explícita. */
bool streq(char* string1, int str1len, char* string2, int str2len);
char *strncpy(char *dst, const char *src, size_t n);
char *strcpy(char *dest, const char *src);
void *memmove(void *dest, const void *src, size_t n);


#endif /* STDLIB_H */

