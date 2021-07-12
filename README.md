# Implementing 3 Servo movements by switches

## Description of hardwasre
In this project, harmonic Servo movements were assigned to each switch to act as robotic's arms. The design was constructed using an Arduino UNO, 6 Servo motors, 3 switches, and 3 1 kohms resistors to minimize the current through the switches. The Servo signal pins were connected to the digital pins on the Arduino, the Vccs and grounds of the Servo motors were connected to 5 volts and ground on the Arduino, the two terminals of the switches were connected to ground and 5 volts through a resistor for each, and digitals pins were connected to the ground of each switch pin. 

## Description of software
After including the Servo library and declaring variables and Servos, each Servo was attached to a digital pin and switches were set as inputs. Moreover, initial positions were written on each Servo. Each switch was set to be responsible for several harmonic movements using if statement. If a switch is pressed, taking an advantage of the delay function inside the for loop, the motors will start rotating slowly to a defined angle and they move back to their initial position. For the first two switches, a repetitive rotation will occur based on time using while loop, however, the third switch, a repetitive rotation will occur based on number of times the loop was executed.
Note that as the servos were rotated to a position, they came back to their initial position to avoid any obstacles of sudden movements.
