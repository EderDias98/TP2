#ifndef T_PACIENTE_H
#define T_PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"

typedef struct paciente tPaciente;


void liberaPaciente(tPaciente* paciente);


tPaciente* criaPaciente();
 



void lePaciente(tPaciente* paciente);
 
void adcionaPaciente(tPaciente** vetor, tPaciente *paciente, int tam);
int EhCadastradoPaciente(tPaciente** vetor, char *cpf, int tam);


char * ObtemNomePaciente(tPaciente* paciente);
char * ObtemDataPaciente(tPaciente* paciente);

int CompletaDadosPaciente(tPaciente* paciente);
char * ObtemCpfPaciente(tPaciente* paciente);

void DefiniLesoesPaciente(tPaciente* paciente,tLesoes* lesoes);
void DefiniDataConsultaPaciente(tPaciente* paciente, char * data);


 
#endif