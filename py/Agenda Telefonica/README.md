# 📒 Agenda Telefônica

Este projeto é uma agenda telefônica simples desenvolvida em Python que permite armazenar, listar, buscar, editar e favoritar contatos. Os dados são salvos em um arquivo CSV para persistência.

## 🚀 Funcionalidades

- 🆕 Criar arquivo CSV para armazenar os contatos (caso não exista)
- ➕ Adicionar novos contatos (nome, telefone, email)
- 📋 Listar todos os contatos salvos
- 🔍 Buscar contatos por nome, telefone ou email
- ✏️ Editar informações de um contato
- ⭐ Favoritar ou desfavoritar contatos
- 🖥️ Interface via terminal com menu interativo

## 🛠️ Tecnologias Utilizadas

- 🐍 Python
- 📊 Módulo `csv` para manipulação do arquivo CSV
- 📂 Módulo `os` para verificação da existência do arquivo

## 📄 Estrutura do arquivo CSV
O arquivo `Agenda_Telefonica.csv` contém as seguintes colunas:

- 👤 nome
- 📞 telefone
- 📧 email
- ❤️ favorito (marcado como True ou False)

## 🧩 Organização do código
- Função criar_agendaContatos(): Cria o arquivo CSV com o cabeçalho, caso ele não exista.
- Classe Contato: Representa um contato da agenda, com métodos para exportar e carregar contatos.
- Classe Agenda: Gerencia a lista de contatos, leitura, escrita, busca, edição, adição e favoritação.
- Loop principal: Menu interativo para interação com o usuário via terminal.

## ⚠️ Observações
- O campo "favorito" é armazenado como texto no CSV ("True" ou "False").
- A busca por contatos é feita pelo nome, telefone ou email, ignorando maiúsculas/minúsculas.
