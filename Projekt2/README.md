# Project 2

Application of two servo motors.

- [x] Reading Encoder 
- [x] Working LCD
- [x] Working Servo
- [x] Custom characters
- [x] Markdown file
- [ ] Video
- [ ] Finish 🎉


# Table of Contents
**[Hardware description](#hardware-description)**

   * [Rotary Encoder](#rotary-encoder)
   * [Servo SG90](#Servo)
   * [LCD](#lcd)

**[Software description](#software-description)**
   * [Repository structure](#repostruct)
   * [Flowcharts](#flowcharts)
      * [Main](#main)
      * [Timer1](#timer1)

**[Video](#video)**</p>
**[References](#references)**

### Team members

* Jaroslav Polkorab (responsible for Github documentation,encoder program, servo registers)
* Tomáš Kristek (responsible for video , debugging)

## Hardware description <div id="hardware-description"/>
For our project, we are using an arduino uno board with external modules. For this case, we are also using two servos, a rotary encoder and a PmodCLP LCD module.

* Schmatic: 
<p align="center">
  <img width="685" height="433" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/obrazky/Schema_serva.png">
</p>

As we can see we read two digital values from the encoder. The servos are controled by PWM signal. 

### Rotary Encoder <div id="rotary-encoder"/>

The rotary Encoders generate two digital square waves, the  first one is named CLK (Clock), and the second one  is named DT (Data). If we compare those two with each other, we get the direction in which the knob moves.

* Rotary Encoder: 
<p align="center">
  <img width="330.5" height="250" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/rotary_encoder.webp">
</p>


* Wave form:
<p align="center">
  <img width="650" height="482" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/encoderwave.png">
</p>


### Servo SG90 <div id="Servo"/>
The servo is powered by red +5V and brown GND cables. The Movement of servo is controled by the width of PWM signal.

* Servo: 
<p align="center">
  <img width="800" height="600" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/obrazky/SG90-Micro-Servo-Motor.png">
</p>



### LCD <div id="lcd"/>

As a display, we used the PmodCLP LCD, which is basically a classic LCD 16x2 display with adapters to FPGA boards. 
<p align="center">
  <img width="400" height="429" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/pmod_clp_vetsi.png">
</p>

## Software description <div id="software-description"/>
For this project we used only library included in school computer exercises.

### Repository structure <div id="repostruct"/>

   ```c
   Project  
   ├── include 
   |    └── README
   |    └── timer.h
   ├── lib             // Library  
   |    └── gpio
   |    └── lcd
   |    └── uart
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```
#### Links to files 
* [Include](https://github.com/Polkorabjaroslav/Digital-electronics-2/tree/main/Projekt2/include)
   * [timer.h](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/include/timer.h)
* [Libraries](https://github.com/Polkorabjaroslav/Digital-electronics-2/tree/main/Projekt2/lib)
   * [gpio](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/lib/gpio)
   * [lcd](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/lib/lcd)
   * [uart](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/lib/uart)
* [Source](https://github.com/Polkorabjaroslav/Digital-electronics-2/tree/main/Projekt2/src)
   * [main.c](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/src/main.c)
   
### Flowcharts <div id="flowcharts"/>
#### Main:   <div id="main"/>
<p align="center">
  <img width="121" height="391" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/obrazky/Untitled%20Diagram.drawio.png">
</p>


#### Timer1: <div id="timer1"/>
<p align="center">
  <img width="666" height="1029" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Projekt2/obrazky/Timer1.png">
</p>



## Video <div id="video"/>

[Video](https://www.youtube.com/watch?v=mfIAXYet1iA)

## References <div id="references"/>

1. [Rotary Encoder](https://docs.nanoframework.net/devicesdetails/RotaryEncoder/README.html)
2. [Servo](https://www.laskakit.cz/plastove-micro-servo-sg90-9g--kontinualni/)
3. [LCD](https://www.tme.eu/en/details/410-142p/add-on-boards/digilent/pmodclp/)
4. [GPIO](https://github.com/Polkorabjaroslav/Digital-electronics-2/tree/main/lab2-gpio_library)
6. [ARDUINO 328P manual](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
