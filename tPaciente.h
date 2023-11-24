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

void DefiniLesoesPaciente(tPaciente* paciente, tLesoes* lesoes);

void DefiniDataConsulta(tPaciente* paciente, char data);
 
tPaciente** BuscarPacientes(tPaciente** pacientes,int tamPacientes,char *nome,char *data,char *diagnostico, int *tamLista);
int comparar_nomes( void *a, void *b);

tPaciente* ObtemPaciente(tPaciente** pacientes,int index);

char* ObtemGeneroPaciente(tPaciente* paciente);
 
 char* ObtemTelefonePaciente(tPaciente* paciente);
 

 int ObtemDiabetesPacientes(tPaciente* paciente);
 
 int ObtemFumantePaciente(tPaciente* paciente);

 int ObtemAlergiaPaciente(tPaciente* paciente);
 
 int ObtemHistoricoCancerPaciente(tPaciente* paciente);
 

 char* ObtemTipoPelePaciente(tPaciente* paciente);

int CalculaIdade(char * data);
 char* SimOuNao(int afirmacao);
 tLesoes* ObtemLesoesPaciente(tPaciente* paciente);

 tPaciente* copiaPaciente(tPaciente* paciente, tLesoes*lesoes);
#endif