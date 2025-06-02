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

