#include "tLesao.h"

struct lesao
{
    char rotulo[5]; // Rótulo (string com no máximo 5 caracteres seguindo o padrão L1, L2, L3, …, Ln)

    // Diagnóstico clínico
    //  Valores
    //  CARCINOMA
    //  BASOCELULAR,
    //  CARCINOMA
    //  possíveis:
    //  ESPINOCELULAR, MELANOMA, CERATOSE
    //  ACTINICA, NEVO,
    //  CERATOSE SEBORREICA e OUTROS

    char diagnosticoClinico[25];
    // Região do corpo
    // Valores possíveis: FACE, ORELHA, COURO CABELUDO, PEITORAL,
    // DORSO, ABDOME, BRAÇO, ANTEBRAÇO, MÃO, COXA, CANELA, PE e
    // OUTROS
    char regiaoCorpo[11];
    int tamanho;           // Tamanho (inteiro representando o tamanho em milímetros)
    int enviarCirurgia;    // Se a lesão deve ser enviada para cirurgia (inteiro assumindo 1 ou 0)
    int enviarCrioterapia; // Se a lesão deve ser enviada para crioterapia (inteiro assumindo 1 ou 0)
};

struct lesoes
{
    tLesao **vetor;
    int indexPaciente;
    int tam;
};

void EscreveBinLesaoVetor(tLesoes *lesoes, FILE *arquivo)
{
    // Escrever o número de lesões no arquivo

    // Loop para escrever cada lesão no arquivo
    for (int i = 0; i < lesoes->tam; i++)
    {
        // Escrever os dados da lesão no arquivo
        fwrite(lesoes->vetor[i], obtemTamTLesao(), 1, arquivo);
    }
}

void LeBinLesaoVetor(tLesoes *lesoes, FILE *arquivo, int tam)
{

    // Realocar o vetor de lesões na estrutura tLesoes
    if (tam != 0)
        lesoes->vetor = (tLesao **)malloc(sizeof(tLesao *) * tam);

    if (lesoes->vetor == NULL)
    {
        printf("Erro ao realocar memória para lesões\n");
        exit(-1);
    }

    // Loop para ler cada lesão do arquivo
    for (int i = 0; i < tam; i++)
    {
        // Alocar memória para a lesão atual
        lesoes->vetor[i] = (tLesao *)calloc(1, obtemTamTLesao());

        // Ler os dados da lesão do arquivo
        fread(lesoes->vetor[i], obtemTamTLesao(), 1, arquivo);
    }

    // Fechar o arquivo
}

void desalocaLesoes(tLesoes *lesoes)
{
    if (lesoes)
    {
        if (lesoes->vetor)
        {
            for (int i = 0; i < lesoes->tam; i++)
            {
                desalocaLesao(lesoes->vetor[i]);
            }
        }

        free(lesoes->vetor);
        free(lesoes);
    }
}

