#ifndef T_CONSTANTES_H
#define T_CONSTANTES_H
#include <stdio.h>
#include <ctype.h>
typedef enum
{
    ADMIN,
    USER,
    MEDI,
} Nivel;

typedef enum
{
    CORRETO,
    INCORRETO,
} Login;

void converterParaMaiuscula(char *str);
#endif