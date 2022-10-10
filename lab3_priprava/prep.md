1. Calculate the overflow times for three Timer/Counter modules that contain ATmega328P if CPU clock frequency is 16&nbsp;MHz. Complete the following table for given prescaler values. Note that, Timer/Counter2 is able to set 7 prescaler values, including 32 and 128 and other timers have only 5 prescaler values.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1.024m | -- | 4.096m | 16.4m |
   | Timer/Counter1 | 16 |  4.096m   |  0.0327    | -- | 0.262 | -- | 1.05 | 4.19 |
   | Timer/Counter2 | 8  |  16u   |  128u    |  512u  | 1.024m |  2.05m  | 4.096m | 16.4m |