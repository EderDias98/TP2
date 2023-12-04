
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
    int numConsultas;
    tLesoes** vetorLesoes;
    char** datas;
    int numDatas;
    int numLesoes;
    
};

void adcionaData(tPaciente*paciente, char *data){
    paciente->numDatas++;
    paciente->datas = realloc(paciente->datas,sizeof(char*)*paciente->numDatas);
    paciente->datas[paciente->numDatas-1] = data;
}
char* obtemDataPaciente(tPaciente* paciente, int index){
    return paciente->datas[index];
}
int obtemNumLesoes(tPaciente* paciente){
    return paciente->numLesoes;
}
int obtemTamTPaciente(){
    return sizeof(tPaciente);
}
tLesoes **ObtemVetorLesoesPaciente(tPaciente *paciente){
    return paciente->vetorLesoes;
}
void DefiniLesoesPaciente(tPaciente *paciente, tLesoes *lesoes){
    paciente->numLesoes++;
    paciente->vetorLesoes = adcionaLesoes(paciente->vetorLesoes,lesoes,paciente->numLesoes);
}
// Função para inicializar um paciente
tPaciente* criaPaciente() {
    tPaciente* paciente = (tPaciente*) calloc(1,sizeof(tPaciente));
    if (paciente == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(EXIT_FAILURE);
    }
    paciente->vetorLesoes =(tLesoes**) calloc(1,sizeof(tLesoes*));
    paciente->datas = (char**) calloc(1,sizeof(char*));
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
    converterParaMaiuscula(paciente->nomeCompleto);

    printf("CPF: \n");
    scanf("%14[^\n]%*c", paciente->cpf);
    converterParaMaiuscula(paciente->cpf);

    printf("DATA DE NASCIMENTO:\n");
    scanf("%10[^\n]%*c", paciente->dataNascimento);
    converterParaMaiuscula(paciente->dataNascimento);

    printf(" TELEFONE:\n");
    scanf("%14[^\n]%*c", paciente->telefone);
    converterParaMaiuscula(paciente->telefone);

    printf("GENERO:\n");
    scanf("%9[^\n]%*c", paciente->genero);
    converterParaMaiuscula(paciente->genero);
}

// na clinica o tamanho começa com zero

