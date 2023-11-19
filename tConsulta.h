#ifndef TCONSULTA_H
#define TCONSULTA_H

#include "tLesao.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tMedico.h"
#include "tPaciente.h"

typedef struct consulta tConsulta;
tConsulta* criaConsulta(int indexMedico, int indexPacient, char *data, char * nomeMedico);
void adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam);

void liberaConsulta(tConsulta* consulta);

void DefinirLesoesConsulta(tConsulta* consulta,tLesoes * lesoes);
void DefiniReceitaConsulta(tConsulta* consulta,tReceita* receita);
void DefinirBiopsiaConsulta(tConsulta* consulta, tBiopsia * biobsia);

void DefinirEncaminhamentoConsulta(tConsulta* consulta, tEncaminhamento* encaminhamento);

#endif