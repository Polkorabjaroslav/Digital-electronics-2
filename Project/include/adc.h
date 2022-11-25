#ifndef ADC_H
# define ADC_H

/***********************************************************************
 * 
 * ADC library for AVR.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit 
 *
 * Copyright (c) 2022 Jaroslav Polkorab
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup adc library <adc.h>
 * @code #include "adc.h" @endcode
 *
 * @brief ADC library for AVR.
 *
 * The library contains macros for controlling the ADC modules such as ADMUX,ADCSRA ect..
 *
 * @note Based on Microchip Atmel ATmega328P manual and no source file
 *       is needed for the library.
 * @author Jaroslav Polkorab, Brno University of Technology, Czechia
 * 
 * @copyright (c) 2022 Jaroslav Polkorab, This work is licensed under 
 *                the terms of the MIT license
 * @{
 */

#include <avr/io.h>
#include <avr/interrupt.h>
/**
 * @name  Definitions for ADMUX
 * @note  Below we could see definitions for ADC Multiplexer Selection Regiseter 
 */

/*------------------Voltage reference-----------------*/

/** @brief Voltage reference AVcc with external capacitor at AREF pin */
#define Vref_AVcc() ADMUX = ADMUX | (1<<REFS0);
/** @brief Voltage reference turned off */
#define Vref_off() ADMUX = ADMUX & ~(1<<REFS0 | 1<<REFS1);
/** @brief Voltage reference reserved */
#define Vref_res()  ADMUX = ADMUX | (1<<REFS1);
/** @brief Voltage reference internal 1.1V with external cap. at AREF pin */
#define Vref_interal() ADMUX = ADMUX & ~(1<<REFS0 | 1<<REFS1);

/*------------------MUX selection-----------------*/

/** @brief Mux input channel ADC0*/
#define ADC0() ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
/** @brief Mux input channel ADC1*/
#define ADC1() ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1)); ADMUX |= (1<<MUX0);
/** @brief Mux input channel ADC2*/
#define ADC2() ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX0)); ADMUX |= (1<<MUX1);
/** @brief Mux input channel ADC3*/
#define ADC3() ADMUX &= ~((1<<MUX3) | (1<<MUX2)); ADMUX |= ((1<<MUX1) | (1<<MUX0));  
/** @brief Mux input channel ADC4*/
#define ADC4() ADMUX &= ~((1<<MUX3) | (1<<MUX1) | (1<<MUX0)); ADMUX |= (1<<MUX2); 
/** @brief Mux input channel ADC5*/
#define ADC5() ADMUX &= ~((1<<MUX3) | (1<<MUX1)); ADMUX |= ((1<<MUX2) | (1<<MUX0));
/** @brief Mux input channel ADC6*/
#define ADC6() ADMUX &= ~((1<<MUX3) | (1<<MUX0)); ADMUX |= ((1<<MUX1) | (1<<MUX2));
/** @brief Mux input channel ADC7*/
#define ADC7() ADMUX &= ~((1<<MUX3)); ADMUX |= ((1<<MUX1) | (1<<MUX2) | (1<<MUX0));
/** @brief Mux input channel ADC8 (for temperature sensor)*/
#define ADC8_temp() ADMUX  &= ~( (1<<MUX2) | (1<<MUX1) | (1<<MUX0)); ADMUX =| (1<<MUX3);

/**
 * @name  Definitions for ADCSRA
 * @note  Below we could see definitions for ADC Control and status registers A
 */

/** @brief ADC is turned off*/
#define ADEN_off() ADCSRA &=  ~(1<<ADEN);
/** @brief ADC is turned on*/
#define ADEN_on() ADCSRA |= (1<<ADEN);
/** @brief Enable complete interrupt*/    
#define ADIE_on() ADCSRA |= (1<<ADIE);
/** @brief Start Conversion*/
#define ADSC_on() ADCSRA |= (1<<ADSC);

/** @brief Set clock prescalar 2*/ 
#define Clock_prescalar_2() ADCSRA &= ~((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
/** @brief Set clock prescalar 4*/ 
#define Clock_prescalar_4() ADCSRA &= ~((1<<ADPS2) | (1<<ADPS0)); ADCSRA |= (1<<ADPS1);
/** @brief Set clock prescalar 8*/ 
#define Clock_prescalar_8() ADCSRA &= ~(1<<ADPS2); ADCSRA |= ((1<<ADPS1)| (1<<ADPS0));
/** @brief Set clock prescalar 16*/ 
#define Clock_prescalar_16() ADCSRA &= ~((1<<ADPS1) | (1<<ADPS0)); ADCSRA |= (1<<ADPS2);
/** @brief Set clock prescalar 32*/ 
#define Clock_prescalar_32() ADCSRA &= ~(1<<ADPS1); ADCSRA |= ((1<<ADPS2)| (1<<ADPS0));
/** @brief Set clock prescalar 64*/ 
#define Clock_prescalar_64() ADCSRA &= ~(1<<ADPS0); ADCSRA |= ((1<<ADPS2)| (1<<ADPS1));
/** @brief Set clock prescalar 128*/ 
#define Clock_prescalar_128() ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);


#endif