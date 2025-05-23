#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NUM_BOMBAS (TAM * TAM) / 3
#define VIDAS (NUM_BOMBAS - 1)

void inicializar(char campo[TAM][TAM], char valor);
void exibirCampo(char campo[TAM][TAM]);
void posicionarBombas(char campo[TAM][TAM]);
int contarBombas(char campo[TAM][TAM], int linha, int coluna);

int main(void)
{
    char campo_real[TAM][TAM];
    char campo_visivel[TAM][TAM];
    int linha_escolhida, coluna_escolhida;
    int vidas = VIDAS;
    int jogadas = 0;
    int espacos = TAM * TAM - NUM_BOMBAS;
    int bombas_ao_redor;

    srand(time(NULL));

    inicializar(campo_real, ' ');
    inicializar(campo_visivel, '~');

    posicionarBombas(campo_real);

    while (true)
    {
        exibirCampo(campo_visivel);
        printf("\nVidas restantes: %d\n", vidas);
        printf("Digite a linha e a coluna para sua jogada (1 a %d): ", TAM);
        scanf("%d %d", &linha_escolhida, &coluna_escolhida);

        linha_escolhida -= 1;
        coluna_escolhida -= 1;

        if (linha_escolhida < 0 || linha_escolhida >= TAM || coluna_escolhida < 0 || coluna_escolhida >= TAM) 
        {
            printf("Posição inválida. Tente novamente.\n");
            continue;
        }

        if (campo_visivel[linha_escolhida][coluna_escolhida] != '~') 
        {
            printf("Posição já escolhida. Tente outra.\n");
            continue;
        }

        if (campo_real[linha_escolhida][coluna_escolhida] == '*') 
        {
            campo_visivel[linha_escolhida][coluna_escolhida] = 'X';
            vidas--;

            if (vidas == 0) 
            {
                printf("Você perdeu todas as vidas!\n");
                break;
            }
        }

        else
        {
            bombas_ao_redor = contarBombas(campo_real, linha_escolhida, coluna_escolhida);
            campo_visivel[linha_escolhida][coluna_escolhida] = bombas_ao_redor + '0';
            jogadas++;

            if (jogadas == espacos) 
            {
                printf("Parabens! Você venceu o jogo!\n");
                break;
            }
        }
    }

    printf("\nCAMPO MINADO:\n");
    exibirCampo(campo_real);

    return 0;
}

void inicializar(char campo[TAM][TAM], char valor)
{
    int l, c;
    for (l = 0; l < TAM; l++) 
    {
        for (c = 0; c < TAM; c++)
            campo[l][c] = valor;
    }
}

void exibirCampo(char campo[TAM][TAM])
{
    int c, linha, coluna;

    printf("\n    ");
    for (c = 0; c < TAM; c++)
        printf(" %2d", c + 1);
    printf("\n");

    printf("   ");
    for (c = 0; c < TAM; c++)
        printf("───");
    printf("\n");

    for (linha = 0; linha < TAM; linha++) 
    {
        printf(" %2d│", linha + 1);
        for (coluna = 0; coluna < TAM; coluna++) 
            printf(" %c ", campo[linha][coluna]);
        printf("\n");
    }
}

void posicionarBombas(char campo[TAM][TAM])
{
    int bombas = 0;
    int linha, coluna;

    while (bombas < NUM_BOMBAS)
    {
        linha = rand() % TAM;
        coluna = rand() % TAM;

        if (campo[linha][coluna] != '*')
        {
            campo[linha][coluna] = '*';
            bombas++;
        }
    }
}

int contarBombas(char campo[TAM][TAM], int linha, int coluna)
{
    int bombas = 0;
    int l, c;

    for (l = linha - 1; l <= linha + 1; l++) 
    {
        for (c = coluna - 1; c <= coluna + 1; c++) 
        {
            if (l >= 0 && l < TAM && c >= 0 && c < TAM) 
            {
                if (campo[l][c] == '*') 
                    bombas++;
            }
        }
    }
    return bombas;
}
