# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

### Team members

* Jaroslav Polkorab (responsible for xxx)
* Tomáš Kristek (responsible for xxx)

## Hardware description
In our project we used arduino uno board with external modules. In our case we were using joy-stick, rotary encoder and PmodCLP LCD module. 

* Schmatic: 
 ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/obr%C3%A1zek_sus_sch%C3%A9ma.png)

As we can see, we are reading two analog values from the joy-stick, two digital values form an encoder and for each component we also got switch signal. 

### Rotary Encoder

Rotary Encoders generates two digital square waves, first one is named CLK(Clock) and second is named DT(Data). If we compare those two each other, we get which way we move the knob. 

* Rotary Encoder: 
![encoder](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/rotary_encoder.webp)

* Wave form:
![waveencoder](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/encoderwave.png)

### Joy-stick 

In case of joy-stick we got two analogs outputs. First one is X-axis and the second one is Y-axis. These two axis are created by potentiometers inside the joystick. 

* Joy-stick: 
![joystick](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Project/obrazky/encoderwave.png)


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. [Rotary Encoder](https://docs.nanoframework.net/devicesdetails/RotaryEncoder/README.html)
2. ...
