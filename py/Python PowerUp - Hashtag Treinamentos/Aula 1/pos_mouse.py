import pyautogui
import keyboard

while True:
    if keyboard.is_pressed('p'):
        print(pyautogui.position())
        break


