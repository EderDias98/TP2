#include "tConstantes.h"


#include <stdio.h>
#include <ctype.h>

void converterParaMaiuscula(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}