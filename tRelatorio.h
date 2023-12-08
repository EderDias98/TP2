#ifndef T_RELATORIO_H
#define T_RELATORIO_H


#define NUM_DIAGONOSTICOS 7



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tClinica.h"
#include <math.h>

typedef struct diagnostico tDiagnostico;
typedef struct relatorio tRelatorio;

typedef int (*func_ptr_compara)(const void *a,const void*b);

tRelatorio *criaRelatorio();

int calculaPacientesAtendidos(tPaciente **pacientes, int numPacientes);
void ContaNumDiagnostico(tLesoes **vetor, tDiagnostico **vetorD, int numDiagnostico, int numLesoes);
int compararDiagnostico(const void *a, const void *b);
tDiagnostico** CriaVetorDiagnostico();
tDiagnostico* CriaDiagnostico(char* nome);
tRelatorio* CriaRelatorio(tClinica* clinica);
void calculaEstatisticasProcedimentos(tLesoes **vetor, int numLesoes,int *totalLesoes ,int *numCirurgias, int *numCrioterapias);
void calculaEstatisticasTamanhoLesoes(tLesoes **vetor, int numLesoes, int *media, int *desvioPadrao);
void calcularDistribuicaoGenero(tPaciente **pacientes, int numPacientes, int *masculino, int *feminino, int *outros);
void calculaEstatisticasIdade(tPaciente **pacientes, int numPacientes, int *media, int *desvioPadrao);

void desalocaRelatorio(void *dado);
void imprimeNaTelaRelatorio(void *dado);
void imprimeEmArquivoRelatorio(void *dado, char *path);

void trocar(tDiagnostico **vetor,int j);

void bubbleSort(tDiagnostico **arr, int n,  func_ptr_compara comparar);
#endif