import csv
import os

ARQUIVO = 'Agenda_Telefonica.csv'
CAMPOS = ['nome', 'telefone', 'email', 'favorito']


def criar_agendaContatos():
    if not os.path.isfile(ARQUIVO):
        with open(ARQUIVO, mode='w', newline='', encoding='utf-8') as arquivo:
            escritor = csv.DictWriter(arquivo, fieldnames=CAMPOS)
            escritor.writeheader()
        print("Arquivo criado com cabeçalho.")
    else:
        print("Arquivo já existe.")

class Contato:

    def __init__(self, nome, telefone, email, favorito=False):
        self.nome = nome.title()
        self.telefone = telefone
        self.email = email
        self.favorito = favorito

    def exportar_contatos(self):
        return {
            'nome': self.nome,
            'telefone': self.telefone,
            'email': self.email,
            'favorito': str(self.favorito)
        }

    @staticmethod
    def carregar_contatos(dados):
        return Contato(
            dados['nome'],
            dados['telefone'],
            dados['email'],
            dados['favorito'].lower() == 'true'
        )


class Agenda:

    def __init__(self):
        criar_agendaContatos()

    def ler_contatos(self):
        contatos = []
        with open(ARQUIVO, mode='r', newline='', encoding='utf-8') as arquivo:
            leitura = csv.DictReader(arquivo)
            for linha in leitura:
                contatos.append(Contato.carregar_contatos(linha))
        return contatos

    def salvar_contatos(self, contatos):
        with open(ARQUIVO, mode='w', newline='', encoding='utf-8') as arquivo:
            escrita = csv.DictWriter(arquivo, fieldnames=CAMPOS)
            escrita.writeheader()
            for contato in contatos:
                escrita.writerow(contato.exportar_contatos())

    def adicionar_contato(self, nome, telefone, email):
        novo = Contato(nome, telefone, email)
        contatos = self.ler_contatos()
        contatos.append(novo)
        self.salvar_contatos(contatos)
        print('Contato adicionado com sucesso!')

    def listar_contatos(self):
        contatos = self.ler_contatos()
        if not contatos:
            print('Nenhum contato na agenda.')
            return

        for i, contato in enumerate(contatos, start=1):
            status = '✔' if contato.favorito else '✘'
            print(f'{i}. 𖨆: {contato.nome}\n☏: {contato.telefone}\n✉: {contato.email}\n❤: {status}\n')

    def buscar_contato(self, busca):
        contatos = self.ler_contatos()
        encontrados = [ctt for ctt in contatos if busca.lower() in ctt.nome.lower()
                       or busca in ctt.telefone or busca.lower() in ctt.email.lower()]

        if encontrados:
            print('Contato(s) encontrado(s):')
            for ctt in encontrados:
                print(f'{ctt.nome} - {ctt.telefone} - {ctt.email}')
        else:
            print(f'Nenhum contato com "{busca}" foi encontrado.')

    def editar_contato(self, busca):
        contatos = self.ler_contatos()
        for ctt in contatos:
            if busca.lower() in ctt.nome.lower() or busca in ctt.telefone or busca.lower() in ctt.email.lower():
                print('[1]. Alterar nome')
                print('[2]. Alterar telefone')
                print('[3]. Alterar email')
                print('[4]. Desfavoritar contato')
                escolha = input(' >>> ')

                if escolha == '1':
                    ctt.nome = input('Novo nome: ').title()
                elif escolha == '2':
                    ctt.telefone = input('Novo telefone: ')
                elif escolha == '3':
                    ctt.email = input('Novo email: ')
                elif escolha == '4':
                    if ctt.favorito:
                        ctt.favorito = False
                    else:
                        print('Esse contato já não está favoritado.')
                else:
                    print('Opção inválida.')
                    return

                self.salvar_contatos(contatos)
                print('Contato atualizado com sucesso!')
                return

        print('Contato não encontrado.')

    def favoritar_contato(self, busca):
        contatos = self.ler_contatos()
        for ctt in contatos:
            if busca.lower() in ctt.nome.lower() or busca in ctt.telefone or busca.lower() in ctt.email.lower():
                ctt.favorito = True
                self.salvar_contatos(contatos)
                print('Contato favoritado com sucesso!')
                return
        print('Contato não encontrado.')


# Menu
agenda = Agenda()

while True:
    print('\n[1]. Listar Contatos')
    print('[2]. Adicionar Contato')
    print('[3]. Editar Contato')
    print('[4]. Buscar Contato')
    print('[5]. Favoritar Contato')
    print('[0]. Sair da Agenda')
    escolha = input(' >>> ')

    if escolha == '0':
        print('Saindo...')
        break
    elif escolha == '1':
        agenda.listar_contatos()
    elif escolha == '2':
        nome = input('Nome: ')
        telefone = input('Telefone: ')
        email = input('Email: ')
        agenda.adicionar_contato(nome, telefone, email)
    elif escolha == '3':
        busca = input('Digite nome, telefone ou email do contato: ')
        agenda.editar_contato(busca)
    elif escolha == '4':
        busca = input('Digite nome, telefone ou email: ')
        agenda.buscar_contato(busca)
    elif escolha == '5':
        contato = input('Digite nome, telefone ou email do contato: ')
        agenda.favoritar_contato(contato)
    else:
        print('Opção inválida.')
