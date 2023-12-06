
#include "tPaciente.h"

struct paciente
{
    char nomeCompleto[101];  // Nome completo (string com no máximo 100 caracteres)
    char cpf[15];            // CPF (no formato: 000.000.000-00)
    char dataNascimento[11]; // Data de nascimento (seguindo padrão dd/mm/aaaa)
    char telefone[15];       // Telefone (formato: (00)00000-0000)
    char genero[10];         // Gênero (masculino, feminino, outros)
    int diabetes;            // 1 e SIM e 0 e NAO
    int fumante;             // 1 e SIM e 0 e NAO
    int alergiaMedicamento;  // 1 e SIM e 0 e NAO
    int historicoCancer;     // 1 e SIM e 0 e NAO
    char tipoPele[5];        // I, II, III, IV, V, VI
    int atendido;
};

int obtemEhAtendido(tPaciente *paciente)
{
    return paciente->atendido;
}
void AtendePaciente(tPaciente *paciente)
{
    paciente->atendido = 1;
}




int obtemTamTPaciente()
{
    return sizeof(tPaciente);
}


// Função para inicializar um paciente
tPaciente *criaPaciente()
{
    tPaciente *paciente = (tPaciente *)calloc(1, sizeof(tPaciente));
    if (paciente == NULL)
    {
        printf("Erro ao alocar memória para o paciente.\n");
        exit(EXIT_FAILURE);
    }

    return paciente;
}

// Função para liberar a memória alocada para um paciente
void liberaPaciente(tPaciente *paciente)
{
    if (paciente != NULL)
    {
        free(paciente);
    }
}

// Funçao que Le o paciente

void lePaciente(tPaciente *paciente)
{
    printf("NOME COMPLETO: ");
    scanf("%100[^\n]%*c", paciente->nomeCompleto);
    converterParaMaiuscula(paciente->nomeCompleto);

    printf("CPF: ");
    scanf("%14[^\n]%*c", paciente->cpf);
    converterParaMaiuscula(paciente->cpf);

    printf("DATA DE NASCIMENTO: ");
    scanf("%10[^\n]%*c", paciente->dataNascimento);
    converterParaMaiuscula(paciente->dataNascimento);

    printf(" TELEFONE: ");
    scanf("%14[^\n]%*c", paciente->telefone);
    converterParaMaiuscula(paciente->telefone);

    printf("GENERO: ");
    scanf("%9[^\n]%*c", paciente->genero);
    converterParaMaiuscula(paciente->genero);
}

// na clinica o tamanho começa com zero



// retorna o indice do paciente;

int EhCadastradoPaciente(tPaciente **vetor, char *cpf, int tam)
{
    for (int i = 0; i < tam; i++)
    {

        if (strcmp(vetor[i]->cpf, cpf) == 0)
        {
            return i;
        }
    }
    return -1;
}

char *ObtemCpfPaciente(tPaciente *paciente)
{
    return paciente->cpf;
}
char *ObtemNomePaciente(tPaciente *paciente)
{
    return paciente->nomeCompleto;
}

char *ObtemDataPaciente(tPaciente *paciente)
{

    return paciente->dataNascimento;
}

char *ObtemGeneroPaciente(tPaciente *paciente)
{
    return paciente->genero;
}
char *ObtemTelefonePaciente(tPaciente *paciente)
{
    return paciente->telefone;
}

int ObtemDiabetesPacientes(tPaciente *paciente)
{
    return paciente->diabetes;
}
int ObtemFumantePaciente(tPaciente *paciente)
{
    return paciente->fumante;
}
int ObtemAlergiaPaciente(tPaciente *paciente)
{
    return paciente->alergiaMedicamento;
}
int ObtemHistoricoCancerPaciente(tPaciente *paciente)
{
    return paciente->historicoCancer;
}

char *ObtemTipoPelePaciente(tPaciente *paciente)
{
    return paciente->tipoPele;
}

char *SimOuNao(int afirmacao)
{
    char *resp = NULL;
    switch (afirmacao)
    {
    case 1:
        resp = "SIM";
        break;
    case 0:
        resp = "NAO";
        break;
    default:
        break;
    }
    return resp;
}

