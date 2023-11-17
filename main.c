#include <stdio.h>

#define TAM_CAMINHO 300

typedef enum
{
    ADMIN,
    USER,
    MEDI,
} Nivel;

typedef enum
{
    CORRETO,
    SENHA_IN,
    USUARIO_IN,
} Login;

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

EhOpcaoCorreta(Nivel acesso, int funcionalidade)
{
}

int main(int argc, int *argv[])
{

    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    printf("################################################\n");

    char pathBancoDados[TAM_CAMINHO];
    scanf("%s", pathBancoDados);

    // se o binário existir é porque já existe um banco de dados para a
    // entidade se não vc ira cria-lo dentro do diretório informado

    int sair = 0;
    while (1)
    {
        MostrarLogin();
        // definir essa função depois
        Login resultado;
        switch (resultado)
        {
        case CORRETO:
            sair = 1;
            break;
        case SENHA_IN:
            printf(" SENHA INCORRETA\n");
            break;
        case USUARIO_IN:
            printf("USUARIO INEXISTENTE\n");
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
    Nivel acesso;

    int funcionalidade = 0;

    while (1)
    {
        MostrarMenu(acesso);
        scanf("%d%*c", &funcionalidade);

// fazer um teste pra ver se é possivel a opção, por exemplo um medico acessar a funcionalidade 3 seria um erro
// pode usar um loop para voltar ao menu para escolher a opcao de novo

        if (!EhOpcaoCorreta(acesso, funcionalidade))
            continue;
        switch (funcionalidade)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
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
