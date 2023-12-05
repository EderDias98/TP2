#include "tReceita.h"

struct tReceita{
    char nomePaciente[100];  // ou qualquer tamanho desejado
    eTipoUso tipoUso;
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    int qntd;
    char nomeMedico[100];
    char CRM[20];
    char dataStr[20];
};


tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
char *tipoMedicamento, char *instrucoes, int qntd,
char *nomeMedico, char *CRM, char *dataStr){

    tReceita *receita = (tReceita *) calloc(1,sizeof(tReceita));

    // Verifica se a alocação de memória foi bem-sucedida
    if (receita == NULL) {
        printf("Erro ao alocar memória para a receita\n");
        exit(EXIT_FAILURE);
    }

    // Copia os dados fornecidos para a estrutura
    strncpy(receita->nomePaciente, nomePaciente, sizeof(receita->nomePaciente) - 1);
    receita->tipoUso = tipoUso;
    strncpy(receita->nomeMedicamento, nomeMedicamento, sizeof(receita->nomeMedicamento) - 1);
    strncpy(receita->tipoMedicamento, tipoMedicamento, sizeof(receita->tipoMedicamento) - 1);
    strncpy(receita->instrucoes, instrucoes, sizeof(receita->instrucoes) - 1);
    receita->qntd = qntd;
    strncpy(receita->nomeMedico, nomeMedico, sizeof(receita->nomeMedico) - 1);
    strncpy(receita->CRM, CRM, sizeof(receita->CRM) - 1);
    strncpy(receita->dataStr, dataStr, sizeof(receita->dataStr) - 1);

    return receita;

        
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaReceita(void *dado){
    tReceita * receita = (tReceita *) dado;
    if(receita)
        free(receita);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaReceita(void *dado){
    tReceita * receita = (tReceita *) dado;

    char *tipoUsoStr;
    switch (receita->tipoUso) {
        case ORAL:
            tipoUsoStr = "ORAL";
            break;
        case TOPICO:
            tipoUsoStr = "TOPICO";
            break;
        default:
            break;
    }
        // Imprime os dados da receita no formato especificado
    printf("RECEITUARIO\n");
    printf("NOME: %s\n\n", receita->nomePaciente);
    printf("USO %s\n\n", tipoUsoStr);

    printf("%s\n", receita->nomeMedicamento);
    printf("%d %s\n\n", receita->qntd, receita->tipoMedicamento);
    printf("%s\n\n", receita->instrucoes);
    if(receita->nomeMedico[0]!='\0'){
        printf("%s (CRM-%s)\n", receita->nomeMedico, receita->CRM);
    }else{
        printf("%s (%s)\n", receita->nomeMedico, receita->CRM);
    }

    printf("%s\n\n", receita->dataStr);

}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoReceita(void *dado, char *path){
    
    FILE *arquivo;
    tReceita *receita = (tReceita *)dado;

    char *tipoUsoStr;
    switch (receita->tipoUso) {
        case ORAL:
            tipoUsoStr = "ORAL";
            break;
        case TOPICO:
            tipoUsoStr = "TOPICO";
            break;
        default:
            tipoUsoStr = "DESCONHECIDO";
            break;
    }

    // Abre o arquivo para escrita
    char endereco[200];
    strncpy(endereco,path,sizeof(endereco)-1);
    strcat(endereco,"/receita.txt");
    arquivo = fopen(endereco, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo receita.txt para escrita.\n");
        return;
    }

    // Imprime os dados no arquivo
    fprintf(arquivo, "RECEITUARIO\n");
    fprintf(arquivo, "NOME: %s\n\n", receita->nomePaciente);
    fprintf(arquivo, "USO %s\n\n", tipoUsoStr);

    fprintf(arquivo, "%s\n", receita->nomeMedicamento);
    fprintf(arquivo, "%d %s\n\n", receita->qntd, receita->tipoMedicamento);
    fprintf(arquivo, "%s\n\n", receita->instrucoes);
    if(receita->nomeMedico[0]!='\0'){
        fprintf(arquivo,"%s (CRM-%s)\n", receita->nomeMedico, receita->CRM);
    }else{
        fprintf(arquivo,"%s (%s)\n", receita->nomeMedico, receita->CRM);
    }

    fprintf(arquivo, "%s\n\n", receita->dataStr);

    // Fecha o arquivo
    fclose(arquivo);
}