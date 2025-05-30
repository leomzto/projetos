import discord
from discord.ext import commands

intents = discord.Intents.default()
intents.message_content = True

bot = commands.Bot(command_prefix='!', intents=intents)

@bot.event
async def on_ready():
    print(f'Bot conectado como {bot.user}')

@bot.event
async def on_member_join(member):
    canal = discord.utils.get(member.guild.text_channels, name='boas-vindas')
    if canal:
        embed = discord.Embed(
            title="🎉 Bem-vindo(a)!",
            description=f"Olá {member.mention}, seja muito bem-vindo(a) ao servidor!",
            color=0x00ff00
        )
        embed.set_thumbnail(url=member.avatar.url)
        embed.set_footer(text="github.com/leomzto/projetos/tree/main/py/bot%20discord")
        await canal.send(embed=embed)

@bot.command()
@commands.has_permissions(manage_messages=True)
async def clear(ctx, quantidade: int):
    await ctx.channel.purge(limit=quantidade)
    await ctx.send(f'Limpei as ultimas {quantidade} mensagens do chat')

@bot.command()
@commands.has_permissions(kick_members=True)
async def kick(ctx, member: commands.MemberConverter, *, motivo=None):
    await member.kick(reason=motivo)
    await ctx.send(f'{member} foi expulso. Motivo: {motivo}')

@bot.command()
@commands.has_permissions(ban_members=True)
async def ban(ctx, member: commands.MemberConverter, *, motivo=None):
    await member.ban(reason=motivo)
    await ctx.send(f'{member} foi banido. Motivo: {motivo}')

@bot.command()
@commands.has_permissions(manage_messages=True)
async def mute(ctx, member: commands.MemberConverter):
    role = discord.utils.get(ctx.guild.roles, name="Mutado")
    if not role:
        role = await ctx.guild.create_role(name="Mutado")

        for canal in ctx.guild.channels:
            await canal.set_permissions(role, send_messages=False, speak=False)

    await member.add_roles(role)
    await ctx.send(f'{member} foi mutado.')

@bot.command()
@commands.has_permissions(manage_messages=True)
async def unmute(ctx, member: commands.MemberConverter):
    role = discord.utils.get(ctx.guild.roles, name="Mutado")
    if role in member.roles:
        await member.remove_roles(role)
        await ctx.send(f'{member} foi desmutado.')
    else:
        await ctx.send(f'{member} não está mutado.')

bot.run('TOKEN') #token escondido por segurança
