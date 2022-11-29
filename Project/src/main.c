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


#define CLK PC2
#define SW PB2
#define DT PC4
#define LED1 PB2
#define LED2 PB3
#define LED3 PB4
#define LED4 PB5
#define LED5 PC1


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
int main(void)
{
    // Initialize display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(0, 0); lcd_puts("X:");
    lcd_gotoxy(6, 0); lcd_puts("Encoder:");
    lcd_gotoxy(0, 1); lcd_puts("Y:");

    GPIO_mode_input_nopull(&DDRC,CLK);
    GPIO_mode_input_nopull(&DDRB,SW);
    GPIO_mode_input_nopull(&DDRC,DT);

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
    TIM1_overflow_4ms();
    TIM1_overflow_interrupt_enable();
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();
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
ISR(TIMER1_OVF_vect)
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
		} 
    else 
    {
		  counter --;
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
  
  if(nooverflow > 50)
  {
    nooverflow = 0;
    ADSC_on();
    ADCSRA &=~(1<<ADSC);
  }
  
}

ISR(TIMER2_OVF_vect)
{
  uint8_t button;/// button řešit rychleji, nebo podmínka 3x v 0 poté výpis 
  static uint8_t buttover = 0;
  buttover++;

  if(buttover>2)
  {
    button = GPIO_read(&PINB,SW);
    if(button == 0)
    {
      lcd_gotoxy(6,2);
      lcd_puts("        ");
      lcd_gotoxy(6,2);
      lcd_puts("Zmack");
    }
    else
    {
      lcd_gotoxy(6,2);
      lcd_puts("         ");
      lcd_gotoxy(6,2);
      lcd_puts("NEZmack");
    }
    buttover =0;
  }
}

ISR(ADC_vect)
{
  uint16_t valueH = ADC;
  char string[4];  // String for converted numbers by itoa()
  // Read converted value
  // Note that, register pair ADCH and ADCL can be read as a 16-bit value ADC
  switch(ADMUX)
  {
    case 0b01000000: //ADC0
      itoa(valueH, string, 10);
      lcd_gotoxy(2,0);
      lcd_puts("    ");
      lcd_gotoxy(2,0);
      lcd_puts(string);
      ADMUX = 0b01000001;
      break;

    case 0b01000001: //ADC1
      itoa(valueH, string, 10);
      lcd_gotoxy(2,1);
      lcd_puts("    ");
      lcd_gotoxy(2,1);
      lcd_puts(string);
      ADMUX = 0b01000000;
      break;
  }
}

