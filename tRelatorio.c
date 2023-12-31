#include "tRelatorio.h"
#include <stdlib.h>
#include <math.h>
struct diagnostico
{
    char nomeDiagnostico[25];
    int qtd;
};

struct relatorio
{

    int numPacientesAtendidos;// Número total de pacientes que possui pelo menos um atendimento
    int mediaIdade;
    int DesvioPadraoIdade; // Média e desvio padrão da idade dos pacientes Utilizando somente a parte inteira
    int distribuicaoFeminino;
    int distribuicaoMasculino;
    int distribuicaoOutros; // Na ordem: feminino, masculino e outros Utilizando somente a parte inteira
    int tamMedioLesoes;
    int DesvioPadraoLesoes; // Utilizando somente a parte inteira
    int numLesoes;
    int numCirurgias;
    int porcentagemCirurgias;
    int numCrioterapias;
    int porcentagemCrioterapias;
    tDiagnostico **diagnosticos;
    int numDiagnosticos;
};
int calculaPacientesAtendidos(tPaciente **pacientes, int numPacientes){
    int soma=0;
    for(int i=0; i<numPacientes;i++){
        if(obtemEhAtendido(ObtemPaciente(pacientes,i))){
            soma++;
        }
    }
    return soma;
}
void calculaEstatisticasIdade(tPaciente **pacientes, int numPacientes, int *media, int *desvioPadrao)
{
    // Cálculo da média
    int somaIdades = 0.0;
    for (int i = 0; i < numPacientes; i++)
    {
        somaIdades += CalculaIdade(ObtemDataPaciente(ObtemPaciente(pacientes, i)));
    }
    *media = somaIdades / numPacientes ;

    // Cálculo do desvio padrão
    int somaDiferencasQuadradas = 0.0;
    for (int i = 0; i < numPacientes; ++i)
    {
        int diferenca = CalculaIdade(ObtemDataPaciente(ObtemPaciente(pacientes, i))) - *media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }
    *desvioPadrao = sqrt(somaDiferencasQuadradas / numPacientes);
}

void calcularDistribuicaoGenero(tPaciente **pacientes, int numPacientes, int *masculino, int *feminino, int *outros)
{
    *masculino = 0;
    *feminino = 0;
    *outros = 0;

    for (int i = 0; i < numPacientes; ++i)
    {
        if (strcmp(ObtemGeneroPaciente(ObtemPaciente(pacientes, i)), "MASCULINO") == 0)
        {
            (*masculino)++;
        }
        else if (strcmp(ObtemGeneroPaciente(ObtemPaciente(pacientes, i)), "FEMININO") == 0)
        {
            (*feminino)++;
        }
        else
        {
            (*outros)++;
        }
    }
}
void calculaEstatisticasTamanhoLesoes(tLesoes **vetor, int numLesoes, int *media, int *desvioPadrao)
{
    // Cálculo da média
    int somaTam = 0.0;
    int cont =0;
    for (int i = 0; i < numLesoes; ++i)
    {
        tLesoes *lesoesAtual = obtemLesoes(vetor, i);

        for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++)
        {
            somaTam += ObtemTamanho(obtemLesao(lesoesAtual, j));
            cont++;
        }
    }
    *media =  somaTam / cont;

    // Cálculo do desvio padrão
    int somaDiferencasQuadradas = 0.0;
    for (int i = 0; i < numLesoes; ++i)
    {

        tLesoes *lesoesAtual = obtemLesoes(vetor, i);
        for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++)
        {
            int diferenca = ObtemTamanho(obtemLesao(lesoesAtual, j)) - *media;
            somaDiferencasQuadradas += diferenca * diferenca;
        }
    }
    *desvioPadrao = sqrt(somaDiferencasQuadradas / numLesoes);
}

