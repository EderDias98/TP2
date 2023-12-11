#include <stdio.h>
#include <stdlib.h>
#include "tClinica.h"
#include "tRelatorio.h"
#include "tFila.h"
#include "tLista_busca.h"
#define TAM_CAMINHO 300

void MostrarMenu(Nivel acesso)
{
    switch (acesso)
    {
    case USER:
        printf("####################### MENU PRINCIPAL #########################\n");

        printf("ESCOLHA UMA OPCAO:\n");

        printf("    (2) CADASTRAR MEDICO\n");

        printf("    (3) CADASTRAR PACIENTE\n");

        printf("    (5) BUSCAR PACIENTES\n");

        printf("    (6) RELATORIO GERAL\n");

        printf("    (7) FILA DE IMPRESSAO\n");

        printf("    (8) FINALIZAR O PROGRAMA\n");

        printf("###############################################################\n");

        break;
    case ADMIN:
        printf("####################### MENU PRINCIPAL #########################\n");

        printf("ESCOLHA UMA OPCAO:\n");

        printf("    (1) CADASTRAR SECRETARIO\n");

        printf("    (2) CADASTRAR MEDICO\n");

        printf("    (3) CADASTRAR PACIENTE\n");

        printf("    (4) REALIZAR CONSULTA\n");

        printf("    (5) BUSCAR PACIENTES\n");

        printf("    (6) RELATORIO GERAL\n");

        printf("    (7) FILA DE IMPRESSAO\n");

        printf("    (8) FINALIZAR O PROGRAMA\n");

        printf("###############################################################\n");

        break;
    case MEDI:
        printf("####################### MENU PRINCIPAL #########################\n");

        printf("    ESCOLHA UMA OPCAO:\n");

        printf("    (4) REALIZAR CONSULTA\n");

        printf("    (5) BUSCAR PACIENTES\n");

        printf("    (6) RELATORIO GERAL\n");

        printf("    (7) FILA DE IMPRESSAO\n");

        printf("    (8) FINALIZAR O PROGRAMA\n");

        printf("###############################################################\n");

        break;
    default:
        break;
    }
}

// EhOpcaoCorreta(Nivel acesso, int funcionalidade)
// {
// }
// secretarios.bin
// ● medicos.bin
// ● pacientes.bin
// ● consultas.bin
// ● lesoes.bin
// ● fila_impressao.bin

int ArquivoBinarioExiste(char *path, char *nome, char *pathBin)
{

    strcat(pathBin, path);
    strcat(pathBin, nome);

    FILE *arquivo = fopen(pathBin, "rb");

    if (arquivo == NULL)
    {

        return 0;
    }

    fclose(arquivo);
    return 1;
}

