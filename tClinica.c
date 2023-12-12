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
tPaciente** obtemVetorPacientes(tClinica* clinica){
    return clinica->pacientes;
}

int obtemNumPacientes(tClinica* clinica){
    return clinica->numPacientes;
}

int obtemNumSecretarios(tClinica* clinica){
    return clinica->numSecretarios;
}
int obtemNUmMedicos(tClinica* clinica){
    return clinica->numMedicos;
}

int obtemTamVetorConsultas(tClinica* clinica){
    return clinica->numConsultas;
}

// Le os documentos binarios
void EscreveBinsecretarios(tClinica* clinica,char *path){
    
    FILE* arquivo = fopen(path, "wb");
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

    int tam=0;
    FILE *arquivo = fopen(path,"rb");
    if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo binario\n");
        exit(-1);
    }
    fread(&tam,sizeof(int),1,arquivo);
    
    if(tam!= 0)
        clinica->secretarios =(tSecretario**)realloc((clinica->secretarios),sizeof(tSecretario*)*tam);
    
    if (clinica->secretarios == NULL) {
        printf("Erro ao realocar memória para secretários\n");
        exit(-1);
    }

    clinica->numSecretarios = tam;

    // Loop para ler cada secretário do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o secretário atual
        int tamT = obtemTamTSecretario();
        clinica->secretarios[i] = (tSecretario*) calloc(1,tamT);

        // Ler os dados do secretário do arquivo
        fread(clinica->secretarios[i], tamT, 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void EscreveBinMedicos(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "wb");
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
    if(tam!= 0)
        clinica->medicos = (tMedico**) realloc(clinica->medicos, sizeof(tMedico*) * tam);

    if (clinica->medicos == NULL) {
        printf("Erro ao realocar memória para médicos\n");
        exit(-1);
    }

    clinica->numMedicos = tam;

    // Loop para ler cada médico do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o médico atual
        clinica->medicos[i] = (tMedico*) calloc(1,obtemTamTMedico());

        // Ler os dados do médico do arquivo

        fread(clinica->medicos[i], obtemTamTMedico(), 1, arquivo);
    }

    // Fechar o arquivo
    fclose(arquivo);
}
void EscreveBinConsultas(tClinica* clinica, const char* path) {
    FILE* arquivo = fopen(path, "wb");
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
    if(tam!= 0)
        clinica->consultas =(tConsulta**) realloc(clinica->consultas, sizeof(tConsulta*) * tam);

    if (clinica->consultas == NULL) {
        printf("Erro ao realocar memória para consultas\n");
        exit(-1);
    }

    clinica->numConsultas = tam;

    // Loop para ler cada consulta do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para a consulta atual
        clinica->consultas[i] = (tConsulta*) calloc(1,obtemTamTConsulta());

        int indexPaciente =0;

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
    if(tam!= 0)
        clinica->pacientes =(tPaciente**) realloc(clinica->pacientes, sizeof(tPaciente*) * tam);

    if (clinica->pacientes == NULL) {
        printf("Erro ao realocar memória para pacientes\n");
        exit(-1);
    }

    clinica->numPacientes = tam;

    // Loop para ler cada paciente do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o paciente atual
        clinica->pacientes[i] = (tPaciente*) calloc(1,obtemTamTPaciente());

        // Ler os dados do paciente do arquivo
        fread(clinica->pacientes[i], obtemTamTPaciente(), 1, arquivo);
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

        tLesoes* lesoesAtual = clinica->vetorLesoes[i];
        int tam = ObtemTamLesoes(lesoesAtual);
        fwrite(&tam, sizeof(int), 1, arquivo);

        // Escrever o índice do paciente
        int indexPaciente = ObtemIndexPacienteLesoes(lesoesAtual);
        fwrite(&indexPaciente, sizeof(int), 1, arquivo);

        // Escrever as lesões do vetor
       
        EscreveBinLesaoVetor(lesoesAtual, arquivo);
    }
    fclose(arquivo);
    // Fechar o arquivo

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
    if(tam!= 0)
        clinica->vetorLesoes =(tLesoes**) realloc(clinica->vetorLesoes, sizeof(tLesoes*) * tam);

    if (clinica->vetorLesoes == NULL) {
        printf("Erro ao realocar memória para lesões\n");
        exit(-1);
    }
