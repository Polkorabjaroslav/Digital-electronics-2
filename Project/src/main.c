#include "timer.h"
#include <lcd.h>
#include <gpio.h>
#include <stdlib.h>
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC

#define CLK PB3
#define SW PB5
#define DT PB4

uint8_t lastStateCLK;
uint8_t currentStateCLK;
uint8_t button;
int8_t counter;
int main(void) 
{
  lcd_init(LCD_DISP_ON); 
  lcd_gotoxy(0,0); 
  GPIO_mode_input_nopull(&DDRB,CLK);
  GPIO_mode_input_nopull(&DDRB,SW);
  GPIO_mode_input_nopull(&DDRB,DT);
    
    //lastStateCLK = GPIO_read(&PINB,CLK);
  TIM1_overflow_interrupt_enable();
  TIM1_overflow_33ms();
  TIM0_overflow_interrupt_enable();
  TIM0_overflow_16ms();
  sei();
  while(1)
  { 
  }
  return(0);
}

ISR(TIMER0_OVF_vect) //timer for encoder
{
  char string[4];
  currentStateCLK = GPIO_read(&PINB, CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (GPIO_read(&PINB, DT) != currentStateCLK) 
    {
			counter --;
		} 
    else 
    {
		  counter ++;
		}

    itoa(counter,string,10);
    lcd_gotoxy(0,0); 
    lcd_puts("    ");
    lcd_gotoxy(0,0); 
		lcd_puts(string);
	}

	// Remember last CLK state
	lastStateCLK = currentStateCLK;

}

ISR(TIMER1_OVF_vect) //timer for button
{
  button = GPIO_read(&PINB,SW);
  if(button==0)
  {
    lcd_puts("           ");
    lcd_gotoxy(0,1);
    lcd_puts("Zmacknuto");
  }
  else
  {
    lcd_gotoxy(0,1);
    lcd_puts("Nezmacknuto");
  }
}