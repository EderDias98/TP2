#ifndef T_CLINICA_H
#define T_CLINICA_H
#include "tPaciente.h"
#include "tSecretario.h"
#include "tMedico.h"
#include "tConsulta.h"
#include "tLista_busca.h"
#include "tLesao.h"
#include "tFila.h"
#include "tEncaminhamento.h"

typedef struct clinica tClinica;


tClinica* criaClinica();

tPaciente** obtemVetorPacientes(tClinica* clinica);
void InicializaClinicaVetores(tClinica* clinica);

int obtemTamVetorConsultas(tClinica* clinica);
 int obtemNumPacientes(tClinica* clinica);
// Função para destruir uma instância da clínica
void liberaClinica(tClinica* clinica);

//Cadastrar Paciente 
// retorna se cadastro foi bem sucedido
int CadastraPacienteClinica(tClinica *clinica);


int CadastraSecretarioClinica(tClinica* clinica);
 

int CadastraMedicoClinica(tClinica* clinica);

Login comfirmarLogin(tClinica* clinica,char* senha,char* usuario,Nivel *acesso, int *indexMedico, int *indexSecretario);

int EhCadastradoCLinica(tClinica* clinica, char *cpf);



void ConsultaMedica(tClinica* clinica, int indexPaciente, int indexMedico, tFila* fila);
void ImprimiSubMenu();
tPaciente** ObtemPacientes(tClinica* clinica);

int ObtemTamPacientes(tClinica* clinica);
int ObtemTamVetorLesoes(tClinica* clinica);


tLesoes** ObtemVetor(tClinica* clinica);

int obtemNumConsultas(tClinica* clinica);

tSecretario** obtemVetorSecretarios(tClinica* clinica);

tMedico** obtemVetorMedicos(tClinica* clinica);

tConsulta** obtemVetorConsultas(tClinica* clinica);

void LeBinLesoes(tClinica* clinica, const char* path);
void EscreveBinLesoes(tClinica* clinica, const char* path);

void LeBinLesaoVetor(tLesao** vetor,FILE * arquivo, int tam);
void EscreveBinLesaoVetor(tLesao** vetor, FILE* arquivo, int tam);


void LeBinPacientes(tClinica* clinica, const char* path);
void EscreveBinPacientes(tClinica* clinica, const char* path);

void LeBinConsultas(tClinica* clinica, const char* path);
void EscreveBinConsultas(tClinica* clinica, const char* path);

void LeBinMedicos(tClinica* clinica, const char* path);
void EscreveBinMedicos(tClinica* clinica, const char* path);


void LeBinSecretarios(tClinica* clinica,char *path);
void EscreveBinsecretarios(tClinica* clinica,char *path);



void adcionaPaciente( tClinica* clinica, tPaciente *paciente);
void adcionaSecretario(tClinica* clinica, tSecretario *secretario);
void adcionaMedico(tClinica* clinica, tMedico *medico);
void adcionaConsulta(tClinica*clinica, tConsulta*consulta);
void adcionaLesoes(tClinica* clinica, tLesoes *lesoes);
#endif