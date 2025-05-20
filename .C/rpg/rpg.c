#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_CLASSES 6 // classes
#define NUM_INIMIGOS 12 // inimigos
#define NIVEL_MAX 10 // barraXP
#define TAMANHO_BARRA 20 // barraVida
#define NUM_ANDARES 5 // andares masmorra

typedef struct
{
    char nome[20];
    float vida, dano, defesa;
} Classe;

typedef struct
{
    char nome[50];
    Classe classe;
    float vida, dano, defesa;
    float vida_max, dano_max, defesa_max;
} Personagem;

typedef struct
{
    char nome[50];
    float vida, dano, defesa;

    float chances_de_aparecer;
} Inimigo;

typedef struct
{
    int andar_atual, andares_completos;
    bool ativa;
    Inimigo inimigos_masmorra[NUM_ANDARES];
} Masmorra;

// prototipos
void limparBuffer(void);

int menu(void);
void novoJogo(Personagem p);
Personagem criarPersonagem(void);
void iniciarBatalha(Personagem *p, Inimigo *i);
Inimigo gerarInimigos(void);
void desafiarMasmorra(Personagem *p, Masmorra *m);
Inimigo gerarInimigosMasmorra(int andar);
void mostrarStatus(Personagem *p);
void barraVida(char *nome, float vida_atual, float vida_max);

const Classe CLASSES[] = 
    {{"Guerreiro", 120.0f, 20.0f, 15.0f},
    {"Mago", 80.0f, 30.0f, 5.0f},
    {"Arqueiro", 100.0f, 25.0f, 10.0f},
    {"Paladino", 130.0f, 18.0f, 20.0f},
    {"Barbaro", 160.0f, 28.0f, 12.0f},
    {"Ladino", 90.0f, 22.0f, 8.0f}};

const Inimigo INIMIGOS[] =
    {{"Esqueleto", 50.0f, 10.0f, 5, 25.0f},
    {"Esqueleto Guerreiro", 80.0f, 15.0f, 8, 15.0f},
    {"Orc", 120.0f, 20.0f, 10, 20.0f},
    {"Chefe Orc", 200.0f, 30.0f, 15, 5.0f},
    {"Goblin", 40.0f, 12.0f, 4, 25.0f},
    {"Goblin Chefe", 90.0f, 18.0f, 6, 10.0f},
    {"Dragao Jovem", 300.0f, 40.0f, 20, 3.0f},
    {"Dragao Anciao", 600.0f, 70.0f, 35, 1.0f},
    {"Slime", 30.0f, 8.0f, 2, 30.0f},
    {"Slime Rei", 150.0f, 18.0f, 10, 5.0f},
    {"Demonio", 100.0f, 25.0f, 10, 7.0f},
    {"Lorde Demonio", 500.0f, 50.0f, 25, 0.5f}};

// main
int main(void)
{
    srand(time(NULL));

    while(1)
    {
        int opcao;
        
        opcao = menu();
        Personagem p;

        if(opcao == 1)
        {
            p = criarPersonagem();
            novoJogo(p);
        }
        else if(opcao == 2)
        {
            int i;
            puts("Saindo");
            for(i = 0; i < 5; i++)
            {
                sleep(1);
                putchar('.');
                fflush(stdout);
            }
            puts("");
            break;
        }
    }

    return 0;
}

// funçoes
void limparBuffer(void)
{
    while(getchar() != '\n');
}

int menu(void) 
{
    int opcao;
    
    do
    {
        system("clear");
        
        puts("-=- RPG -=-");
        puts("1. Novo Jogo");
        puts("2. Sair");
        printf(" --> ");
        
        if(scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 2)
        {
            puts("Opcao invalida!");
            limparBuffer();
            sleep(1);
            continue;
        }
        
        if(opcao == 1)
        {
            int i;
            system("clear");
            puts("\nCarregando jogo");
            printf("Progresso: [");
            
            for(i = 0; i < 10; i++)
            {
                usleep(250000);
                putchar('#');
                fflush(stdout);
            }
            
            puts("] 100%\n");
            sleep(1);
        }
        
    } while(opcao < 1 || opcao > 2);
    
    return opcao;
}

