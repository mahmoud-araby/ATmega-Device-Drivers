/*
 * LED.c
 *
 * Created: 27/01/2020 02:42:23 PM
 *  Author: Embedded_PC
 */ 
#include "LED.h"

 struct led_data {
	 tGPIO_PORT_NO LED_PORT;
	 tGPIO_PIN_NO LED_PIN ;
	 tLED_STATE LED_STATE;
 };
 
 typedef struct led_data* LED_DATA_ADDR ;
 typedef struct led_data LED_DATA ;

 static LED_DATA LEDs[LEDs_COUNT];
 
 
tERORR LEDs_INIT ( void )
{
	tERORR ret = NO_ERORR ;
	char counter ;
	for (counter =0 ; counter < LEDs_COUNT ; counter++)
	{
		GPIO_PIN_INIT ( LEDs[counter].LED_PORT, LEDs[counter].LED_PIN , GPIO_PIN_OUT );
		GPIO_PIN_SET_STATE ( LEDs[counter].LED_PORT , LEDs[counter].LED_PIN  , LED_OFF );
	}
	return  NO_ERORR ;
}

tERORR LED_SET_DATA (tLED LED_NO,  tGPIO_PORT_NO LED_PORT ,tGPIO_PIN_NO LED_PIN)
{
	tERORR ret = NO_ERORR ;
	LEDs[LED_NO].LED_PORT = LED_PORT;
	LEDs[LED_NO].LED_PIN = LED_PIN;
	return  NO_ERORR ;
}


tERORR LED_SET_STATE ( tLED LED_NO , tLED_STATE LED_STATE )
{
	tERORR ret = NO_ERORR ;
	GPIO_PIN_SET_STATE(LEDs[LED_NO].LED_PORT, LEDs[LED_NO].LED_PIN , LED_STATE);
	LEDs[LED_NO].LED_STATE = LED_STATE ;
	return  NO_ERORR ;
}

tERORR LED_TOGGLE ( tLED LED_NO )
{
	tERORR ret = NO_ERORR ;
	tLED_STATE LED_next_State = LEDs[LED_NO].LED_STATE ? LED_OFF : LED_ON ;
	LED_SET_STATE (  LED_NO ,  LED_next_State );
	LEDs[LED_NO].LED_STATE = LED_next_State ;
	return  NO_ERORR ;
}

inline tLED_STATE LED_GET_STATE ( tLED LED_NO )
{
	tLED_STATE ret = LEDs[LED_NO].LED_STATE;
	return ret ;
}