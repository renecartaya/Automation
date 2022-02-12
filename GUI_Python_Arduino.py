import serial # require pip install PySerial for Serial communication
from tkinter import *
import tkinter as tk 
import time   #for delay functions

root = Tk()
root.wm_iconbitmap('C:/Users/renea/Pictures/Logos/gen_logo.ico')
root.wm_title('Name of the Company that own the software')
root.resizable(width=False, height=False)
root.geometry("450x130+300+40")

mainFrame = Frame(root, bd=10, bg='gainsboro',relief=RIDGE)
mainFrame.grid()

innerFrame = Frame(mainFrame, bd=5, bg='gainsboro', relief=RIDGE)
innerFrame.grid()

       # ==========================================  Importante ==================================================#

ser = serial.Serial('COM5', 9600)  # open serial port
time.sleep(2)                      # wait 2 seconds

       # =========================================== Functions set ===============================================#

def turn_LED_ON():
    ser.write(b'H')

def turn_LED_OFF(): 
    ser.write(b'L')

        #============================================Buttons Widget===============================================#

btn_On = Button(innerFrame, text="LED ON", width=10, height =2, font=('arial',18,'bold'), bd=7, bg='gainsboro', command=turn_LED_ON)
btn_On.grid(row=0,column = 0)

btn_Off = Button(innerFrame, text="LED OFF", width=10, height =2, font=('arial',18,'bold'), bd=7, bg='gainsboro', command=turn_LED_OFF)
btn_Off.grid(row=0,column = 2)


root.mainloop()