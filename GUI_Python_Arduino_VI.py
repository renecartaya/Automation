import serial
from tkinter import *
import tkinter as tk
from tkinter import messagebox
import time

root = Tk() 
root.wm_iconbitmap('C:/Users/renea/Pictures/Logos/gen_logo.ico')
root.wm_title('Software or Company Name')
root.geometry("350x350")

commPort = 'COM6'
ser = serial.Serial(commPort, baudrate = 9600, timeout = 1)

blinkTime = ['50','100','200','400','600','800','1000','1200']
userDelay = StringVar()
delayMenu = tk.OptionMenu(root,userDelay,*blinkTime)
userDelay.set('800')
delayLabel = tk.Label(root,text="Blink (ms)")
delayLabel.grid(row=1,column=0)
delayMenu.grid(row=1,column=1)

def turn_LED_ON():
    if blinkState.get() == 1:
        turn_LED_BLINK()
    else:
        ser.write(b'H')
        
def turn_LED_OFF(): 
    ser.write(b'L')

def turn_LED_BLINK():
    if blinkState.get() == 1:
        ser.write(b'h')
        time.sleep(1)
        delay = userDelay.get()
        numBlinks = entryBlink.get()
        userInputVaild = userDataCheck(numBlinks)
        if userInputVaild == True:
            dataToSend = delay + '-' + numBlinks
            ser.write(dataToSend.encode())

def userDataCheck(userInput):
    try:
        int(userInput)
        return True
    except:
        messagebox.showerror("Error", "Please enter a valid integer", icon = 'error')
        return False

def menuBlinkEnable():
    if blinkState.get() != 1:
        blinkState.set(1)
    blinkLED()

def menuTurnOn():
    if blinkState.get() == 1:
        blinkState.set(0)
    ser.write(b'H')

def menuTurnOff():
    if blinkState.get() == 1:
        blinkState.set(0)
    ser.write(b'L')

def menuSave():
    print("Selected Save")

def exitGUI():
    root.destroy()

btn_On = tk.Button(root, text="Turn On", command=turn_LED_ON)
btn_On.grid(row=0, column=0)

btn_Off = tk.Button(root, text="Turn Off", command=turn_LED_OFF)
btn_Off.grid(row=0, column=1)

blinkState = IntVar()
chkBtn_Blink = tk.Checkbutton(root, text = "Blink",variable = blinkState, command = turn_LED_BLINK)
chkBtn_Blink.grid(row=0, column = 2)

entryBlink = Entry(root,width=3)
entryBlink.insert(0,"5")
entryBlinkLabel = tk.Label(root,text="Num Blinks")
entryBlinkLabel.grid(row=2,column =0)
entryBlink.grid(row=2,column = 1)

menuBar = Menu(root)
root.config(menu = menuBar)

fileMenu = Menu(menuBar,tearoff = 0)
menuBar.add_cascade(label ='File', menu = fileMenu)  
fileMenu.add_command(label ='Save', command = menuSave)
fileMenu.add_command(label ='Exit', command = exitGUI)

settings = Menu(menuBar, tearoff = 0)
menuBar.add_cascade(label ='Settings', menu = settings) 
settings.add_command(label ='Blink', command = menuBlinkEnable) 
settings.add_command(label ='Turn On', command = menuTurnOn)
settings.add_command(label ='Turn Off', command = menuTurnOff)

root.mainloop()