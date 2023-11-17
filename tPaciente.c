
#include "tPaciente.h"

struct paciente{
    char nomeCompleto[101]; // Nome completo (string com no máximo 100 caracteres)
    char cpf[15];           // CPF (no formato: 000.000.000-00)
    char dataNascimento[11];// Data de nascimento (seguindo padrão dd/mm/aaaa)
    char telefone[15];      // Telefone (formato: (00)00000-0000)
    char genero[10];        // Gênero (masculino, feminino, outros)
    int diabetes;  // 1 e SIM e 0 e NAO
    int fumante;   // 1 e SIM e 0 e NAO
    int alergiaMedicamento;  // 1 e SIM e 0 e NAO
    int historicoCancer;     // 1 e SIM e 0 e NAO
    char tipoPele[5];  // I, II, III, IV, V, VI
    int totalLesoes;
    int enviadaCirurgia;
    int enviadaCrioterapia;
    
    tLesao ** lesoes;
    
};

// Função para inicializar um paciente
tPaciente* criaPaciente() {
    tPaciente* paciente = (tPaciente*) calloc(1,sizeof(tPaciente));
    if (paciente == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(EXIT_FAILURE);
    }
    return paciente;
}

void InicializaPacienteLesoes(tPaciente* paciente){

    // Inicializar o array de lesões (isso depende da lógica específica do seu programa)
    paciente->lesoes = (tLesao **) calloc(1,sizeof(tLesao*));
    
    if (paciente->lesoes == NULL) {
        printf("Erro ao alocar memória para o paciente->lesoes.\n");
        exit(EXIT_FAILURE);
    }
}

// Função para liberar a memória alocada para um paciente
void liberaPaciente(tPaciente* paciente) {
    if(paciente!=NULL){
        free(paciente);
    }

}

//Funçao que Le o paciente

void lePaciente(tPaciente* paciente){
    printf("NOME COMPLETO:\n");
    scanf("%100[^\n]%*c", paciente->nomeCompleto);

    printf("CPF: \n");
    scanf("%14[^\n]%*c", paciente->cpf);

    printf("DATA DE NASCIMENTO:\n");
    scanf("%10[^\n]%*c", paciente->dataNascimento);

    printf(" TELEFONE:\n");
    scanf("%14[^\n]%*c", paciente->telefone);

    printf("GENERO:\n");
    scanf("%9[^\n]%*c", paciente->genero);
}

// na clinica o tamanho começa com zero

tPaciente** adcionaPaciente(tPaciente** vetor, tPaciente *paciente, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    tPaciente** novoVetor = (tPaciente**)realloc(vetor, (tam) * sizeof(tPaciente*));

    // Verificar se a realocação foi bem-sucedida
    if (novoVetor == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    novoVetor[tam-1] = paciente;

    return novoVetor;
}
