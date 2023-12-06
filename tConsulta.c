#include "tConsulta.h"

struct consulta{
    int indexPaciente;
    char nomePaciente[100];
    char dataConsulta[11];
    char nomeMedico[100];
    //colocar as lesoes aqui
};

int obtemTamTConsulta(){
    return sizeof(tConsulta);
}

tConsulta* criaConsulta(char *data, char * nomeMedico, char * nomePaciente, int indexPaciente){
    tConsulta* consulta = (tConsulta*) calloc(1,sizeof(tConsulta));
    if (consulta == NULL) {
        printf("Erro ao alocar memória para o consulta.\n");
        exit(EXIT_FAILURE);
    }

    consulta->indexPaciente;
    strcpy(consulta->dataConsulta,data);
    strcpy(consulta->nomeMedico, nomeMedico);
    strcpy(consulta->nomePaciente,nomePaciente);
    return consulta;
}


void liberaConsulta(tConsulta* consulta) {
    if(consulta=NULL){
        free(consulta);
    }
}


char* obtemDataConsulta(tConsulta* consulta){
    return consulta->dataConsulta;
}

