# Lab 3: Jaroslav Polkorab

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

     #define TIM2_stop()           TCCR0B &= ~((1<<CS22) | (1<<CS21) | (1<<CS20));
   /** @brief Set overflow 16u, prescaler 001 --> 1 */
   #define TIM2_overflow_16u()   TCCR0B &= ~((1<<CS22) | (1<<CS21)); TCCR0B |= (1<<CS20);
   /** @brief Set overflow 128us, prescaler 010 --> 8 */
   #define TIM2_overflow_128u()  TCCR0B &= ~((1<<CS22) | (1<<CS20)); TCCR0B |= (1<<CS21);
   /** @brief Set overflow 512us, prescaler 011 --> 32 */
   #define TIM2_overflow_512us() TCCR0B &= ~(1<<CS22); TCCR0B |= (1<<CS21) | (1<<CS20);
   /** @brief Set overflow 1s, prescaler 100 --> 64 */
   #define TIM2_overflow_1ms()    TCCR0B &= ~((1<<CS21) | (1<<CS20)); TCCR0B |= (1<<CS22);
   /** @brief Set overflow 2ms, prescaler // 101 --> 128 */
   #define TIM2_overflow_2ms()    TCCR0B &= ~(1<<CS21); TCCR0B |= (1<<CS22) | (1<<CS20);
   /** @brief Set overflow 4ms, prescaler // 110 --> 256 */
   #define TIM2_overflow_4ms()    TCCR0B &= ~(1<<CS20); TCCR0B |= (1<<CS22) | (1<<CS21);
   /** @brief Set overflow 16ms, prescaler // 111 --> 1024 */
   #define TIM2_overflow_16ms()    TCCR0B |= (1<<CS22) | (1<<CS20) | (1<<CS21);

   /** @brief Enable overflow interrupt, 1 --> enable */
   #define TIM2_overflow_interrupt_enable()  TIMSK2 |= (1<<TOIE2);
   /** @brief Disable overflow interrupt, 0 --> disable */
   #define TIM2_overflow_interrupt_disable() TIMSK2 &= ~(1<<TOIE2);
   
   ```