void CompletaDadosPaciente(tPaciente *paciente)
{
    printf("POSSUI DIABETES: ");

    scanf("%d%*c", &paciente->diabetes);

    printf("FUMANTE: ");
  
    scanf("%d%*c", &paciente->fumante);

    printf("ALEGIA A MEDICAMENTO: ");

    scanf("%d%*c", &paciente->alergiaMedicamento);

    printf("HISTORICO DE CANCER: ");

    scanf("%d%*c", &paciente->historicoCancer);

    printf("TIPO DE PELE:\n");
    
    scanf("%4[^\n]%*c", paciente->tipoPele);
}

int comparar_nomes(const void *a, const void *b)
{
    tPaciente *paciente_a = (tPaciente *)a;
    tPaciente *paciente_b = (tPaciente *)b;
    return strcmp(paciente_b->nomeCompleto, (paciente_a->nomeCompleto));
}

tPaciente *ObtemPaciente(tPaciente **pacientes, int index)
{
    return pacientes[index];
}

int CalculaIdade(char *data)
{

    int anoAtual = 2023, mesAtual = 11, diaAtual = 9;
    int ano = 0, mes = 0, dia = 0;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    int idade = anoAtual - ano;

    // Ajusta a idade se a data de nascimento ainda não ocorreu este ano
    if ((mes < mesAtual) || (mes == mesAtual && dia < diaAtual))
    {
        idade--;
    }

    return idade;
}

void DeslocaPaciente(tPaciente *paciente)
{
    if (paciente)
    {
        free(paciente);
    }
}

tPaciente *copiaPaciente(tPaciente *paciente)
{
    tPaciente *copia = criaPaciente();

    if (copia == NULL)
    {
        perror("Erro ao alocar memória para o paciente copiado");
        exit(EXIT_FAILURE);
    }

    // Copia os campos do paciente original para a cópia
    strcpy(copia->nomeCompleto, paciente->nomeCompleto);
    strcpy(copia->cpf, paciente->cpf);
    strcpy(copia->dataNascimento, paciente->dataNascimento);
    strcpy(copia->telefone, paciente->telefone);
    strcpy(copia->genero, paciente->genero);
    copia->diabetes = paciente->diabetes;
    copia->fumante = paciente->fumante;
    copia->alergiaMedicamento = paciente->alergiaMedicamento;
    copia->historicoCancer = paciente->historicoCancer;
    strcpy(copia->tipoPele, paciente->tipoPele);
   

    // CopiaLesoes
    return copia;
}




int JaTemPacientesLista(tPaciente **lista, tPaciente *paciente, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        if (paciente == lista[i])
            return 1;
    }
    return 0;
}
tPaciente** adcionaPacienteLista( tPaciente** vetor, tPaciente *paciente, int tam)
{

    // Realocar o vetor de pacientes para acomodar o novo tamanho
    vetor = (tPaciente **)realloc(vetor, (tam) * sizeof(tPaciente *));


    // Verificar se a realocação foi bem-sucedida
    if ( vetor== NULL)
    {
        printf("Erro ao realocar memória para o vetor de pacientes.\n");
        exit(EXIT_FAILURE);
    }

    // Inserir Paciente
    vetor[tam-1] = paciente;
    return vetor;
}


tPaciente **BuscaPacientes(tPaciente **vetorPacientes, int tamPacientes, char *nome, int *tamLista)
{

    tPaciente **lista = (tPaciente **)calloc(1, sizeof(tPaciente *));

    if (lista == NULL)
    {
        printf("Erro ao alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    int peloMenosUmPaciente = 0;

    // nome

    for (int i = 0; i < tamPacientes; i++)
    {
        tPaciente *pacienteAtual = vetorPacientes[i];
        if (strcmp(nome, ObtemNomePaciente(pacienteAtual)) == 0 &&
            !JaTemPacientesLista(lista, pacienteAtual, *tamLista))
        {
            peloMenosUmPaciente = 1;
            (*tamLista)++;
            lista  = adcionaPacienteLista(lista, pacienteAtual, *tamLista);
        }
    }

    if(peloMenosUmPaciente == 0){
        return NULL;
    }

    return lista;
}

