#include "tClinica.h"


struct clinica {
 
    tSecretario** secretarios;
    int numSecretarios;
    tMedico** medicos;
    int numMedicos;
    tPaciente** pacientes;
    int numPacientes;
    tLesoes** vetorLesoes;
    int tamVetorLesoes;
    tConsulta** consultas;
    int numConsultas;
    
    // Outros campos conforme necessário
};

tSecretario** obtemVetorSecretarios(tClinica* clinica){
    return clinica->secretarios;
}
tMedico** obtemVetorMedicos(tClinica* clinica){
    return clinica->medicos;
}
tConsulta** obtemVetorConsultas(tClinica* clinica){
    return clinica->consultas;
}

// Le os documentos binarios
void EscreveBinsecretarios(tClinica* clinica,char *path){
    
    FILE* arquivo = fopen(path, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binario para escrita\n");
        exit(-1);
    }

    // Escrever o número de secretários no início do arquivo
    fwrite(&(clinica->numSecretarios), sizeof(int), 1, arquivo);

    // Loop para escrever cada secretário no arquivo
    for (int i = 0; i < clinica->numSecretarios; i++) {
        // Escrever os dados do secretário no arquivo
        fwrite(clinica->secretarios[i], obtemTamTSecretario(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void LeBinSecretarios(tClinica* clinica,char *path){
    tSecretario** vetor = clinica->secretarios;
    int tam=0;
    FILE *arquivo = fopen(path,"rb");
    if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo binario\n");
        exit(-1);
    }
    fread(&tam,sizeof(int),1,arquivo);
    
     vetor =(tSecretario**)realloc(vetor,sizeof(tSecretario*)*tam);
    
    if (clinica->secretarios == NULL) {
        printf("Erro ao realocar memória para secretários\n");
        exit(-1);
    }

    clinica->numSecretarios = tam;

    // Loop para ler cada secretário do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o secretário atual
        clinica->secretarios[i] = (tSecretario*) malloc(sizeof(obtemTamTSecretario()));

        // Ler os dados do secretário do arquivo
        fread(clinica->secretarios[i], obtemTamTSecretario(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void EscreveBinMedicos(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário para escrita\n");
        exit(-1);
    }

    // Escrever o número de médicos no início do arquivo
    fwrite(&(clinica->numMedicos), sizeof(int), 1, arquivo);

    // Loop para escrever cada médico no arquivo
    for (int i = 0; i < clinica->numMedicos; i++) {
        // Escrever os dados do médico no arquivo
        fwrite(clinica->medicos[i], obtemTamTMedico(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void LeBinMedicos(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário\n");
        exit(-1);
    }

    int tam;
    fread(&tam, sizeof(int), 1, arquivo);

    // Realocar o vetor de médicos na clínica
    clinica->medicos = realloc(clinica->medicos, sizeof(tMedico*) * tam);

    if (clinica->medicos == NULL) {
        printf("Erro ao realocar memória para médicos\n");
        exit(-1);
    }

    clinica->numMedicos = tam;

    // Loop para ler cada médico do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o médico atual
        clinica->medicos[i] = (tMedico*)malloc(obtemTamTMedico());

        // Ler os dados do médico do arquivo
        fread(clinica->medicos[i], obtemTamTMedico(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void EscreveBinConsultas(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário para escrita\n");
        exit(-1);
    }

    // Escrever o número de consultas no início do arquivo
    fwrite(&(clinica->numConsultas), sizeof(int), 1, arquivo);

    // Loop para escrever cada consulta no arquivo
    for (int i = 0; i < clinica->numConsultas; i++) {
        // Escrever os dados da consulta no arquivo
        fwrite(clinica->consultas[i], obtemTamTConsulta(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void LeBinConsultas(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário\n");
        exit(-1);
    }

    int tam;
    fread(&tam, sizeof(int), 1, arquivo);

    // Realocar o vetor de consultas na clínica
    clinica->consultas = realloc(clinica->consultas, sizeof(tConsulta*) * tam);

    if (clinica->consultas == NULL) {
        printf("Erro ao realocar memória para consultas\n");
        exit(-1);
    }

    clinica->numConsultas = tam;

    // Loop para ler cada consulta do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para a consulta atual
        clinica->consultas[i] = (tConsulta*)malloc(obtemTamTConsulta());

        // Ler os dados da consulta do arquivo
        fread(clinica->consultas[i], obtemTamTConsulta(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void EscreveBinPacientes(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário para escrita\n");
        exit(-1);
    }

    // Escrever o número de pacientes no início do arquivo
    fwrite(&(clinica->numPacientes), sizeof(int), 1, arquivo);

    // Loop para escrever cada paciente no arquivo
    for (int i = 0; i < clinica->numPacientes; i++) {
        // Escrever os dados do paciente no arquivo
        fwrite(clinica->pacientes[i], obtemTamTPaciente(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void LeBinPacientes(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário\n");
        exit(-1);
    }

    int tam;
    fread(&tam, sizeof(int), 1, arquivo);

    // Realocar o vetor de pacientes na clínica
    clinica->pacientes = realloc(clinica->pacientes, sizeof(tPaciente*) * tam);

    if (clinica->pacientes == NULL) {
        printf("Erro ao realocar memória para pacientes\n");
        exit(-1);
    }

    clinica->numPacientes = tam;

    // Loop para ler cada paciente do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o paciente atual
        clinica->pacientes[i] = (tPaciente*)malloc(obtemTamTPaciente());

        // Ler os dados do paciente do arquivo
        fread(clinica->pacientes[i], obtemTamTPaciente(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void EscreveBinLesaoVetor(tLesao** vetor, FILE* arquivo, int tam) {
    // Escrever o número de lesões no arquivo
    fwrite(&tam, sizeof(int), 1, arquivo);

    // Loop para escrever cada lesão no arquivo
    for (int i = 0; i < tam; i++) {
        // Escrever os dados da lesão no arquivo
        fwrite(vetor[i], obtemTamTLesao(), 1, arquivo);
    }
}

void LeBinLesaoVetor(tLesao** vetor,FILE * arquivo, int tam) {



    // Realocar o vetor de lesões na estrutura tLesoes
    vetor =(tLesao**) malloc(sizeof(tLesao*) * tam);

    if (vetor == NULL) {
        printf("Erro ao realocar memória para lesões\n");
        exit(-1);
    }


    // Loop para ler cada lesão do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para a lesão atual
        vetor[i] = (tLesao*)malloc(obtemTamTLesao());

        // Ler os dados da lesão do arquivo
        fread(vetor[i], obtemTamTLesao(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}


void EscreveBinLesoes(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário para escrita\n");
        exit(-1);
    }

    // Escrever o número de conjuntos de lesões no início do arquivo
    fwrite(&(clinica->tamVetorLesoes), sizeof(int), 1, arquivo);

    // Loop para escrever cada conjunto de lesões no arquivo
    for (int i = 0; i < clinica->tamVetorLesoes; i++) {
        // Escrever o tamanho do vetor de lesões
        int tam = ObtemTamLesoes(clinica->vetorLesoes[i]);
        fwrite(&tam, sizeof(int), 1, arquivo);

        // Escrever o índice do paciente
        int indexPaciente = ObtemIndexPacienteLesoes(clinica->vetorLesoes[i]);
        fwrite(&indexPaciente, sizeof(int), 1, arquivo);

        // Escrever as lesões do vetor
        EscreveBinLesaoVetor(ObtemVetorLesoes(clinica->vetorLesoes[i]), arquivo, tam);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void LeBinLesoes(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binário\n");
        exit(-1);
    }

    int tam;
    fread(&tam, sizeof(int), 1, arquivo);

    // Realocar o vetor de lesões na clínica
    clinica->vetorLesoes = realloc(clinica->vetorLesoes, sizeof(tLesoes*) * tam);

    if (clinica->vetorLesoes == NULL) {
        printf("Erro ao realocar memória para lesões\n");
        exit(-1);
    }
// definir tamanho de vetorlesoes
    clinica->tamVetorLesoes = tam;

    // Loop para ler cada conjunto de lesões do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o conjunto de lesões atual
        clinica->vetorLesoes[i] = (tLesoes*)malloc(obtemTamTLesoes());
        int tam=0,indexPaciente=0;
        fread(&tam, sizeof(int), 1, arquivo);
        fread(&indexPaciente, sizeof(int), 1, arquivo);
        DefineLesoesBin(clinica->vetorLesoes[i],indexPaciente,tam);
        // Ler os dados do conjunto de lesões do arquivo
        LeBinLesaoVetor(ObtemVetorLesoes(clinica->vetorLesoes[i]),arquivo,tam);
    }

    // Fechar o arquivo
    fclose(arquivo);
}


// Função para inicializar um clinica
tClinica* criaClinica() {
    tClinica* clinica = (tClinica*) calloc(1,sizeof(tClinica));
    if (clinica == NULL) {
        printf("Erro ao alocar memória para o clinica.\n");
        exit(EXIT_FAILURE);
    }
    return clinica;
}

void InicializaClinicaVetores(tClinica* clinica){
    clinica->medicos = (tMedico**) calloc(1,sizeof(tMedico*));
    if (clinica->medicos == NULL) {
        printf("Erro ao alocar memória para o clinica->medicos.\n");
        exit(EXIT_FAILURE);
    }
    clinica->pacientes = (tPaciente**) calloc(1,sizeof(tPaciente*));
    if (clinica->pacientes == NULL) {
        printf("Erro ao alocar memória para o clinica->pacientes.\n");
        exit(EXIT_FAILURE);
    }
    clinica->secretarios = (tSecretario**) calloc(1, sizeof(tSecretario*));
    if (clinica->secretarios == NULL) {
        printf("Erro ao alocar memória para o clinica->secretarios.\n");
        exit(EXIT_FAILURE);
    }
    clinica->vetorLesoes = (tLesoes**) calloc(1, sizeof(tLesoes*));
    if (clinica->vetorLesoes == NULL) {
        printf("Erro ao alocar memória para o clinica->vetorLesoes.\n");
        exit(EXIT_FAILURE);
    }
    clinica->consultas = (tConsulta**) calloc(1, sizeof(tConsulta*));
    if (clinica->consultas == NULL) {
        printf("Erro ao alocar memória para o clinica->consultas.\n");
        exit(EXIT_FAILURE);
    }
}



// Função para destruir uma instância da clínica
void liberaClinica(tClinica* clinica) {
    if (clinica != NULL) {


        // Liberar memória relacionada aos secretários
        for (int i = 0; i < clinica->numSecretarios; i++) {
           liberaSecretario(clinica->secretarios[i]);
        }
        free(clinica->secretarios);

        // Liberar memória relacionada aos médicos
        for (int i = 0; i < clinica->numMedicos; i++) {
            liberaMedico(clinica->medicos[i]);
        }
        free(clinica->medicos);

        // Liberar memória relacionada aos pacientes
        for (int i = 0; i < clinica->numPacientes; i++) {
            liberaPaciente(clinica->pacientes[i]);
        }
        free(clinica->pacientes);
        //Libera memoria relascionda a Consultas

        //Libera memoria relacionada a lesoes

        // Liberar a estrutura principal
        free(clinica);
    }
}

//Cadastrar Paciente 
// retorna se cadastro foi bem sucedido
int CadastraPacienteClinica(tClinica *clinica){
    tPaciente* paciente = criaPaciente();
    lePaciente(paciente);
    if(EhCadastradoPaciente(clinica->pacientes,ObtemCpfPaciente(paciente),clinica->numPacientes) != -1){
        //Incrementa numero de pacientes
        clinica->numPacientes++;
        adcionaPaciente(clinica->pacientes,paciente,clinica->numPacientes);
        return 1;
    }
    return 0;
}

int CadastraSecretarioClinica(tClinica* clinica){

    tSecretario* secretario = CriaSecretario();
    leSecretario(secretario);
    if(EhCadastradoSecretario(clinica->secretarios,secretario,clinica->numSecretarios != -1)){
        clinica->numSecretarios++;
        adcionaSecretario(clinica->secretarios,secretario,clinica->numSecretarios);
        return 1;
    }
    return 0;
}

int CadastraMedicoClinica(tClinica* clinica){
    tMedico* medico = criaMedico();
    leMedico(medico);
    if(EhCadastradoMedico(clinica->medicos, medico, clinica->numMedicos) != -1){
        clinica->numMedicos++;
        adcionaMedico(clinica->medicos, medico, clinica->numMedicos);
        return 1;
    }
    return 0;
}


Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso, int *indexMedico, int *indexSecretario){
    //porcurar login ou senha em medicos seja e retornar login
    Login medico;
    medico  = loginMedico(clinica->medicos,senha,usuario, clinica->numMedicos,indexMedico);

    Login secretario = loginSecretario(clinica->secretarios, senha , usuario, clinica->numSecretarios, indexSecretario);
    if(medico == CORRETO){
        *acesso = MEDI;
        return CORRETO;
    }else if(secretario == CORRETO){
        *acesso = ObtemNivelAcessoSecretario(obtemSecretario(clinica->secretarios,*indexSecretario));
        return CORRETO;
    }

    return INCORRETO;
}

int EhCadastradoCLinica(tClinica* clinica, char *cpf){
    return EhCadastradoPaciente(clinica->pacientes,cpf,clinica->numPacientes);
}
//Cadastrar Medico

//Cadastrar Secretario
int previaDaConsulta(tClinica* clinica, int idx){
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: %s\n", ObtemCpfPaciente(clinica->pacientes[idx]));
    printf("---\n");
    printf("- NOME: %s\n", ObtemNomePaciente(clinica->pacientes[idx]));
    printf("- DATA DE NASCIMENTO: %s\n", ObtemDataPaciente(clinica->pacientes[idx]));
    printf("---");
    printf("DATA DA CONSULTA: ");
    char dataConsulta[11]= {'\0'};
    scanf("%10[^\n]%*c",dataConsulta);
    printf("%s\n", dataConsulta);
    return CompletaDadosPaciente(clinica->pacientes[idx]);
}

void ImprimiSubMenu(){
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("(1) CADASTRAR LESAO\n");
    printf("(2) GERAR RECEITA MEDICA\n");
    printf("(3) SOLICITACAO DE BIOPSIA\n");
    printf("(4) ENCAMINHAMENTO\n");
    printf("(5) ENCERRAR CONSULTA\n");
    printf("############################################################");

}

// acrescentar taVetorLesoes antes

void ConsultaMedica(tClinica* clinica, int indexPaciente, int indexMedico){
    tPaciente* paciente =NULL;
    paciente = clinica->pacientes[indexPaciente];
    tMedico* medico = NULL;
    medico =clinica->medicos[indexMedico];

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: %s\n", ObtemCpfPaciente(paciente));
    printf("---\n");
    printf("- NOME: %s\n", ObtemNomePaciente(paciente));
    printf("- DATA DE NASCIMENTO: %s\n", ObtemDataPaciente(paciente));
    printf("---");
    printf("DATA DA CONSULTA: ");
    char dataConsulta[11]= {'\0'};
    scanf("%10[^\n]%*c",dataConsulta);    
    printf("%s\n", dataConsulta);
    //cada paciente tera uma consulta e sua data ta na sua struct
   
    // Os documentos e lesoes serao adcionados de acordo 
    tConsulta* consulta= criaConsulta(paciente,medico,dataConsulta,ObtemNomeMedico(medico), ObtemNomePaciente(paciente));
    tLesoes* lesoes =NULL;
    while (1)
    {
        ImprimiSubMenu();
        int opcao;
        int sair = 0,cont=1;
        scanf("%d%*c", &opcao);
        switch (opcao)
        {
        case 1:
            if(cont==1){
                
                lesoes= CriaLesoes();
                //compartilham o ponteiro para struct lesoes
                tLesoes** lesoesPaciente = ObtemVetorLesoesPaciente(paciente);
                incrementaNumLesoesPaciente(paciente);
                int tamLesoesPaciente = ObtemNumLesoesPaciente(paciente);
                adcionaLesoes(lesoesPaciente,lesoes,tamLesoesPaciente);

            
                DefiniLesoesConsulta(consulta,lesoes);
   
                //sempre lembra de incrementar o tamanho antes da funçao adicionar
                clinica->tamVetorLesoes++;
                adcionaLesoes(clinica->vetorLesoes,lesoes, clinica->tamVetorLesoes);
            }
            
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("CADASTRO DE LESAO:\n");

            
            tLesao * lesaoAtual = criaLesao();
            leLesao(lesaoAtual);

            IncrementaTamLesoes(lesoes);
            CadastraLesao(ObtemVetorLesoes(lesoes),lesaoAtual,ObtemTamLesoes(lesoes));

            printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
            printf("RETORNAR AO MENU ANTERIOR");
            printf("############################################################");
            scanf("%*c");
            cont++;
            break;
        case 2:
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("RECEITA MEDICA:\n");
            printf("TIPO DE USO: ");
            char uso[8]={'\0'};
            scanf("%7[^\n]%*c",uso);
            eTipoUso tUso;
            if(strcmp(uso,"ORAL")){
                tUso = ORAL;
            }else if(strcmp(uso,"TOPICO")){
                tUso = TOPICO;
            }
            printf("\nNOME DO MEDICAMENTO: ");
            char nomeMedicamento[50]= {'\0'};
            scanf("%49[^\n]%*c", nomeMedicamento);
            printf("\nQUANTIDADE: ");
            int quantidade;
            scanf("%d%*c", &quantidade);
            printf("\nTIPO DE MEDICAMENTO: ");
            char instrucoes[300];
            printf("\nINSTRUÇÕES DE USO: ");
            scanf("%299[^\n]%*c", instrucoes);
            char tipoMedicamento[50]= {'\0'};
            scanf("%49[^\n]%*c", tipoMedicamento);


            

            //criar receita;
            tReceita *receita = criaReceita(ObtemNomePaciente(paciente),
            tUso,nomeMedicamento,tipoMedicamento,instrucoes,quantidade,ObtemNomeMedico(medico) ,
            ObtemCrm(medico) ,dataConsulta);

            DefiniReceitaConsulta(consulta,receita);
            printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
            printf("RETORNAR AO MENU ANTERIOR");
            printf("############################################################");
            scanf("%*c");
            break;
        case 3:

            if(NaoTemLesaoCirurgia(lesoes)){
                printf("#################### CONSULTA MEDICA #######################\n");
                printf("NAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE\n");
                printf("QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                scanf("%*c");
                continue;;
            }

            tBiopsia* biobsia = criaBiopsia(ObtemNomePaciente(paciente),ObtemCpfPaciente(paciente),
            lesoes,ObtemNomeMedico(medico),ObtemCrm(medico),dataConsulta);

            DefiniBiopsiaConsulta(consulta, biobsia);

            printf("#################### CONSULTA MEDICA #######################\n");
            printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE\n");
            printf("QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
            scanf("%*c");
            break;
        case 4:
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("ENCAMINHAMENTO:\n");
            printf("ESPECIALIDADE ENCAMINHADA: ");
            char especialidade[51]= {'\0'};
            scanf("%s50[^\n]%*c",especialidade);
            printf("\nMOTIVO: ");
            char motivo[301];
            scanf("%s300[^\n]%*c",motivo);

            tEncaminhamento* encaminhamento = criaEncaminhamento(ObtemNomePaciente(paciente),ObtemCpfPaciente(paciente)
            ,ObtemNomeMedico(medico),ObtemCrm(medico),dataConsulta,especialidade,motivo);
            DefiniEncaminhamentoConsulta(consulta,encaminhamento);

            printf("\nENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER\n");  
            printf("QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
            scanf("%*c");

            break;
        case 5:
            sair=1;
            break;
        
        default:
            break;
        }

        

        if(sair==1){
            break;
        }
    }
    clinica->numConsultas++;
    adcionaConsulta(clinica->consultas,consulta,clinica->numConsultas);
}

tPaciente** ObtemPacientes(tClinica* clinica){
    return clinica->pacientes;
}
int ObtemTamPacientes(tClinica* clinica){
    return clinica->numPacientes;
}

int ObtemTamVetorLesoes(tClinica* clinica){
    return clinica->tamVetorLesoes;
}

tLesoes** ObtemVetor(tClinica* clinica){
    return clinica->vetorLesoes;
}


int obtemNumConsultas(tClinica* clinica){
    return clinica->numConsultas;
}