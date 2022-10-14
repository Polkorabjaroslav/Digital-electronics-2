# Lab 3: YOUR_FIRSTNAME LASTNAME

### Overflow times

1. Complete table with overflow times.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1.024m | -- | 4.096m | 16.4m |
   | Timer/Counter1 | 16 |  4.096m   |  0.0327    | -- | 0.262 | -- | 1.05 | 4.19 |
   | Timer/Counter2 | 8  |  16u   |  128u    |  512u  | 1.024m |  2.05m  | 4.096m | 16.4m |

### Interrupts

2. In `timer.h` header file, define macros also for Timer/Counter2. Listing of part of the header file with settings for Timer/Counter2. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   /**
    * @name  Definitions for 8-bit Timer/Counter2
    * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
    */
   // WRITE YOUR CODE HERE
   ```