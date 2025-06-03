import pyautogui
from time import sleep
# CODIGO AULA 1: usepython
# CODIGO AULA 2:
# CODIGO AULA 3:
# CODIGO AULA 4:

AULA = 1
SITE = 'https://hashaqui.com/certificados/jornada-python'
CODIGO = ''
EMAIL = 'leopmanzato@gmail.com'
NOME = 'Leonardo Padovani Manzato'

pyautogui.press('win')
pyautogui.write('chrome')
pyautogui.press('enter')
sleep(2)
pyautogui.write(SITE)
pyautogui.press('enter')
sleep(2)
pyautogui.press('tab')
pyautogui.press('enter')
pyautogui.press('down', presses=AULA)
pyautogui.press('enter')
sleep(0.75)
pyautogui.press('tab')
pyautogui.write(CODIGO)
sleep(0.75)
pyautogui.press('tab')
pyautogui.write(EMAIL)
sleep(0.75)
pyautogui.press('tab')
pyautogui.write(NOME)
sleep(0.75)
pyautogui.press('tab')
pyautogui.press('enter')

