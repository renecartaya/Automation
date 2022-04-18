
# Automation and CNC

The current repository contains documentation related to CNC Robotics solutions for Lab automation applications assisted by Machine Learning algorithms.

The project is focused on the development of:

 1) XYZ Positioning systems operating in cartesian coordinates
 2) Selective Compliance Assembly Robot Arm (SCARA) Robot
 3) Proportional Integral Derivative (PID) controller for sample temperature control
 4) Peristaltic pump for high accuracy liquids pumping

The project includes the operation of stepper motors and servomotors.

## System scheme

![alt text](https://github.com/renecartaya/Automation-and-CNC/blob/main/Autosampler%20I.png)

## Requeriments

It is necessary to install the module PySerial. One way is to run in the command prompt the following line.

  >> pip install PySerial

The folder GUI Firmware contains the code for the programming of the microcontrollers enabling them to receive the command from the Computer. The folder GUI code includes the code in python for general control and data acquisition of the actuators and sensors.

## Hardware used

### XYZ Positioning system

The XYZ Positioning system as actuators used 3xNema17 steppers motors and one 20 kg Servo Motor. The stepper motors were moved through driver A4988, and the stepper motors were moved using Arduino driving signals while the engine was connected directly to the power supply. The drivers were controlled through the Joy-IT Development board, an Arduino UNO compatible board. The system was also tested using an original Arduino UNO board. The power supply was settled at 6.8 Volts; it is the maximum suitable voltage for the Servomotor and enough to move the Steppers. 

### Grafical User Interface (GUI)

The GUI allows to control the XYZ positioning system in order to access any position on the table, get the home position or lead specific functions.

![alt text](https://github.com/renecartaya/Automation-and-CNC/blob/main/GUI_Autosampler.png)

## Observation

The current system is under development. 
