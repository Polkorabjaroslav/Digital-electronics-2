#ifndef F_CPU
# define F_CPU 16000000  /
#endif

#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>
#include <uart.h>

//define pins PB1 as sv_1 (servos)
#define sv_1 PB1
#define sv_2 PB2
//define pins for encoder
#define DT PC4
#define SW PC3
#define CLK PC2

uint32_t middle = 1500;
uint8_t counter;
uint16_t right = 2000;
uint16_t left = 1000;
int8_t time_dir = 25;
uint16_t serv_2 = 1500;

uint8_t lastStateCLK;
uint8_t currentStateCLK;
uint16_t overflow;


 

int main(void) 
{
  uart_init(UART_BAUD_SELECT(9600, F_CPU));
  //setting output pins
  GPIO_mode_output(&DDRB, sv_1);
  GPIO_mode_output(&DDRB, sv_2);
  //encoder inputs
  GPIO_mode_input_nopull(&DDRC,CLK);
  GPIO_mode_input_pullup(&DDRC,SW);
  GPIO_mode_input_nopull(&DDRC,DT);
  //setting PWM registers / PWM mode
  TCCR1A &=~ ((1<<COM1A0) | (1<<COM1B0));  
  TCCR1A |=  ((1<<COM1A1) | (1<<COM1B1));
  TCCR1A |=  (1<<WGM11);
  TCCR1B |=  (1<<WGM13);
  //prescalar
  TCCR1B |=  (1 << CS11);
  //PWM period
  ICR1=20000;
  //start position 
  OCR1A = middle;
  OCR1B = middle;
  //Timer overflow time + timer interrupts
  TIM0_overflow_1ms();
  TIM0_overflow_interrupt_enable();
  // global iterrupts
  sei();

  while(1)
  {}
  return 0;
}

 ISR(TIMER0_OVF_vect)
{ 
  overflow++;
  char string[4];
  currentStateCLK = GPIO_read(&PINC, CLK);


  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
		if (GPIO_read(&PINC, DT) != currentStateCLK) 
    {

			middle += 25;

      if(middle > 2000)
      {
        middle = 2000;
      }

		} 
    else 
    {
		  middle -= 25;
      if (middle < 1000) 
      {
        middle = 1000;
      }

		}
    OCR1A = middle;
	}
  
  lastStateCLK = currentStateCLK;
  if(overflow > 500)
  {
    serv_2 += time_dir;
    if(serv_2 == 2000)
    {
      time_dir = -25;
    }
    else if (serv_2 == 1000)
    {
      time_dir = 25;
    }
    OCR1B = serv_2;
    itoa(serv_2,string,10);
    uart_puts(string);
    uart_puts("\r\n");

    overflow = 0;
  }

}