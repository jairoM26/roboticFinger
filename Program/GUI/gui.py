'''
Instituto Tecnológico de Costa Rica
Python 3.4.0
Jairo Méndez Martínez
17-05-2018
'''
#importar bibliotecas necesarias para la realización del proyecto
from tkinter import *
import os
from threading import Thread
import threading
import random
import time
from datetime import datetime
import tkinter.scrolledtext as tkst

fileName = "text.txt"

def writeFile(x, function, number):
    file = open(fileName,"w") 
    tmp = "resolution "+resolution+"\n"
    file.write(tmp)
    if(x != 0):
        tmp = function + " " + number +"\n"
        file.write(tmp)
    else:
        file.write(function+"\n")
    file.close() 

#-------------------------------------------------------------------------------------------------------------------------------------------------------------
#crear ventana principal
ventana_principal = Tk()   #la acredita o atributa como ventana principal
ventana_principal.title('RoboticFinger')  #le pone el título a la ventana
ventana_principal.config(bg = 'light blue')  #le otorga color al 2fondo
ventana_principal.geometry('400x400+100+30')  #destina el tamaño de la ventana
ventana_principal.resizable(width=NO, height=NO)

canvas= Canvas(ventana_principal, width=800, height=700, bg= 'light blue').place(x=-1,y=-1)

labelResolution = Label(canvas, text = "Screen Resolution", font= ('roboto condensed',12), bg= 'light blue', fg= 'blue').place(x=10,y=10)
entryResolution = Entry(canvas, width=3, bg='white', font= ('roboto condensed',12),fg='blue')
entryResolution.place(x=160,y=10) 
entryResolution.insert(0, "1")
entryMove= Entry(canvas, width=3, bg='white', font= ('roboto condensed',12),fg='blue')
entryMove.place(x=85,y=228)
labelMove=Label(canvas, text = "Key", font= ('roboto condensed',12), bg= 'light blue', fg= 'blue').place(x=130,y=229)
entryPress= Entry(canvas, width=3, bg='white', font= ('roboto condensed',12),fg='blue')
entryPress.place(x=275,y=55)
labelPress=Label(canvas, text = "Seconds", font= ('roboto condensed',12), bg= 'light blue', fg= 'blue').place(x=317,y=55)
key = ""
seconds = ""
resolution = ""
#---------------------------------------------------functions definition-----------------------------------------------
def push():
    resolution = entryResolution.get()
    print("touch")
    writeFile(0, "touch", 0)
    os.system("cd .. && cd Interprete/ && sudo ./roboticFinger -g ../GUI/"+fileName)

def press():
    resolution = entryResolution.get()
    seconds = entryPress.get()
    print(seconds)
    writeFile(1, "press", seconds)
    os.system("cd .. && cd Interprete/ && sudo ./roboticFinger -g ../GUI/"+fileName)

def moveTo():
    resolution = entryResolution.get()
    key = entryMove.get()
    print(key)
    writeFile(1, "move", key)
    os.system("cd .. && cd Interprete/ && sudo ./roboticFinger -g ../GUI/"+fileName)

#boton para regresar
boton_touch = Button(ventana_principal, text= 'TOUCH', height= 8, width=12,  command= push, font= ('roboto condensed',10), bg= 'white', fg= 'blue').place(x=80, y=70)
boton_press = Button(ventana_principal, text= 'PRESS', height= 8, width=12,  command= press, font= ('roboto condensed',10), bg= 'white', fg= 'blue').place(x=250, y=100)
boton_move = Button(ventana_principal, text= 'MOVE TO', height= 8, width=12,  command= moveTo, font= ('roboto condensed',10), bg= 'white', fg= 'blue').place(x=80, y=250)


ventana_principal.mainloop()
