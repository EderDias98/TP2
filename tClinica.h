#ifndef T_CLINICA_H
#define T_CLINICA_H
#include "tPaciente.h"
#include "tSecretario.h"
#include "tMedico.h"
#include "tConsulta.h"
#include "tLista_busca.h"
#include "tBusca.h"

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

Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso,int *indexMedico);

int EhCadastradoCLinica(tClinica* clinica, char *cpf);



void ConsultaMedica(tClinica* clinica, int indexPaciente, int indexMedico);
void ImprimiSubMenu();
tPaciente** ObtemPacientes(tClinica* clinica);

int ObtemTamPacientes(tClinica* clinica);
 


#endif