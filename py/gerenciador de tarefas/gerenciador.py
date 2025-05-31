from os import system
from time import sleep

def adicionar_tarefa(tarefas, nome_tarefa,):
    tarefa = {'tarefa': nome_tarefa, 'completada': False}
    tarefas.append(tarefa)
    print(f'Tarefa {nome_tarefa} foi adicionada com sucesso!')
    return

def ver_tarefas(tarefas):
    if not tarefas:
        print('\nVocê não possuí nenhuma tarefa.')
    else:
        print('\nLista de tarefas')
        for numero_tarefa, tarefa in enumerate(tarefas, start=1):
            status = '✔' if tarefa['completada'] else " "
            nome_tarefa = tarefa['tarefa']
            print(f'{numero_tarefa}. [{status}] - {nome_tarefa}')
    return

def atualizar_tarefa(tarefas, tarefa_atual, novo_nome):
    tarefas[tarefa_atual]['tarefa'] = novo_nome
    print(f'Tarefa {tarefa_atual} atualizada para {novo_nome}')
    return

def completar_tarefa(tarefas, tarefa_atual):
    if not tarefas[tarefa_atual]['completada']:
        tarefas[tarefa_atual]['completada'] = True
        print(f'{tarefa_atual} completada.')
    else:
        print('Essa tarefa ja estava completa.')
    return

def deletar_completas(tarefas):
    for tarefa in tarefas:
        if tarefa['completada']:
            tarefas.remove(tarefa)
    print('\nTarefas completadas removidas com sucesso.')
    return

tarefas = []
while True:
    system('cls')
    print('Menu de Gerenciador de Lista de tarefas:')
    print('1. Adicionar tarefas')
    print('2. Ver tarefas')
    print('3. Atualizar Tarefa')
    print('4. Completar Tarefa')
    print('5. Deletar tarefas completas')
    print('0. Sair')
    escolha = int(input('Digite sua escolha: '))

    if escolha == 0:
        break
    elif escolha == 1:
        system('cls')
        tarefa = input('Adicionar tarefa: ')
        adicionar_tarefa(tarefas, tarefa)
    elif escolha == 2:
        system('cls')
        ver_tarefas(tarefas)
        input('\n[ENTER] para continuar')
    elif escolha == 3:
        system('cls')
        ver_tarefas(tarefas)
        tarefa_atual = int(input('\nNumero da tarefa a ser atualizada: ')) - 1
        nova_tarefa = input('Atualizar para: ')
        atualizar_tarefa(tarefas, tarefa_atual, nova_tarefa)
    elif escolha == 4:
        system('cls')
        ver_tarefas(tarefas)
        tarefa = int(input('\nNumero da tarefa a ser completada: ')) -1
        completar_tarefa(tarefas, tarefa)
    elif escolha == 5:
        system('cls')
        confirmar = input('\nTem certeza que deseja excluir todas as tarefas ja completas? (s/n): ')
        if confirmar == 's':
            deletar_completas(tarefas)
            ver_tarefas(tarefas)
        else:
            print('\nOpção inválida')
    else:
        print('\nOpção indisponível.')
system('clear')
print("Programa finalizado")
sleep(0.5)
system('cls')
