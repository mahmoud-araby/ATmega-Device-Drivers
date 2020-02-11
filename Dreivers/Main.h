/*
 * Main.h
 *
 * Created: 28/01/2020 03:38:30 PM
 *  Author: Embedded_PC
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#include <avr/io.h>


#define OS_TICK_MS   (0)
#define F_CPU 1000000
////////////////////////////////////
/*LED DERIVER hardware description */
#define LEDs_COUNT 1
typedef enum{
	LED_NO_0 = 0
} tLED ;
//////////////////////////////////////


////////////////////////////////////
/*SW DRIVER hardware description */
#define SWs_COUNT 1
typedef enum{
	SW_NO_0 = 0
} tSW ;

#define N_SAMPLES 2
#define SW_PRESSED_LEVEL        (0)
#define SW_RELEASED_LEVEL       (1)
#define SW_PERIOD_MS   (0)
//////////////////////////////////////


////////////////////////////////////
/*ADC DRIVER hardware description */

#define ADC_MODE  NORMAL_MODE
#define CHANNELs_COUNT  2
#define ADC_PERIOD_MS 0
	
typedef enum {
	SENSORS =0 ,
	CALC
}tCHANNELS;

//////////////////////////////////////

///////////////////////
/*SPI DRIVER hardware description */
#define SPI_PERIOD_MS 0

//////////////////////////////////////

///////////////////////
/*UART DRIVER hardware description */
#define UART_PERIOD_MS 0

//////////////////////////////////////
typedef char tbyte  ;
typedef unsigned int tWORD  ;



////////////////////////driver operating mode/////////////////////
#define  NORMAL_MODE  0 
#define  INTERRUPT_MODE 1


////////////////////////data types/////////////////////
#define  MACROS  0
#define  ENUM  1


////////////////////////driver types/////////////////////
#define  DYNAMIC  0
#define  STATIC   1



/////////////////erorrs /////////////////////
typedef enum  {
	NO_ERORR ,
	PARAMETERS_ERORR ,
	INCOMPLETE_PROCESS_ERORR
}tERORR;





#endif /* MAIN_H_ */