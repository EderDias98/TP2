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
    while (1)
    {
        MostrarLogin();
        char senha[21];
        char usuario[21];
        scanf("%20[^\n]%*c", senha);
        scanf("%20[^\n]%*c", usuario);
        // definir essa função depois
        
        Login resultado =comfirmarLogin(clinica, senha, usuario, &acesso);
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
            char cpf[15] = '\0';
            scanf("%14[^\n]%*c",cpf);
            int idx = EhCadastradoCLinica(clinica,cpf);
            if(idx !=-1){
                if(previaDaConsulta(clinica)){
                    ConsultaMedica(clinica, idx);
                }
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
            /* code */
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
