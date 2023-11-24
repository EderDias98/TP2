#ifndef T_LESAO_
#define T_LESAO_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lesao tLesao;
typedef struct lesoes tLesoes;
tLesao* criaLesao();



// Função para liberar a memória alocada para um lesao
void liberaLesao(tLesao* lesao);
tLesoes* CriaLesoes();
//Funçao que Le o lesao

void leLesao(tLesao* lesao);


// na clinica o tamanho começa com zero

tLesao** adcionaLesao(tLesao** vetor, tLesao *lesao, int tam);
void CadastraLesaoClinica(tLesao** vetor, tLesao*lesao,int tam);

void adcionaLesoes(tLesoes ** vetor, tLesoes *lesoes, int tam);
void IncrementaTamLesoes(tLesoes* lesoes);

tLesao ** ObtemVetorLesoes(tLesoes* lesoes);

int ObtemTamLesoes(tLesoes* lesoes);

char * ObtemDiagnostico(tLesao* lesao);

char *ObtemlesaoVetor(tLesoes* lesoes, int index);

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

tLesao* ObtemLesao(tLesao** vetor, int index);
#endif