// definir tamanho de vetorlesoes
    clinica->tamVetorLesoes = tam;

    // Loop para ler cada conjunto de lesões do arquivo
    for (int i = 0; i < tam; i++) {
        // Alocar memória para o conjunto de lesões atual
        clinica->vetorLesoes[i] = (tLesoes*) calloc(1,obtemTamTLesoes());
        tLesoes* lesoesAtual = clinica->vetorLesoes[i];
        int tam=0,indexPaciente=0;
        fread(&tam, sizeof(int), 1, arquivo);
        fread(&indexPaciente, sizeof(int), 1, arquivo);
        DefineLesoesBin(clinica->vetorLesoes[i],indexPaciente,tam);
        // Ler os dados do conjunto de lesões do arquivo
        LeBinLesaoVetor(lesoesAtual,arquivo,tam);
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


//Cadastrar Paciente 
// retorna se cadastro foi bem sucedido
int CadastraPacienteClinica(tClinica *clinica){

    printf("#################### CADASTRO PACIENTE #######################\n");
    tPaciente* paciente = criaPaciente();
    lePaciente(paciente);
    if(EhCadastradoPaciente(clinica->pacientes,ObtemCpfPaciente(paciente),clinica->numPacientes) == -1){
        //Incrementa numero de pacientes
        adcionaPaciente(clinica,paciente);
        return 1;
    }
    desalocaPaciente(paciente);
    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
    return 0;
}



int CadastraSecretarioClinica(tClinica* clinica){
    
    printf("#################### CADASTRO SECRETARIO #######################\n");
    tSecretario* secretario = CriaSecretario();
    leSecretario(secretario);
    if(EhCadastradoSecretario(clinica->secretarios,secretario,clinica->numSecretarios) == -1){
        adcionaSecretario(clinica,secretario);
        return 1;
    }
    liberaSecretario(secretario);
    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
    return 0;
}

int CadastraMedicoClinica(tClinica* clinica){

    printf("#################### CADASTRO MEDICO #######################\n");
    tMedico* medico = criaMedico();

    leMedico(medico);
    
    if(EhCadastradoMedico(clinica->medicos, medico, clinica->numMedicos) == -1){
        adcionaMedico(clinica,medico);
        return 1;
    }
    liberaMedico(medico);
    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
    return 0;
}

// medico e primeira vez
// secretario e primeira vez
void comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso, int *indexMedico, int *indexSecretario, Login *resultado){
    //porcurar login ou senha em medicos seja e retornar login
    Login medico;
    
    medico  = loginMedico(clinica->medicos,senha,usuario, clinica->numMedicos,indexMedico);

    Login secretario = loginSecretario(clinica->secretarios, senha , usuario, clinica->numSecretarios, indexSecretario);
    if(medico == CORRETO){
        *acesso = MEDI;
        *resultado = CORRETO;
    }else if(secretario == CORRETO){
        *acesso = ObtemNivelAcessoSecretario(obtemSecretario(clinica->secretarios,*indexSecretario));
        *resultado = CORRETO;
    }else {
        *resultado = INCORRETO;
    }

    printf("\n#%d#\n", *resultado);
}

int EhCadastradoCLinica(tClinica* clinica, char *cpf){
    return EhCadastradoPaciente(clinica->pacientes,cpf,clinica->numPacientes);
}
//Cadastrar Medico

//Cadastrar Secretario

void ImprimiSubMenu(){
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("    (1) CADASTRAR LESAO\n");
    printf("    (2) GERAR RECEITA MEDICA\n");
    printf("    (3) SOLICITACAO DE BIOPSIA\n");
    printf("    (4) ENCAMINHAMENTO\n");
    printf("    (5) ENCERRAR CONSULTA\n");
    printf("############################################################\n");

}



// acrescentar taVetorLesoes antes

