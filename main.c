#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define TAM_CAMINHO 300


int main(int argc , int *argv[]){
   
    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n"); 
    printf("################################################\n");

    char pathBancoDados[TAM_CAMINHO];
    scanf("%s", pathBancoDados);
    printf("%s", pathBancoDados);

    // Tenta abrir o diretório
    if (access(pathBancoDados, F_OK) != -1) {
        printf("O diretório existe.\n");
    } else {
        printf("O diretório NÃO existe ou não é acessível.\n");
    }





    return 0;
}