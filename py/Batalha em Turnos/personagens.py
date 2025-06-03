import random
# Personagem: classe mae
# Heroi: herda personagem, controlado pelo usuario
# Inimigo: herda personagem, adversario do usuario

class Personagem:
    def __init__(self, nome, vida, nivel):
        self.__nome = nome
        self.__vida = vida
        self.__nivel = nivel
    def get_nome(self):
        return self.__nome
    def get_vida(self):
        return self.__vida
    def get_nivel(self):
        return self.__nivel
    def exibir_detalhes(self):
        return f'\nNome: {self.get_nome()}\nVida: {self.get_vida()}\nNivel: {self.get_nivel()}'
    def receber_ataque(self, dano):
        self.__vida -= dano
        if self.__vida < 0:
            self.__vida = 0
    def atacar(self, alvo):
        dano = random.randint(2 * self.get_nivel(), 4 * self.get_nivel())
        alvo.receber_ataque(dano)
        print(f'{self.__nome} atacou {alvo.__nome} causando {dano} de dano.')


class Heroi(Personagem):
    def __init__(self, nome, vida, nivel, habilidade):
        super().__init__(nome, vida, nivel)
        self.__habilidade = habilidade
    def get_habilidade(self):
        return self.__habilidade
    def exibir_detalhes(self):
        return f'{super().exibir_detalhes()}\nHabilidade: {self.get_habilidade()}'
    def ataque_especial(self, alvo):
        dano = random.randint(5 * self.get_nivel(), 8 * self.get_nivel())
        alvo.receber_ataque(dano)
        print(f'{self.get_nome()} usou {self.get_habilidade()} em {alvo.get_nome()} e causou {dano} de dano.')
class Inimigo(Personagem):
    def __init__(self, nome, vida, nivel, tipo):
        super().__init__(nome, vida, nivel)
        self.__tipo = tipo
    def get_tipo(self):
        return self.__tipo
    def exibir_detalhes(self):
        return f'{super().exibir_detalhes()}\nTipo: {self.get_tipo()}'
