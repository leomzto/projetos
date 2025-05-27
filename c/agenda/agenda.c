#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#define MAX_CTTS 100

#define MAX_NOME 50
#define MAX_NUM 17
#define MAX_EMAIL 50

typedef struct
{
	char nome[MAX_NOME];
	char numero[MAX_NUM];
	char email[MAX_EMAIL];
} sContato;

int menu(void);
void addContato(void);
void listarContatos(void);
void buscarContato(void);

int main(void)
{
    while(1)
    {
        system("clear || cls");
        int opcao = menu();
        while(getchar() != '\n');

        switch(opcao)
        {
            case 0:
                return 0;
            case 1:
                addContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                // editarContato();
                // break;
            default:
                break;
        }
    }

	return 0;
}

int menu(void)
{
    int escolha;
    do {
        puts("Agenda Telefonica");
        puts("[1] Adicionar novo contato");
        puts("[2] Procurar contatos");
        puts("[0] Fechar agenda");
        printf(" >>> ");
        scanf("%d", &escolha);
    } while(escolha < 0 || escolha > 3);

    return escolha;
}

void addContato(void)
{
    system("clear || cls");
    sContato ctt;

	FILE *contatos = fopen("contatos.csv", "a");
    if (contatos == NULL)
    {
        printf("Erro\n");
        return;
    }

    printf("Nome: ");
    fgets(ctt.nome, sizeof(ctt.nome), stdin);
    ctt.nome[strcspn(ctt.nome, "\n")] = '\0';
    printf("Numero: ");
    fgets(ctt.numero, sizeof(ctt.numero), stdin);
    ctt.numero[strcspn(ctt.numero, "\n")] = '\0';
    printf("E-mail: ");
    fgets(ctt.email, sizeof(ctt.email), stdin);
    ctt.email[strcspn(ctt.email, "\n")] = '\0';

    fprintf(contatos, "Nome: %s\nNumero: %s\nEmail: %s\n\n",
        ctt.nome, ctt.numero, ctt.email);

	fclose(contatos);
}


void listarContatos(void)
{
    FILE *contatos = fopen("contatos.csv", "r");
    if (contatos == NULL)
    {
        printf("Erro.\n");
        return;
    }

    char linha[MAX_CTTS];
    char contatoCompleto[1024] = "";
    int contato = 1;
    char opcao[10];

    while (fgets(linha, sizeof(linha), contatos))
    {
        strcat(contatoCompleto, linha);

        if (strcmp(linha, "\n") == 0)
        {
            system("clear || cls");
            printf("Contato %d:\n%s", contato++, contatoCompleto);

            printf("\n[ENTER] Proximo | [PESQUISAR] Buscar Contato | [SAIR] Sair\n>>> ");
            fgets(opcao, sizeof(opcao), stdin);
            opcao[strcspn(opcao, "\n")] = '\0';
            if(strncasecmp(opcao, "pesquisar", 9) == 0)
            {
                fclose(contatos);
                buscarContato();
            }
            if(strncasecmp(opcao, "sair", 4) == 0) break;

            contatoCompleto[0] = '\0';
        }
    }

    fclose(contatos);
}

void buscarContato(void)
{
    system("clear || cls");

    FILE *contatos = fopen("contatos.csv", "r");
    if(contatos == NULL)
    {
        printf("Erro.\n");
        return;
    }

    char busca[100];
    printf("Pesquisar: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    if (strlen(busca) == 0)
    {
        printf("Busca vazia.\n");
        fclose(contatos);
        printf("Pressione Enter para continuar...");
        while(getchar() != '\n');
        return;
    }

    char linha[MAX_CTTS];
    sContato contato;
    int encontrou = 0;
    int campoAtual = 0; // 0=nada, 1=nome, 2=numero, 3=email

    while(fgets(linha, sizeof(linha), contatos))
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (strncmp(linha, "Nome: ", 6) == 0)
        {

            if (campoAtual == 3)
            {
                if (strcasestr(contato.nome, busca) != NULL ||
                    strcasestr(contato.numero, busca) != NULL ||
                    strcasestr(contato.email, busca) != NULL)
                {
                    printf("\nContato encontrado: \n");
                    printf("Nome: %s\n", contato.nome);
                    printf("Numero: %s\n", contato.numero);
                    printf("Email: %s\n\n", contato.email);
                    encontrou = 1;
                }
            }
            strcpy(contato.nome, linha + 6);
            campoAtual = 1;
        }
        else if (strncmp(linha, "Numero: ", 8) == 0)
        {
            strcpy(contato.numero, linha + 8);
            campoAtual = 2;
        }
        else if (strncmp(linha, "Email: ", 7) == 0)
        {
            strcpy(contato.email, linha + 7);
            campoAtual = 3;
        }
        else if (strlen(linha) == 0)
        {
            if (campoAtual == 3)
            {
                if (strcasestr(contato.nome, busca) != NULL ||
                    strcasestr(contato.numero, busca) != NULL ||
                    strcasestr(contato.email, busca) != NULL)
                {
                    printf("\nContato Encontrado:\n");
                    printf("Nome: %s\n", contato.nome);
                    printf("Numero: %s\n", contato.numero);
                    printf("Email: %s\n\n", contato.email);
                    encontrou = 1;
                }
            }
            campoAtual = 0;
        }
    }

    if (campoAtual == 3)
    {
        if (strcasestr(contato.nome, busca) != NULL ||
            strcasestr(contato.numero, busca) != NULL ||
            strcasestr(contato.email, busca) != NULL)
        {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", contato.nome);
            printf("Numero: %s\n", contato.numero);
            printf("Email: %s\n\n", contato.email);
            encontrou = 1;
        }
    }

    if (!encontrou) printf("\nNenhum contato encontrado com: '%s'\n", busca);

    fclose(contatos);

    printf("Pressione Enter para continuar...");
    while(getchar() != '\n');
}

