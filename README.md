
# Automation and CNC

The current repository contains documentation related to the development of different automation projects. Among the the project under development can be mentioned the development of:

 1) XYZ Positioning systems
 2) Selective Compliance Assembly Robot Arm (SCARA) Robot
 3) Proportional Integral Derivative (PID) controller for sample temperature control
 4) Peristaltic pump for liquids handling
 5) Coffee machines - integrating embedding programming, temperature control and water pumping

The project includes the operation of stepper motors and servomotors.

## XYZ Positioning system - applications for pick and place (pnp), and liquid handler

### System scheme

![alt text](https://github.com/renecartaya/Automation-and-CNC/blob/main/Autosampler%20I.png)

### Requeriments

It is necessary to install the module PySerial. One way is to run in the command prompt the following line.

  >> pip install PySerial

The folder GUI Firmware contains the code for the programming of the microcontrollers enabling them to receive the command from the Computer. The folder GUI code includes the code in python for general control and data acquisition of the actuators and sensors.

### Hardware used

The XYZ Positioning system as actuators uses three units of Nema17 steppers motors and one 20 kg Servo Motor. The stepper motors were moved through driver A4988, and the stepper motors were moved using and ATMEGA328 microcontroller for the generation of the driving signals while the engine was connected directly to the power supply. The drivers were controlled through the Joy-IT Development board, an Arduino UNO compatible board. The system was also tested using an original Arduino UNO board. The power supply was settled at 6.8 Volts; it is the maximum suitable voltage for the Servomotor and enough to move the Steppers. 

### Grafical User Interface (GUI)

The GUI allows to control the XYZ positioning system for applications as pick and place (PnP) and liquid handling solutions as examples. There the GUI is aimed to command the access of selected position on the table, get the home position or lead specific functions.

![alt text](https://github.com/renecartaya/Automation-and-CNC/blob/main/GUI_Autosampler.png)

### Observation

The current repository is under development. 

## Liquid sample transfer and storage

It is an automation project aimed to didactically combine heating/cooling systems, liquid pumps and embedded programming for control of sample temperatures and liquid sample transfers. 


