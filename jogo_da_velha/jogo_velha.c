#include <stdio.h>

void exibir_tabuleiro(char tabuleiro[3][3]);
int vitoria(char tabuleiro[3][3], char jogador);
int empate(char tabuleiro[3][3]);

int main(void)
{
    char tabuleiro[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int linha_escolhida, coluna_escolhida, posicao_valida;
    int jogador_atual = 'X';

    while(1)
    {
        exibir_tabuleiro(tabuleiro);
        posicao_valida = 0;

        while(!posicao_valida)
        {
            printf("\nTurno do jogador %c.\nDigite a linha e a coluna para sua jogada: ", jogador_atual);
            scanf("%d %d", &linha_escolhida, &coluna_escolhida);

            linha_escolhida -= 1;
            coluna_escolhida -= 1;

            if(linha_escolhida >= 0 && linha_escolhida < 3 && coluna_escolhida >= 0 && coluna_escolhida < 3 && tabuleiro[linha_escolhida][coluna_escolhida] == ' ')
            {
                tabuleiro[linha_escolhida][coluna_escolhida] = jogador_atual;
                posicao_valida = 1;
            }
            else
            {
                printf("\nJogada Inválida.\nTente novamente.\n");
            }
        }

        if(vitoria(tabuleiro, jogador_atual))
        {
            exibir_tabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogador_atual);

            break;
        }

        if(empate(tabuleiro))
        {
            exibir_tabuleiro(tabuleiro);
            printf("Empate!\n");

            break;
        }

        jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
    }

    return 0;
}


void exibir_tabuleiro(char tabuleiro[3][3])
{
    int linha, coluna;

    for(linha = 0; linha < 3; linha++)
    {
        for(coluna = 0; coluna < 3; coluna++)
        {
            printf(" %c ", tabuleiro[linha][coluna]);
            if (coluna < 2) printf("|");
        }
        printf("\n");
        if (linha < 2) printf("---|---|---\n");
    }
}


int vitoria(char tabuleiro[3][3], char jogador)
{
    int l, c;

    for(l = 0; l < 3; l++)
    {
        if (tabuleiro[l][0] == jogador && tabuleiro[l][1] == jogador && tabuleiro[l][2] == jogador)
            return 1;
    }

    for(c = 0; c < 3; c++)
    {
        if(tabuleiro[0][c] == jogador && tabuleiro[1][c] == jogador && tabuleiro[2][c] == jogador)
            return 1;
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;

    return 0;
}


int empate(char tabuleiro[3][3])
{
    int linha, coluna;

    for(linha = 0; linha < 3; linha++)
    {
        for(coluna = 0; coluna < 3; coluna++)
        {
            if(tabuleiro[linha][coluna] == ' ')
                return 0;
        }
    }
    return 1;
}