tPaciente** adcionaPaciente(tPaciente** vetor, tPaciente *paciente, int tam) {
    

    // Realocar o vetor de pacientes para acomodar o novo tamanho
     vetor = (tPaciente**)realloc(vetor, (tam) * sizeof(tPaciente*));

    // Verificar se a realocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    vetor[tam-1] = paciente;
    return vetor;
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



int comparar_nomes( const void *a, const void *b) {
    tPaciente *paciente_a = (tPaciente *)a;
    tPaciente *paciente_b = (tPaciente *)b;
    return strcmp(paciente_b->nomeCompleto, (paciente_a->nomeCompleto));
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

void DeslocaPaciente(tPaciente* paciente){
    if(paciente){
        for(int i=0; i< paciente->numLesoes;i++){
        }
        free(paciente->vetorLesoes);
        free(paciente->datas);
        free(paciente);
    }

}

tPaciente* copiaPaciente(tPaciente* paciente){
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
     
    // CopiaLesoes
    paciente->vetorLesoes = copiaVetorLesoes(paciente->vetorLesoes, paciente->numLesoes);
    return copia;

}
int ObtemNumLesoesPaciente(tPaciente* paciente){

    return paciente->numLesoes;
}

void incrementaNumLesoesPaciente(tPaciente* paciente){
    paciente->numLesoes++;
}

int JaTemPacientesLista(tPaciente** lista, tPaciente*paciente,int tam){
    
    for(int i=0; i<tam;i++){
        if(paciente == lista[i])
            return 1;
    }
    return 0;
}

tPaciente** BuscaPacientes(tPaciente** vetorPacientes,int tamPacientes,char *nome,char *data,char *diagnostico,
int* tamLista){

    
    tPaciente** lista = (tPaciente**) calloc(1, sizeof(tPaciente*));


    tLesoes ** vetorLesoes = NULL;
 
    if(lista == NULL){
        printf("Erro ao alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    int peloMenosUmPaciente =0;

//nome
    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual =vetorPacientes[i];
            if(strcmp(nome,ObtemNomePaciente(pacienteAtual))==0 &&
            !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
        }
    }
//data
    if(nome[0]=='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual = vetorPacientes[i];
            for(int j=0; j<pacienteAtual->numDatas;j++){
                if(strcmp(data,obtemDataPaciente(pacienteAtual,j)) ==0 &&
                !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                }
            }

        }
    }
//lesao
    if(nome[0]=='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            
            tPaciente* pacienteAtual = vetorPacientes[i];
            vetorLesoes = pacienteAtual->vetorLesoes;
            for(int j=0; j<obtemNumLesoes(pacienteAtual);j++){
                
                tLesao* lesoesAtual = obtemLesoes(vetorLesoes,j);
                
                for(int k=0; k<ObtemTamLesoes(lesoesAtual);k++){
                    
                    tLesao* lesaoAtual = obtemLesao(lesoesAtual,k);
                    
                    if(strcmp(diagnostico, ObtemDiagnostico(lesaoAtual))==0
                    && !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    
                        peloMenosUmPaciente =1;
                        (*tamLista)++;
                        adcionaPaciente(lista, pacienteAtual,*tamLista);

                    }
                }
            }
        }
    }

    
// nome e data
    if(nome[0]!='\0'  && data[0] != '\0' && diagnostico[0] == '0'){
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual = vetorPacientes[i];
            for(int k=0; k<pacienteAtual->numDatas;k++){
                if(ObtemNomePaciente(pacienteAtual) ==0 &&
                obtemDataPaciente(vetorPacientes[i],k) ==0 &&
                !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                    peloMenosUmPaciente =1;
                    (*tamLista)++;
                    adcionaPaciente(lista, pacienteAtual,*tamLista);
                }
            }

        }
    }
//nome e diagnostico
    if(nome[0]!='\0'  && data[0] == '\0' && diagnostico[0] != '0'){
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual = vetorPacientes[i];
            vetorLesoes = pacienteAtual->vetorLesoes;
            for(int j=0; j<obtemNumLesoes(pacienteAtual);j++){
                tLesao* lesoesAtual = obtemLesoes(vetorLesoes,j);
                for(int k=0; k<ObtemTamLesoes(lesoesAtual),k++){
                    tLesao* lesaoAtual = obtemLesao(lesoesAtual,k);
                    if(strcmp(diagnostico, ObtemDiagnostico(lesaoAtual))==0
                    && strcmp(ObtemNomePaciente(pacienteAtual),nome)==0 &&
                    !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                        peloMenosUmPaciente =1;
                        (*tamLista)++;
                        adcionaPaciente(lista, pacienteAtual,*tamLista);
                    }
                }
            }
        }
    }

    //data e diagnostico

    if(nome[0] =='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        int data=0,diagnostico =0;
        //se paciente tem  a data
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual = vetorPacientes[i];
            vetorLesoes = pacienteAtual->vetorLesoes;
            
            for(int j=0; j<pacienteAtual->numDatas;j++){
                if(strcmp(data,obtemDataPaciente(pacienteAtual,j)) ==0 ){
                   data=1;
                }
            }
        //se paciente tem lesao
            for(int j=0; j<obtemNumLesoes(pacienteAtual);j++){
                tLesao* lesoesAtual = obtemLesoes(vetorLesoes,j);
                for(int k=0; k<ObtemTamLesoes(lesoesAtual);k++){
                    tLesao* lesaoAtual = obtemLesao(lesoesAtual,k);
                    if(strcmp(diagnostico, ObtemDiagnostico(lesaoAtual))==0){
                        diagnostico =1;
                    }
                }
            }
            if(data && diagnostico &&  !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
            nome = 0;
            diagnostico =0;
        }
        
    }

 // data nome e lesao
    if(nome[0] !='\0'  && data[0] != '\0' && diagnostico[0] != '0'){
        int data=0,diagnostico =0,nome ;
        //se paciente tem  a data
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual = vetorPacientes[i];
            vetorLesoes = pacienteAtual->vetorLesoes;
            
            for(int j=0; j<pacienteAtual->numDatas;j++){
                if(strcmp(data,obtemDataPaciente(pacienteAtual,j)) ==0 ){
                   data=1;
                }
            }
        //se paciente tem nome
        for(int i=0; i < tamPacientes;i++){
            tPaciente* pacienteAtual =vetorPacientes[i];
            if(strcmp(nome,ObtemNomePaciente(pacienteAtual))==0){
                nome =1;
            }
        }
        //se paciente tem lesao
            for(int j=0; j<obtemNumLesoes(pacienteAtual);j++){
                tLesao* lesoesAtual = obtemLesoes(vetorLesoes,j);
                for(int k=0; k<ObtemTamLesoes(lesoesAtual);k++){
                    tLesao* lesaoAtual = obtemLesao(lesoesAtual,k);
                    if(strcmp(diagnostico, ObtemDiagnostico(lesaoAtual))==0){
                        diagnostico =1;
                    }
                }
            }
            if(data && diagnostico && nome && !JaTemPacientesLista(lista,pacienteAtual,*tamLista)){
                peloMenosUmPaciente =1;
                (*tamLista)++;
                adcionaPaciente(lista, pacienteAtual,*tamLista);
            }
            data =0;
            nome=0;
            diagnostico =0;
        }
    }

    if(!peloMenosUmPaciente){
        free(lista);
        lista =NULL;
    }

    return lista;
}