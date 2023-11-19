#ifndef T_MEDICO_H
#define T_MEDICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConstantes.h"

typedef struct medico tMedico;

void liberaMedico(tMedico* medico);
int EhCadastradoMedico(tMedico** vetor, tMedico *medico, int tam);
void adcionaMedico(tMedico** vetor, tMedico *medico, int tam);
void leMedico(tMedico* medico);
tMedico* criaMedico();
Login loginMedico(tMedico** vetor, char *senha, char *usuario, int tam,int *indexMedico);

char * ObtemNomeMedico(tMedico* medico);
char *ObtemCrm(tMedico*medico);
#endif