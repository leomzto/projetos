# 🤖 Python IA - Interface de Conversa com IA

Projeto desenvolvido durante a **Jornada Python** da Hashtag Treinamentos. O objetivo é criar uma interface de chat utilizando **Streamlit** e a **API da OpenAI**, com foco em experiência de usuário e histórico de mensagens.

## 💬 Objetivo do Projeto

O objetivo é oferecer uma interface simples e funcional onde o usuário pode interagir com um modelo de linguagem avançado da OpenAI (como o `gpt-4o`) e visualizar todo o histórico da conversa diretamente na tela.

## 🚀 Funcionalidades

- Campo de input para envio de mensagens ao modelo da OpenAI.
- Respostas automáticas do modelo exibidas em tempo real.
- Histórico completo da conversa exibido no formato de chat.
- Botão para limpar o histórico de mensagens.

## 🧠 Como funciona

1. O usuário envia uma mensagem através do campo de input.
2. A mensagem é adicionada ao histórico (`st.session_state.chat_history`).
3. A mensagem é enviada para o modelo da OpenAI (`gpt-4o`).
4. A resposta da IA é exibida na interface e adicionada ao histórico.
5. Toda a conversa pode ser visualizada como um chat em tempo real.

## 🛠️ Tecnologias utilizadas

- [Python](https://www.python.org/)
- [Streamlit](https://streamlit.io/)
- [OpenAI Python SDK](https://github.com/openai/openai-python)
