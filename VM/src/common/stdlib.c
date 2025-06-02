#include "stdlib.h"

bool streq(char* string1, int str1len, char* string2, int str2len) {
	if (str1len != str2len) return false;
	for (int i = 0; i < str1len; i++) {
		if (string1[i] != string2[i]) return false;
	}
	return true;
}

void *memcpy(void *dst, const void *src, size_t n) {
    // Copiamos byte a byte; asumo que no importa la alineación
    uint8_t *d = (uint8_t*)dst;
    const uint8_t *s = (const uint8_t*)src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dst;
}

void *memset(void *dst, int c, size_t n) {
    uint8_t *d = (uint8_t*)dst;
    uint8_t byte = (uint8_t)c;
    for (size_t i = 0; i < n; i++) {
        d[i] = byte;
    }
    return dst;
}

int memcmp(const void *a, const void *b, size_t n) {
    const uint8_t *pa = (const uint8_t*)a;
    const uint8_t *pb = (const uint8_t*)b;
    for (size_t i = 0; i < n; i++) {
        if (pa[i] < pb[i]) return -1;
        if (pa[i] > pb[i]) return +1;
    }
    return 0;
}

int strcmp(const char *a, const char *b) {
    size_t i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return +1;
        i++;
    }
    // Si salimos, o bien ambos son '\0' (iguales), o uno es más corto.
    if (a[i] == '\0' && b[i] == '\0') return 0;
    if (a[i] == '\0') return -1;
    return +1;
}

size_t strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
