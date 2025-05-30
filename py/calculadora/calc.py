import time
from math import factorial as fact
from math import sqrt
from sys import exit

MAX_NUM = 100

def main():
    while True:
        print('-= Calculadora =-')
        print('[1]. Soma')
        print('[2]. Subtração')
        print('[3]. Multiplicação')
        print('[4]. Divisão')
        print('[5]. Exponenciação')
        print('[6]. Fatorial')
        print('[7]. Raiz Quadrada')
        print('[8]. Outras operações')
        print('[0]. Sair')
        opcao = int(input(' >>> '))

        if opcao == 0:
            print('Saindo...')
            time.sleep(1)
            exit()

        elif opcao in (1, 2, 3, 4):
            qtd_numeros = int(input('Quantos números você deseja inserir? '))
            if 0 < qtd_numeros <= MAX_NUM:
                numeros = []
                for i in range(qtd_numeros):
                    numero = float(input(f'{i+1}º número: '))
                    numeros.append(numero)

                if opcao == 1:
                    resultado = sum(numeros)
                    print(f'Soma: {resultado:.2f}')
                elif opcao == 2:
                    resultado = numeros[0]
                    for n in numeros[1:]:
                        resultado -= n
                    print(f'Subtração: {resultado:.2f}')
                elif opcao == 3:
                    resultado = 1
                    for n in numeros:
                        resultado *= n
                    print(f'Multiplicação: {resultado:.2f}')
                elif opcao == 4:
                    resultado = numeros[0]
                    for n in numeros[1:]:
                        if n == 0:
                            print('Erro: divisão por zero!')
                            break
                        resultado /= n
                    else:
                        print(f'Divisão: {resultado:.2f}')
            else:
                print('Quantidade inválida.')

        elif opcao == 5:
            base = float(input('Base: '))
            expoente = int(input('Expoente: '))
            resultado = pow(base, expoente)
            print(f'{base}^{expoente} = {resultado:.2f}')

        elif opcao == 6:
            num_fatorial = int(input('Número para fatorial: '))
            if num_fatorial >= 0:
                resultado = fact(num_fatorial)
                print(f'{num_fatorial}! = {resultado}')
            else:
                print('Fatorial não existe para negativos.')

        elif opcao == 7:
            num_raiz = float(input('Número para raiz quadrada: '))
            if num_raiz >= 0:
                resultado = sqrt(num_raiz)
                print(f'√{num_raiz:.2f} = {resultado:.2f}')
            else:
                print('Número negativo não possui raiz real.')

        elif opcao == 8:
            print('-= Outras Operações =-')
            print('[1]. Par/Ímpar')
            print('[2]. Primos')
            print('[3]. MDC')
            print('[4]. MMC')
            print('[5]. Média Aritmética')
            print('[6]. Conversor de Base')
            print('[0]. Voltar')
            opcao_extra = int(input(' >>> '))

            if opcao_extra == 0:
                continue

            elif opcao_extra in (1, 2):
                qtd_numeros = int(input('Quantos números? '))
                if 0 < qtd_numeros <= MAX_NUM:
                    numeros = []
                    for i in range(qtd_numeros):
                        numero = int(input(f'{i+1}º número: '))
                        numeros.append(numero)

                    if opcao_extra == 1:
                        for num in numeros:
                            tipo = 'par' if num % 2 == 0 else 'ímpar'
                            print(f'{num} é {tipo}')
                    elif opcao_extra == 2:
                        for num in numeros:
                            if num < 2:
                                print(f'{num} não é primo')
                            else:
                                primo = True
                                for i in range(2, int(num**0.5) + 1):
                                    if num % i == 0:
                                        primo = False
                                        break
                                print(f'{num} {"é" if primo else "não é"} primo')
                else:
                    print('Quantidade inválida.')

            elif opcao_extra == 3:
                n1 = int(input('Primeiro número: '))
                n2 = int(input('Segundo número: '))
                while n2 != 0:
                    n1, n2 = n2, n1 % n2
                print(f'MDC = {n1}')

            elif opcao_extra == 4:
                n1 = int(input('Primeiro número: '))
                n2 = int(input('Segundo número: '))
                a, b = n1, n2
                while b != 0:
                    a, b = b, a % b
                mdc = a
                mmc = (n1 * n2) // mdc
                print(f'MMC = {mmc}')

            elif opcao_extra == 5:
                qtd_numeros = int(input('Quantos números? '))
                if 0 < qtd_numeros <= MAX_NUM:
                    numeros = []
                    for i in range(qtd_numeros):
                        numero = float(input(f'{i+1}º número: '))
                        numeros.append(numero)
                    media = sum(numeros) / len(numeros)
                    print(f'Média: {media:.2f}')
                else:
                    print('Quantidade inválida.')

            elif opcao_extra == 6:
                numero = int(input('Número inteiro positivo: '))
                if numero >= 0:
                    print(f'Binário: {bin(numero)[2:]}')
                    print(f'Octal: {oct(numero)[2:]}')
                    print(f'Hexadecimal: {hex(numero)[2:].upper()}')
                else:
                    print('Número deve ser positivo.')

        continuar = input('Deseja continuar? [s | n] ').strip().lower()
        if continuar != 's':
            print('Encerrando...')
            time.sleep(1)
            exit()

main()
