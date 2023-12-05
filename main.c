#include <stdio.h>
#include <stdlib.h>
#include "tClinica.h"
#include "tRelatorio.h"
#include "tFila.h"
#include "tLista_busca.h"
#define TAM_CAMINHO 300

void MostrarMenu(Nivel acesso, FILE* arquivoSaida)
{
    switch (acesso)
    {
    case USER:
        printf("####################### MENU PRINCIPAL #########################\n");
        fprintf(arquivoSaida,"####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        fprintf(arquivoSaida,"ESCOLHA UMA OPCAO:\n");
        printf("(2) CADASTRAR MEDICO\n");
        fprintf(arquivoSaida,"(2) CADASTRAR MEDICO\n");
        printf("(3) CADASTRAR PACIENTE\n");
        fprintf(arquivoSaida,"(3) CADASTRAR PACIENTE\n");
        printf("(5) BUSCAR PACIENTES\n");
        fprintf(arquivoSaida,"(5) BUSCAR PACIENTES\n");
        printf("(6) RELATORIO GERAL\n");
        fprintf(arquivoSaida,"(6) RELATORIO GERAL\n");
        printf("(7) FILA DE IMPRESSAO\n");
        fprintf(arquivoSaida,"(7) FILA DE IMPRESSAO\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
        fprintf(arquivoSaida,"(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");
        fprintf(arquivoSaida,"###############################################################\n");

        break;
    case ADMIN:
        printf("####################### MENU PRINCIPAL #########################\n");
        fprintf(arquivoSaida,"####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        fprintf(arquivoSaida,"ESCOLHA UMA OPCAO:\n");
        printf("(1) CADASTRAR SECRETARIO\n");
        fprintf(arquivoSaida,"(1) CADASTRAR SECRETARIO\n");
        printf("(2) CADASTRAR MEDICO\n");
        fprintf(arquivoSaida,"(2) CADASTRAR MEDICO\n");
        printf("(3) CADASTRAR PACIENTE\n");
        fprintf(arquivoSaida,"(3) CADASTRAR PACIENTE\n");
        printf("(4) REALIZAR CONSULTA\n");
        fprintf(arquivoSaida,"(4) REALIZAR CONSULTA\n");
        printf("(5) BUSCAR PACIENTES\n");
        fprintf(arquivoSaida,"(5) BUSCAR PACIENTES\n");
        printf("(6) RELATORIO GERAL\n");
        fprintf(arquivoSaida,"(6) RELATORIO GERAL\n");
        printf("(7) FILA DE IMPRESSAO\n");
        fprintf(arquivoSaida,"(7) FILA DE IMPRESSAO\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
        fprintf(arquivoSaida,"(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");
        fprintf(arquivoSaida,"###############################################################\n");
        break;
    case MEDI:
        printf("####################### MENU PRINCIPAL #########################\n");
        fprintf(arquivoSaida,"####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        fprintf(arquivoSaida,"ESCOLHA UMA OPCAO:\n");
        printf("(4) REALIZAR CONSULTA\n");
        fprintf(arquivoSaida,"(4) REALIZAR CONSULTA\n");
        printf("(5) BUSCAR PACIENTES\n");
        fprintf(arquivoSaida,"(5) BUSCAR PACIENTES\n");
        printf("(6) RELATORIO GERAL\n");
        fprintf(arquivoSaida,"(6) RELATORIO GERAL\n");
        printf("(7) FILA DE IMPRESSAO\n");
        fprintf(arquivoSaida,"(7) FILA DE IMPRESSAO\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
        fprintf(arquivoSaida,"(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");
        fprintf(arquivoSaida,"###############################################################\n");
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
        printf("O arquivo %s ainda nao existe\n", nome);

        return 0;
    }

    fclose(arquivo);
    return 1;
}

void ConfigurarArquivosBinarios(char *path, int *sec, int *med, int *pac, int *cons, int *les, tClinica *clinica)
{
    char pathBin[200] = {'\0'};
    int tamVetor;
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
int main(int argc, int *argv[])
{

    FILE* arquivoSaida = fopen("./saida.txt","w");

    printf("################################################\n");
    fprintf(arquivoSaida,"################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    fprintf(arquivoSaida,"DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    printf("################################################\n");
    fprintf(arquivoSaida,"################################################\n");

    char pathBancoDados[TAM_CAMINHO];
    scanf("%[^\n]%*c", pathBancoDados);

    // se o binário existir é porque já existe um banco de dados para a
    // entidade se não vc ira cria-lo dentro do diretório informado
    tClinica *clinica = criaClinica();
    InicializaClinicaVetores(clinica);
    int sec = 0, med = 0, pac = 0, cons = 0, les = 0, fil = 0;
    char pathSec[200] = {'\0'};
    char pathMed[200] = {'\0'};
    char pathPac[200] = {'\0'};
    char pathCons[200] = {'\0'};
    char pathLes[200] = {'\0'};
    char pathFil[200] = {'\0'};
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

    int sair = 0;
    Nivel acesso;
    int indexMedico = 0;
    int indexSecretario = 0;
    while (1)
    {
        char senha[21];
        char usuario[21];
        printf("######################## ACESSO MINI-SADE ######################\n");
        fprintf(arquivoSaida,"######################## ACESSO MINI-SADE ######################\n");
        printf("DIGITE SEU LOGIN:");
        fprintf(arquivoSaida,"DIGITE SEU LOGIN:");
        scanf("%20[^\n]%*c", usuario);
        printf("\nDIGITE SUA SENHA:");
        fprintf(arquivoSaida,"\nDIGITE SUA SENHA:");
        scanf("%20[^\n]%*c", senha);
        printf("\n###############################################################\n");
        fprintf(arquivoSaida,"\n###############################################################\n");
        converterParaMaiuscula(senha);
        converterParaMaiuscula(usuario);
        // definir essa função depois

        Login resultado = comfirmarLogin(clinica, senha, usuario, &acesso, &indexMedico, &indexSecretario);
        if (resultado == CORRETO || acesso == ADMIN)
        {
            break;
        }
        else
        {
            printf(" SENHA INCORRETA OU USUARIO INEXISTENTE\n");
            fprintf(arquivoSaida," SENHA INCORRETA OU USUARIO INEXISTENTE\n");
        }
    }

    int funcionalidade = 0;
    int sairL = 0;
    tFila *fila = criaFila();
    while (1)
    {
        MostrarMenu(acesso, arquivoSaida);
        scanf("%d%*c", &funcionalidade);

        // fazer um teste pra ver se é possivel a opção, por exemplo um medico acessar a funcionalidade 3 seria um erro
        // pode usar um loop para voltar ao menu para escolher a opcao de novo

        // if (!EhOpcaoCorreta(acesso, funcionalidade))
        //     continue;

        switch (funcionalidade)
        {
        case 1:
            printf("#################### CADASTRO SECRETARIO #######################\n");
            fprintf(arquivoSaida,"#################### CADASTRO SECRETARIO #######################\n");
            if (CadastraSecretarioClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                fprintf(arquivoSaida,"CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                fprintf(arquivoSaida,"VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
                fprintf(arquivoSaida,"###############################################################");
            }

            scanf("%*c%*c");
            break;
        case 2:
            printf("#################### CADASTRO MEDICO #######################\n");
            fprintf(arquivoSaida,"#################### CADASTRO MEDICO #######################\n");
            if (CadastraMedicoClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                fprintf(arquivoSaida,"CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                fprintf(arquivoSaida,"VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
                fprintf(arquivoSaida,"###############################################################");
            }
            scanf("%*c%*c");
            break;
        case 3:
            printf("#################### CADASTRO PACIENTE #######################\n");
            fprintf(arquivoSaida,"#################### CADASTRO PACIENTE #######################\n");
            if (CadastraPacienteClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                fprintf(arquivoSaida,"CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                fprintf(arquivoSaida,"VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
                fprintf(arquivoSaida,"###############################################################");
            }
            scanf("%*c%*c");
            break;
        case 4:
            printf("#################### CONSULTA MEDICA #######################\n");
            fprintf(arquivoSaida,"#################### CONSULTA MEDICA #######################\n");
            printf("CPF DO PACIENTE:\n");
            fprintf(arquivoSaida,"CPF DO PACIENTE:\n");
            printf("############################################################\n");
            fprintf(arquivoSaida,"############################################################\n");
            char cpf[15] = {'\0'};
            scanf("%14[^\n]%*c", cpf);
            int indexPaciente = EhCadastradoCLinica(clinica, cpf);

            if (acesso == ADMIN)
            {
                indexMedico = -1;
            }

            if (indexPaciente != -1)
            {

                ConsultaMedica(clinica, indexPaciente, indexMedico, fila, arquivoSaida);
            }
            else
            {
                printf("#################### CONSULTA MEDICA #######################\n");
                fprintf(arquivoSaida,"#################### CONSULTA MEDICA #######################\n");
                printf("CPF DO PACIENTE: %s\n", cpf);
                fprintf(arquivoSaida,"CPF DO PACIENTE: %s\n", cpf);
                printf("PACIENTE SEM CADASTRO\n");
                fprintf(arquivoSaida,"PACIENTE SEM CADASTRO\n");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                fprintf(arquivoSaida,"PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                printf("############################################################\n");
                fprintf(arquivoSaida,"############################################################\n");
                scanf("%*c%*c");
                
                continue;
            }
            break;
        case 5:

            printf("#################### BUSCAR PACIENTES #######################\n");
            fprintf(arquivoSaida,"#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: \n");
            fprintf(arquivoSaida,"NOME DO PACIENTE: \n");
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
                fprintf(arquivoSaida,"#################### BUSCAR PACIENTES #######################\n");
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA\n");
                fprintf(arquivoSaida,"NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU ANTERIOR\n");
                fprintf(arquivoSaida,"RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                fprintf(arquivoSaida,"############################################################\n");
                scanf("%*c%*c");
                continue;
            }

            tLista *listaBusca = criaListaDeBusca(lista, numPacientesLista);

            int opcao = 0;

            imprimeNaTelaLista(listaBusca);

            printf("\nSELECIONE UMA OPÇÃO:\n");
            fprintf(arquivoSaida,"\nSELECIONE UMA OPÇÃO:\n");
            printf("(1) ENVIAR LISTA PARA IMPRESSAO\n");
            fprintf(arquivoSaida,"(1) ENVIAR LISTA PARA IMPRESSAO\n");
            printf("(2) RETORNAR AO MENU PRINCIPAL\n");
            fprintf(arquivoSaida,"(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
            fprintf(arquivoSaida,"############################################################\n");
            scanf("%d%*c", &opcao);
            if (opcao == 1)
            {
                insereDocumentoFila(fila, listaBusca, imprimeNaTelaLista, imprimeEmArquivoLista, desalocaLista);
                printf(" #################### BUSCAR PACIENTES #######################\n");
                fprintf(arquivoSaida," #################### BUSCAR PACIENTES #######################\n");
                printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                fprintf(arquivoSaida,"LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU PRINCIPAL\n");
                fprintf(arquivoSaida,"RETORNAR AO MENU PRINCIPAL\n");
                printf("############################################################\n");
                fprintf(arquivoSaida,"############################################################\n");
                scanf("%*c%*c");
            }

            break;
        case 6:
            int opcaoA;
            tRelatorio *relatorio = CriaRelatorio(clinica);
            imprimeNaTelaRelatorio(relatorio);
            scanf("%d%*c", &opcaoA);
            if (opcaoA == 1)
            {   
                insereDocumentoFila(fila,relatorio,imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio,desalocaRelatorio);
                printf("RELATORIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                fprintf(arquivoSaida,"RELATORIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
            
                printf("############################################################\n");
                fprintf(arquivoSaida,"############################################################\n");
                scanf("%*c%*c");
            }

            break;
        case 7:
            printf("################### FILA DE IMPRESSAO MEDICA #####################\n");
            fprintf(arquivoSaida,"################### FILA DE IMPRESSAO MEDICA #####################\n");
            printf("ESCOLHA UMA OPCAO:\n");
            fprintf(arquivoSaida,"ESCOLHA UMA OPCAO:\n");
            printf("(1) EXECUTAR FILA DE IMPRESSAO\n");
            fprintf(arquivoSaida,"(1) EXECUTAR FILA DE IMPRESSAO\n");
            printf("(2) RETORNAR AO MENU PRINCIPAL\n");
            fprintf(arquivoSaida,"(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
            fprintf(arquivoSaida,"############################################################\n");
            int opcaoF=0;
            scanf("%d%*c", &opcaoF);
            if (opcaoF == 1)
            {   
                printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
                fprintf(arquivoSaida,"################ FILA DE IMPRESSAO MEDICA ##################\n");
                printf("EXECUTANDO FILA DE IMPRESSAO:\n");
                fprintf(arquivoSaida,"EXECUTANDO FILA DE IMPRESSAO:\n");
                imprimeFila(fila,".");
            }
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
            fprintf(arquivoSaida,"PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
            printf("############################################################\n");
            fprintf(arquivoSaida,"############################################################\n");
            scanf("%*c%*c");
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
    fclose(arquivoSaida);
    EscreveBinsecretarios(clinica, pathSec);
    EscreveBinMedicos(clinica, pathMed);
    EscreveBinConsultas(clinica, pathCons);
    EscreveBinPacientes(clinica, pathPac);
    EscreveBinLesoes(clinica, pathLes);
    return 1;
}