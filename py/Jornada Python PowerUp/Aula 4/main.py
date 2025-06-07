# Titulo
# Input do char
# A cada mensagem eviada:
    # Mostrar a mensagem que foi enviada pelo usuario
    # Enviar a mensagem para a IA
    # Mostrar na tela a resposta da IA

import streamlit as st
from openai import OpenAI

client = OpenAI(api_key='')

st.write('# ChatRanho')

if "chat_history" not in st.session_state:
    st.session_state.chat_history = []

if st.button('Limpar chat'):
    st.session_state.chat_history = []

for msg in st.session_state.chat_history:
    with st.chat_message(msg["role"]):
        st.write(msg["content"])

user_msg = st.chat_input("Converse comigo:")
if user_msg:
    st.chat_message("user").write(user_msg)
    st.session_state.chat_history.append({"role": "user", "content": user_msg})

    client_response = client.chat.completions.create(
        messages=st.session_state.chat_history,
        model="gpt-4o"
    )
    response = client_response.choices[0].message.content
    st.chat_message("assistant").write(response)
    st.session_state.chat_history.append({"role": "assistant", "content": response})

