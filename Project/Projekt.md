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

**[Video](#video)**

**[References](#references)**

### Team members

* Jaroslav Polkorab (responsible for xxx)
* Tomáš Kristek (responsible for xxx)
* 

## Hardware description <div id="hardware-description"/>
In our project we used arduino uno board with external modules. In our case we were using joy-stick, rotary encoder and PmodCLP LCD module. 

* Schmatic: 
 ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/obr%C3%A1zek_sus_sch%C3%A9ma.png)

As we can see, we are reading two analog values from the joy-stick, two digital values form an encoder and for each component we also got switch signal. 

### Rotary Encoder <div id="rotary-encoder"/>

Rotary Encoders generates two digital square waves, first one is named CLK(Clock) and second is named DT(Data). If we compare those two each other, we get which way we move the knob. 

* Rotary Encoder: 
![encoder](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/rotary_encoder.webp)

* Wave form:
![waveencoder](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/encoderwave.png)

### Joy-stick <div id="joy-stick"/>

In case of joy-stick we got two analogs outputs. First one is X-axis and the second one is Y-axis. These two axis are created by potentiometers inside the joystick. 

* Joy-stick: 

![joystick](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/joystick.jpg)

* X-Y axis

![joystick](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/potentiometers.jpg)

### LCD <div id="lcd"/>

As display we used PmodCLP LCD, which is basicaly classic LCD 16x2 display with adapters to FPGA boards. 
![joystick](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/pmod_clp_vetsi.png)

## Software description <div id="software-description"/>

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video <div id="video"/>

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References <div id="references"/>

1. [Rotary Encoder](https://docs.nanoframework.net/devicesdetails/RotaryEncoder/README.html)
2. [Joy-stick](https://navody.dratek.cz/navody-k-produktum/arduino-joystick-ps2.html)
3. [LCD](https://www.tme.eu/en/details/410-142p/add-on-boards/digilent/pmodclp/)
