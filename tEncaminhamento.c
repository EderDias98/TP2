#include "tEncaminhamento.h"

 struct encaminhamento{
    char nomePaciente[100];
    char cpfPaciente[15];
    char nomeMedico[100];
    char CRM[20];
    char dataStr[11];
    char especialidade[50];
    char motivo[300];
} ;




tEncaminhamento *criaEncaminhamento(char *nomePaciente,  char *cpfPaciente,
char *nomeMedico, char *CRM, char *dataStr,char* especialidade, char* motivo){
    tEncaminhamento *encaminhamento = (tEncaminhamento*) calloc(1,sizeof(tEncaminhamento));

    // Verifica se a alocação de memória foi bem-sucedida
    if (encaminhamento == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o encaminhamento.\n");
        exit(EXIT_FAILURE);
    }

    // Copia os dados fornecidos para a estrutura usando ponteiros
    strncpy(encaminhamento->nomePaciente, nomePaciente, sizeof(encaminhamento->nomePaciente) - 1);
    strncpy(encaminhamento->cpfPaciente, cpfPaciente, sizeof(encaminhamento->cpfPaciente) - 1);
    strncpy(encaminhamento->nomeMedico, nomeMedico, sizeof(encaminhamento->nomeMedico) - 1);
    strncpy(encaminhamento->CRM, CRM, sizeof(encaminhamento->CRM) - 1);
    strncpy(encaminhamento->dataStr, dataStr, sizeof(encaminhamento->dataStr) - 1);
    strncpy(encaminhamento->especialidade, especialidade, sizeof(encaminhamento->especialidade) - 1);
    strncpy(encaminhamento->motivo, motivo, sizeof(encaminhamento->motivo) - 1);

    return encaminhamento;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaEncaminhamento(void *dado){
    tEncaminhamento* encaminhamento = (tEncaminhamento* )dado;
    if(encaminhamento)
        free(encaminhamento);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaEncaminhamento(void *dado){
    
    tEncaminhamento *encaminhamento = (tEncaminhamento *)dado;

    // Imprime os dados no formato especificado
    printf("PACIENTE: %s\n", encaminhamento->nomePaciente);
    printf("CPF: %s\n\n", encaminhamento->cpfPaciente);
    printf("ESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento->especialidade);
    printf("MOTIVO: %s\n\n", encaminhamento->motivo);
    printf("%s (%s)\n", encaminhamento->nomeMedico, encaminhamento->CRM);
    printf("%s\n\n", encaminhamento->dataStr);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoEncaminhamento(void *dado, char *path){
    
    FILE *arquivo;
    tEncaminhamento *encaminhamento = (tEncaminhamento *)dado;

    // Abre o arquivo para escrita
    char endereco[200];
    strcpy(endereco,path);
    strcat(endereco,"/encaminhamento.txt");


    static int primeiraVezFuncao = 1;
    if(primeiraVezFuncao){
        arquivo = fopen(endereco, "w");
    }else {
        arquivo = fopen(endereco, "a");
    }

    primeiraVezFuncao =0;

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Imprime os dados no arquivo usando fprintf
    fprintf(arquivo, "PACIENTE: %s\n", encaminhamento->nomePaciente);
    fprintf(arquivo, "CPF: %s\n\n", encaminhamento->cpfPaciente);
    fprintf(arquivo, "ESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento->especialidade);
    fprintf(arquivo, "MOTIVO: %s\n\n", encaminhamento->motivo);
    fprintf(arquivo, "%s (%s)\n", encaminhamento->nomeMedico, encaminhamento->CRM);


    fprintf(arquivo, "%s\n\n", encaminhamento->dataStr);

    // Fecha o arquivo
    fclose(arquivo);
}