/***********************************************************************
 * 
 * Use Analog-to-digital conversion to read push buttons on LCD keypad
 * shield and display it on LCD screen.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2018 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "adc.h"
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions
#include <math.h>


#define CLK PC2
#define joyButt PB2
#define DT PC4
#define SW PC3



/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion every 100 ms.
 *           When AD conversion ends, send converted value to LCD screen.
 * Returns:  none
 **********************************************************************/
uint8_t lastStateCLK;
uint8_t currentStateCLK;
int8_t counter;
uint16_t guy[] = {
  0b01110,
  0b11101,
  0b11101,
  0b11110,
  0b11110,
  0b01110,
  0b01010,
  0b01010,

  0b00011,
  0b00110,
  0b01000,
  0b11001,
  0b11000,
  0b01000,
  0b00110,
  0b00011,

  0b11111,
  0b00000,
  0b11001,
  0b00001,
  0b11001,
  0b00100,
  0b11000,
  0b11111,

  0b11111,
  0b00000,
  0b00100,
  0b00101,
  0b00100,
  0b11000,
  0b00000,
  0b11111,

  0b11100,
  0b00110,
  0b11010,
  0b00001,
  0b11001,
  0b00101,
  0b11010,
  0b11100
};

int main(void)
{
    // Initialize display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(0, 0); lcd_puts("X:");
    lcd_gotoxy(10, 0); lcd_puts("Enc:");
    lcd_gotoxy(0, 1); lcd_puts("Y:");
    lcd_command(1<<LCD_CGRAM);       // Set addressing to CGRAM (Character Generator RAM// ie to individual lines of character patterns
    for (uint8_t i = 0; i < 40; i++)  // Copy new character patterns line by line to CGRAM
    lcd_data(guy[i]);
    lcd_command(1<<LCD_DDRAM); 

    GPIO_mode_input_nopull(&DDRC,CLK);
    GPIO_mode_input_pullup(&DDRC,SW);
    GPIO_mode_input_nopull(&DDRC,DT);
    GPIO_mode_input_nopull(&DDRB,joyButt);
    /*GPIO_mode_output(&DDRB,LED1);
    GPIO_mode_output(&DDRB,LED2);
    GPIO_mode_output(&DDRB,LED3);
    GPIO_mode_output(&DDRB,LED4);
    GPIO_mode_output(&DDRC,LED5);*/
    Clock_prescalar_128();
    Vref_AVcc();
    ADIE_on();
    ADEN_on();
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 33 ms and enable overflow interrupt
    TIM2_overflow_2ms();
    TIM2_overflow_interrupt_enable();
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask
    sei();
    ADSC_on();
    // Infinite loop  
    

    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 100 ms.
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{ 
    // Start ADC conversion
  char string[4];
  currentStateCLK = GPIO_read(&PINC, CLK);
  static int8_t nooverflow = 0;
  nooverflow++;
  

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (GPIO_read(&PINC, DT) != currentStateCLK) 
    {
			counter ++;
      if(counter > 99)
      {
        counter = 99;
      }
		} 
    else 
    {
		  counter --;
      if (counter < -9) //  LDC don't have a space for bigger mun 
      {
        counter = -9;
      }
		}
    itoa(counter,string,10);
    lcd_gotoxy(14,0); 
    lcd_puts("    ");
    lcd_gotoxy(14,0); 
		lcd_puts(string);
	}

	// Remember last CLK state
	lastStateCLK = currentStateCLK;
  //button
  
  if(nooverflow > 100)
  {
    nooverflow = 0;
    ADSC_on();
    ADCSRA &=~(1<<ADSC);
  }
  
}

ISR(TIMER1_OVF_vect)
{
  uint8_t button;/// button řešit rychleji, nebo podmínka 3x v 0 poté výpis 
  uint8_t buttonjoy; 
  button = GPIO_read(&PINC,SW);
  if(button == 0)
  {
    counter = 0;
    lcd_gotoxy(14,0); 
    lcd_puts("    ");
    lcd_gotoxy(14,0); 
    lcd_puts("0");
  }
  buttonjoy = GPIO_read(&PINB,joyButt);
  if(buttonjoy == 0)
  {
    lcd_gotoxy(6,2);
    lcd_puts("      ");
    lcd_gotoxy(6,2);
    lcd_putc(0x00);
    lcd_gotoxy(7,2);
    lcd_putc(0x01);
    lcd_gotoxy(8,2);
    lcd_putc(0x02);
    lcd_gotoxy(9,2);
    lcd_putc(0x03);
    lcd_gotoxy(10,2);
    lcd_putc(0x04);
  }
  else 
  {
    lcd_gotoxy(6,2);
    lcd_puts("      ");
    lcd_gotoxy(6,2);
    lcd_puts("NE");
  }
}

ISR(ADC_vect)
{
  uint16_t valueH = ADC;
  char string[4];  // String for converted numbers by itoa()

  if(ADMUX == 0b01000000) //choose ADMUX adress
  {                       //ADC0
     
    itoa(valueH, string, 10);
    lcd_gotoxy(2,0);
    lcd_puts("    ");
    lcd_gotoxy(2,0);
    lcd_puts(string);
    ADMUX = 0b01000001;
  }  
  else if(ADMUX == 0b01000001)
  {                       //ADC1
    itoa(valueH, string, 10);
  
    lcd_gotoxy(2,1);
    lcd_puts("    ");
    lcd_gotoxy(2,1);
    lcd_puts(string);
    ADMUX = 0b01000000;
  }
  
}
