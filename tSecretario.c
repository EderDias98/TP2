#include "tSecretario.h"

struct secretario {
    char nomeCompleto[101]; // Nome completo (string com no máximo 100 caracteres)
    char cpf[15];           // CPF (no formato: 000.000.000-00)
    char dataNascimento[11];// Data de nascimento (seguindo padrão dd/mm/aaaa)
    char telefone[15];      // Telefone (formato: (00)00000-0000)
    char genero[10];        // Gênero (masculino, feminino, outros)
    char nomeUsuario[21];
    char senha[21];
    char nivelAcesso[10];
};


int obtemTamTSecretario(){
    return sizeof(tSecretario);
}
tSecretario* CriaSecretario() {
    tSecretario* secretario = (tSecretario*) calloc(1,sizeof(tSecretario));
    if (secretario == NULL) {
        printf("Erro ao alocar memória para o secretario.\n");
        exit(EXIT_FAILURE);
    }
    return secretario;
}

tSecretario* obtemSecretario(tSecretario** vetor, int index){
    return vetor[index];
}


// Função para liberar a memória alocada para um secretario
void liberaSecretario(tSecretario* secretario) {
    if(secretario!=NULL){
        free(secretario);
    }
}

//Funçao que Le o secretario

void leSecretario(tSecretario* secretario){
    printf("NOME COMPLETO: ");
    scanf("%100[^\n]%*c", secretario->nomeCompleto);
    converterParaMaiuscula(secretario->nomeCompleto);

    printf("CPF: ");
    scanf("%14[^\n]%*c", secretario->cpf);
    converterParaMaiuscula(secretario->cpf);

    printf("DATA DE NASCIMENTO: ");
    scanf("%10[^\n]%*c", secretario->dataNascimento);
    converterParaMaiuscula(secretario->dataNascimento);

    printf("TELEFONE: ");
    scanf("%14[^\n]%*c", secretario->telefone);
    converterParaMaiuscula(secretario->telefone);

    printf("GENERO: ");
    scanf("%9[^\n]%*c", secretario->genero);
    converterParaMaiuscula(secretario->genero);

    printf("NOME DE USUARIO: ");
    scanf("%20[^\n]%*c", secretario->nomeUsuario);
    converterParaMaiuscula(secretario->nomeUsuario);

    printf("SENHA: ");
    scanf("%20[^\n]%*c", secretario->senha);
    converterParaMaiuscula(secretario->senha);

    printf("NIVEL DE ACESSO: ");
    scanf("%9[^\n]%*c", secretario->nivelAcesso);
    converterParaMaiuscula(secretario->nivelAcesso);
}

// na clinica o tamanho começa com zero


    //incrementar numero de pacientes antes da funçao



int EhCadastradoSecretario(tSecretario** vetor, tSecretario *secretario, int tam){
    for(int i=0; i<tam;i++){
        
        if(strcmp(vetor[i]->cpf,secretario->cpf)==0){
            return i;
        }
    }
    return -1;
}

Login loginSecretario(tSecretario** vetor, char *senha, char *usuario, int tam, int *indexSecretario){
    int senhaCorreta =0;
    int usuarioCorreto =0;

    int i,j;
    for(i=0; i< tam; i++){
        if(strcmp(vetor[i]->senha,senha)==0){
            senhaCorreta =1;
            break;
        }
    }
    if(!senhaCorreta){
        return INCORRETO;
    }

    for(j=0; j< tam; j++){
        if(strcmp(vetor[j]->nomeUsuario,usuario)==0){
            usuarioCorreto =1;
            break;
        }
    }

    if(!usuarioCorreto){
        return INCORRETO;
    }

    if(i==j){
        *indexSecretario = i;
        return CORRETO;
    }

    return INCORRETO;

}

Nivel ObtemNivelAcessoSecretario(tSecretario * secretario){
    if(strcmp(secretario->nivelAcesso, "ADMIN")==0)
        return ADMIN;
    if(strcmp(secretario->nivelAcesso, "USER")==0)
        return USER;
    
    return MEDI;
}

void desalocarSecretario(tSecretario* secretario){
    if(secretario){
        free(secretario);
    }
}