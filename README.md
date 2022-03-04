
# Automation and CNC

The current repository contains documentation related to CNC Robotics solutions for Lab automation applications assisted by Machine Learning algorithms.

The project is focused on the development of:

 1) XYZ Positioning systems operating in cartesian coordinates
 2) Selective Compliance Assembly Robot Arm (SCARA) Robot
 3) Proportional Integral Derivative (PID) controller for sample temperature control
 4) Peristaltic pump for high accuracy liquids pumping

The project includes the operation of stepper motors and servomotors.

## Requeriments

It is necessary to install the module PySerial. One way is to run in the command prompt the following line.

  >> pip install PySerial

The folder GUI Firmware contains the code for the programming of the microcontrollers enabling them to receive the command from the Computer. The folder GUI code includes the code in python for general control and data acquisition of the actuators and sensors.

