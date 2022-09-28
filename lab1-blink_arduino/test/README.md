# Lab 1: Jaroslav Polkorab

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{
    
    uint8_t led_value = LOW;
    pinMode(LED_GREEN, OUTPUT); 
    // Infinite loop
    while (1)
    {
        digitalWrite(LED_GREEN,led_value); 
        _delay_ms(LONG_DELAY); //LONG_DELAY 750ms 
        digitalWrite(LED_GREEN,HIGH);
        _delay_ms(500);
        digitalWrite(LED_GREEN,led_value);
        _delay_ms(SHORT_DELAY);  //SHORT_DELAY 250ms
        digitalWrite(LED_GREEN,HIGH);     
        _delay_ms(1000); 
    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Obrazky/Blink.png)
