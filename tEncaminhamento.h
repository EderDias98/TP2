#ifndef T_ENCAMINHAMENTO
#define T_ENCAMINHAMENTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  encaminhamento tEncaminhamento;

/**
 * Função que recebe todas as informações pertinentes a uma receita e retorna
 * um ponteiro com a receita criada.
 *
 */
tEncaminhamento *criaEncaminhamento(char *nomePaciente,  char *cpfPaciente,
                      char *nomeMedico, char *CRM, char *dataStr,char* especialidade, char* motivo);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaEncaminhamento(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaEncaminhamento(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoEncaminhamento(void *dado, char *path);

#endif