# 🤖 BOT do Discord

Um bot simples para Discord, criado com a biblioteca `discord.py`, que oferece funcionalidades como mensagem de boas-vindas, comandos de moderação (clear, kick, ban, mute e unmute), e sistema de permissões.

## ⚙️ Funcionalidades

- 🎉 Mensagem de boas-vindas automática com embed
- 🧹 `!clear <quantidade>` – Limpa mensagens do canal
- 🦵 `!kick @membro [motivo]` – Expulsa um membro
- 🔨 `!ban @membro [motivo]` – Bane um membro
- 🔇 `!mute @membro` – Silencia um membro
- 🔊 `!unmute @membro` – Remove o silêncio de um membro

## 🔐 Permissões Necessárias

Cada comando exige o bot ter permissões específicas:
- `!clear`, `!mute`, `!unmute` → `Gerenciar mensagens`
- `!kick` → `Expulsar membros`
- `!ban` → `Banir membros`
--------