void ConfigurarArquivosBinarios(char *path, int *sec, int *med, int *pac, int *cons, int *les, tClinica *clinica)
{
    char pathBin[200] = {'\0'};

    if (ArquivoBinarioExiste(path, "/secretarios.bin", pathBin) == 0)
    {

        FILE *arquivo = fopen(pathBin, "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o secretarios.bin %s\n", pathBin);
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *sec = 1;
    }
    memset(pathBin, '\0', sizeof(pathBin));

    if (ArquivoBinarioExiste(path, "/medicos.bin", pathBin) == 0)
    {

        FILE *arquivo = fopen(pathBin, "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o medicos.bin\n");
            exit(-1);
        }

        fclose(arquivo);
    }
    else
    {
        *med = 1;
    }

    memset(pathBin, '\0', sizeof(pathBin));

    if (ArquivoBinarioExiste(path, "/pacientes.bin", pathBin) == 0)
    {

        FILE *arquivo = fopen(pathBin, "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o pacientes.bin\n");
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *pac = 1;
    }

    memset(pathBin, '\0', sizeof(pathBin));

    if (ArquivoBinarioExiste(path, "/consultas.bin", pathBin) == 0)
    {

        FILE *arquivo = fopen(pathBin, "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o consultas.bin\n");
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *cons = 1;
    }

    memset(pathBin, '\0', sizeof(pathBin));

    if (ArquivoBinarioExiste(path, "/lesoes.bin", pathBin) == 0)
    {

        FILE *arquivo = fopen(pathBin, "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o lesoes.bin\n");
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *les = 1;
    }

    memset(pathBin, '\0', sizeof(pathBin));
}
// secretarios.bin
// ● medicos.bin
// ● pacientes.bin
// ● consultas.bin
// ● lesoes.bin
// ● fila_impressao.bin
// ~/TP2/bancoDeDados
int main(int argc, char *argv[])
{

    printf("################################################\n");

    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");

    printf("################################################\n");

    char pathA[TAM_CAMINHO]= {'\0'};
    // strcat(pathA,argv[1]);

    char pathSaida[TAM_CAMINHO]= {'\0'};
    char path[TAM_CAMINHO]= {'\0'};

    char pathBancoDados[TAM_CAMINHO]= {'\0'};
    scanf("%[^\n]%*c", path);
    
    strcat(pathBancoDados,pathA);
    strcat(pathBancoDados,path);

    strcat(pathSaida,pathA);
    strcat(pathSaida,"./saida");

    // printf("Caminho do banco de dados: %s\n", pathBancoDados);
    // printf("Caminho da pasta de saida: %s\n", pathSaida);
   


    // se o binário existir é porque já existe um banco de dados para a
    // entidade se não vc ira cria-lo dentro do diretório informado
    tClinica *clinica = criaClinica();
    InicializaClinicaVetores(clinica);
    int sec = 0, med = 0, pac = 0, cons = 0, les = 0;
    char pathSec[200] = {'\0'};
    char pathMed[200] = {'\0'};
    char pathPac[200] = {'\0'};
    char pathCons[200] = {'\0'};
    char pathLes[200] = {'\0'};

    strcat(pathSec, pathBancoDados);
    strcat(pathMed, pathBancoDados);
    strcat(pathPac, pathBancoDados);
    strcat(pathCons, pathBancoDados);
    strcat(pathLes, pathBancoDados);

    strcat(pathSec, "/secretarios.bin");
    strcat(pathMed, "/medicos.bin");
    strcat(pathPac, "/pacientes.bin");
    strcat(pathCons, "/consultas.bin");
    strcat(pathLes, "/lesoes.bin");

    ConfigurarArquivosBinarios(pathBancoDados, &sec, &med, &pac, &cons, &les, clinica);

    if (sec == 1)
    {
        LeBinSecretarios(clinica, pathSec);
    }
    if (med == 1)
    {
        LeBinMedicos(clinica, pathMed);
    }
    if (pac == 1)
    {
        LeBinPacientes(clinica, pathPac);
    }
    if (cons == 1)
    {
        LeBinConsultas(clinica, pathCons);
    }
    if (les == 1)
    {
        LeBinLesoes(clinica, pathLes);
    }


    Nivel acesso;
    int indexMedico = 0;
    int indexSecretario = 0;
    while (1)
    {
        char senha[21];
        char usuario[21];

        if (sec == 0 && med == 0)
        {
            CadastraSecretarioClinica(clinica);
            printf("\n######################## ACESSO MINI-SADE ######################\n");

            printf("DIGITE SEU LOGIN: ");

            scanf("%20[^\n]%*c", usuario);
            printf("DIGITE SUA SENHA: ");

            scanf("%20[^\n]%*c", senha);
            printf("\n###############################################################\n");

            converterParaMaiuscula(senha);
            converterParaMaiuscula(usuario);
        }
        else
        {
            printf("\n######################## ACESSO MINI-SADE ######################\n");

            printf("DIGITE SEU LOGIN: ");

            scanf("%20[^\n]%*c", usuario);
            printf("DIGITE SUA SENHA: ");

            scanf("%20[^\n]%*c", senha);
            printf("\n###############################################################\n");

            converterParaMaiuscula(senha);
            converterParaMaiuscula(usuario);
        }

        // definir essa função depois

        Login resultado = comfirmarLogin(clinica, senha, usuario, &acesso, &indexMedico, &indexSecretario);
        if (resultado == CORRETO || acesso == ADMIN)
        {
            break;
        }
        else
        {
            printf(" SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
    }

    int funcionalidade = 0;
    int sairL = 0;
    tFila *fila = criaFila();
    while (1)
    {
        MostrarMenu(acesso);
        scanf("%d%*c", &funcionalidade);

        // fazer um teste pra ver se é possivel a opção, por exemplo um medico acessar a funcionalidade 3 seria um erro
        // pode usar um loop para voltar ao menu para escolher a opcao de novo

        // if (!EhOpcaoCorreta(acesso, funcionalidade))
        //     continue;

        switch (funcionalidade)
        {
        case 1:

            if (CadastraSecretarioClinica(clinica))
            {
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");

                printf("###############################################################\n");

                scanf("%*c%*c");

            }

            break;
        case 2:

            if (CadastraMedicoClinica(clinica))
            {
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");

                printf("###############################################################\n");
                scanf("%*c%*c");
            }

            break;
        case 3:

            if (CadastraPacienteClinica(clinica))
            {
                printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");

                printf("###############################################################\n");
                scanf("%*c%*c");
            }

            break;
        case 4:

            char cpf[15] = {'\0'};
            scanf("%14[^\n]%*c", cpf);
            int indexPaciente = EhCadastradoCLinica(clinica, cpf);

            if (acesso == ADMIN)
            {
                indexMedico = -1;
            }

            if (indexPaciente != -1)
            {

                ConsultaMedica(clinica, indexPaciente, indexMedico, fila);
            }
            else
            {
                printf("#################### CONSULTA MEDICA #######################\n");

                printf("CPF DO PACIENTE: %s\n", cpf);

                printf("PACIENTE SEM CADASTRO\n");

                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");

                printf("############################################################\n");

                scanf("%*c%*c");

                continue;
            }
            break;
        case 5:

            printf("#################### BUSCAR PACIENTES #######################\n");

            printf("NOME DO PACIENTE: ");

            char nome[100] = {'\0'};
            scanf("%99[^\n]%*c", nome);

            int numPacientesLista = 0;
            int numPacientes = obtemNumPacientes(clinica);

            tPaciente **vetorPaciente = obtemVetorPacientes(clinica);
            tPaciente **lista = BuscaPacientes(vetorPaciente, numPacientes,
                                               nome, &numPacientesLista);
            if (lista == NULL)
            {

                printf("#################### BUSCAR PACIENTES #######################\n");

                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");

                printf("############################################################\n");

                scanf("%*c%*c");
                continue;
            }

            tLista *listaBusca = criaListaDeBusca(lista, numPacientesLista);

            int opcao = 0;
            printf("PACIENTES ENCONTRADOS:\n");
            imprimeNaTelaLista(listaBusca);

            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("SELECIONE UMA OPCAO:\n");

            printf("    (1) ENVIAR LISTA PARA IMPRESSAO\n");

            printf("    (2) RETORNAR AO MENU PRINCIPAL\n");

            printf("############################################################\n");

            scanf("%d%*c", &opcao);
            if (opcao == 1)
            {
                insereDocumentoFila(fila, listaBusca, imprimeNaTelaLista, imprimeEmArquivoLista, desalocaLista);
                printf("#################### BUSCAR PACIENTES #######################\n");

                printf("\nLISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");

                printf("############################################################\n");

                scanf("%*c%*c");
            }else{
                desalocaLista(listaBusca);
            }

            break;
        case 6:
            int opcaoA;
            tRelatorio *relatorio = CriaRelatorio(clinica);
            printf("#################### RELATORIO GERAL #######################\n");
            imprimeNaTelaRelatorio(relatorio);
            printf("SELECIONE UMA OPCAO:\n");

            printf("    (1) ENVIAR LISTA PARA IMPRESSAO\n");

            printf("    (2) RETORNAR AO MENU PRINCIPAL\n");

            printf("############################################################\n");
            scanf("%d%*c", &opcaoA);
            if (opcaoA == 1)
            {
                insereDocumentoFila(fila, relatorio, imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorio);
                printf("\nRELATORIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");

                printf("############################################################\n");

                scanf("%*c%*c");
            }else{
                desalocaRelatorio(relatorio);
            }

            break;
        case 7:
            int opcaoF = 0;
            scanf("%d%*c", &opcaoF);
            while (1)
            {
                /* code */
                printf("################### FILA DE IMPRESSAO MEDICA #####################\n");

                printf("ESCOLHA UMA OPCAO:\n");

                printf("    (1) EXECUTAR FILA DE IMPRESSAO\n");

                printf("    (2) RETORNAR AO MENU PRINCIPAL\n");

                printf("############################################################\n");

                if(opcaoF==2){
                    break;
                }
                if (opcaoF == 1)
                {
                    printf("################ FILA DE IMPRESSAO MEDICA ##################\n");

                    printf("EXECUTANDO FILA DE IMPRESSAO:\n");

                    imprimeFila(fila, pathSaida);
                }
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");

                printf("############################################################\n");

                scanf("%*c%*c");
                scanf("%d%*c", &opcaoF);
            }

            break;
        case 8:
            sairL = 1;
            break;

        default:
            break;
        }

        if (sairL)
            break;
    }
    // quarda os dados nos arquivos binarios;

    EscreveBinsecretarios(clinica, pathSec);
    
    EscreveBinMedicos(clinica, pathMed);

    EscreveBinConsultas(clinica, pathCons);

    EscreveBinPacientes(clinica, pathPac);

    EscreveBinLesoes(clinica, pathLes);
    desalocaClinica(clinica);
    desalocaFila(fila);
    return 1;
}
//~/template-TP2-etapa-1/Casos/1