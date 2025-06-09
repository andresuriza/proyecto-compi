#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>

/*
 * strcmp: compara dos cadenas terminadas en '\0'.
 *  Devuelve 0 si son iguales, <0 si a < b, >0 si a > b (lexicográficamente).
 */
int strcmp(const char *a, const char *b) {
    size_t i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return +1;
        i++;
    }
    // Si salimos del bucle, una (o ambas) cadenas terminaron en '\0'
    if (a[i] == '\0' && b[i] == '\0') return 0;
    if (a[i] == '\0') return -1;
    return +1;
}

/*
 * strlen: cuenta el número de caracteres antes del '\0'.
 */
size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

/*
 * atoi: convierte una cadena (opcionalmente con signo) a int.
 *  Solo maneja enteros “normales” (sin decimales ni exponentes).
 */
int atoi(const char *s) {
    int res = 0;
    int signo = 1;
    size_t i = 0;

    // Saltar espacios iniciales
    while (s[i] == ' ' || s[i] == '\t') {
        i++;
    }
    // Signo
    if (s[i] == '+') {
        i++;
    } else if (s[i] == '-') {
        signo = -1;
        i++;
    }
    // Dígitos
    while (s[i] >= '0' && s[i] <= '9') {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return signo * res;
}

/*
 * atof: convierte cadena a double en forma muy básica.
 *  Soporta parte entera, parte decimal, signo, pero NO manejamos exponentes (e o E).
 */
double atof(const char *s) {
    double resultado = 0.0;
    double signo = 1.0;
    size_t i = 0;

    // Saltar espacios iniciales
    while (s[i] == ' ' || s[i] == '\t') {
        i++;
    }
    // Signo
    if (s[i] == '+') {
        i++;
    } else if (s[i] == '-') {
        signo = -1.0;
        i++;
    }
    // Parte entera
    while (s[i] >= '0' && s[i] <= '9') {
        resultado = resultado * 10.0 + (double)(s[i] - '0');
        i++;
    }
    // Parte decimal (si existe un '.')
    if (s[i] == '.') {
        i++;
        double parte = 0.0;
        double divisor = 10.0;
        while (s[i] >= '0' && s[i] <= '9') {
            parte += (double)(s[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
        resultado += parte;
    }
    // Nota: no manejamos exponente “e/E” en esta versión mínima.
    return signo * resultado;
}

/* 
 * streq: compara dos buffers byte a byte, con longitud explicita.
 *  Esta función no es estrictamente necesaria para parsear parámetros, 
 *  pero la mantenemos si la estabas usando en otra parte.
 */
bool streq(char* string1, int str1len, char* string2, int str2len) {
    if (str1len != str2len) return false;
    for (int i = 0; i < str1len; i++) {
        if ((uint8_t)string1[i] != (uint8_t)string2[i]) return false;
    }
    return true;
}

/*
 * memcpy: copia n bytes de src a dst (no se solapan).
 */
void *memcpy(void *dst, const void *src, size_t n) {
    unsigned char *d = (unsigned char*)dst;
    const unsigned char *s = (const unsigned char*)src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

/*
 * strchr: busca el primer carácter c (convertido a char) en s,
 * devuelve puntero a él o NULL si no se encuentra.
 */
char *strchr(const char *s, int c) {
    char ch = (char)c;
    for (; *s; s++) {
        if (*s == ch) return (char*)s;
    }
    return (ch == '\0') ? (char*)s : NULL;
}

/*
 * strstr: busca la primera aparición de needle en haystack,
 * devuelve puntero al inicio o NULL si no se encuentra.
 */
char *strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char*)haystack;
    for (; *haystack; haystack++) {
        const char *h = haystack, *n = needle;
        while (*h && *n && *h == *n) {
            h++; n++;
        }
        if (!*n) return (char*)haystack;
    }
    return NULL;
}

/*
 * strncmp: compara hasta n caracteres de a y b.
 *  Devuelve 0 si iguales, <0 si a<b, >0 si a>b.
 */
int strncmp(const char *a, const char *b, size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        unsigned char ca = (unsigned char)a[i];
        unsigned char cb = (unsigned char)b[i];
        if (ca != cb || ca == '\0' || cb == '\0') {
            return (int)ca - (int)cb;
        }
    }
    return 0;
}

/*
 * strtok: tokeniza s en delimitadores sep.
 *  Llamadas posteriores con s==NULL continúan la tokenización.
 */
char *strtok(char *s, const char *sep) {
    static char *saveptr;
    if (s == NULL) {
        s = saveptr;
        if (s == NULL) return NULL;
    }
    /* Saltar delimitadores iniciales */
    s += strspn(s, sep);
    if (*s == '\0') {
        saveptr = NULL;
        return NULL;
    }
    /* Encontrar final del token */
    char *tok = s;
    s = strpbrk(tok, sep);
    if (s) {
        *s = '\0';
        saveptr = s + 1;
    } else {
        saveptr = NULL;
    }
    return tok;
}

/*
 * strspn: longitud del prefijo de s que contiene solo bytes de accept.
 */
size_t strspn(const char *s, const char *accept) {
    const char *p;
    size_t count = 0;
    for (; *s; s++) {
        for (p = accept; *p; p++) {
            if (*s == *p) break;
        }
        if (!*p) break;
        count++;
    }
    return count;
}

/*
 * strpbrk: busca en s el primer carácter que esté en accept,
 * devuelve puntero a él o NULL.
 */
char *strpbrk(const char *s, const char *accept) {
    for (; *s; s++) {
        for (const char *a = accept; *a; a++) {
            if (*s == *a) return (char*)s;
        }
    }
    return NULL;
}

char *strncpy(char *dst, const char *src, size_t n) {
    size_t i = 0;
    // Copiar caracteres de src
    for (; i < n && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    // Rellenar con '\0' si src terminó antes
    for (; i < n; i++) {
        dst[i] = '\0';
    }
    return dst;
}

