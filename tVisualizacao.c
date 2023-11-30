#include "tVisualizacao.h"

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */



void imprimeEmTelaBusca(void *dado){
    tPaciente* paciente = (tPaciente*) dado;
    printf("NOME: %s\n", ObtemNomePaciente(paciente));
    printf("DATA DE NASCIMENTO: %s (32 ANOS)",ObtemDataPaciente(paciente),CalculaIdade(ObtemDataPaciente(paciente)));
    printf("GENERO: %\n", ObtemGeneroPaciente(paciente) );
    printf("TELEFONE: %d\n", ObtemTelefonePaciente(paciente));
    printf("DIABETES: %s\n", SimOuNao(ObtemDiabetesPacientes(paciente)));
    printf("FUMANTE: %s\n", SimOuNao(ObtemFumantePaciente(paciente)));
    printf("ALERGIA A MEDICAMENTO: %s\n", SimOuNao(ObtemAlergiaPaciente(paciente)));
    printf("HISTORICO DE CANCER: %s\n", SimOuNao(ObtemHistoricoCancerPaciente(paciente)));
    printf("TIPO DE PELE: %s\n", ObtemTipoPelePaciente(paciente));
    printf("LESOES:\n");
    tLesoes** vetorlesoes = ObtemVetorLesoesPaciente(paciente);
    int numVetorLesoes = ObtemNumLesoesPaciente(paciente);
    if(vetorlesoes[0]){
      
        printf("TOTAL: %d", calculaNumLesao(vetorlesoes,numVetorLesoes));
        printf("ENVIADA PARA CIRURGIA: %d", QtdEnvidasCirurgia(vetorlesoes,numVetorLesoes));
        printf("ENVIADA PARA CRIOTERAPIA: %d", QtdEnvidasCrioterapia(vetorlesoes,numVetorLesoes));
        printf("DESCRICAO DAS LESOES:\n");
        for(int i=0; i< numVetorLesoes;i++){
            tLesoes* lesoesAtual = obtemLesoes(vetorlesoes,i);
            for(int j=0; j< ObtemTamLesoes(vetorlesoes[i]) ;j++){
                tLesao* lesao = obtemLesao(lesoesAtual,j);
                printf("%s - %s - %s - %dMM - %s\n",ObtemRotulo(lesao),
                ObtemDiagnostico(lesao), ObtemRegiaoCorpo(lesao), ObtemTamanho(lesao),EnviadaOnde(lesao));
            }
            printf("\n");
        }   
    }

}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoBusca(void *dado, char *path){
    
    tPaciente* paciente = (tPaciente*)dado;

    FILE* arquivo;
    char endereco[200];
    strncpy(endereco,path,sizeof(endereco)-1);
    strcat(endereco,"/visualizacao.txt");
    arquivo = fopen(endereco, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo receita.txt para escrita.\n");
        return;
    }

     fprintf(arquivo, "NOME: %s\n", ObtemNomePaciente(paciente));
    fprintf(arquivo, "DATA DE NASCIMENTO: %s (%d ANOS)\n", ObtemDataPaciente(paciente), CalculaIdade(ObtemDataPaciente(paciente)));
    fprintf(arquivo, "GENERO: %s\n", ObtemGeneroPaciente(paciente));
    fprintf(arquivo, "TELEFONE: %d\n", ObtemTelefonePaciente(paciente));
    fprintf(arquivo, "DIABETES: %s\n", SimOuNao(ObtemDiabetesPacientes(paciente)));
    fprintf(arquivo, "FUMANTE: %s\n", SimOuNao(ObtemFumantePaciente(paciente)));
    fprintf(arquivo, "ALERGIA A MEDICAMENTO: %s\n", SimOuNao(ObtemAlergiaPaciente(paciente)));
    fprintf(arquivo, "HISTORICO DE CANCER: %s\n", SimOuNao(ObtemHistoricoCancerPaciente(paciente)));
    fprintf(arquivo, "TIPO DE PELE: %s\n", ObtemTipoPelePaciente(paciente));
    fprintf(arquivo, "LESOES:\n");

    tLesoes** vetorlesoes = ObtemVetorLesoesPaciente(paciente);
    int numVetorLesoes = ObtemNumLesoesPaciente(paciente);
    if (vetorlesoes[0]) {
       
        fprintf(arquivo, "TOTAL: %d\n",calculaNumLesao(vetorlesoes,numVetorLesoes));
        fprintf(arquivo, "ENVIADA PARA CIRURGIA: %d\n",  QtdEnvidasCirurgia(vetorlesoes,numVetorLesoes));
        fprintf(arquivo, "ENVIADA PARA CRIOTERAPIA: %d\n",  QtdEnvidasCrioterapia(vetorlesoes,numVetorLesoes));
        fprintf(arquivo, "DESCRICAO DAS LESOES:\n");

        for(int i=0; i< numVetorLesoes;i++){
            tLesoes* lesoesAtual = obtemLesoes(vetorlesoes,i);
            for(int j=0; j< ObtemTamLesoes(vetorlesoes[i]) ;j++){
                tLesao* lesao = obtemLesao(lesoesAtual,j);
                printf("%s - %s - %s - %dMM - %s\n",ObtemRotulo(lesao),
                ObtemDiagnostico(lesao), ObtemRegiaoCorpo(lesao), ObtemTamanho(lesao),EnviadaOnde(lesao));
            }
            printf("\n");
        }   
    }
}

