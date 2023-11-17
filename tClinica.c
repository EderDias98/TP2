#include "tClinica.h"

struct clinica {
    char* nome;
    tSecretario** secretarios;
    int numSecretarios;
    tMedico** medicos;
    int numMedicos;
    tPaciente** pacientes;
    int numPacientes;
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

        // Liberar a estrutura principal
        free(clinica);
    }
}

//Cadastrar Paciente 
// retorna se cadastro foi bem sucedido
int CadastraPacienteClinica(tClinica *clinica){
    tPaciente* paciente = criaPaciente();
    lePaciente(paciente);
    if(EhCadastradoPaciente(clinica->pacientes,paciente,clinica->numPacientes)){
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
    if(EhCadastradoSecretario(clinica->secretarios,secretario,clinica->numSecretarios)){
        clinica->numSecretarios++;
        adcionaSecretario(clinica->secretarios,secretario,clinica->numSecretarios);
        return 1;
    }
    return 0;
}

int CadastraMedicoClinica(tClinica* clinica){
    tMedico* medico = criaMedico();
    leMedico(medico);
    if(EhCadastradoMedico(clinica->medicos, medico, clinica->numMedicos)){
        clinica->numMedicos++;
        adcionaMedico(clinica->medicos, medico, clinica->numMedicos);
        return 1;
    }
    return 0;
}

Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso){
    //porcurar login ou senha em medicos seja e retornar login
    Login medico;
    medico  = loginMedico(clinica->medicos,senha,usuario, clinica->numMedicos);
    if(medico == CORRETO){
        *acesso = MEDI;
        return CORRETO;
    }
    Login secretario = loginSecretario(clinica->secretarios, senha , usuario, clinica->numSecretarios, &acesso);

    if(secretario == CORRETO){
        return CORRETO;
    }

    return SENHA_IN;
}

//Cadastrar Medico

//Cadastrar Secretario