void ConsultaMedica(tClinica* clinica, int indexPaciente, int indexMedico, tFila* fila, tMedico* medicoVazio){
    tPaciente* paciente =NULL;
    paciente = clinica->pacientes[indexPaciente];
    tMedico* medico = NULL;

    int desalocaMedicoA=0;
    if(indexMedico !=-1){
        medico =clinica->medicos[indexMedico];
    }else{
        
        medico =  medicoVazio;
    }

    AtendePaciente(paciente);
    printf("#################### CONSULTA MEDICA #######################\n");
    
    printf("CPF DO PACIENTE: ---\n");

    printf("---\n");
   
    printf("- NOME: %s\n", ObtemNomePaciente(paciente));
   
    printf("- DATA DE NASCIMENTO: %s\n", ObtemDataPaciente(paciente));
  
    printf("---\n");

    printf("DATA DA CONSULTA: ");
   
    char dataConsulta[11]= {'\0'};
    char dataBase[12]= {'\0'};
    scanf("%10[^\n]%*c",dataBase);
    
    int ano = 0, mes = 0, dia = 0;

    sscanf(dataBase, "%d/%d/%d", &dia, &mes, &ano);
    sprintf(dataConsulta,"%d/%d/%d",dia,mes,ano);
 
    //cada paciente tera uma consulta e sua data ta na sua struct
    CompletaDadosPaciente(paciente);
    // Os documentos e lesoes serao adcionados de acordo 
    tConsulta* consulta= criaConsulta(dataConsulta,ObtemNomeMedico(medico), ObtemNomePaciente(paciente),indexPaciente);
    tLesoes* lesoes =NULL;
    int cont =1;
    while (1)
    {
        ImprimiSubMenu();
        int opcao;
        int sair = 0;
        scanf("%d%*c", &opcao);
        switch (opcao)
        {
        case 1:
            if(cont==1){
                
                lesoes= CriaLesoes();
                defineIndexPacienteLesoes(lesoes,indexPaciente);
                //compartilham o ponteiro para struct lesoes
                adcionaLesoes(clinica,lesoes);
                //colocar a lesoes no paciente
  
   
            }
            
            printf("#################### CONSULTA MEDICA #######################\n");
     
            printf("CADASTRO DE LESAO:\n");
   

            tLesao * lesaoAtual = criaLesao();
            leLesao(lesaoAtual);


            CadastraLesao(lesoes,lesaoAtual);

            printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
            
        
        
            printf("############################################################\n");
          
            scanf("%*c%*c");
            cont++;
            break;
        case 2:
            printf("#################### CONSULTA MEDICA #######################\n");
            
            printf("RECEITA MEDICA:\n");

            printf("TIPO DE USO: ");

            char uso[8]={'\0'};
            scanf("%7[^\n]%*c",uso);
            eTipoUso tUso;
            if(strcmp(uso,"ORAL")==0){
                tUso = ORAL;
            }else if(strcmp(uso,"TOPICO")==0){
                tUso = TOPICO;
            }
            printf("NOME DO MEDICAMENTO: ");
            
            char nomeMedicamento[50]= {'\0'};
            scanf("%49[^\n]%*c", nomeMedicamento);

            printf("TIPO DE MEDICAMENTO: ");
          
            char tipoMedicamento[50]= {'\0'};
            scanf("%49[^\n]%*c", tipoMedicamento);
            
            printf("QUANTIDADE: ");
       
            int quantidade;
            scanf("%d%*c", &quantidade);
            
            char instrucoes[300];         
            printf("INSTRUCOES DE USO:\n");
      
            scanf("%299[^\n]%*c", instrucoes);


            

            //criar receita;
            tReceita *receita = criaReceita(ObtemNomePaciente(paciente),
            tUso,nomeMedicamento,tipoMedicamento,instrucoes,quantidade,ObtemNomeMedico(medico) ,
            ObtemCrm(medico) ,dataConsulta);

            insereDocumentoFila(fila, receita,imprimeNaTelaReceita, imprimeEmArquivoReceita,desalocaReceita);

    
            printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
            
          
            
            printf("############################################################\n");
          
            scanf("%*c%*c");
            break;
        case 3:

            if(NaoTemLesaoCirurgia(lesoes)){
                printf("#################### CONSULTA MEDICA #######################\n");
     
                printf("NAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                
                printf("############################################################\n");
      
                scanf("%*c");
                continue;
            }

            tBiopsia* biobsia = criaBiopsia(ObtemNomePaciente(paciente),ObtemCpfPaciente(paciente),
            lesoes,ObtemNomeMedico(medico),ObtemCrm(medico),dataConsulta);

            insereDocumentoFila(fila, biobsia, imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);


          

            printf("#################### CONSULTA MEDICA #######################\n");

            printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        
            
            printf("############################################################\n");
            scanf("%*c%*c");
            break;
        case 4:
            printf("#################### CONSULTA MEDICA #######################\n");
           
            printf("ENCAMINHAMENTO:\n");
          
            printf("ESPECIALIDADE ENCAMINHADA: ");
        
            char especialidade[51]= {'\0'};
            scanf("%50[^\n]%*c",especialidade);
            printf("\nMOTIVO: ");
  
            char motivo[301];
            scanf("%300[^\n]%*c",motivo);

            tEncaminhamento* encaminhamento = criaEncaminhamento(ObtemNomePaciente(paciente),ObtemCpfPaciente(paciente)
            ,ObtemNomeMedico(medico),ObtemCrm(medico),dataConsulta,especialidade,motivo);
            
           

            insereDocumentoFila(fila,encaminhamento,imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento,desalocaEncaminhamento);

            printf("\nENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
          
            
            printf("############################################################\n");
            scanf("%*c%*c");

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
    adcionaConsulta(clinica,consulta);


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


void adcionaPaciente( tClinica* clinica, tPaciente *paciente)
{
    clinica->numPacientes++;
    int tam = clinica->numPacientes;
    // Realocar o vetor de pacientes para acomodar o novo tamanho
    clinica->pacientes = (tPaciente **)realloc(clinica->pacientes, (tam) * sizeof(tPaciente *));


    // Verificar se a realocação foi bem-sucedida
    if (clinica->pacientes == NULL)
    {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    // Inserir Paciente
    clinica->pacientes[tam-1] = paciente;

}


void adcionaSecretario(tClinica* clinica, tSecretario *secretario) {
    
    clinica->numSecretarios++;
    int tam = clinica->numSecretarios;

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    clinica->secretarios = (tSecretario**)realloc(clinica->secretarios, (tam) * sizeof(tSecretario*));

    // Verificar se a realocação foi bem-sucedida
    if (clinica->secretarios == NULL) {
        printf("Erro ao realocar memória para o vetor de secretarios.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    clinica->secretarios[tam-1] = secretario;

}

void adcionaMedico(tClinica* clinica, tMedico *medico) {
    
    clinica->numMedicos++;
    int tam = clinica->numMedicos;
    // Realocar o vetor de pacientes para acomodar o novo tamanho
    clinica->medicos = (tMedico**)realloc(clinica->medicos, (tam) * sizeof(tMedico*));

    // Verificar se a realocação foi bem-sucedida
    if (clinica->medicos == NULL) {
        printf("Erro ao realocar memória para o vetor de medicos.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    clinica->medicos[tam-1] = medico;
}

void adcionaConsulta(tClinica*clinica, tConsulta*consulta) {
    
    clinica->numConsultas++;
    int tam = clinica->numConsultas;
    // Realocar o vetor de pacientes para acomodar o novo tamanho
     clinica->consultas = (tConsulta**)realloc(clinica->consultas, (tam) * sizeof(tConsulta*));

    // Verificar se a realocação foi bem-sucedida
    if (clinica->consultas == NULL) {
        printf("Erro ao realocar memória para o vetor de consultas.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    clinica->consultas[tam-1] = consulta;

}

void adcionaLesoes(tClinica* clinica, tLesoes *lesoes) {
    
    clinica->tamVetorLesoes++;
    int tam = clinica->tamVetorLesoes;
    // Realocar o vetor de pacientes para acomodar o novo tamanho
    clinica->vetorLesoes = (tLesoes**)realloc(clinica->vetorLesoes, (tam) * sizeof(tLesoes*));

    // Verificar se a realocação foi bem-sucedida
    if (clinica->vetorLesoes == NULL) {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    //Inserir Paciente
    clinica->vetorLesoes[tam-1] = lesoes;
}

void desalocaClinica(tClinica* clinica){
    if(clinica){

        if(clinica->secretarios){
            for(int i=0; i< clinica->numSecretarios;i++){
                desalocarSecretario(clinica->secretarios[i]);
            }
            free(clinica->secretarios);
        }

        if(clinica->medicos){
            for(int j=0; j< clinica->numMedicos;j++){
                desalocaMedico(clinica->medicos[j]);
            }
            free(clinica->medicos);
        }

        if(clinica->pacientes){
            for(int k=0; k<clinica->numPacientes;k++){
                desalocaPaciente(clinica->pacientes[k]);
            }
            free(clinica->pacientes);
        }

        if(clinica->consultas){
            for(int l=0; l<clinica->numConsultas;l++){
                desalocaConsulta(clinica->consultas[l]);
            }
            free(clinica->consultas);
        }
        if(clinica->vetorLesoes){
            for(int m=0; m<clinica->tamVetorLesoes;m++){
                desalocaLesoes(clinica->vetorLesoes[m]);
            }
            free(clinica->vetorLesoes);
        }

        free(clinica);

    }
}