void calculaEstatisticasProcedimentos(tLesoes **vetor, int numLesoes, int *totalLesoes, int *numCirurgias, int *numCrioterapias)
{
    // Inicializa contadores
    *numCirurgias = 0;
    *numCrioterapias = 0;
    *totalLesoes = 0;

    // Conta o número total de lesões, cirurgias e crioterapias
    for (int i = 0; i < numLesoes; ++i)
    {
        tLesoes *lesoesAtual = obtemLesoes(vetor, i);

        for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++)
        {
            tLesao *lesaoAtual = obtemLesao(lesoesAtual, j);

            // Conta o número total de lesões
            // (você pode adicionar mais lógica para contar cirurgias e crioterapias)
            if (ObtemEnviarCirurgia(lesaoAtual))
            {
                (*numCirurgias)++;
            }

            if (ObtemEnviarCrioterapia(lesaoAtual))
            {
                (*numCrioterapias)++;
            }
            (*totalLesoes)++;
        }
    }
}
tRelatorio *CriaRelatorio(tClinica *clinica)
{
    tRelatorio *relatorio = (tRelatorio *)calloc(1, sizeof(tRelatorio));

    if (relatorio == NULL)
    {
        printf("Erro ao alocar memória para a relatorio\n");
        exit(EXIT_FAILURE);
    }


    tPaciente **vetorPaciente = ObtemPacientes(clinica);
    int numLesoes = ObtemTamVetorLesoes(clinica);
    int numPacientes = ObtemTamPacientes(clinica);
    relatorio->numPacientesAtendidos = calculaPacientesAtendidos(vetorPaciente,numPacientes);
    calculaEstatisticasIdade(vetorPaciente, numPacientes, &relatorio->mediaIdade, &relatorio->DesvioPadraoIdade);

    calcularDistribuicaoGenero(vetorPaciente, numPacientes, &relatorio->distribuicaoMasculino,
                               &relatorio->distribuicaoFeminino, &relatorio->distribuicaoOutros);

    tLesoes **vetorLesoes = ObtemVetor(clinica);
    calculaEstatisticasTamanhoLesoes(vetorLesoes, numLesoes, &relatorio->tamMedioLesoes,
                                     &relatorio->DesvioPadraoLesoes);
    calculaEstatisticasProcedimentos(vetorLesoes, numLesoes, &relatorio->numLesoes,
                                     &relatorio->numCirurgias, &relatorio->numCrioterapias);
    relatorio->porcentagemCirurgias = relatorio->numCirurgias / (int)relatorio->numLesoes;
    relatorio->porcentagemCrioterapias = relatorio->numCrioterapias / (int)relatorio->numLesoes;
    
    // tDiagnostico **vetorDiagnostico = CriaVetorDiagnostico();
    // relatorio->numDiagnosticos = NUM_DIAGONOSTICOS;
    // ContaNumDiagnostico(vetorLesoes,vetorDiagnostico, relatorio->numDiagnosticos, numLesoes);
    // bubbleSort(vetorDiagnostico, relatorio->numDiagnosticos,compararDiagnostico);
    // qsort(vetorDiagnostico,relatorio->numDiagnosticos,sizeof(tDiagnostico*), compararDiagnostico);

    return relatorio;
}

tDiagnostico *CriaDiagnostico(char *nome)
{
    tDiagnostico *diagnostico = (tDiagnostico *)calloc(NUM_DIAGONOSTICOS, sizeof(tDiagnostico));

    if (diagnostico == NULL)
    {
        printf("Erro ao alocar memória para a diagnostico\n");
        exit(EXIT_FAILURE);
    }

    strcpy(diagnostico->nomeDiagnostico, nome);

    return diagnostico;
}

tDiagnostico **CriaVetorDiagnostico()
{
    tDiagnostico **vetor = (tDiagnostico **)calloc(NUM_DIAGONOSTICOS, sizeof(tDiagnostico *));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória para o vetor de diagnosticos\n");
        exit(EXIT_FAILURE);
    }
    vetor[0] = CriaDiagnostico("CARCINOMA BASOCELULAR");
    vetor[1] = CriaDiagnostico("CARCINOMA ESPINOCELULAR");
    vetor[2] = CriaDiagnostico("MELANOMA");
    vetor[3] = CriaDiagnostico("CERATOSE ACTINICA");
    vetor[4] = CriaDiagnostico("NEVO");
    vetor[5] = CriaDiagnostico("CERATOSE SEBORREICA ");
    vetor[6] = CriaDiagnostico("OUTROS");
    return vetor;
}

int compararDiagnostico(const void *a, const void *b)
{
    // Comparação decrescente pela quantidade (qtd)
    const tDiagnostico* dA = (const tDiagnostico*)a;
    const tDiagnostico* dB =  (const tDiagnostico*)b;
    int diferenca = dB->qtd - dA->qtd;

    // Em caso de empate, use a ordem alfabética do nomeDiagnostico
    if (diferenca == 0)
    {
        return strcmp(dA->nomeDiagnostico, dB->nomeDiagnostico);
    }

    return diferenca;
}
void trocar(tDiagnostico **vetor,int j) {
    tDiagnostico *temp = vetor[j];
    vetor[j] = vetor[j+1];
    vetor[j+1] = temp;
}
void bubbleSort(tDiagnostico **arr, int n,  func_ptr_compara comparar) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparar(arr[j], arr[j + 1]) > 0) {
                // Trocar os elementos se estiverem fora de ordem
                trocar(arr,j);
            }
        }
    }
}

