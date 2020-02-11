/*
 * GPIO.h
 *
 * Created: 27/01/2020 02:28:28 PM
 *  Author: Embedded_PC
 */


#ifndef GPIO_H_
#define GPIO_H_

#include "../Main.h"

///////////////////////////////////////////////////////////
/*internal  hardware specifications and macros */
///////////////////////////////////////////////////////////


#define GPIO_DATA_TYPES      ENUM

#define SET_PIN_STATE(GPIO_PORTx,GPIO_PIN_NO,GPIO_PIN_STATE)  (  GPIO_PORTx  =   ((GPIO_PORTx & (~(1<< GPIO_PIN_NO))  ) |  (GPIO_PIN_STATE << GPIO_PIN_NO))  )
#define GET_PIN_STATE(GPIO_PORTx,GPIO_PIN_NO)  ((GPIO_PORTx & (1 << GPIO_PIN_NO)) >> GPIO_PIN_NO )

#define GPIO_PORTA 0x39
#define GPIO_PORTB 0x36
#define GPIO_PORTC 0x33
#define GPIO_PORTD 0x30

#define OFFSET_PIN 0x00
#define OFFSET_DIR 0x01
#define OFFSET_PORT 0x02

#define PORT_READ(GPIO_PORTx)     (*((volatile unsigned char* const)( GPIO_PORTx  + OFFSET_PIN )))
#define PORT_WRITE(GPIO_PORTx)    (*((volatile unsigned char* const)( GPIO_PORTx + OFFSET_PORT )))
#define PORT_DIR(GPIO_PORTx)      (*((volatile unsigned char* const)( GPIO_PORTx + OFFSET_DIR )))

typedef tbyte tGPIO_PORT_NO;



#if ( GPIO_DATA_TYPES == ENUM )
typedef enum  {
	PIN_0 = 0, 
	PIN_1 , 
	PIN_2 , 
	PIN_3 , 
	PIN_4 , 
	PIN_5 , 
	PIN_6 , 
	PIN_7
}tGPIO_PIN_NO;

typedef enum  {
	GPIO_PIN_OUT = 1 ,
	GPIO_PIN_IN = 0 ,
	GPIO_PORT_OUT = 0xff ,
	GPIO_PORT_IN = 0x00 ,
}tGPIO_DIR;
	
typedef enum  {
	GPIO_PIN_ON = 1 ,
	GPIO_PIN_OFF = 0,
	GPIO_PORT_ON = 0Xff ,
	GPIO_PORT_OFF = 0x00
}tGPIO_STATE;

#elif ( GPIO_DATA_TYPES == MACROS )

#define PIN_0   ((tbyte)0)
#define PIN_1   ((tbyte)1)
#define PIN_2   ((tbyte)2)
#define PIN_3   ((tbyte)3)
#define PIN_4   ((tbyte)4)
#define PIN_5   ((tbyte)5)
#define PIN_6   ((tbyte)6)
#define PIN_7   ((tbyte)7)
typedef tbyte tGPIO_PIN_NO  ;


#define GPIO_PIN_OUT   ((tbyte)1)
#define GPIO_PIN_IN    ((tbyte)0)
#define GPIO_PORT_OUT   ((tbyte)0xff)
#define GPIO_PORT_IN    ((tbyte)0)
typedef tbyte tGPIO_DIR  ;

#define GPIO_PIN_ON     ((tbyte)1)
#define GPIO_PIN_OFF    ((tbyte)0)
#define GPIO_PORT_ON    ((tbyte)0xff)
#define GPIO_PORT_OFF   ((tbyte)0)
typedef tbyte tGPIO_STATE  ;

#endif
	
	
	
	
////////////////////////////////////////////////////////////////////////////////////

tERORR GPIO_PIN_INIT ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO , tGPIO_DIR GPIO_DIRECTION );
tERORR GPIO_PORT_INIT ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_DIR GPIO_DIRECTION);

tERORR GPIO_PIN_SET_STATE ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO , tGPIO_STATE GPIO_PIN_STATE );
tERORR GPIO_PORT_SET_STATE ( tGPIO_PORT_NO GPIO_PORTx ,tGPIO_STATE GPIO_STATE );

tGPIO_STATE GPIO_PIN_GET_STATE ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO );
tGPIO_STATE GPIO_PORT_GET_STATE ( tGPIO_PORT_NO GPIO_PORTx );



#endif /* GPIO_H_ */