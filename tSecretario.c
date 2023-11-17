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

tSecretario* CriaSecretario() {
    tSecretario* secretario = (tSecretario*) calloc(1,sizeof(tSecretario));
    if (secretario == NULL) {
        printf("Erro ao alocar memória para o secretario.\n");
        exit(EXIT_FAILURE);
    }
    return secretario;
}



// Função para liberar a memória alocada para um secretario
void liberaSecretario(tSecretario* secretario) {
    if(secretario!=NULL){
        free(secretario);
    }
}

//Funçao que Le o secretario

void leSecretario(tSecretario* secretario){
    printf("NOME COMPLETO:\n");
    scanf("%100[^\n]%*c", secretario->nomeCompleto);

    printf("CPF: \n");
    scanf("%14[^\n]%*c", secretario->cpf);

    printf("DATA DE NASCIMENTO:\n");
    scanf("%10[^\n]%*c", secretario->dataNascimento);

    printf(" TELEFONE:\n");
    scanf("%14[^\n]%*c", secretario->telefone);

    printf("GENERO:\n");
    scanf("%9[^\n]%*c", secretario->genero);
    
    printf("NOME DE USUARIO:\n");
    scanf("%20[^\n]%*c", secretario->nomeUsuario);

    printf("SENHA:\n");
    scanf("%20[^\n]%*c", secretario->senha);

    printf("NIVEL DE ACESSO:\n");
    scanf("%9[^\n]%*c", secretario->nivelAcesso);

}

// na clinica o tamanho começa com zero


    //incrementar numero de pacientes antes da funçao

tSecretario** adcionaSecretario(tSecretario** vetor, tSecretario *secretario, int tam) {
    


    // Realocar o vetor de pacientes para acomodar o novo tamanho
    tSecretario** novoVetor = (tSecretario**)realloc(vetor, (tam) * sizeof(tSecretario*));

    // Verificar se a realocação foi bem-sucedida
    if (novoVetor == NULL) {
        printf("Erro ao realocar memória para o vetor de secretarios.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    novoVetor[tam-1] = secretario;

    return novoVetor;
}

int EhCadastradoSecretario(tSecretario** vetor, tSecretario *secretario, int tam){
    for(int i=0; i<tam;i++){
        
        if(strcmp(vetor[i]->cpf,secretario->cpf)==0){
            return 1;
        }
    }
    return 0;
}

Login loginSecretario(tSecretario** vetor, char *senha, char usuario, int tam, Nivel *acesso){
    int senhaCorreta =0;
    int usuarioCorreto =0;
    int mesmaConta=0;
    int i,j;
    for(i=0; i< tam; i++){
        if(strcmp(vetor[i]->senha,senha)){
            senhaCorreta =1;
            break;
        }
    }
    if(!senhaCorreta){
        return SENHA_IN;
    }

    for(j=0; j< tam; j++){
        if(strcmp(vetor[j]->nomeUsuario,usuario)){
            usuarioCorreto =1;
            break;
        }
    }

    if(!usuarioCorreto){
        return USUARIO_IN;
    }

    if(i==j){
        *acesso = ObtemNivelAcessoSecretario(vetor[i]);
        return CORRETO;
    }else {
        
        if(!strcmp(vetor[i]->senha,senha))
            return SENHA_IN;
        if(!strcmp(vetor[j]->nomeUsuario,usuario))
            return USUARIO_IN;
    }

}

Nivel ObtemNivelAcessoSecretario(tSecretario * secretario){
    if(strcmp(secretario->nivelAcesso, "ADMIN")==0)
        return ADMIN;
    if(strcmp(secretario->nivelAcesso, "USER")==0)
        return USER;
    
    return MEDI;
}