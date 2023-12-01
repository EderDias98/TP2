#include "tRelatorio.h"


struct diagnostico {
    char nomeDiagnostico[20];
    int qtd;
    
};



struct relatorio{
    int numPacientes; //Número total de pacientes que possui pelo menos um atendimento
    float mediaIdade;
    float DesvioPadraoIdade;//Média e desvio padrão da idade dos pacientes Utilizando somente a parte inteira
    float distribuicaoFeminino;
    float distribuicaoMasculino;
    float distribuicaoOutros;//Na ordem: feminino, masculino e outros Utilizando somente a parte inteira
    float tamMedioLesoes;
    float DesvioPadraoLesoes;//Utilizando somente a parte inteira
    float numLesoes;
    float numCirurgias;
    float porcentagemCirurgias;
    float numCrioterapias;
    float porcentagemCrioterapias;
    tDiagnostico** diagnosticos;
    int numDiagnosticos;
};


void calculaEstatisticasIdade(tPaciente **pacientes, int numPacientes, float *media, float *desvioPadrao) {
    // Cálculo da média
    float somaIdades = 0.0;
    for (int i = 0; i < numPacientes; ++i) {
        somaIdades += CalculaIdade(ObtemDataPaciente(ObtemPaciente(pacientes,i)));
    }
    *media = somaIdades / numPacientes;

    // Cálculo do desvio padrão
    float somaDiferencasQuadradas = 0.0;
    for (int i = 0; i < numPacientes; ++i) {
        float diferenca = CalculaIdade(ObtemDataPaciente(ObtemPaciente(pacientes,i))) - *media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }
    *desvioPadrao = sqrt(somaDiferencasQuadradas / numPacientes);
}

void calcularDistribuicaoGenero(tPaciente **pacientes, int numPacientes, int *masculino, int *feminino, int *outros) {
    *masculino = 0;
    *feminino = 0;
    *outros = 0;

    for (int i = 0; i < numPacientes; ++i) {
        if (strcmp(ObtemGeneroPaciente(ObtemPaciente(pacientes,i)), "MASCULINO") == 0) {
            (*masculino)++;
        } else if (strcmp(ObtemGeneroPaciente(ObtemPaciente(pacientes,i)), "FEMININO") == 0) {
            (*feminino)++;
        } else {
            (*outros)++;
        }
    }
}
void calculaEstatisticasTamanhoLesoes(tLesoes **vetor, int numLesoes, float *media, float *desvioPadrao) {
    // Cálculo da média
    float somaIdades = 0.0;
    for (int i = 0; i < numLesoes; ++i) {
        tLesoes* lesoesAtual = ObtemLesao(vetor,i);

        for(int j=0;j< ObtemTamLesoes(lesoesAtual);j++){
            somaIdades += ObtemTamanho(ObtemLesao(ObtemVetorLesoes(lesoesAtual),j));
        }
       
    }
    *media = somaIdades / numLesoes;

    // Cálculo do desvio padrão
    float somaDiferencasQuadradas = 0.0;
    for (int i = 0; i < numLesoes; ++i) {
        
        tLesoes* lesoesAtual = ObtemLesao(vetor,i);
        for(int j=0;j< ObtemTamLesoes(lesoesAtual);j++){
            float diferenca = ObtemTamanho(ObtemLesao(ObtemVetorLesoes(lesoesAtual),j)) - *media;
            somaDiferencasQuadradas += diferenca * diferenca;
        }
       

    }
    *desvioPadrao = sqrt(somaDiferencasQuadradas / numLesoes);
}

