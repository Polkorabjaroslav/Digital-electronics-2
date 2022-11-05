# Lab 6: Jaroslav Polkorab

### ASCII

1. Complete the table with selected ASCII codes.

   | **Char** | **Decimal** | **Hexadecimal** | **Binary** |
   | :-: | :-: | :-: | :-: |
   | `a` | 97 | 0x61 | `0b0110_0001` |
   | `b` | 98 | 0x62 | `0b0110_0010` |
   | `c` | 99 | 0x63 | `0b0110_0011` |
   | `0` | 48 | 0x30 | `0b0011_0000` |
   | `1` | 49 | 0x31 | `0b0011_0001` |
   | `2` | 50 | 0x32 | `0b0011_0010` |
   | `Esc` | 59 | 0x3b | `0b0011_1011` |
   | `Space` | 32 | 0x20 | `0b0100_0000` |
   | `Tab` | 9 | 0x9 | `0b0000_1001` |
   | `Backspace` | 8 | 0x8 | `0b0000_1000` |
   | `Enter` | 13 | d | `0b0000_1101` |

### UART communication

2. Draw timing diagram of the output from UART/USART when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd). The image can be drawn on a computer or by hand. Name all parts timing diagram.

   ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Obrazky/DE2_uart.png)

3. Draw a flowchart for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of individual algorithm steps.

   ![your figure](https://github.com/Polkorabjaroslav/Digital-electronics-2/blob/main/Obrazky/digicigi_diagram.png)
   
Preview of code written in **Clion**:
(instead of int8_t we use int)
 ```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_parity(int type, int data);
int main()
{
    get_parity(0,10111010); // type 1 odd(liche) , 0 even(sudy)
}

int get_parity(int type, int data)
{
    int i;
    int counter ;
    char srt[8];
    itoa(data,srt,10);
    for(i = 0; i <= strlen(srt); i++)
    {
        if(srt[i]=='1')
        {
            counter++;
        }
    }
    if (type == 1 & counter%2 != 0 | type == 0 & counter%2 == 0)
    {
        printf("add parity 0");
    }
    else
    {
        printf("add parity 1");
    }

    /*if (type == 1 & counter%2 == 0 | type == 0 & counter%2 != 0)
    {
        printf("add parity 1");
    }*/
}
 ```