Personagem criarPersonagem(void)
{
    Personagem p;

    char escolha_classe[20];
    bool classe_valida = false;

    int i;

    // criaçao do personagem
    limparBuffer();
    system("clear");
    puts("Cricao de personagem:");
    printf("Nome -> ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    p.nome[0] = toupper(p.nome[0]);

    printf("%s esta nascendo.\n", p.nome);
    for(i = 0; i < 10; i++)
        {
            usleep(250000);
            putchar('.');
            fflush(stdout);
        }
    sleep(1);

    // escolha da classe
    puts("\n\nEscolha sua classe:");
    for (i = 0; i < NUM_CLASSES; i++)
        printf("%d. %s | HP: %.1f | ATQ: %.1f | DEF: %.1f\n",
                i + 1, CLASSES[i].nome, CLASSES[i].vida, CLASSES[i].dano, CLASSES[i].defesa);

    while(!classe_valida)
    {
        printf("\nEu escolho ser ");
        fgets(escolha_classe, sizeof(escolha_classe), stdin);
        escolha_classe[strcspn(escolha_classe, "\n")] = '\0';

        for(i = 0; i < NUM_CLASSES; i++)
        {
            if(strcasecmp(escolha_classe, CLASSES[i].nome) == 0)
            {
                p.classe = CLASSES[i];
                printf("Atribuindo a classe %s a %s.\n",p.classe.nome, p.nome);
                for(i = 0; i < 10; i++)
                {
                    usleep(250000);
                    putchar('.');
                    fflush(stdout);
                }
                sleep(1);
                
                printf("\n\n%s agora e %s\n", p.nome, p.classe.nome);
                classe_valida = true;

                sleep(2);
                system("clear");
                break;
            }
        }

        if(!classe_valida)
            puts("Classe invalida.");
    }

    p.vida = p.classe.vida;
    p.dano = p.classe.dano;
    p.defesa = p.classe.defesa;

    p.vida_max = p.classe.vida;
    p.dano_max = p.classe.dano;
    p.defesa_max = p.classe.defesa;

    return p;
}

void novoJogo(Personagem p)
{
    while(p.vida > 0)
    {
        int escolha;
        puts("\nO que voce que fazer agora?");
        puts("1. Procurar monstros");
        puts("2. Desafiar masmorra");
        printf("3. Ver [%s]\n", p.nome);
        puts("0. Voltar ao menu");
        printf("Escolha -> ");
        scanf("%d", &escolha);
        limparBuffer();

        switch(escolha)
        {
            case 0:
                return;
            case 1:
            {
                Inimigo inimigo = gerarInimigos();
                iniciarBatalha(&p, &inimigo);
                break;
            }
            case 2:
            {
                Masmorra m;
                desafiarMasmorra(&p, &m);
                break;
            }
            case 3:
            {
                mostrarStatus(&p);
                break;
            }
        }
    }
}

void iniciarBatalha(Personagem *p, Inimigo *i)
{
    char escolha_jogador[20];
    float vida_maxima_p = (*p).classe.vida;
    float vida_maxima_i = (*i).vida;

    float golpe_jogador = (*p).dano - (*i).defesa;
    if(golpe_jogador < 1) golpe_jogador = 1;
    float golpe_inimigo = (*i).dano - (*p).defesa;
    if(golpe_inimigo < 1) golpe_inimigo = 1;

    int j;
    puts("\nProcurando inimigos");
    for(j = 0; j < 10; j++)
    {
        usleep(250000);
        putchar('.');
        fflush(stdout);
    }
    sleep(1);
    puts("\n\nInimigo encontrado.");
    puts("Iniciando batalha");
    for(j = 0; j < 10; j++)
    {
        usleep(250000);
        putchar('.');
        fflush(stdout);
    }
    sleep(2);
    system("clear");

    barraVida((*p).nome, (*p).vida, vida_maxima_p);
    puts("");
    barraVida((*i).nome, (*i).vida, vida_maxima_i);

    while((*p).vida > 0 && (*i).vida > 0)
    {
        puts("\n1. Atacar");
        puts("2. Correr");

        while(1)
        {
            printf("Eu escolho ");
            fgets(escolha_jogador, sizeof(escolha_jogador), stdin);
            escolha_jogador[strcspn(escolha_jogador, "\n")] = '\0';

            for(j = 0; escolha_jogador[j]; j++)
                escolha_jogador[j] = tolower(escolha_jogador[j]);

            // escolheu atacar
            if(strcasecmp(escolha_jogador, "atacar") == 0)
            {
                // vez do jogador
                printf("\nAtacando %s [", (*i).nome);
                for(j = 0; j < 7; j++)
                {
                    usleep(250000);
                    printf(">");
                    fflush(stdout);
                }
                puts("]");
                sleep(1);
                (*i).vida -= golpe_jogador;
                if ((*i).vida < 0) (*i).vida = 0;
                
                system("clear");
                barraVida((*p).nome, (*p).vida, vida_maxima_p);
                puts("");
                barraVida((*i).nome, (*i).vida, vida_maxima_i);
                printf("\nVoce atacou %s e causou %.1f de dano.\n",
                     (*i).nome, golpe_jogador);

                // vez do inimigo
                if((*i).vida > 0)
                {
                    printf("%s esta te atacando [", (*i).nome);
                    for(j = 0; j < 7; j++)
                    {
                        usleep(250000);
                        printf(">");
                        fflush(stdout);
                    }
                    puts("]");
                    sleep(1);
                    (*p).vida -= golpe_inimigo;
                    if ((*p).vida < 0) (*p).vida = 0;
                    
                    system("clear");
                    barraVida((*p).nome, (*p).vida, vida_maxima_p);
                    puts("");
                    barraVida((*i).nome, (*i).vida, vida_maxima_i);
                    printf("\n%s realizou um contra ataque causando %.1f de dano.\n", 
                    (*i).nome, golpe_inimigo);
                }
                break;
            }
            // escolheu correr
            else if(strcasecmp(escolha_jogador, "correr") == 0)
            {
                puts("Voce escolheu correr, seu cagao.");
                sleep(2);
                system("clear");
                return;
            }
            else
                puts("\nEscolha invalida.\nVoce so pode atacar ou correr.\n");
        }

        if((*i).vida <= 0)
        {
            (*p).vida += (*p).classe.vida * 0.3;
            if ((*p).vida > (*p).classe.vida) 
                (*p).vida = (*p).classe.vida;

            printf("\nVoce venceu a luta contra %s!\n", (*i).nome);
            sleep(2);
            system("clear");
            break;
        }
        else if((*p).vida <= 0)
        {
            printf("\nVoce perdeu a luta contra %s.\n", (*i).nome);
            sleep(2);
            system("clear");
            puts("Game Over");
            sleep(2);
            exit(0);
        }
    }
}

Inimigo gerarInimigos(void)
{
    int i;

    float chance_spawn = 0.0f;

    for(i = 0; i < 12; i++)
        chance_spawn += INIMIGOS[i].chances_de_aparecer;

    float sortear_inimigos = ((float)rand() / RAND_MAX) * chance_spawn;

    float chance_geral = 0.0f;
    for(i = 0; i < 12; i++)
    {
        chance_geral += INIMIGOS[i].chances_de_aparecer;
        if(sortear_inimigos <= chance_geral)
            return INIMIGOS[i];
    }

    return INIMIGOS[0];
    
}

void desafiarMasmorra(Personagem *p, Masmorra *m)
{
    int j;
    int i;

    if(!(*m).ativa)
    {
        (*m).ativa = true;
        (*m).andar_atual = 0;
        (*m).andares_completos = 0;

        for(i = 0; i < NUM_ANDARES; i++)
            (*m).inimigos_masmorra[i] = gerarInimigosMasmorra(i);

    
        puts("\nEntrando na masmorra");
        for(j = 0; j < 10; j++)
        {
            usleep(250000);
            putchar('.');
            fflush(stdout);
        }
        sleep(2);
        system("clear");
        puts("\n\nVoce entrou!\nTome cuidado.");
    }

    if((*m).andar_atual >= NUM_ANDARES)
    {
        puts("\nParabens, voce completou a masmorra.");
        (*m).ativa = false;

        (*p).vida = (*p).classe.vida;
        (*p).dano += 5;

        return;
    }

    printf("\nAndar [%d]/[%d]\n", (*m).andar_atual + 1, NUM_ANDARES);
    puts("\n\nExplorando");
    for(j = 0; j < 10; j++)
    {
        usleep(250000);
        putchar('.');
        fflush(stdout);
    }
    sleep(1);
    puts("\n\nInimigo encontrado.");
    puts("Iniciando batalha");
    for(j = 0; j < 10; j++)
    {
        usleep(250000);
        putchar('.');
        fflush(stdout);
    }
    sleep(2);
    puts("");

    Inimigo* inimigo_atual = &(*m).inimigos_masmorra[(*m).andar_atual];
    barraVida((*p).nome, (*p).vida, (*p).classe.vida);
    puts("");
    barraVida((*inimigo_atual).nome, (*inimigo_atual).vida, (*inimigo_atual).vida);

    char escolha[20];
    puts("\n1. Atacar");
    puts("2. Sair");
    printf("Eu escolho ");
    fgets(escolha, sizeof(escolha), stdin);
    escolha[strcspn(escolha, "\n")] = '\0';
                
    for(j = 0; escolha[j]; j++)
        escolha[j] = tolower(escolha[j]);

    // escolheu atacar
    if(strcasecmp(escolha, "atacar") == 0)
    {
        // vez do jogador
        printf("\nAtacando %s [", (*inimigo_atual).nome);
        for(j = 0; j < 7; j++)
        {
            usleep(250000);
            printf(">");
            fflush(stdout);
        }
        puts("]");
        sleep(1);
        iniciarBatalha(p, inimigo_atual);

        if ((*p).vida > 0 && (*inimigo_atual).vida <= 0)
        {
            printf("\n%s derrotou o inimigo do andar %d!\n", (*p).nome, (*m).andar_atual + 1);
            (*m).andar_atual++;
            
            (*p).vida += (*p).classe.vida * 0.3;
            if ((*p).vida > (*p).classe.vida) 
                (*p).vida = (*p).classe.vida;
        }
    }
    else if(strcasecmp(escolha, "sair") == 0)
    {
        puts("Voce escolheu correr, seu cagao.");
        (*m).ativa = false;
        sleep(2);
        system("clear");
        return;
    }
    else
        puts("\nEscolha invalida.\nVoce so pode atacar ou correr.\n");
}

Inimigo gerarInimigosMasmorra(int andar)
{
    Inimigo inimigo = gerarInimigos();

    float dificuldade = 1.0 + (andar * 0.2);
    inimigo.vida *= dificuldade;
    inimigo.dano *= dificuldade;
    inimigo.defesa *= dificuldade;

    return inimigo;
}

void mostrarStatus(Personagem *p)
{
    system("clear");
    printf("\nNome: %s", (*p).nome);
    printf("\nClasse: %s", (*p).classe.nome);
    printf("\nNivel: <nivel>");

    barraVida("\nVida", (*p).vida, (*p).classe.vida);
    printf("\nDano: %.1f", (*p).dano);
    printf("\nDefesa: %.1f", (*p).defesa);

    char escolha;
    puts("\nDeseja abrir o inventario?");
    puts("S / N --> ");
    scanf(" %c", &escolha);
    escolha = tolower(escolha);

    if(escolha == 's')
        puts("<abrir inventario>");
    
    limparBuffer();
}

void barraVida(char *nome, float vida_atual, float vida_max)
{
    int hp = (int)((vida_atual / vida_max) * TAMANHO_BARRA);

    if(vida_atual > 0 && hp == 0)
        hp = 1;

    printf("%s - [", nome);
    int i;
    for(i = 0; i < hp; i++)
        printf("+");

    for(i = hp; i < TAMANHO_BARRA; i++)
        printf("-");

    printf("] (%.1f/%.1f)", vida_atual, vida_max);
}

