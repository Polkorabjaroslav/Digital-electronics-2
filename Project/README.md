# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

- [x] Reading Encoder 
- [x] Reading Joystick
- [x] Working LCD
- [x] Reading buttons
- [x] Own ADC library
- [x] Counter
- [x] X-Y axis
- [x] Reset button
- [x] Custom character button 
- [ ] Markdown file
- [ ] Video
- [ ] Finish 🎉


# Table of Contents
**[Hardware description](#hardware-description)**

   * [Rotary Encoder](#rotary-encoder)
   * [Joy-stick](#joy-stick)
   * [LCD](#lcd)

**[Software description](#software-description)**
   * [Flowcharts](#flowcharts)
      * [Main](#main)
      * [Timer2](#timer2)
      * [Timer1](#timer1)
      * [ADC](#acd)

**[Video](#video)**
**[References](#references)**

### Team members

* Jaroslav Polkorab (responsible for xxx)
* Tomáš Kristek (responsible for xxx)

## Hardware description <div id="hardware-description"/>
For our project, we are using an arduino uno board with external modules. For this case, we are also using a joy-stick, a rotary encoder and a PmodCLP LCD module.

* Schmatic: 
 ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/obr%C3%A1zek_sus_sch%C3%A9ma.png)

As we can see, we are reading two analog values from the joy-stick, two digital values from the encoder, and for each component we also get a switch signal.

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


### Joy-stick <div id="joy-stick"/>

In case of a joy-stick, we have two analog outputs. The first one is the X-axis and the second one is the Y-axis. These two axis are created by potentiometers inside the joystick. 

* Joy-stick: 
<p align="center">
  <img width="400" height="429" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/joystick.jpg">
</p>


* X-Y axis
<p align="center">
  <img width="387" height="215" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/potentiometers.jpg">
</p>


### LCD <div id="lcd"/>

As a display, we used the PmodCLP LCD, which is basically a classic LCD 16x2 display with adapters to FPGA boards. 
<p align="center">
  <img width="400" height="429" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/pmod_clp_vetsi.png">
</p>

## Software description <div id="software-description"/>

### Flowcharts <div id="flowcharts"/>
#### Main:   <div id="main"/>
<p align="center">
  <img width="122" height="512" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/Untitled%20Diagram.drawio.png">
</p>

#### Timer2: <div id="timer2"/>
<p align="center">
  <img width="691" height="640" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/timer2_OVF.png">
</p>

#### Timer1: <div id="timer1"/>
<p align="center">
  <img width="356" height="551" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/Timer1_OVF.drawio.png">
</p>

#### ADC: <div id="ADC"/>
<p align="center">
  <img width="312" height="442" src="https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/ADC_vect.drawio.png">
</p>

## Video <div id="video"/>

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References <div id="references"/>

1. [Rotary Encoder](https://docs.nanoframework.net/devicesdetails/RotaryEncoder/README.html)
2. [Joy-stick](https://navody.dratek.cz/navody-k-produktum/arduino-joystick-ps2.html)
3. [LCD](https://www.tme.eu/en/details/410-142p/add-on-boards/digilent/pmodclp/)
