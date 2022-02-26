
# Automation and CNC

The current repository contains documentation related to the development of CNC Robotics solutions for Lab automation applications assisted by Machine Learning algorithms.

The project is focused in the development of:

 1) XYZ Positioning systems operating in cartesian coordinates
 2) Selective Compliance Assembly Robot Arm (SCARA) Robot
 3) Proportional Integral Derivative (PID) controller for sample temperature control
 4) Peristaltic pump for high accuracy liquids pumping

The project is includs the operation of stepper motors, and servomotor.

## Requeriments

Is necesary to install the module PySerial. One way is to run in the command prompt the following line.

  >> pip install PySerial

The folder GUI Firmware contains the code for the programming of the microcontrollers enabling them to receive command from the Computer. The folder GUI code contains the code in python for the control and data acquisition of the actuators and sensors in general.

