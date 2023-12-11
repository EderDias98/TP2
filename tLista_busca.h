#ifndef LISTA_BUSCA_H
#define  LISTA_BUSCA_H

#include "tPaciente.h"


typedef struct lista tLista;

tLista *criaListaDeBusca(tPaciente** lista, int numPacientesLista);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLista(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaLista(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoLista(void *dado, char *path);



void adcionaPacienteListaBusca(tLista* lista, tPaciente* paciente);
#endif