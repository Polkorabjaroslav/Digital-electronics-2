#ifndef F_CPU
# define F_CPU 16000000  /
#endif

#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>
#include <uart.h>
#include <lcd.h>
//define pins PB1 as sv_1 (servos)
#define sv_1 PB1
#define sv_2 PB2
//define pins for encoder
#define DT PC4
#define SW PC3
#define CLK PC2

uint32_t middle = 1500;
uint8_t counter;
uint16_t right = 2400;
uint16_t left = 600;
int8_t time_dir = 100;
uint16_t serv_2 = 1500;

uint8_t lastStateCLK;
uint8_t currentStateCLK;
uint16_t overflow;

uint16_t arrows[] = {
  0b00000,      //arrow right
  0b00100,
  0b00110,
  0b11111,
  0b11111,
  0b00110,
  0b00100,
  0b00000,
  0b00100,      //arrow up
  0b01110,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000,
  0b00100,      //arrow down
  0b00100,      
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};
 

int main(void) 
{
  //LCD start
  lcd_init(LCD_DISP_ON);

  lcd_gotoxy(0, 0); lcd_puts("S1 position:"); 
  lcd_gotoxy(0, 1); lcd_puts("S2 position:"); 
  
  lcd_command(1<<LCD_CGRAM);       // Set addressing to CGRAM (Character Generator RAM// ie to individual lines of character patterns
  for (uint8_t i = 0; i < 24; i++)  // Copy new character patterns line by line to CGRAM
  lcd_data(arrows[i]);
  lcd_command(1<<LCD_DDRAM);

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
  lcd_gotoxy(12,0);
  lcd_putc(0x00);
  OCR1B = middle;
  lcd_gotoxy(12,1);
  lcd_putc(0x00);
   
  //Timer overflow time + timer interrupts
  TIM0_overflow_1ms();
  TIM0_overflow_interrupt_enable();
  // global iterrupts
  sei();

  while(1)
  {}
  return 0;
}

 ISR(TIMER0_OVF_vect) // Timer0 overflow function (encoder control + autonome servo)
{ 
  overflow++;
  currentStateCLK = GPIO_read(&PINC, CLK);


  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
		if (GPIO_read(&PINC, DT) != currentStateCLK) 
    {
			middle += 25;
      if(middle > 2400)
      {
        middle = 2400;
      }
		} 
    else 
    {
		  middle -= 25;
      if (middle < 600) 
      {
        middle = 600;
      }
		}
    OCR1A = middle;
    if(middle == 1500)
    {
      lcd_gotoxy(12,0);
      lcd_puts("    ");
      lcd_gotoxy(12,0);
      lcd_putc(0x00);
    }
    else if (middle == 600)
    {
      lcd_gotoxy(12,0);
      lcd_puts("    ");
      lcd_gotoxy(12,0);
      lcd_putc(0x02);
    }
    else if (middle == 2400)
    {
      lcd_gotoxy(12,0);
      lcd_puts("    ");
      lcd_gotoxy(12,0);
      lcd_putc(0x01);
    }
	}
  
  lastStateCLK = currentStateCLK;
  if(overflow > 500)
  {
    serv_2 += time_dir;
    if(serv_2 == 2400)
    {
      time_dir = -100;
      lcd_gotoxy(12,1);
      lcd_puts("    ");
      lcd_gotoxy(12,1);
      lcd_putc(0x01);
    }
    else if (serv_2 == 600)
    {
      time_dir = 100;
      lcd_gotoxy(12,1);
      lcd_puts("    ");
      lcd_gotoxy(12,1);
      lcd_putc(0x02);
    }
    else if(serv_2 == 1500)
    {
      lcd_gotoxy(12,1);
      lcd_puts("    ");
      lcd_gotoxy(12,1);
      lcd_putc(0x00);
    }
    OCR1B = serv_2;
    overflow = 0;
  }

}