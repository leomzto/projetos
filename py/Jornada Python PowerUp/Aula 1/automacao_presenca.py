import pyautogui
from time import sleep

AULA = numero da aula
SITE = 'https://hashaqui.com/certificados/jornada-python'
CODIGO = 'Codigo da aula'
EMAIL = 'Email para envio do certificado'
NOME = 'Nome a ser exibido no certificado'

# ABRIR O NAVEGADOR
pyautogui.press('win')
pyautogui.write('chrome')
pyautogui.press('enter')
sleep(2)
# ACESSAR O SITE
pyautogui.write(SITE)
pyautogui.press('enter')
sleep(2)
# SELECIONAR A AULA
pyautogui.press('tab')
pyautogui.press('enter')
pyautogui.press('down', presses=AULA)
pyautogui.press('enter')
sleep(0.75)
# INSERIR O CODIGO DA AULA
pyautogui.press('tab')
pyautogui.write(CODIGO)
sleep(0.75)
#INSERIR O EMAIL
pyautogui.press('tab')
pyautogui.write(EMAIL)
sleep(0.75)
# INSERIR O NOME
pyautogui.press('tab')
pyautogui.write(NOME)
sleep(0.75)
# ENVIAR
pyautogui.press('tab')
pyautogui.press('enter')

