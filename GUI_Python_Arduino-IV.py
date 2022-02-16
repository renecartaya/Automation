########################################## Loading of Packages ##################################################

import serial
from tkinter import *
import tkinter as tk
import time

################################# GUI Windown logo and name configuration ########################################

root = Tk() 
root.wm_iconbitmap('C:/Users/renea/Pictures/Logos/gen_logo.ico')
root.wm_title('Software or Company Name')
root.geometry("350x350")

########################################  Serial port configuration ##############################################

commPort = 'COM6'
serial_comm = serial.Serial(commPort, baudrate = 9600, timeout = 1)

########################################## Parameters pre-setting #################################################

blinkTime = ['50','100','200','400','600','800','1000','1200']
userDelay = StringVar()
delayMenu = tk.OptionMenu(root,userDelay,*blinkTime)
userDelay.set('800')
delayLabel = tk.Label(root,text="Blink (ms)")
delayLabel.grid(row=1,column=0)
delayMenu.grid(row=1,column=1)

############################################### Functions set #####################################################

def turn_LED_ON():
    if blinkState.get() == 1:
        blinkLED()
    else:
        serial_comm.write(b'H')
        
def turn_LED_OFF(): 
    serial_comm.write(b'L')

def turn_LED_BLINK():
    if blinkState.get() == 1:
        serial_comm.write(b'h')
        time.sleep(1)
        delay = userDelay.get()
        numBlinks = entryBlink.get()
        dataToSend = delay + '-' + numBlinks
        serial_comm.write(dataToSend.encode())
    
############################################### Buttons Widget#######################################################

btn_On = tk.Button(root, text="Turn On", command=turn_LED_ON)
btn_On.grid(row=0, column=0)

btn_Off = tk.Button(root, text="Turn Off", command=turn_LED_OFF)
btn_Off.grid(row=0, column=1)

blinkState = IntVar()
chkBtn_Blink = tk.Checkbutton(root, text = "Blink",variable = blinkState, command = turn_LED_BLINK)
chkBtn_Blink.grid(row=0, column = 2)

########################################## Parameters entry #################################################

entryBlink = Entry(root,width=3)
entryBlink.insert(0,"5")
entryBlinkLabel = tk.Label(root,text="Num Blinks")
entryBlinkLabel.grid(row=2,column =0)
entryBlink.grid(row=2,column = 1)

root.mainloop()