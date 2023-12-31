#ifndef T_LESAO_
#define T_LESAO_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lesao tLesao;
typedef struct lesoes tLesoes;


tLesao* criaLesao();





void desalocaLesoes(tLesoes* lesoes);

tLesoes** copiaVetorLesoes(tLesoes** vetor, int tam);


tLesoes* CopiaLesoes(tLesoes* lesoes);


tLesao* copiaLesao(tLesao* lesao);


// Função para liberar a memória alocada para um lesao
void desalocaLesao(tLesao* lesao);

tLesoes* CriaLesoes();
//Funçao que Le o lesao

void leLesao(tLesao* lesao);


// na clinica o tamanho começa com zero

 void adcionaLesao(tLesoes*lesoes, tLesao *lesao);

void CadastraLesao(tLesoes* lesoes, tLesao*lesao);


void IncrementaTamLesoes(tLesoes* lesoes);

tLesao ** ObtemVetorLesoes(tLesoes* lesoes);

int ObtemTamLesoes(tLesoes* lesoes);

char * ObtemDiagnostico(tLesao* lesao);



char * ObtemRotulo(tLesao * lesao);

// Função para obter o diagnóstico clínico da lesão
char *ObtemDiagnosticoClinico(tLesao *lesao);


// Função para obter a região do corpo da lesão
char *ObtemRegiaoCorpo(tLesao *lesao);


// Função para obter o tamanho da lesão
int ObtemTamanho(tLesao *lesao);
 

// Função para obter se a lesão deve ser enviada para cirurgia
int ObtemEnviarCirurgia(tLesao *lesao);


// Função para obter se a lesão deve ser enviada para crioterapia
int ObtemEnviarCrioterapia(tLesao *lesao);

tLesao* obtemLesao(tLesoes* lesoes, int index);


int QtdEnvidasCirurgia(tLesoes** vetor, int tam);

int QtdEnvidasCrioterapia(tLesoes** vetor, int tam);
int ObtemIndexPacienteLesoes(tLesoes* lesoes);

   

char* EnviadaOnde(tLesao* lesao);
int calculaNumLesao(tLesoes** vetor , int numLesoes);

tLesoes *obtemLesoes(tLesoes** vetor, int index);
void DefineLesoesBin(tLesoes* lesoes, int indexPaciente, int tam);

int obtemTamTLesao();
int obtemTamTLesoes();
int NaoTemLesaoCirurgia(tLesoes* lesoes);

void LeBinLesaoVetor(tLesoes* lesoes,FILE * arquivo, int tam);
void EscreveBinLesaoVetor(tLesoes* lesoes, FILE* arquivo);
void defineIndexPacienteLesoes(tLesoes* lesoes, int indexPaciente);
#endif