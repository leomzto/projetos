import tkinter as tk
import time

def horaAtual():
    agora = time.strftime('%X\n%x')
    label.config(text=agora)
    label.after(1000, horaAtual)


janela = tk.Tk()
janela.geometry('400x200')
janela.title('Relogio Digital')

label  = tk.Label(janela, font=('Arial', 30))
label.pack(expand=True)

horaAtual()

janela.mainloop()
