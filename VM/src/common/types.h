#ifndef __TYPES_H
#define __TYPES_H

#define bool int
#define false 0
#define true 1
// Tipos de ancho fijo, para reemplazar <stdint.h>
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;

// También define los tamaños básicos
typedef char               int8_t;
typedef short              int16_t;
typedef int                int32_t;

typedef uint32_t           size_t;   
typedef int32_t            ssize_t;  

#endif
