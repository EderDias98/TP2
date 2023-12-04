#include "tConsulta.h"

struct consulta{
    tPaciente* paciente;
    tMedico* medico;
    char nomePaciente[100];
    char dataConsulta[11];
    char nomeMedico[100];
    //colocar as lesoes aqui
    tLesoes* lesoes;
    tReceita* receita;
    tBiopsia* biobsia;
    tEncaminhamento* encaminhamento;
};

int obtemTamTConsulta(){
    return sizeof(tConsulta);
}
tLesoes* obtemLesoesConsulta(tConsulta* consulta){
    return consulta->lesoes;
}
tConsulta* criaConsulta(tPaciente* paciente,tMedico* medico, char *data, char * nomeMedico, char * nomePaciente){
    tConsulta* consulta = (tConsulta*) calloc(1,sizeof(tConsulta));
    if (consulta == NULL) {
        printf("Erro ao alocar memória para o consulta.\n");
        exit(EXIT_FAILURE);
    }
    consulta->paciente = paciente;
    consulta->medico = medico;
    strcpy(consulta->dataConsulta,data);
    strcpy(consulta->nomeMedico, nomeMedico);
    strcpy(consulta->nomePaciente,nomePaciente);
    return consulta;
}

tConsulta** adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
     vetor = (tConsulta**)realloc(vetor, (tam) * sizeof(tConsulta*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de consultas.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = consulta;
    return vetor;
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
char* obtemDataConsulta(tConsulta* consulta){
    return consulta->dataConsulta;
}
char * ObtemCpfConsulta(tConsulta* consulta){
    return ObtemCpfPaciente(consulta->paciente);
}

