#ifndef T_SECRETARIO_H
#define T_SECRETARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConstantes.h"

typedef struct secretario tSecretario;

void liberaSecretario(tSecretario* secretario);

int EhCadastradoSecretario(tSecretario** vetor, tSecretario *secretario, int tam);

void adcionaSecretario(tSecretario** vetor, tSecretario *secretario, int tam);

void leSecretario(tSecretario* secretario);

tSecretario* CriaSecretario();
Login loginSecretario(tSecretario** vetor, char *senha, char *usuario, int tam, int *indexSecretario);
Nivel ObtemNivelAcessoSecretario(tSecretario * secretario);
tSecretario* obtemSecretario(tSecretario** vetor, int index);


int obtemTamTSecretario();
#endif