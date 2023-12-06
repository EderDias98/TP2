#ifndef TCONSULTA_H
#define TCONSULTA_H

#include "tLesao.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tMedico.h"
#include "tPaciente.h"
#include "tFila.h"

typedef struct consulta tConsulta;
tConsulta* criaConsulta( char *data, char * nomeMedico,char * nomePaciente, int indexPaciente);


void liberaConsulta(tConsulta* consulta);



char* obtemDataConsulta(tConsulta* consulta);

int obtemTamTConsulta();

#endif