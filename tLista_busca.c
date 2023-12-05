#include "tLista_busca.h"

struct lista{
    tPaciente** vetor;
    int tam;
};




tLista* criaListaDeBusca(tPaciente** lista, int numPacientesLista){
    
    tLista* novaLista = (tLista*) calloc(1,sizeof(tLista));

    if(lista==NULL){
        printf("Erro ao alocar memoria para lista\n");
        exit(EXIT_FAILURE);
    }
    novaLista->vetor = lista;
    novaLista->tam = numPacientesLista;

    return novaLista;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLista(void *dado){
    tLista *lista = (tLista*) dado;

    if(lista)
        free(lista);
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaLista(void *dado){
    tLista *lista = (tLista*) dado;
    for(int i=0; i<lista->tam;i++){
        printf("%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->vetor[i]), ObtemCpfPaciente(lista->vetor[i]));
    }
    printf("\n");
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoLista(void *dado, char *path){
    tLista *lista = (tLista*) dado;



    FILE* arquivo =NULL;
    char endereco[200];
    strncpy(endereco,path,sizeof(endereco)-1);
    strcat(endereco,"/lista_busca.txt");
    arquivo = fopen(endereco, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo receita.txt para escrita.\n");
        return;
    }

    for(int i=0; i<lista->tam;i++){
        fprintf(arquivo,"%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->vetor[i]), ObtemCpfPaciente(lista->vetor[i]));
    }

    fclose(arquivo);
}