tLesoes **copiaVetorLesoes(tLesoes **vetor, int tam)
{
    tLesoes **vetorLesoes = (tLesoes **)calloc(1, sizeof(tLesoes *) * tam);
    if (vetorLesoes == NULL)
    {
        printf("Erro ao alocar tLesoes**\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < tam; i++)
    {
        vetorLesoes[i] = CopiaLesoes(vetor[i]);
    }
    return vetorLesoes;
}

tLesoes *CopiaLesoes(tLesoes *lesoes)
{
    tLesoes *CopiaLesoes = (tLesoes *)calloc(1, sizeof(tLesoes));
    CopiaLesoes->vetor = (tLesao **)calloc(lesoes->tam, sizeof(tLesao *));
    for (int i = 0; i < lesoes->tam; i++)
    {
        CopiaLesoes->vetor[i] = copiaLesao(lesoes->vetor[i]);
    }
    CopiaLesoes->tam = lesoes->tam;
    CopiaLesoes->indexPaciente = lesoes->indexPaciente;
    return CopiaLesoes;
}

tLesao *copiaLesao(tLesao *lesao)
{
    tLesao *copiaLesao = criaLesao();
    strcpy(copiaLesao->diagnosticoClinico, lesao->diagnosticoClinico);
    copiaLesao->enviarCirurgia = lesao->enviarCirurgia;
    copiaLesao->enviarCrioterapia = lesao->enviarCrioterapia;
    strcpy(copiaLesao->regiaoCorpo, lesao->regiaoCorpo);
    strcpy(copiaLesao->rotulo, lesao->rotulo);
    copiaLesao->tamanho = lesao->tamanho;
    return copiaLesao;
}

int obtemTamTLesao()
{
    return sizeof(tLesao);
}
int obtemTamTLesoes()
{
    return sizeof(tLesoes);
}
void DefineLesoesBin(tLesoes *lesoes, int indexPaciente, int tam)
{
    lesoes->indexPaciente = indexPaciente;
    lesoes->tam = tam;
}

char *ObtemRotulo(tLesao *lesao)
{
    return lesao->rotulo;
}
// Função para obter o diagnóstico clínico da lesão
char *ObtemDiagnosticoClinico(tLesao *lesao)
{
    return lesao->diagnosticoClinico;
}

// Função para obter a região do corpo da lesão
char *ObtemRegiaoCorpo(tLesao *lesao)
{
    return lesao->regiaoCorpo;
}

// Função para obter o tamanho da lesão
int ObtemTamanho(tLesao *lesao)
{
    return lesao->tamanho;
}

// Função para obter se a lesão deve ser enviada para cirurgia
int ObtemEnviarCirurgia(tLesao *lesao)
{
    return lesao->enviarCirurgia;
}

// Função para obter se a lesão deve ser enviada para crioterapia
int ObtemEnviarCrioterapia(tLesao *lesao)
{
    return lesao->enviarCrioterapia;
}

int ObtemIndexPacienteLesoes(tLesoes *lesoes)
{
    return lesoes->indexPaciente;
}

tLesao *criaLesao()
{
    tLesao *lesao = (tLesao *)calloc(1, sizeof(tLesao));
    if (lesao == NULL)
    {
        printf("Erro ao alocar memória para o lesao.\n");
        exit(EXIT_FAILURE);
    }
    return lesao;
}

// Função para liberar a memória alocada para um lesao
void desalocaLesao(tLesao *lesao)
{
    if (lesao)
    {
        free(lesao);
    }
}

// Funçao que Le o lesao

void leLesao(tLesao *lesao)
{
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%23[^\n]%*c", lesao->diagnosticoClinico);

    printf("REGIAO DO CORPO: ");
    scanf("%10[^\n]%*c", lesao->regiaoCorpo);

    printf("TAMANHO: ");
    scanf("%d%*c", &lesao->tamanho);

    printf("ENVIAR PARA CIRURGIA: ");
    scanf("%d%*c", &lesao->enviarCirurgia);

    printf("ENVIAR PARA CRIOTERAPIA:\n");
    scanf("%d%*c", &lesao->enviarCrioterapia);
}

// na clinica o tamanho começa com zero

void adcionaLesao(tLesoes *lesoes, tLesao *lesao)
{

    lesoes->tam++;
    int tam = lesoes->tam;
    // Realocar o vetor de pacientes para acomodar o novo tamanho
    lesoes->vetor = (tLesao **)realloc(lesoes->vetor, (tam) * sizeof(tLesao *));

    // Verificar se a realocação foi bem-sucedida
    if (lesoes->vetor == NULL)
    {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    // Inserir Paciente
    lesoes->vetor[tam - 1] = lesao;
}

tLesoes *CriaLesoes()
{
    tLesoes *lesoes = (tLesoes *)calloc(1, sizeof(tLesoes));
    if (lesoes == NULL)
    {
        printf("Erro ao alocar memória para o lesoes.\n");
        exit(EXIT_FAILURE);
    }
    lesoes->vetor = (tLesao **)calloc(1, sizeof(tLesao *));

    if (lesoes->vetor == NULL)
    {
        printf("Erro ao alocar memória para o lesoes->vetor .\n");
        exit(EXIT_FAILURE);
    }
    return lesoes;
}

void defineIndexPacienteLesoes(tLesoes *lesoes, int indexPaciente)
{
    lesoes->indexPaciente = indexPaciente;
}
void CadastraLesao(tLesoes *lesoes, tLesao *lesao)
{

    static int i = 1;
    sprintf(lesao->rotulo, "L%d", i);
    i++;
    adcionaLesao(lesoes, lesao);
};

void IncrementaTamLesoes(tLesoes *lesoes)
{
    lesoes->tam++;
}

tLesao **ObtemVetorLesoes(tLesoes *lesoes)
{
    return lesoes->vetor;
}

int ObtemTamLesoes(tLesoes *lesoes)
{
    return lesoes->tam;
}

char *ObtemDiagnostico(tLesao *lesao)
{
    return lesao->diagnosticoClinico;
}

tLesao *obtemLesao(tLesoes *lesoes, int index)
{
    return lesoes->vetor[index];
}

int QtdEnvidasCirurgia(tLesoes **vetor, int tam)
{
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {

        for (int j = 0; j < ObtemTamLesoes(vetor[i]); j++)
        {

            soma += ObtemEnviarCirurgia(vetor[i]->vetor[j]);
        }
    }
    return soma;
}
int QtdEnvidasCrioterapia(tLesoes **vetor, int tam)
{
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {

        for (int j = 0; j < ObtemTamLesoes(vetor[i]); j++)
        {

            soma += ObtemEnviarCrioterapia(vetor[i]->vetor[j]);
        }
    }
    return soma;
}

char *EnviadaOnde(tLesao *lesao)
{
    if (lesao->enviarCirurgia)
        return "ENVIADA PARA CIRURGIA";
    else
        return "ENVIADA PARA CRIOTERAPIA";
}

int calculaNumLesao(tLesoes **vetor, int numLesoes)
{
    int soma = 0;
    for (int i = 0; i < numLesoes; i++)
    {
        soma += vetor[i]->tam;
    }
    return soma;
}

tLesoes *obtemLesoes(tLesoes **vetor, int index)
{
    return vetor[index];
}

int NaoTemLesaoCirurgia(tLesoes *lesoes)
{
    for (int i = 0; i < lesoes->tam; i++)
    {
        if (lesoes->vetor[i]->enviarCirurgia == 1)
        {
            return 0;
        }
    }
    return 1;
}
