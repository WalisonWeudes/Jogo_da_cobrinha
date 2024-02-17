#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define M 25

char snake[M * M][2];
int tamanho = 1;
int comida[2];
char direcao = 's';
int V = 300000000;
int pontos = 0;
void inicializarJogo();
void imprimirTabuleiro();
int verificarColisao();
void gerarComida();

int main()
{
    int jogoAtivo = 1;

    inicializarJogo();

    while (jogoAtivo)
    {
        imprimirTabuleiro();
        printf("PONTOS = %d", pontos);
        printf("\nW - Cima, S - Baixo, A - Esquerda, D - Direita, Q - Sair\n");

        if (_kbhit())
        {
            direcao = getch();
        }

        int X = snake[0][0];
        int Y = snake[0][1];

        if (direcao == 'w')
        {
            X--;
        }
        else if (direcao == 's')
        {
            X++;
        }
        else if (direcao == 'a')
        {
            Y--;
        }
        else if (direcao == 'd')
        {
            Y++;
        }

        for (int i = tamanho - 1; i > 0; i--)
        {
            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }

        snake[0][0] = X;
        snake[0][1] = Y;

        if (snake[0][0] == comida[0] && snake[0][1] == comida[1])
        {

            tamanho++;
            printf("\a");
            V = V - 5000000;
            pontos++;

            gerarComida();
        }

        if (verificarColisao())
        {
            printf("Fim do Jogo!\n");
            break;
        }

        for (int i = 0; i < V; i++)
            ;
    }

    return 0;
}
void inicializarJogo()
{
    snake[0][0] = 0;
    snake[0][1] = 0;

    comida[0] = rand() % M;
    comida[1] = rand() % M;
}

void imprimirTabuleiro()
{
    system("cls");

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int coordenadas = 1;
            if (i == 0 || i == M - 1 || j == 0 || j == M - 1)
            {
                printf("%c ", 223);
                coordenadas = 0;
            }
            for (int k = 0; k < tamanho; k++)
            {
                if (snake[k][0] == i && snake[k][1] == j)
                {
                    printf("%c ", 207);
                    coordenadas = 0;
                    break;
                }
            }

            if (comida[0] == i && comida[1] == j)
            {
                printf("%c ", 248);
                coordenadas = 0;
            }

            if (coordenadas)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int verificarColisao()
{
    int X = snake[0][0];
    int Y = snake[0][1];

    if (X < 0 || X >= M || Y < 0 || Y >= M)
    {
        return 1;
    }

    for (int i = 1; i < tamanho; i++)
    {
        if (snake[i][0] == X && snake[i][1] == Y)
        {
            return 1;
        }
    }

    return 0;
}

void gerarComida()
{
    int X = rand() % M;
    int Y = rand() % M;
    if (X > 2 && X < (M - 2))
    {
        comida[0] = X;
    }
    if (Y > 2 && Y < (M - 2))
    {
        comida[1] = Y;
    }
}
