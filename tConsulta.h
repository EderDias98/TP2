#ifndef TCONSULTA_H
#define TCONSULTA_H

#include "tLesao.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tMedico.h"
#include "tPaciente.h"

typedef struct consulta tConsulta;
tConsulta* criaConsulta(tPaciente* paciente,tMedico* medico, char *data, char * nomeMedico,char * nomePaciente);
tConsulta** adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam);
tLesoes* obtemLesoesConsulta(tConsulta* consulta);
void liberaConsulta(tConsulta* consulta);

void DefiniLesoesConsulta(tConsulta* consulta,tLesoes * lesoes);
void DefiniReceitaConsulta(tConsulta* consulta,tReceita* receita);
void DefiniBiopsiaConsulta(tConsulta* consulta, tBiopsia * biobsia);

void DefiniEncaminhamentoConsulta(tConsulta* consulta, tEncaminhamento* encaminhamento);

char* obtemDataConsulta(tConsulta* consulta);

int obtemTamTConsulta();
tPaciente** BuscaPacientes(tConsulta** vetorConsulta,int tamConsultas,char *nome,char *data,char *diagnostico,
int* tamLista);
char * ObtemCpfConsulta(tConsulta* consulta);
#endif