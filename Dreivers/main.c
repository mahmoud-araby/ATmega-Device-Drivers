/*
 * Dreivers.c
 *
 * Created: 27/01/2020 02:18:04 PM
 * Author : Embedded_PC
 */ 

#include "SW/SW.h"
#include "LED/LED.h"
#include "ADC/ADC.h"
#include "Main.h"

void delay (void );


int main (void)
{
ADC_SET_PORTs (ADC_2 , SENSORS );
ADC_SET_PORTs (ADC_0 , CALC  );

ADC_CONFIGURE ( CLK_64 , ADC_8_BIT_RESOLUTION , VCC_SUPLLY , NORMAL_TRIGGER );
GPIO_PORT_INIT(GPIO_PORTB, GPIO_PORT_OUT);
GPIO_PORT_INIT(GPIO_PORTC, GPIO_PORT_OUT);

ADC_START (  );

    while (1) 
    {
		ADC_UPDATE ();
	//	
 GPIO_PORT_SET_STATE(GPIO_PORTB, (char) ADC_GET_VALUE (CALC));
GPIO_PORT_SET_STATE(GPIO_PORTC, (char) ADC_GET_VALUE (SENSORS));
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();

	}
}


void delay (void )
{
	unsigned long int x;
	for (x=0 ; x<10000 ; x++ )
	{
			for (x=0 ; x<10000 ; x++ )
			{
							for (x=0 ; x<10000 ; x++ )
							{
											for (x=0 ; x<10000 ; x++ );

							}

			}

	}
	
}