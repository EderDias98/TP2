
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
    char dataConsulta[11];
    tLesoes * lesoes;
    
};

// Função para inicializar um paciente
tPaciente* criaPaciente() {
    tPaciente* paciente = (tPaciente*) calloc(1,sizeof(tPaciente));
    if (paciente == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(EXIT_FAILURE);
    }
    paciente->lesoes =NULL;
    return paciente;
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

void adcionaPaciente(tPaciente** vetor, tPaciente *paciente, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
     vetor = (tPaciente**)realloc(vetor, (tam) * sizeof(tPaciente*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = paciente;

}

//retorna o indice do paciente;

int EhCadastradoPaciente(tPaciente** vetor, char *cpf, int tam){
    for(int i=0; i<tam;i++){
        
        if(strcmp(vetor[i]->cpf,cpf)==0){
            return i;
        }
    }
    return -1;
}

char * ObtemCpfPaciente(tPaciente* paciente){
    return paciente->cpf;
}
char * ObtemNomePaciente(tPaciente* paciente){
    return paciente->nomeCompleto;
}
 
char * ObtemDataPaciente(tPaciente* paciente){

    return paciente->dataNascimento;
 }

 char* ObtemGeneroPaciente(tPaciente* paciente){
    return paciente->genero;
 }
 char* ObtemTelefonePaciente(tPaciente* paciente){
    return paciente->telefone;
 }

 int ObtemDiabetesPacientes(tPaciente* paciente){
    return paciente->diabetes;
 }
 int ObtemFumantePaciente(tPaciente* paciente){
    return paciente->fumante;
 }
 int ObtemAlergiaPaciente(tPaciente* paciente){
    return paciente->alergiaMedicamento;
 }
 int ObtemHistoricoCancerPaciente(tPaciente* paciente){
    return paciente->historicoCancer;
 }

 char* ObtemTipoPelePaciente(tPaciente* paciente){
    return paciente->tipoPele;
 }

 char* SimOuNao(int afirmacao){
    char *resp = NULL;
    switch (afirmacao)
    {
    case 1 :
        resp = "SIM";
        break;
    case 0:
        resp = "NAO";
        break;
    default:
        break;
    }
    return resp;
 }

int CompletaDadosPaciente(tPaciente* paciente){
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &paciente->diabetes);
    printf("%d\n", paciente->diabetes);
    
    printf("FUMANTE: ");
    scanf("%d%*c", &paciente->fumante);
    printf("%d", paciente->fumante);
    
    printf("ALEGIA A MEDICAMENTO: ");
    scanf("%d%*c", &paciente->alergiaMedicamento);
    printf("%d", paciente->alergiaMedicamento);

    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &paciente->historicoCancer);
    printf("%d", paciente->historicoCancer);

    printf("TIPO DE PELE: ");
    scanf("%4[^\n]%*c", paciente->tipoPele);
    printf("%s", paciente->tipoPele);

    return 1;

}
void DefiniLesoesPaciente(tPaciente* paciente, tLesoes* lesoes){
    paciente->lesoes = lesoes;
}

void DefiniDataConsulta(tPaciente* paciente, char data){
    strcpy(paciente->dataConsulta,data);
}

tPaciente** BuscarPacientes(tPaciente** pacientes,int tamPacientes,char *nome,char *data,char *diagnostico,
int* tamLista){
    tPaciente** lista = (tPaciente**) calloc(1, sizeof(tPaciente*));
    

    tLesoes * lesoes = NULL;

    if(lista == NULL){
        printf("Erro ao alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    int peloMenosUmPaciente =0;
    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            if(strcmp(nome, pacientes[i]->nomeCompleto)==0){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacientes[i],*tamLista);
            }
        }
    }

    if(nome[0]=='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            if(strcmp(data, pacientes[i]->dataConsulta)==0){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacientes[i],*tamLista);
            }
        }
    }

    if(nome[0]=='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            lesoes = pacientes[i]->lesoes;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(ObtemlesaoVetor(lesoes,j)))==0){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacientes[i],*tamLista);
                }
            }
        }
    }

    if(nome[0]!='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            if(strcmp(nome, pacientes[i]->nomeCompleto)==0 &&
            strcmp(data, pacientes[i]->dataConsulta)==0){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacientes[i],*tamLista);
            }
        }
    }

    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            lesoes = pacientes[i]->lesoes;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(ObtemlesaoVetor(lesoes,j)))==0 
                && strcmp(nome, pacientes[i]->nomeCompleto)==0){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacientes[i],*tamLista);
                }
            }
        }
    }

    if(nome[0] =='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            lesoes = pacientes[i]->lesoes;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(ObtemlesaoVetor(lesoes,j)))==0 
                && strcmp(data, pacientes[i]->dataConsulta)==0){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacientes[i],*tamLista);
                }
            }
        }
    }

    if(nome[0] !='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            lesoes = pacientes[i]->lesoes;
            for(int j=0; j< ObtemTamLesoes(lesoes);j++){
                if(strcmp(diagnostico, ObtemDiagnostico(ObtemlesaoVetor(lesoes,j)))==0 
                && strcmp(data, pacientes[i]->dataConsulta)==0
                && strcmp(nome, pacientes[i]->nomeCompleto)==0){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacientes[i],*tamLista);
                }
            }
        }
    }

    if(!peloMenosUmPaciente){
        free(lista);
        lista =NULL;
    }

    return lista;
}
int comparar_nomes( void *a, void *b) {
    return strcmp(((tPaciente *)b)->nomeCompleto, ((tPaciente *)a)->nomeCompleto);
}

tPaciente* ObtemPaciente(tPaciente** pacientes,int index){
    return pacientes[index];
}



int CalculaIdade(char * data){
    


    int anoAtual=2023, mesAtual=11, diaAtual =9;
    int ano=0,mes=0,dia=0;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    int idade = anoAtual - ano;

    // Ajusta a idade se a data de nascimento ainda não ocorreu este ano
    if (( mes <mesAtual) || ( mes == mesAtual && dia < diaAtual)) {
        idade--;
    }


    return idade;

}

tLesoes* ObtemLesoesPaciente(tPaciente* paciente){
    return paciente->lesoes;
}

tPaciente* copiaPaciente(tPaciente* paciente, tLesoes*lesoes){
    tPaciente* copia  = criaPaciente();
    
    if (copia == NULL) {
        perror("Erro ao alocar memória para o paciente copiado");
        exit(EXIT_FAILURE);
    }

    // Copia os campos do paciente original para a cópia
    strcpy(copia->nomeCompleto, paciente->nomeCompleto);
    strcpy(copia->cpf, paciente->cpf);
    strcpy(copia->dataNascimento, paciente->dataNascimento);
    strcpy(copia->telefone, paciente->telefone);
    strcpy(copia->genero, paciente->genero);
    copia->diabetes = paciente->diabetes;
    copia->fumante = paciente->fumante;
    copia->alergiaMedicamento = paciente->alergiaMedicamento;
    copia->historicoCancer = paciente->historicoCancer;
    strcpy(copia->tipoPele, paciente->tipoPele);
    copia->totalLesoes = paciente->totalLesoes;
    copia->enviadaCirurgia = paciente->enviadaCirurgia;
    copia->enviadaCrioterapia = paciente->enviadaCrioterapia;
    strcpy(copia->dataConsulta, paciente->dataConsulta);
    
    copia->lesoes = lesoes;

    return copia;

}