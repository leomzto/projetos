#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_NUM 100

int calculadora(void);

float soma(int numeros[], int qtd_numeros);
float subtracao(int numeros[], int qtd_numeros);
float multiplicacao(int numeros[], int qtd_numeros);
float divisao(int numeros[], int qtd_numeros);
float media(int numeros[], int qtd_numeros);

float exponenciacao(float base, int expoente);
int fatorial(int numero);
float raiz_quadrada(float numero);

void ParImpar(int numeros[], int qtd);
void primos(int numeros[], int qtd);

int calcularMDC(int a, int b);
int calcularMMC(int a, int b);

void converterbase(int numero);

int main()
{
    calculadora();

    return 0;
}

int calculadora(void)
{
    char continuar = 's';
    int operacao;
    float resultado;
    int numeros[MAX_NUM], qtd_numeros, qtd_numeros2;
    int i, i2;
    

    while(continuar == 's')
    {
        printf("\n-=Calculadora=-\n");
        printf("1. Soma\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Exponenciação\n6. Fatoração\n7. Raiz Quadrada\n8. Outras operações\n0. Sair\n  >>>>  ");
        //printf("9. Par | Impar\n10. Primos\n11. MDC\n12. MMC\n13. Média aritimatica\n14. Porcentagem\n15. Conversor de bases\n0. Sair\n  >>>>");
        scanf("%d", &operacao);

        switch (operacao)
        {
            case 0:
                printf("Saindo...\n");
                sleep(2);
                continuar = 'n';
                continue;

            case 1: //soma
            case 2: //subtraçao
            case 3: //multiplicaçao
            case 4: // divisao

                printf("Quantos números você deseja inserir? ");
                scanf("%d", &qtd_numeros);

                if (qtd_numeros > 0 && qtd_numeros <= MAX_NUM)
                {
                    for (i = 0; i < qtd_numeros; i++)
                    {
                        printf("%d° número: ", i + 1);
                        scanf("%d", &numeros[i]);
                    }

                    if (operacao == 1)
                        resultado = soma(numeros, qtd_numeros), printf("A soma entre os números é %.2f\n", resultado);
                    else if (operacao == 2)
                        resultado = subtracao(numeros, qtd_numeros), printf("A subtração entre os números é %.2f\n", resultado);
                    else if (operacao == 3)
                        resultado = multiplicacao(numeros, qtd_numeros), printf("A multiplicação entre os números é %.2f\n", resultado);
                    else if (operacao == 4)
                        resultado = divisao(numeros, qtd_numeros), printf("A divisão entre os números é %.2f\n", resultado);
                }
                else
                    printf("Quantidade Inválida.\n");

                break;

            case 5: //exponencial
                {
                    float base;
                    int expoente;

                    printf("Base: ");
                    scanf("%f", &base);
                    printf("Expoente: ");
                    scanf("%d", &expoente);

                    resultado = exponenciacao(base, expoente);
                    printf("%.2f^%d = %.2f\n", base, expoente, resultado);

                    break;
                }

            case 6: //fatoraçao
                {
                    int num_fatorial;

                    printf("Insira um número para calcular seu fatorial: ");
                    scanf("%d", &num_fatorial);

                    resultado = fatorial(num_fatorial);
                    printf("%d! = %.2f\n", num_fatorial, resultado);

                    break;
                }

            case 7: //raiz quadrada
                {
                    float num_raiz;

                    printf("Insira um número para descobrir sua raiz quadrada: ");
                    scanf("%f", &num_raiz);

                    resultado = raiz_quadrada(num_raiz);
                    printf("A raiz quadrada de %.2f é %.2f\n", num_raiz, resultado);

                    break;
                }
            
            case 8: //outras operações
            {
                int outras_operacoes;
                printf("\n-=Calculadora=-\n");
                printf("1. Par | Impar\n2. Primos\n3. MDC\n4. MMC\n5. Média aritmética\n6. Conversor de bases\n0. Voltar\n  >>>>");
                scanf("%d", &outras_operacoes);

                switch (outras_operacoes)
                {
                    case 0: //voltar pro outro menu
                        continue;

                        case 1: //par ou impar
                        case 2: //primos

                            printf("Quantos números você deseja inserir? ");
                            scanf("%d", &qtd_numeros2);
                        
                            if (qtd_numeros2 > 0 && qtd_numeros2 <= MAX_NUM)
                            {
                                int numeros[qtd_numeros2];
                                for (i2 = 0; i2 < qtd_numeros2; i2++)
                                {
                                    printf("%d° número: ", i2 + 1);
                                    scanf("%d", &numeros[i2]);
                                }
                        
                                if (outras_operacoes == 1)
                                    ParImpar(numeros, qtd_numeros2);
                                else if (outras_operacoes == 2)
                                    primos(numeros, qtd_numeros2);
                            }
                            else
                                printf("Quantidade inválida!\n");

                            break;

                        case 3: //mdc
                        {
                            int n1, n2;
                            printf("Digite 2 números para calcular o MDC.\n  >>>  ");
                            scanf("%d %d", &n1, &n2);

                            printf("MDC(%d, %d) = %d\n", n1, n2, calcularMDC(n1, n2));

                            break;
                        }

                        case 4: //mmc
                        {
                            int n1, n2;
                            printf("Digite 2 números para calcular o MMC.\n  >>>  ");
                            scanf("%d %d", &n1, &n2);

                            printf("MMC(%d, %d) = %d\n", n1, n2, calcularMMC(n1, n2));

                            break;
                        }
                        
                        case 5: //media
                        {
                            printf("Quantos números você deseja inserir? ");
                            scanf("%d", &qtd_numeros2);

                            if (qtd_numeros2 > 0 && qtd_numeros2 <= MAX_NUM)
                            {
                                for (i = 0; i < qtd_numeros2; i++)
                                {
                                    printf("%d° número: ", i + 1);
                                    scanf("%d", &numeros[i]);
                                }

                            resultado = media(numeros, qtd_numeros2);
                            printf("A média entre os números é %.2f\n", resultado);
                            }
                            else
                                printf("Quantidade inválida.\n");

                            break;
                        }

                        case 6: //converter base
                        {
                            int num_conver_base;
                            printf("Escolha um número para converter: \n");
                            scanf("%d", &num_conver_base);
                        
                            converterbase(num_conver_base);
                            break;
                        }

                        
                    default:
                        printf("Opção inválida!\n");
                }
                break;
            }
            
            default:
                printf("Opção inválida!\n");
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
        continuar = tolower(continuar);
    }
}

float soma(int numeros[], int qtd_numeros)
{
    float resultado = 0;
    int n;
    for (n = 0; n < qtd_numeros; n++)
        resultado += numeros[n];
    return resultado;
}

float subtracao(int numeros[], int qtd_numeros)
{
    float resultado = numeros[0];
    int n;
    for (n = 1; n < qtd_numeros; n++)
        resultado -= numeros[n];

    return resultado;
}

float multiplicacao(int numeros[], int qtd_numeros)
{
    float resultado = 1;
    int n;
    for (n = 0; n < qtd_numeros; n++)
        resultado *= numeros[n];

    return resultado;
}

float divisao(int numeros[], int qtd_numeros)
{
    if (numeros[0] == 0) return -1;
    float resultado = numeros[0];
    int n;
    for (n = 1; n < qtd_numeros; n++)
    {
        if (numeros[n] == 0) return -1;
        resultado /= numeros[n];
    }

    return resultado;
}

float media(int numeros[], int qtd_numeros)
{
    if (qtd_numeros <= 0) return 0;
    float quantidade = 0;
    int n;
    for (n = 0; n < qtd_numeros; n++)
        quantidade += numeros[n];

    return quantidade / (float)qtd_numeros;
}

float exponenciacao(float base, int expoente)
{
    float resultado = 1;
    int n;
    for (n = 0; n < expoente; n++)
        resultado *= base;

    return resultado;
}

int fatorial(int numero)
{
    int resultado = 1;
    int n;
    for (n = 2; n <= numero; n++)
        resultado *= n;

    return resultado;
}

float raiz_quadrada(float numero)
{
    float resultado = numero / 2.0;
    int n;
    for (n = 0; n < 10; n++)
        resultado = (resultado + numero / resultado) / 2.0;

    return resultado;
}

void ParImpar(int numeros[], int qtd)
{
    int i;
    printf("\nSão pares: ");
    for (i = 0; i < qtd; i++)
    {
        if (numeros[i] % 2 == 0)
            printf("%d ", numeros[i]);
    }

    printf("\nSão ímpares: ");
    for (i = 0; i < qtd; i++)
    {
        if (numeros[i] % 2 != 0)
            printf("%d ", numeros[i]);
    }
    printf("\n");
}

void primos(int numeros[], int qtd)
{
    int i;
    printf("\nSão primos: ");
    for (i = 0; i < qtd; i++)
    {
        int n = numeros[i];
        int divisor;
        bool primo = true;

        if (n <= 1)
            primo = false;

        for (divisor = 2; divisor <= n / 2; divisor++)
        {
            if (n % divisor == 0)
            {
                primo = false;
                break;
            }
        }

        if (primo)
            printf("%d ", n);
    }
    printf(".\n");
}

int calcularMDC(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int calcularMMC(int a, int b)
{
    return (a * b) / calcularMDC(a, b);
}

void converterbase(int numero)
{
    printf("Decimal: %d.\n", numero);
    printf("Binário: \n");
    printf("Octal: %o.\n", numero);
    printf("Hexadecimal: %X, %x.\n", numero, numero);
}
