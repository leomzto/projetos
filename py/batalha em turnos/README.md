# 🗡️ Jogo de Batalha em Turnos

Um simples jogo debatalha em turnos feito em Python, utilizando os conceitos de Programação Orientada a Objetos (POO), como herança, encapsulamento e polimorfismo.

---

## 🎮 Sobre o Jogo

Você controla um herói com uma habilidade especial e enfrenta um inimigo em uma batalha por turnos. Em cada turno, o jogador escolhe entre um ataque normal ou especial, e o inimigo responde automaticamente com um ataque.

---

## 📁 Estrutura do Projeto

├── personagens.py # Contém as classes base
├── gestao.py # Arquivo principal que orquestra a batalha
├── jogo.py # Inicia o jogo

---

## 🧱 Classes

- **Personagem**: Classe base com atributos como nome, vida e nível.
- **Heroi**: Herda de `Personagem`, com uma habilidade especial.
- **Inimigo**: Herda de `Personagem`, com um tipo específico.
- **Jogo**: Classe que organiza a lógica de batalha em turnos.

---

## 📚 Conceitos Aplicados
- Encapsulamento com atributos privados e métodos getters
- Herança entre classes
- Polimorfismo com sobrescrita do método exibir_detalhes
- Uso de módulos (import)
