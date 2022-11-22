#include "timer.h"
#include <lcd.h>
#include <gpio.h>
#include <stdlib.h>


#define CLK PB3
#define SW PB5
#define DT PB4

uint8_t lastStateCLK;
uint8_t currentStateCLK;
uint8_t counter;
int main(void) 
{
  lcd_init(LCD_DISP_ON); 
  lcd_gotoxy(0,0); 
  GPIO_mode_input_pullup(&DDRB,CLK);
  GPIO_mode_input_pullup(&DDRB,SW);
  GPIO_mode_input_pullup(&DDRB,DT);

  lastStateCLK = GPIO_read(&DDRB,CLK);

  while(1)
  {
  }

return(0);
}

void loop() 
{
  char string[4];
  currentStateCLK = GPIO_read(&DDRB,CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1)
  {
		
		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if ( GPIO_read(&DDRB,DT) != currentStateCLK) 
    {
			counter --;
		} 
    else 
    {
			// Encoder is rotating CW so increment
			counter ++;
      //itoa(counter,string,10)
		}
    itoa(counter,string,10);
    lcd_gotoxy(0,0); 
		lcd_puts(string);
		
	}
	
	// Remember last CLK state
	lastStateCLK = currentStateCLK;


}