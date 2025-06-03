
from personagens import Heroi, Inimigo

class Jogo:
    """ Classe orquestradora do jogo """
    def __init__(self):
        self.heroi = Heroi(nome='Heroi', vida=100, nivel=5, habilidade='Super Força')
        self.inimigo = Inimigo(nome='Inimigo', vida=70, nivel=3, tipo='Tenebroso')
    def iniciar_batalha(self):
        """ Fazer a gestap da batalha em turnos"""
        print('Iniciando batalha!')
        while self.heroi.get_vida() > 0 and self.inimigo.get_vida() > 0:
            print('\nDetalhes dos personagens: ')
            print(self.heroi.exibir_detalhes())
            print(self.inimigo.exibir_detalhes())

            input('\n[ENTER] para atacar')
            escolha = input('Escolha:\n1 - Ataque Normal\n2 - Ataque Especial\n >>> ')

            if escolha == '1':
                self.heroi.atacar(self.inimigo)
                if self.inimigo.get_vida() > 0:
                    self.inimigo.atacar(self.heroi)
            elif escolha == '2':
                self.heroi.ataque_especial(self.inimigo)
                if self.inimigo.get_vida() > 0:
                    self.inimigo.atacar(self.heroi)
            else:
                print('Escolha inválida.')
                pass

        if self.heroi.get_vida() >= 0:
            print('\nParabens, voce venceu a batalha.')
        else:
            print('n\Voce perdeu a batalha.')
