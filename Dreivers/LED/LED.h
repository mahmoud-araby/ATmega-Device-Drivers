/*
 * LED.h
 *
 * Created: 27/01/2020 02:42:36 PM
 *  Author: Embedded_PC
 */ 


#ifndef LED_H_
#define LED_H_

#include "../Main.h"
#include "../GPIO/GPIO.h"

#define LED_DATA_TYPES      ENUM

#if ( LED_DATA_TYPES == ENUM )

typedef enum{
	LED_OFF = 0 ,
	LED_ON = 1
	} tLED_STATE ;
	
#elif ( LED_DATA_TYPES == MACROS )

#define LED_ON    ((tbyte)1)
#define LED_OFF   ((tbyte)0)
typedef tbyte tLED_STATE  ;

#endif


tERORR LEDs_INIT ( void );

tERORR LED_SET_DATA (tLED LED_NO, tGPIO_PORT_NO LED_PORT  ,tGPIO_PIN_NO LED_PIN);
tERORR LED_SET_STATE ( tLED LED_NO , tLED_STATE LED_STATE );
tERORR LED_TOGGLE ( tLED LED_NO  );
tLED_STATE LED_GET_STATE ( tLED LED_NO );




#endif /* LED_H_ */