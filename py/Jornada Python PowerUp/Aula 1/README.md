# 🐍 Python PowerUp - Automação com PyAutoGUI

Projetos desenvolvidos durante a primeira aula da **Jornada Python** da Hashtag Treinamentos. Os scripts automatizam tarefas no navegador utilizando a biblioteca `pyautogui`.

## 📚 Projeto da Aula 1 — Automação de Cadastro de Produtos

O projeto dessa aula automatiza o processo de **cadastro de produtos** em um sistema web. Ele realiza as seguintes etapas:

1. Abre o navegador (Chrome).
2. Acessa o site do sistema.
3. Faz login com e-mail e senha.
4. Lê os dados de um arquivo `produtos.csv`.
5. Preenche os campos do formulário com os dados da tabela.
6. Clica no botão de "Enviar" para cadastrar o produto.

### Bibliotecas utilizadas

- `pyautogui`: Para automação da interface gráfica.
- `time`: Para controlar o tempo de espera entre ações.
- `pandas`: Para leitura do arquivo CSV com os produtos.

---

## ✅ Validação de Presença

Codifiquei este script para automatizar o processo de **validação de presença** para liberar o certificado da jornada, assim, podendo por em prática as novas habilidades.

### Etapas:

1. Abre o navegador e acessa o site de validação
2. Clica no botão de seleção de aula.
3. Escolhe a aula correspondente
4. Preenche os campos com:
   - Código da aula
   - Email
   - Nome completo
5. Envia o formulário.

### Parâmetros configuráveis

- `AULA`: número da aula
- `CODIGO`: código fornecido ao final da aula
- `EMAIL`: email para envio do certificado
- `NOME`: nome a ser exibido no certificado

---

## 📁 Arquivos

- `cadastro_produtos.py`: script do projeto da Aula 1
- `produtos.csv`: tabela de produtos utilizados no projeto da Aula 1
- `validacao_presenca.py`: script realizado pós-aula para validação de presença
- `posicao_mouse.py`: script auxiliar para descobrir coordenadas do mouse

---

**Leonardo Padovani Manzato**
Estudante de Sistemas de Informação - UFV/CRP
GitHub: [leomzto](https://github.com/leomzto)
LinkedIn: [leomzto](https://linkedin.com/in/leomzto/)
