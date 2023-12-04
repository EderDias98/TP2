#include "tMedico.h"

struct medico{
    char nomeCompleto[101]; // Nome completo (string com no máximo 100 caracteres)
    char cpf[15];           // CPF (no formato: 000.000.000-00)
    char dataNascimento[11];// Data de nascimento (seguindo padrão dd/mm/aaaa)
    char telefone[15];      // Telefone (formato: (00)00000-0000)
    char genero[10];
    char crm [13];
    char nomeUsuario[21];
    char senha[21];        // Gênero (masculino, feminino, outros)
};


int obtemTamTMedico(){
    return sizeof(tMedico);
}
// Função para inicializar um medico
tMedico* criaMedico() {
    tMedico* medico = (tMedico*) calloc(1,sizeof(tMedico));
    if (medico == NULL) {
        printf("Erro ao alocar memória para o medico.\n");
        exit(EXIT_FAILURE);
    }
    return medico;
}

// Função para liberar a memória alocada para um medico
void liberaMedico(tMedico* medico) {
    if(medico!=NULL){
        free(medico);
    }
}

//Funçao que Le o medico

void leMedico(tMedico* medico){
    printf("NOME COMPLETO:\n");
    scanf("%100[^\n]%*c", medico->nomeCompleto);
    converterParaMaiuscula(medico->nomeCompleto);

    printf("CPF: \n");
    scanf("%14[^\n]%*c", medico->cpf);
    converterParaMaiuscula(medico->cpf);

    printf("DATA DE NASCIMENTO:\n");
    scanf("%10[^\n]%*c", medico->dataNascimento);
    converterParaMaiuscula(medico->dataNascimento);

    printf(" TELEFONE:\n");
    scanf("%14[^\n]%*c", medico->telefone);
    converterParaMaiuscula(medico->telefone);

    printf("GENERO:\n");
    scanf("%9[^\n]%*c", medico->genero);
    converterParaMaiuscula(medico->genero);

    printf("CRM:\n");
    scanf("%12[^\n]%*c", medico->crm);
    converterParaMaiuscula(medico->crm);

    printf("NOME DE USUARIO:\n");
    scanf("%20[^\n]%*c", medico->nomeUsuario);
    converterParaMaiuscula(medico->nomeUsuario);

    printf("SENHA:\n");
    scanf("%20[^\n]%*c", medico->senha);
    converterParaMaiuscula(medico->senha);
}

// na clinica o tamanho começa com zero

tMedico** adcionaMedico(tMedico** vetor, tMedico *medico, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    vetor = (tMedico**)realloc(vetor, (tam) * sizeof(tMedico*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de medicos.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = medico;
    return vetor;
}


int EhCadastradoMedico(tMedico** vetor, tMedico *medico, int tam){
    for(int i=0; i<tam;i++){

        if(strcmp(vetor[i]->cpf,medico->cpf)==0){
            return i;
        }
    }
    return -1;
}

Login loginMedico(tMedico** vetor, char *senha, char * usuario, int tam,int *indexMedico){
    int senhaCorreta =0;
    int usuarioCorreto =0;
    int mesmaConta=0;
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
        *indexMedico = i;
        return CORRETO;
    }
    return INCORRETO;
        

}

char * ObtemNomeMedico(tMedico* medico){
    return medico->nomeCompleto;
}
char *ObtemCrm(tMedico*medico){
    return medico->crm;
}