void calculaEstatisticasProcedimentos(tLesoes **vetor, int numLesoes,int *totalLesoes ,int *numCirurgias, int *numCrioterapias) {
    // Inicializa contadores
    *numCirurgias = 0;
    *numCrioterapias = 0;
    *totalLesoes = 0;

    // Conta o número total de lesões, cirurgias e crioterapias
    for (int i = 0; i < numLesoes; ++i) {
        tLesoes* lesoesAtual = ObtemLesao(vetor, i);

        for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++) {
            tLesao* lesaoAtual = ObtemLesao(ObtemVetorLesoes(lesoesAtual), j);
            
            // Conta o número total de lesões
            // (você pode adicionar mais lógica para contar cirurgias e crioterapias)
            if (ObtemEnviarCirurgia(lesaoAtual)) {
                (*numCirurgias)++;
            }
            
            if (ObtemEnviarCrioterapia(lesaoAtual)) {
                (*numCrioterapias)++;
            }
            (*totalLesoes)++;
        }
    }
}
tRelatorio* CriaRelatorio(tClinica* clinica){
    tRelatorio* relatorio = (tRelatorio* ) calloc(1, sizeof(tRelatorio));

    if (relatorio == NULL) {
        printf("Erro ao alocar memória para a relatorio\n");
        exit(EXIT_FAILURE);
    }
    tPaciente** vetorPaciente = ObtemPacientes(clinica);
    int numLesoes=ObtemTamVetorLesoes(clinica);
    relatorio->numPacientes = ObtemTamPacientes(clinica);
    calculaEstatisticasIdade(vetorPaciente,relatorio->numPacientes,&relatorio->mediaIdade,&relatorio->DesvioPadraoIdade);
    calcularDistribuicaoGenero(vetorPaciente,relatorio->numPacientes,&relatorio->distribuicaoMasculino,
    &relatorio->distribuicaoFeminino, &relatorio->distribuicaoOutros);
    tLesoes ** vetorLesoes = ObtemVetor(clinica);
    calculaEstatisticasTamanhoLesoes(vetorLesoes,numLesoes,&relatorio->tamMedioLesoes,
    &relatorio->DesvioPadraoLesoes);
    calculaEstatisticasProcedimentos(vetorLesoes,numLesoes,&relatorio->numLesoes,
    &relatorio->numCirurgias, &relatorio->numCrioterapias);
    relatorio->porcentagemCirurgias = relatorio->numCirurgias/(float)relatorio->numLesoes;
    relatorio->porcentagemCrioterapias = relatorio->numCrioterapias/(float)relatorio->numLesoes;
    tDiagnostico** vetorDiagnostico = CriaVetorDiagnostico();
    relatorio->numDiagnosticos = NUM_DIAGONOSTICOS;
    ContaNumDiagnostico(vetorDiagnostico,relatorio->numDiagnosticos,numLesoes);
    qsort(vetorDiagnostico,relatorio->numDiagnosticos,sizeof(tDiagnostico*),compararDiagnostico);


}

