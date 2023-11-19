#include "tLesao.h"

struct lesao {
    char rotulo[5]; //Rótulo (string com no máximo 5 caracteres seguindo o padrão L1, L2, L3, …, Ln)

//Diagnóstico clínico
// Valores
// CARCINOMA
// BASOCELULAR,
// CARCINOMA
// possíveis:
// ESPINOCELULAR, MELANOMA, CERATOSE
// ACTINICA, NEVO,
// CERATOSE SEBORREICA e OUTROS

    char diagnosticoClinico[20]; 
// Região do corpo
// Valores possíveis: FACE, ORELHA, COURO CABELUDO, PEITORAL,
// DORSO, ABDOME, BRAÇO, ANTEBRAÇO, MÃO, COXA, CANELA, PE e
// OUTROS
    char regiaoCorpo[11]; 
    char tamanho[10];//Tamanho (inteiro representando o tamanho em milímetros)
    int enviarCirurgia; //Se a lesão deve ser enviada para cirurgia (inteiro assumindo 1 ou 0)
    int enviarCrioterapia; //Se a lesão deve ser enviada para crioterapia (inteiro assumindo 1 ou 0)
};

struct lesoes{
    tLesao** vetor;
    int indexPaciente;
    int tam;
};



tLesao* criaLesao() {
    tLesao* lesao = (tLesao*) calloc(1,sizeof(tLesao));
    if (lesao == NULL) {
        printf("Erro ao alocar memória para o lesao.\n");
        exit(EXIT_FAILURE);
    }
    return lesao;
}


// Função para liberar a memória alocada para um lesao
void liberaLesao(tLesao* lesao) {
    if(lesao!=NULL){
        free(lesao);
    }

}

//Funçao que Le o lesao

void leLesao(tLesao* lesao){
    printf("DIAGNOSTICO CLINICO:\n");
    scanf("%19[^\n]%*c", lesao->diagnosticoClinico);

    printf("REGIAO DO CORPO:\n");
    scanf("%10[^\n]%*c", lesao->regiaoCorpo);

    printf("TAMANHO:\n");
    scanf("%9[^\n]%*c", lesao->tamanho);

    printf("ENVIAR PARA CIRURGIA:\n");
    scanf("%d%*c", &lesao->enviarCirurgia);

    printf("ENVIAR PARA CRIOTERAPIA:\n");
    scanf("%d%*c", &lesao->enviarCrioterapia);
}

// na clinica o tamanho começa com zero

tLesao** adcionaLesao(tLesao** vetor, tLesao *lesao, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    tLesao** vetor = (tLesao**)realloc(vetor, (tam) * sizeof(tLesao*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = lesao;

    return vetor;
}

void adcionaLesoes(tLesoes ** vetor, tLesoes *lesoes, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    tLesoes ** vetor = (tLesoes**)realloc(vetor, (tam) * sizeof(tLesoes*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = lesoes;

    return vetor;
}
tLesoes* CriaLesoes(){
    tLesoes* lesoes = (tLesoes*) calloc(1,sizeof(tLesoes));
    if (lesoes == NULL) {
        printf("Erro ao alocar memória para o lesoes.\n");
        exit(EXIT_FAILURE);
    }
    lesoes->vetor = (tLesao**) calloc(1,sizeof(tLesao*));
    
    if (lesoes->vetor == NULL) {
        printf("Erro ao alocar memória para o lesoes->vetor .\n");
        exit(EXIT_FAILURE);
    }
    return lesoes;
}
void CadastraLesaoClinica(tLesao** vetor, tLesao*lesao,int tam){

    static int i = 1;
    sprintf(lesao->rotulo, "L%d", i);
    i++;
    adcionaLesao(vetor,lesao,tam);
};

void IncrementaTamLesoes(tLesoes* lesoes){
    lesoes->tam++;
}

tLesao ** ObtemVetorLesoes(tLesoes* lesoes){
    lesoes->vetor;
}

int ObtemTamLesoes(tLesoes* lesoes){
    return lesoes->tam;
}