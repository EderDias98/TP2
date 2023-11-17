#ifndef T_CLINICA_H
#define T_CLINICA_H
#include "tPaciente.h"
#include "tSecretario.h"
#include "tMedico.h"

typedef struct clinica tClinica;


tClinica* criaClinica();


void InicializaClinicaVetores(tClinica* clinica);


// Função para destruir uma instância da clínica
void liberaClinica(tClinica* clinica);

//Cadastrar Paciente 
// retorna se cadastro foi bem sucedido
int CadastraPacienteClinica(tClinica *clinica);


int CadastraSecretarioClinica(tClinica* clinica);
 

int CadastraMedicoClinica(tClinica* clinica);

Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso);

int EhCadastradoCLinica(tClinica* clinica, char cpf);

#endif