tDiagnostico* CriaDiagnostico(char* nome){
    tDiagnostico* diagnostico =(tDiagnostico*) calloc(NUM_DIAGONOSTICOS,sizeof(tDiagnostico));
    
    if (diagnostico == NULL) {
        printf("Erro ao alocar memória para a diagnostico\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(diagnostico->nomeDiagnostico,nome);

    return diagnostico;
}

tDiagnostico** CriaVetorDiagnostico(){
    tDiagnostico** vetor = (tDiagnostico**) calloc(7,sizeof(tDiagnostico*));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor de diagnosticos\n");
        exit(EXIT_FAILURE);
    }
    vetor[0]  = CriaDiagnostico("CARCINOMA BASOCELULAR");
    vetor[1] = CriaDiagnostico("ESPINOCELULAR");
    vetor[2] = CriaDiagnostico(" MELANOMA");
    vetor[3] = CriaDiagnostico("CERATOSE ACTINICA");
    vetor[4] = CriaDiagnostico(" NEVO");
    vetor[5] = CriaDiagnostico("CERATOSE SEBORREICA ");
    vetor[6] = CriaDiagnostico(" OUTROS");
    return vetor;
}

int compararDiagnostico(const void *a, const void *b) {
    // Comparação decrescente pela quantidade (qtd)
    int diferenca = ((tDiagnostico *)b)->qtd - ((tDiagnostico *)a)->qtd;

    // Em caso de empate, use a ordem alfabética do nomeDiagnostico
    if (diferenca == 0) {
        return strcmp(((tDiagnostico *)a)->nomeDiagnostico, ((tDiagnostico *)b)->nomeDiagnostico);
    }

    return diferenca;
}


void ContaNumDiagnostico(tDiagnostico **vetor, int numDiagnostico, int numLesoes) {
    // Inicializa contadores


    // Conta o número total de lesões, cirurgias e crioterapias
    for(int k=0; k< numDiagnostico;k++){
        for (int i = 0; i < numLesoes; ++i) {
        tLesoes* lesoesAtual = ObtemLesao(vetor, i);

            for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++) {
                tLesao* lesaoAtual = ObtemLesao(ObtemVetorLesoes(lesoesAtual), j);
                char *nomeDiagnostico = ObtemDiagnostico(lesaoAtual);
                tDiagnostico* diagnosticoAtual;
                if(strcmp(nomeDiagnostico,diagnosticoAtual->nomeDiagnostico)){
                    diagnosticoAtual->qtd++;
                }
            }
        }
    }
}
/**
 * Função que recebe o ponteiro genérico (que deve conter uma receita) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaRelatorio(void *dado){
    tRelatorio* relatorio = (tRelatorio*) dado;
    if(relatorio){
        for(int i=0;i<relatorio->numDiagnosticos;i++){
            free(relatorio->diagnosticos[i]);
        }
        free(relatorio->diagnosticos);
        free(relatorio);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaRelatorio(void *dado){
    tRelatorio* relatorio = (tRelatorio*) dado;
    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->numPacientes);
    printf("IDADE MEDIA: %.0f +- %.0f\n",relatorio->mediaIdade, relatorio->DesvioPadraoIdade);
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %.0f%%\n", relatorio->distribuicaoFeminino);
    printf("- MASCULINO: %.0f%%\n", relatorio->distribuicaoMasculino);
    printf("- OUTROS: %.0f%%\n",relatorio->distribuicaoOutros);
    printf("TAMANHO MEDIO DAS LESOES: %.0f +- %.0f MM",relatorio->tamMedioLesoes,relatorio->DesvioPadraoLesoes);
    printf("NUMERO TOTAL DE LESOES: %.0f\n", relatorio->numLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %.0f (%.0f%%)\n", relatorio->numCirurgias,relatorio->porcentagemCirurgias);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %.0f (%.0f%%)\n", relatorio->numCrioterapias,relatorio->porcentagemCrioterapias);
    printf("DISTRIBUICAO POR DIAGNOSTICO:\n");
    for(int i=0; i<relatorio->numDiagnosticos;i++){
        tDiagnostico* diagnosticoAtual= relatorio->diagnosticos[i];
        if(diagnosticoAtual->qtd){
            printf("- %s: %.0f (%.0f%%)\n",diagnosticoAtual->nomeDiagnostico ,
            diagnosticoAtual->qtd,diagnosticoAtual->qtd/(float)relatorio->numDiagnosticos);
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
void imprimeEmArquivoRelatorio(void *dado, char *path){
    FILE *arquivo;
    tRelatorio *relatorio = (tRelatorio *)dado;

    // Abre o arquivo para escrita
    char endereco[200];
    strncpy(endereco,path,sizeof(endereco)-1);
    strcat(endereco,"/relatorio_geral.txt");
    arquivo = fopen(endereco, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo relatorio_geral.txt\n");
        return 1;
    }

    fprintf(arquivo, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->numPacientes);
    fprintf(arquivo, "IDADE MEDIA: %.0f +- %.0f\n", relatorio->mediaIdade, relatorio->DesvioPadraoIdade);
    fprintf(arquivo, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arquivo, "- FEMININO: %.0f%%\n", relatorio->distribuicaoFeminino);
    fprintf(arquivo, "- MASCULINO: %.0f%%\n", relatorio->distribuicaoMasculino);
    fprintf(arquivo, "- OUTROS: %.0f%%\n", relatorio->distribuicaoOutros);
    fprintf(arquivo, "TAMANHO MEDIO DAS LESOES: %.0f +- %.0f MM\n", relatorio->tamMedioLesoes, relatorio->DesvioPadraoLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE LESOES: %.0f\n", relatorio->numLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE CIRURGIAS: %.0f (%.0f%%)\n", relatorio->numCirurgias, relatorio->porcentagemCirurgias);
    fprintf(arquivo, "NUMERO TOTAL DE CRIOTERAPIA: %.0f (%.0f%%)\n", relatorio->numCrioterapias, relatorio->porcentagemCrioterapias);
    fprintf(arquivo, "DISTRIBUICAO POR DIAGNOSTICO:\n");
    
    for (int i = 0; i < relatorio->numDiagnosticos; i++) {
        tDiagnostico *diagnosticoAtual = relatorio->diagnosticos[i];
        if (diagnosticoAtual->qtd) {
            fprintf(arquivo, "- %s: %.0f (%.0f%%)\n", diagnosticoAtual->nomeDiagnostico,
                    diagnosticoAtual->qtd, diagnosticoAtual->qtd / (float)relatorio->numDiagnosticos);
        }
    }
    fclose(arquivo);
}