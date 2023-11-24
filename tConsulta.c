#include "tConsulta.h"

struct consulta{
    int indexPaciente;
    int indexMedico;
    char nomePaciente[100];
    char dataPaciente[11];
    char nomeMedico[100];
    //colocar as lesoes aqui
    tLesoes* lesoes;
    tReceita* receita;
    tBiopsia* biobsia;
    tEncaminhamento* encaminhamento;
};

tConsulta* criaConsulta(int indexMedico, int indexPaciente, char *data, char * nomeMedico, char * nomePaciente){
    tConsulta* consulta = (tConsulta*) calloc(1,sizeof(tConsulta));
    if (consulta == NULL) {
        printf("Erro ao alocar memória para o consulta.\n");
        exit(EXIT_FAILURE);
    }
    consulta->indexMedico = indexMedico;
    consulta->indexPaciente = indexPaciente;
    strcpy(consulta->dataPaciente,data);
    strcpy(consulta->nomeMedico, nomeMedico);
    strcpy(consulta->nomePaciente,nomePaciente);
    return consulta;
}

void adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    tConsulta** vetor = (tConsulta**)realloc(vetor, (tam) * sizeof(tConsulta*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de consultas.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = consulta;

}

void liberaConsulta(tConsulta* consulta) {
    if(consulta=NULL){
        free(consulta);
    }
}

void DefiniLesoesConsulta(tConsulta* consulta,tLesoes * lesoes){
    consulta->lesoes = lesoes;
}

void DefiniReceitaConsulta(tConsulta* consulta,tReceita* receita){
    consulta->receita = receita;
}
void DefiniBiopsiaConsulta(tConsulta* consulta, tBiopsia * biobsia){
    consulta->biobsia  = biobsia;
}

void DefiniEncaminhamentoConsulta(tConsulta* consulta, tEncaminhamento* encaminhamento){
    consulta->encaminhamento = encaminhamento;
}
