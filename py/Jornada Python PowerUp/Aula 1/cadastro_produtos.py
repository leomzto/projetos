import pyautogui
import time

pyautogui.PAUSE = 0.5
SISTEMA = "https://dlp.hashtagtreinamentos.com/python/intensivao/login"
EMAIL = "email.login.sistema@gmail.com"
SENHA = "senha de login"

# ABRIR O NAVEGADOR
print('Abrindo navegador...')
pyautogui.press("win")
pyautogui.write("chrome")
pyautogui.press("enter")
time.sleep(2.5)

# ENTRAR NO SITE DO SISTEMA
print('Entrando no sistema...')
pyautogui.write(SISTEMA)
pyautogui.press("enter")
time.sleep(2.5)

# LOGAR NO SISTEMA
print('Fazendo login no sistema...')
pyautogui.click(x=780, y=376)
pyautogui.write(EMAIL)
pyautogui.press("tab")
pyautogui.write(SENHA)
pyautogui.click(x=938, y=536)
time.sleep(2.5)

# CADASTRAR UM PRODUTO
import pandas as pd

tabela = pd.read_csv("produtos.csv")

for linha in tabela.index:
    # ESCREVER CODIGO DO PRODUTO
    pyautogui.click(x=881, y=253)
    pyautogui.write(str(tabela.loc[linha, 'codigo']))
    # ESCREVER MARCA DO PRODUTO
    pyautogui.press('tab')
    pyautogui.write(str(tabela.loc[linha, 'marca']))
    # ESCREVER TIPO DO PRODUTO
    pyautogui.press('tab')
    pyautogui.write(str(tabela.loc[linha, 'tipo']))
    # ESCREVER CATEGORIA DO PRODUTO
    pyautogui.press('tab')
    pyautogui.write(str(tabela.loc[linha, 'categoria']))
    # ESCREVER PREÇO UNITARIO DO PRODUTO
    pyautogui.press('tab')
    pyautogui.write(str(tabela.loc[linha, 'preco_unitario']))
    # ECREVER CUSTO DO PRODUTO
    pyautogui.press('tab')
    pyautogui.write(str(tabela.loc[linha, 'custo']))
    # ESCREVER OBS
    pyautogui.press('tab')
    obs = tabela.loc[linha, "obs"]
    if not pd.isna(obs):
            pyautogui.write(str(tabela.loc[linha, "obs"]))
    # CLICA EM ENVIAR
    pyautogui.scroll(5000) # volta pro topo da pagina
    pyautogui.press('tab')
    pyautogui.press('enter')
