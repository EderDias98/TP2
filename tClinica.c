#include "tClinica.h"

struct clinica {
    char* nome;
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


Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso, int *indexMedico){
    //porcurar login ou senha em medicos seja e retornar login
    Login medico;
    medico  = loginMedico(clinica->medicos,senha,usuario, clinica->numMedicos,indexMedico);
    if(medico == CORRETO){
        *acesso = MEDI;
        return CORRETO;
    }
    Login secretario = loginSecretario(clinica->secretarios, senha , usuario, clinica->numSecretarios, acesso);

    if(secretario == CORRETO){
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
    tPaciente* paciente = clinica->pacientes[indexPaciente];
    tMedico* medico = clinica->medicos[indexMedico];

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
    DefiniDataConsultaPaciente(paciente,dataConsulta);
    // Os documentos e lesoes serao adcionados de acordo 
    tConsulta* consulta= criaConsulta(indexPaciente,indexMedico,dataConsulta,obtemNomeMedico(medico), ObtemNomePaciente(paciente));
    tLesoes *lesoes =NULL;
    while (1)
    {
        ImprimiSubMenu();
        int opcao;
        int sair = 0,cont=0;
        scanf("%d%*c", &opcao);
        switch (opcao)
        {
        case 1:
            if(cont==0){
                clinica->tamVetorLesoes++;
                tLesoes* lesoes = criaLesoes();
                //compartilham o ponteiro para struct lesoes
                DefiniLesoesConsulta(consulta,lesoes);
                DefiniLesoesPaciente(paciente,lesoes);
                adcionaLesoes(clinica->vetorLesoes,lesoes, clinica->tamVetorLesoes);
            }
            lesoes =  clinica->vetorLesoes[clinica->tamVetorLesoes-1];
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("CADASTRO DE LESAO:\n");

            
            tLesao * lesao = criaLesao();
            leLesao(lesao);

            IncrementaTamLesoes(lesoes);
            CadastraLesaoClinica(ObtemVetorLesoes(lesoes),lesao,ObtemTamLesoes(lesoes));

            printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
            printf("RETORNAR AO MENU ANTERIOR");
            printf("############################################################");
            scanf("%*c");
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
            tUso,nomeMedicamento,tipoMedicamento,instrucoes,quantidade,obtemNomeMedico(medico) ,
            ObtemCrm(paciente) ,dataConsulta);

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

            tBiopsia* biobsia = Criabiobsia(ObtemNomePaciente(paciente),ObtemCpfPaciente(paciente),
            lesoes,ObtemNomeMedico(medico),ObtemCrm(medico),dataConsulta);

            DefinirBiopsiaConsulta(consulta, biobsia);

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

        cont++;

        if(sair==1){
            break;
        }
    }
    clinica->numConsultas++;
    adcionaConsulta(clinica->consultas,consulta,clinica->numConsultas);
}








