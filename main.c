#include <stdio.h>
#include <stdlib.h>
#include "tClinica.h"
#include "tRelatorio.h"
#define TAM_CAMINHO 300

void MostrarLogin()
{
    printf("######################## ACESSO MINI-SADE ######################\n");
    printf("DIGITE SEU LOGIN:\n");
    printf("DIGITE SUA SENHA:\n");
    printf("###############################################################\n");
    return;
}

void MostrarMenu(Nivel acesso)
{
    switch (acesso)
    {
    case USER:
        printf("####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("(2) CADASTRAR MEDICO\n");
        printf("(3) CADASTRAR PACIENTE\n");
        printf("(5) BUSCAR PACIENTES\n");
        printf("(6) RELATORIO GERAL\n");
        printf("(7) FILA DE IMPRESSAO\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");

        break;
    case ADMIN:
        printf("####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("(1) CADASTRAR SECRETARIO\n");
        printf("(2) CADASTRAR MEDICO\n");
        printf("(3) CADASTRAR PACIENTE\n");
        printf("(4) REALIZAR CONSULTA\n");
        printf("(5) BUSCAR PACIENTES\n");
        printf("(6) RELATORIO GERAL\n");
        printf("(7) FILA DE IMPRESSAO\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");
        break;
    case MEDI:
        printf("####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("(4) REALIZAR CONSULTA\n");
        printf("(5) BUSCAR PACIENTES\n");
        printf("(8) FINALIZAR O PROGRAMA\n");
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

FILE *ArquivoBinarioExiste(char *path, char *nome)
{

    strcat(path, nome);
    FILE *arquivo = fopen("path", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nome);
        exit(-1);
    }
    return arquivo;
}
int sec = 0, med = 0, pac = 0, cons = 0, les = 0, fil = 0;
void ConfigurarArquivosBinarios(char *path, int *sec, int *med, int *pac, int *cons, int *les, int *fil, tClinica *clinica)
{

    int tamVetor;
    if (ArquivoBinarioExiste(path, "/secretarios.bin") == NULL)
    {

        FILE *arquivo = fopen("secretarios.bin", "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o secretarios.bin\n");
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *sec = 1;
   
    }

    if (ArquivoBinarioExiste(path, "/medicos.bin") == NULL)
    {

        FILE *arquivo = fopen("medicos.bin", "wb");

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

    if (ArquivoBinarioExiste(path, "/pacientes.bin") == NULL)
    {

        FILE *arquivo = fopen("/pacientes.bin", "wb");

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

    if (ArquivoBinarioExiste(path, "/consultas.bin") == NULL)
    {

        FILE *arquivo = fopen("consultas.bin", "wb");

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

    if (ArquivoBinarioExiste(path, "/lesoes.bin") == NULL)
    {

        FILE *arquivo = fopen("lesoes.bin", "wb");

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

    if (ArquivoBinarioExiste(path, "/fila_impressao") == NULL)
    {

        FILE *arquivo = fopen("fila_impressao.bin", "wb");

        if (arquivo == NULL)
        {
            printf("Erro ao criar o fila_impressao.bin\n");
            exit(-1);
        }
        fclose(arquivo);
    }
    else
    {
        *fil = 1;
    }
}
// secretarios.bin
// ● medicos.bin
// ● pacientes.bin
// ● consultas.bin
// ● lesoes.bin
// ● fila_impressao.bin

int main(int argc, int *argv[])
{

    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    printf("################################################\n");

    char pathBancoDados[TAM_CAMINHO];
    scanf("%s", pathBancoDados);

    // se o binário existir é porque já existe um banco de dados para a
    // entidade se não vc ira cria-lo dentro do diretório informado
    tClinica *clinica = criaClinica();
    InicializaClinicaVetores(clinica);
    int  sec = 0, med = 0, pac = 0, cons = 0, les = 0, fil = 0;
    char pathSec[200] = {'\0'};
    char pathMed[200]= {'\0'};
    char pathPac[200]= {'\0'};
    char pathCons[200]= {'\0'};
    char pathLes[200]= {'\0'};
    char pathFil[200]= {'\0'};
    strcat(pathSec,pathBancoDados);
    strcat(pathMed,pathBancoDados);
    strcat(pathPac,pathBancoDados);
    strcat(pathCons,pathBancoDados);
    strcat(pathLes,pathBancoDados);
    strcat(pathFil,pathBancoDados);
    
    strcat(pathSec,"/secretarios.bin");
    strcat(pathMed,"/medicos.bin");
    strcat(pathPac,"/pacientes.bin");
    strcat(pathCons,"/consultas.bin");
    strcat(pathLes,"/lesoes.bin");
    strcat(pathFil,"fila_impressao.bin");


    ConfigurarArquivosBinarios(pathBancoDados, &sec, &med, &pac, &cons, &les, &fil, clinica);

    if(sec == 1){   
        LeBinSecretarios(clinica,pathSec);
    }
    if(med==1){
        LeBinMedicos(clinica,pathMed);
    }
    if(pac==1){
        LeBinPacientes(clinica,pathPac);
    }
    if(cons == 1){
        LeBinConsultas(clinica,pathCons);
    }
    if(les==1){ 
        LeBinLesoes(clinica,pathLes);
    }
    if(fil==1){

    }



    int sair = 0;
    Nivel acesso;
    int indexMedico = 0;
    int indexSecretario = 0;
    while (1)
    {
        MostrarLogin();
        char senha[21];
        char usuario[21];
        scanf("%20[^\n]%*c", senha);
        scanf("%20[^\n]%*c", usuario);
        // definir essa função depois

        Login resultado = comfirmarLogin(clinica, senha, usuario, &acesso, &indexMedico, &indexSecretario);
        switch (resultado)
        {
        case CORRETO:
            sair = 1;
            break;
        case INCORRETO:
            printf(" SENHA INCORRETA OU USUARIO INEXISTENTE\n");
            break;

        default:
            break;
        }

        if (sair)
            break;
    }

    /*O login e senha deve ser comparado com as credências do secretário ou médico já
cadastrados no banco. Se o login falhar (ou seja, não existe o usuário ou a senha está
incorreta), o programa deve exibir a mensagem SENHA INCORRETA OU USUARIO
INEXISTENTE e repetir a tela de acesso. Se o login for bem-sucedido, o programa
deve ir para o menu inicial que será descrito na sequência. Se este for o primeiro
acesso ao sistema (ou seja, não existe nenhum usuário cadastrado), o sistema deve
direcionar para a tela de cadastro de usuário que terá o nível de acesso ADMIN. */

    // definir o tipo de acesso do usuario

    int funcionalidade = 0;

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
            printf("#################### CADASTRO SECRETARIO #######################\n");
            if (CadastraSecretarioClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
            }

            /* code */
            break;
        case 2:
            printf("#################### CADASTRO MEDICO #######################\n");
            if (CadastraSecretarioClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
            }

            break;
        case 3:
            printf("#################### CADASTRO PACIENTE #######################\n");
            if (CadastraSecretarioClinica(clinica))
            {
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
            }

            break;
        case 4:
            printf("#################### CONSULTA MEDICA #######################");
            printf("CPF DO PACIENTE:\n");
            printf("############################################################");
            char cpf[15] = {'\0'};
            scanf("%14[^\n]%*c", cpf);
            int indexPaciente = EhCadastradoCLinica(clinica, cpf);

            if (indexPaciente != -1)
            {

                ConsultaMedica(clinica, indexPaciente, indexMedico);
            }
            else
            {
                printf("#################### CONSULTA MEDICA #######################");
                printf("CPF DO PACIENTE: %s", cpf);
                printf("PACIENTE SEM CADASTRO\n");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL");
                printf("############################################################");
                scanf("%*c");
                continue;
            }
            break;
        case 5:

            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            char nome[100] = {'\0'};
            scanf("%99[^n]%*c", nome);
            printf("\nDATA DA CONSULTA: ");
            char data[11];
            scanf("%10[^n]%*c", data);
            printf("\nDIAGNOSTICO: ");
            char diagnostico[30];
            scanf("%29[^n]%*c", diagnostico);
            int numPacientes = ObtemTamPacientes(clinica);
            tPaciente **pacientes = ObtemPacientes(clinica);
            int numPacientesLista = 0;
            int numConsultas = obtemNumConsultas(clinica);
            tPaciente **lista = BuscarPacientes(pacientes, numPacientes,
                                                nome, data, diagnostico, &numPacientesLista);
            if (pacientes == NULL)
            {

                printf("#################### BUSCAR PACIENTES #######################\n");
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU ANTERIOR");
                printf("############################################################");
                scanf("%*c");
                continue;
            }

            qsort(pacientes, numPacientes, sizeof(tPaciente *), comparar_nomes);

            tLista *listaBusca = criaListaDeBusca(lista, numPacientesLista);

            int opcao = 0;
            imprimeEmTelaLista(listaBusca);
            scanf("%d%*c", &opcao);
            if (opcao == 1)
            {
                printf(" #################### BUSCAR PACIENTES #######################\n");
                printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU PRINCIPAL\n");
                printf("############################################################");
                scanf("%*c");
            }
            else if (opcao == 2)
            {
                int numPaciente = 0;
                printf(" #################### BUSCAR PACIENTES #######################\n");
                printf("DIGITE O NUMERO DO PACIENTE: ");
                scanf("%d%*c", &numPaciente);
                printf("\n############################################################\n");
                int opcaoB = 0;
                tPaciente *paciente = ObtemPaciente(pacientes, numPaciente - 1);
                imprimeEmTelaBusca(paciente);
                scanf("%d%*c", &opcaoB);
                if (opcao == 1)
                {
                    printf(" #################### BUSCAR PACIENTES #######################\n");
                    printf("DADOS ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                    printf("RETORNAR AO MENU PRINCIPAL\n");
                    printf("############################################################");
                    scanf("%*c");
                }
                else if (opcao == 2)
                {
                    continue;
                }
            }

            break;
        case 6:
            int opcaoA;
            tRelatorio *relatorio = CriaRelatorio(clinica);
            imprimeNaTelaRelatorio(relatorio);
            scanf("%d%*c", &opcaoA);
            if (opcaoA == 1)
            {
                printf(" #################### BUSCAR PACIENTES #######################\n");
                printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU PRINCIPAL\n");
                printf("############################################################");
                scanf("%*c");
            }
            else if (opcaoA == 2)
            {
                continue;
            }

            break;
        case 7:
            printf("################### FILA DE IMPRESSAO MEDICA #####################\n");
            printf("ESCOLHA UMA OPCAO:\n");
            printf("(1) EXECUTAR FILA DE IMPRESSAO\n");
            printf("(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
            if (opcao == 1)
            {
                // le arquivo binario fila de impressao
                //  e executar ela;
            }
            else if (opcao == 2)
            {
                continue;
            }
            break;
        case 8:
            return 1;
            break;

        default:
            break;
        }

        return 0;
    }
    // quarda os dados nos arquivos binarios;
    EscreveBinsecretarios(clinica,pathSec);
    EscreveBinMedicos(clinica,pathMed);
    EscreveBinConsultas(clinica,pathCons);
    EscreveBinPacientes(clinica,pathPac);
    EscreveBinLesoes(clinica,pathLes);

}
