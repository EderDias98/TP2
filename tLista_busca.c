#include "tLista_busca.h"

struct lista{
    tPaciente** vetor;
    int tam;
};

void adcionaPacienteListaBusca(tLista* lista, tPaciente* paciente){
    lista->tam++;
    int tam= lista->tam;
    lista->vetor = realloc(lista->vetor, sizeof(tPaciente*)*tam);
    lista->vetor[tam-1] = paciente;
}


tLista* criaListaDeBusca(tPaciente** lista, int numPacientesLista){
    
    tLista* novaLista = (tLista*) calloc(1,sizeof(tLista));
    novaLista->vetor = (tPaciente**) calloc(1,sizeof(tPaciente*));
    if(lista==NULL){
        printf("Erro ao alocar memoria para lista\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<numPacientesLista;i++){
        adcionaPacienteListaBusca(novaLista, copiaPaciente(lista[i]));
    }

    novaLista->tam = numPacientesLista;
    free(lista);
    return novaLista;
}

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLista(void *dado){
    tLista *lista = (tLista*) dado;

    if(lista){
        for(int i=0; i<lista->tam;i++){
            desalocaPaciente(lista->vetor[i]);
        }
        free(lista->vetor);
        free(lista);
    }
        
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


    static int primeiraVezFuncao = 1;
    if(primeiraVezFuncao){
        arquivo = fopen(endereco, "w");
    }else {
        arquivo = fopen(endereco, "a");
    }

    primeiraVezFuncao =0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo receita.txt para escrita.\n");
        return;
    }
    
    for(int i=0; i<lista->tam;i++){
        fprintf(arquivo,"%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->vetor[i]), ObtemCpfPaciente(lista->vetor[i]));
    }
    fprintf(arquivo,"\n");
    fclose(arquivo);
}