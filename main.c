#include <stdio.h>
#include "tClinica.h"
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

int main(int argc, int *argv[])
{

    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    printf("################################################\n");

    char pathBancoDados[TAM_CAMINHO];
    scanf("%s", pathBancoDados);

    // se o binário existir é porque já existe um banco de dados para a
    // entidade se não vc ira cria-lo dentro do diretório informado
    tClinica* clinica = criaClinica();
    int sair = 0;
    Nivel acesso;
    int indexMedico =0;
    while (1)
    {
        MostrarLogin();
        char senha[21];
        char usuario[21];
        scanf("%20[^\n]%*c", senha);
        scanf("%20[^\n]%*c", usuario);
        // definir essa função depois
        
        Login resultado =comfirmarLogin(clinica, senha, usuario, &acesso, &indexMedico);
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
            if(CadastraSecretarioClinica(clinica)){
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                printf("###############################################################");
            }

           
     
            /* code */
            break;
        case 2:
            printf("#################### CADASTRO MEDICO #######################\n");
            if(CadastraSecretarioClinica(clinica)){
                printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("VOLTAR PARA O MENU INICIAL\n");
                  printf("###############################################################");
            }

            break;
        case 3:
            printf("#################### CADASTRO PACIENTE #######################\n");
            if(CadastraSecretarioClinica(clinica)){
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
            scanf("%14[^\n]%*c",cpf);
            int indexPaciente = EhCadastradoCLinica(clinica,cpf);
            
            if(indexPaciente !=-1){
                
                ConsultaMedica(clinica, indexPaciente,indexMedico);
                
            }else{
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
            scanf("%99[^/n]%*c", nome);
            printf("\nDATA DA CONSULTA: ");
            char data[11]  = {'\0'};
            scanf("%10[^/n]%*c", data);
            char diagnostico[20] = {'\0'};
            scanf("%19[^/n]%*c", diagnostico);
            printf("\n############################################################\n");
            /* code */
            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            char nome[100] = {'\0'};
            scanf("%99[^n]%*c",nome);
            printf("\nDATA DA CONSULTA: ");
            char data[11];
            scanf("%10[^n]%*c",data);
            printf("\nDIAGNOSTICO: ");
            char diagnostico[30];
            scanf("%29[^n]%*c",diagnostico);
            int tamPacientes = ObtemTamPacientes(clinica);
            tPaciente** pacientes = ObtemPacientes(clinica);
            int tamLista=0;
            tPaciente** lista = BuscarPacientes(pacientes,tamPacientes,
            nome,data,diagnostico, &tamLista);
            if(pacientes == NULL){

                printf("#################### BUSCAR PACIENTES #######################\n");
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU ANTERIOR");
                printf("############################################################");
                scanf("%*c");
                continue;
            }

            qsort(pacientes,tamPacientes,sizeof(tPaciente*), comparar_nomes);
            
            tLista *listaBusca = criaListaDeBusca(lista,tamLista);
            
            int opcao=0;
            imprimeEmTelaLista(listaBusca);
            scanf("%d%*c", &opcao);
            if(opcao == 1){
                printf(" #################### BUSCAR PACIENTES #######################\n");
                printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                printf("RETORNAR AO MENU PRINCIPAL\n");
                printf("############################################################");
               scanf("%*c");
            }else if(opcao==2){
                int numPaciente=0;
                printf(" #################### BUSCAR PACIENTES #######################\n");
                printf("DIGITE O NUMERO DO PACIENTE: ");
                scanf("%d%*c", &numPaciente);
                printf("\n############################################################\n");
                int opcaoB =0;
                tPaciente *paciente = ObtemPaciente(pacientes, numPaciente-1);
                imprimeEmTelaBusca(paciente);
                scanf("%d%*c", &opcaoB);
                if(opcao==1){
                    printf(" #################### BUSCAR PACIENTES #######################\n");
                    printf("DADOS ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA\n");
                    printf("RETORNAR AO MENU PRINCIPAL\n");
                    printf("############################################################");
                    scanf("%*c");                  
                }else if(opcao==2){
                    continue;
                }
            }


            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            /* code */
            break;
        default:
            break;
        }

        return 0;
    }
}