void ContaNumDiagnostico(tLesoes **vetor, tDiagnostico **vetorD, int numDiagnostico, int numLesoes)
{
    // Inicializa contadores

    // Conta o número total de lesões, cirurgias e crioterapias

    for (int i = 0; i < numLesoes; ++i)
    {
        tLesoes *lesoesAtual = obtemLesoes(vetor, i);

        for (int j = 0; j < ObtemTamLesoes(lesoesAtual); j++)
        {
            tLesao *lesaoAtual = obtemLesao(lesoesAtual, j);
            char *nomeDiagnostico = ObtemDiagnostico(lesaoAtual);
            for (int k = 0; k < NUM_DIAGONOSTICOS; k++)
            {
                tDiagnostico *diagnosticoAtual = vetorD[k];
                if (strcmp(nomeDiagnostico, diagnosticoAtual->nomeDiagnostico)==0)
                {
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
void desalocaRelatorio(void *dado)
{
    tRelatorio *relatorio = (tRelatorio *)dado;
    if (relatorio)
    {   
        if(relatorio->diagnosticos){
            for (int i = 0; i < relatorio->numDiagnosticos; i++)
            {
            free(relatorio->diagnosticos[i]);
            }

            free(relatorio->diagnosticos);
        }

        free(relatorio);
    }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaRelatorio(void *dado)
{
    tRelatorio *relatorio = (tRelatorio *)dado;

    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->numPacientesAtendidos);
    printf("IDADE MEDIA: %d\n", relatorio->mediaIdade);
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %d\n", relatorio->distribuicaoFeminino);
    printf("- MASCULINO: %d\n", relatorio->distribuicaoMasculino);
    printf("- OUTROS: %d\n", relatorio->distribuicaoOutros);
    printf("TAMANHO MEDIO DAS LESOES: %d\n", relatorio->tamMedioLesoes);
    printf("NUMERO TOTAL DE LESOES: %d\n", relatorio->numLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio->numCirurgias);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", relatorio->numCrioterapias);
    // printf("DISTRIBUICAO POR DIAGNOSTICO:\n");
    // for (int i = 0; i < relatorio->numDiagnosticos; i++)
    // {
    //     tDiagnostico *diagnosticoAtual = relatorio->diagnosticos[i];
    //     if (diagnosticoAtual->qtd)
    //     {
    //         printf("- %s: %d (%.0f%%)\n", diagnosticoAtual->nomeDiagnostico,
    //                diagnosticoAtual->qtd, diagnosticoAtual->qtd / (int)relatorio->numDiagnosticos);
    //     }
    // }
}

/**
 * Função que recebe um ponteiro genérico (que deve conter uma receita) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoRelatorio(void *dado, char *path)
{
    FILE *arquivo;
    tRelatorio *relatorio = (tRelatorio *)dado;

    // Abre o arquivo para escrita
    char endereco[200];
    strncpy(endereco, path, sizeof(endereco) - 1);
    strcat(endereco, "/relatorio_geral.txt");


    static int primeiraVezFuncao = 1;
    if(primeiraVezFuncao){
        arquivo = fopen(endereco, "w");
    }else {
        arquivo = fopen(endereco, "a");
    }

    primeiraVezFuncao =0;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo relatorio_geral.txt\n");
        exit(-1);
    }

    fprintf(arquivo, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio->numPacientesAtendidos);
    fprintf(arquivo, "IDADE MEDIA: %d\n", relatorio->mediaIdade);
    fprintf(arquivo, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arquivo, "- FEMININO: %d\n", relatorio->distribuicaoFeminino);
    fprintf(arquivo, "- MASCULINO: %d\n", relatorio->distribuicaoMasculino);
    fprintf(arquivo, "- OUTROS: %d\n", relatorio->distribuicaoOutros);
    fprintf(arquivo, "TAMANHO MEDIO DAS LESOES: %d\n", relatorio->tamMedioLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE LESOES: %d\n", relatorio->numLesoes);
    fprintf(arquivo, "NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio->numCirurgias);
    fprintf(arquivo, "NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", relatorio->numCrioterapias);
    // fprintf(arquivo, "DISTRIBUICAO POR DIAGNOSTICO:\n");

    // for (int i = 0; i < relatorio->numDiagnosticos; i++)
    // {
    //     tDiagnostico *diagnosticoAtual = relatorio->diagnosticos[i];
    //     if (diagnosticoAtual->qtd)
    //     {
    //         fprintf(arquivo, "- %s: %d (%.0f%%)\n", diagnosticoAtual->nomeDiagnostico,
    //                 diagnosticoAtual->qtd, diagnosticoAtual->qtd / (int)relatorio->numDiagnosticos);
    //     }
    // }
    fclose(arquivo);
}