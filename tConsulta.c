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

void adcionaConsulta(tConsulta** vetor, tConsulta *consulta, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
     vetor = (tConsulta**)realloc(vetor, (tam) * sizeof(tConsulta*));

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
char* obtemDataConsulta(tConsulta* consulta){
    return consulta->dataConsulta;
}


tPaciente** BuscaPacientes(tConsulta** vetorConsulta,int tamConsultas,char *nome,char *data,char *diagnostico,
int* tamLista){
    tPaciente** lista = (tPaciente**) calloc(1, sizeof(tPaciente*));


    tLesoes * lesoes = NULL;
 
    if(lista == NULL){
        printf("Erro ao alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    int peloMenosUmPaciente =0;

//nome
    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamConsultas;i++){
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;
            if(strcmp(nome,ObtemNomePaciente(pacienteAtual))==0 &&
            !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
        }
    }
//data
    if(nome[0]=='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamConsultas;i++){
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;
            if(strcmp(nome,obtemDataConsulta(vetorConsulta[i]))==0 &&
            !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
        }
    }
//lesao
    if(nome[0]=='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamConsultas;i++){
            lesoes = vetorConsulta[i]->lesoes;
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(obtemLesao(lesoes,j)))==0
                && !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                }
            }
        }
    }

    
// nome e data
    if(nome[0]!='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamConsultas;i++){
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;
            if(ObtemNomePaciente(pacienteAtual) ==0 &&
            obtemDataConsulta(vetorConsulta[i]) ==0 &&
            !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){

                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
        }
    }
//nome e diagnostico
    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamConsultas;i++){
            lesoes = vetorConsulta[i]->lesoes;
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){

                if(strcmp(nome,ObtemNomePaciente(pacienteAtual))==0 &&
                strcmp(diagnostico, ObtemDiagnostico(obtemLesao(lesoes,j)))==0 &&
                !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){

                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                }
            }
        }
    }

    //data e diagnostico

    if(nome[0] =='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamConsultas;i++){
            
            lesoes = vetorConsulta[i]->lesoes;
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;

            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(obtemLesao(lesoes,j)))==0 &&
                obtemDataConsulta(vetorConsulta[i]) ==0 &&
                !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                }
            }
        }
    }

 // data paciente e lesao
    if(nome[0] !='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamConsultas;i++){
                  
            lesoes = vetorConsulta[i]->lesoes;
            tPaciente* pacienteAtual = vetorConsulta[i]->paciente;

            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(obtemLesao(lesoes,j)))==0 &&
                obtemDataConsulta(vetorConsulta[i]) ==0 &&
                strcmp(nome,ObtemNomePaciente(pacienteAtual))==0 &&
                 !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                    
                }
            }
        }
    }

    if(!peloMenosUmPaciente){
        free(lista);
        lista =NULL;
    }

    return lista;
}