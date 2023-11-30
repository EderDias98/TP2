#ifndef T_PACIENTE_H
#define T_PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"
#include "tConsulta.h"
#include "tClinica.h"

typedef struct paciente tPaciente;

void liberaPaciente(tPaciente *paciente);

tPaciente *criaPaciente();

void lePaciente(tPaciente *paciente);

void adcionaPaciente(tPaciente **vetor, tPaciente *paciente, int tam);
int EhCadastradoPaciente(tPaciente **vetor, char *cpf, int tam);

int CompletaDadosPaciente(tPaciente *paciente);

void DefiniLesoesPaciente(tPaciente *paciente, tLesoes *lesoes);

tPaciente **BuscarPacientes(tPaciente **pacientes, int tamPacientes, char *nome, char *data, char *diagnostico, int *tamLista);
int comparar_nomes(void *a, void *b);

int CalculaIdade(char *data);
char *SimOuNao(int afirmacao);

tPaciente *copiaPaciente(tPaciente* paciente, tLesoes **vetorLesoes);

tLesoes **ObtemVetorLesoesPaciente(tPaciente *paciente);
tPaciente *ObtemPaciente(tPaciente **pacientes, int index);

char* ObtemNomePaciente(tPaciente *paciente);
char* ObtemDataPaciente(tPaciente *paciente);
char* ObtemGeneroPaciente(tPaciente *paciente);

char* ObtemTelefonePaciente(tPaciente *paciente);

char* ObtemTipoPelePaciente(tPaciente *paciente);
char* ObtemCpfPaciente(tPaciente *paciente);

int ObtemDiabetesPacientes(tPaciente *paciente);

int ObtemFumantePaciente(tPaciente *paciente);

int ObtemAlergiaPaciente(tPaciente *paciente);

int ObtemHistoricoCancerPaciente(tPaciente *paciente);
int ObtemNumLesoesPaciente(tPaciente* paciente);

void incrementaNumLesoesPaciente(tPaciente* paciente);

int JaTemPacientesLista(tPaciente** lista, tPaciente*paciente,int tam);
#endif