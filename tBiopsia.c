#include "tBiopsia.h"

struct biopsia {
    char nomePaciente[100];
    char nomeMedico[100];
    char CRM[20];
    char data[11];  // Data no formato dd/mm/aaaa
    char cpfPaciente[15]; 
    tLesoes *lesoes;            // Outros campos conforme necessário
};

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tBiopsia *criaBiopsia(char *nomePaciente,  char *cpfPaciente,tLesoes*lesoes,
char *nomeMedico, char *CRM, char *dataStr){
    
    tBiopsia* biopsia = (tBiopsia *) calloc(1,sizeof(tBiopsia));

    // Verifica se a alocação de memória foi bem-sucedida
    if (biopsia == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a biópsia.\n");
        exit(EXIT_FAILURE);
    }

    // Copia os dados fornecidos para a estrutura
    strncpy(biopsia->nomePaciente, nomePaciente, sizeof(biopsia->nomePaciente) - 1);
    strncpy(biopsia->cpfPaciente, cpfPaciente, sizeof(biopsia->cpfPaciente) - 1);
    biopsia->lesoes = CopiaLesoes(lesoes); // Supondo que lesoes seja uma estrutura válida
    strncpy(biopsia->nomeMedico, nomeMedico, sizeof(biopsia->nomeMedico) - 1);
    strncpy(biopsia->CRM, CRM, sizeof(biopsia->CRM) - 1);
    strncpy(biopsia->data, dataStr, sizeof(biopsia->data) - 1);

    return biopsia;

}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaBiopsia(void *dado){
    tBiopsia* biopsia = (tBiopsia*) dado;
    if(biopsia){
        if(biopsia->lesoes){
            desalocaLesoes(biopsia->lesoes);
        }

        free(biopsia);

    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaBiopsia(void *dado){
    tBiopsia *biopsia = (tBiopsia *)dado;

    // Imprime os dados no formato especificado
    printf("PACIENTE: %s\n", biopsia->nomePaciente);
    printf("CPF: %s\n\n", biopsia->cpfPaciente);

    // Imprime as lesões
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");

    for(int i=0; i<ObtemTamLesoes(biopsia->lesoes);i++){
        tLesao *lesaoAtual = obtemLesao(biopsia->lesoes,i);
        if(ObtemEnviarCirurgia(lesaoAtual) == 1){
            printf("%s - %s - %s - %dMM\n", ObtemRotulo(lesaoAtual), ObtemDiagnosticoClinico(lesaoAtual), ObtemRegiaoCorpo(lesaoAtual),
             ObtemTamanho(lesaoAtual));
        }
    }

    printf("\n%s (%s)\n", biopsia->nomeMedico, biopsia->CRM);
    printf("%s\n\n", biopsia->data);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoBiopsia(void *dado, char *path){
    FILE *arquivo;
    tBiopsia *biopsia = (tBiopsia *)dado;

    // Abre o arquivo para escrita
    char endereco[200];
    strncpy(endereco,path,sizeof(endereco)-1);
    strcat(endereco,"/biopsia.txt");

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

    // Imprime os dados no arquivo
    fprintf(arquivo, "PACIENTE: %s\n", biopsia->nomePaciente);
    fprintf(arquivo, "CPF: %s\n\n", biopsia->cpfPaciente);

    // Imprime as lesões no arquivo
    fprintf(arquivo, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");

    for (int i = 0; i < ObtemTamLesoes(biopsia->lesoes); i++) {
        tLesao *lesaoAtual = obtemLesao(biopsia->lesoes, i);
        if (ObtemEnviarCirurgia(lesaoAtual) == 1) {
            fprintf(arquivo, "%s - %s - %s - %dMM\n", ObtemRotulo(lesaoAtual), ObtemDiagnosticoClinico(lesaoAtual),
                    ObtemRegiaoCorpo(lesaoAtual), ObtemTamanho(lesaoAtual));
        }
    }

    fprintf(arquivo, "\n%s (%s)\n", biopsia->nomeMedico, biopsia->CRM);
    int ano = 0, mes = 0, dia = 0;

    sscanf(biopsia->data, "%d/%d/%d", &dia, &mes, &ano);

    fprintf(arquivo, "%d/%d/%d\n\n", dia,mes,ano);

    // Fecha o arquivo
    fclose(arquivo);
}

int EhPossivelBiopsia(tBiopsia * biopsia){
    for (int i = 0; i < ObtemTamLesoes(biopsia->lesoes); i++) {
        tLesao *lesaoAtual = obtemLesao(biopsia->lesoes, i);
        if (ObtemEnviarCirurgia(lesaoAtual) == 1) {
            return 1;
        }
    }
    return 0;
}