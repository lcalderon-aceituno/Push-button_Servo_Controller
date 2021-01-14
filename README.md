# Program: Servo controller
**Author:** Lydia Calderon-Aceituno
**Date:** December 8, 2021

**Purpose:** Moving a servo with push buttons

## Configuration
Designed for bare metal Mbed OS 6 (enabled through `mbed_app.json`).

## Hardware
### External
* Blue push button connected to p5 (DigitalIn)
* Green push button connected to p6 (DigitalIn)
* Yellow push button connected to p7 (DigitalIn)
* HS-422 HiTEC Servo connected to p21 and right power bus
* Battery pack connected to right power bus and ground 
  

## Flow
```mermaid
graph TD
A("main()") --> B{Is it true?}
B --> |yes| C[Is home button pushed?]
C--> |yes| D[Set angle to 0 degrees]
D --> E
C --> |no| E[Is increase button pushed and previous angle less than 90?]
E --> |yes| F[Increment angle by 1 degree]
F --> G
E--> |no| G[Is decrease button pushed and previous angle more than negative 90?]
G --> |yes| H[Decrease angle by 1 degree]
H --> I
G --> |no| I[Sleep for 100ms]
I --> B
```