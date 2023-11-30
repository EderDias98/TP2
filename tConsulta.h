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
void adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam);

void liberaConsulta(tConsulta* consulta);

void DefiniLesoesConsulta(tConsulta* consulta,tLesoes * lesoes);
void DefiniReceitaConsulta(tConsulta* consulta,tReceita* receita);
void DefiniBiopsiaConsulta(tConsulta* consulta, tBiopsia * biobsia);

void DefiniEncaminhamentoConsulta(tConsulta* consulta, tEncaminhamento* encaminhamento);

char* obtemDataConsulta(tConsulta* consulta);

#endif