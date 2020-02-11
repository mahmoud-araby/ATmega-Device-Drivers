/*
 * SW.c
 *
 * Created: 28/01/2020 12:19:25 AM
 *  Author: Embedded_PC
 */ 
#include "SW.h"



struct sw_data {
	tGPIO_PORT_NO SW_PORT ;
	tSW_STATE SW_SAMPLES[N_SAMPLES] ;
	tGPIO_PIN_NO SW_PIN ;
	tSW_STATE SW_STATE;	
	};

typedef struct sw_data* SW_DATA_ADDR ;
typedef struct sw_data SW_DATA ;

static SW_DATA SWs [SWs_COUNT];



tERORR  SWs_UPDATE (void)
{
	tERORR ret = NO_ERORR ;
	static tbyte SW_timer_counter = 0;
	SW_timer_counter += OS_TICK_MS;

	if (SW_timer_counter > SW_PERIOD_MS)
	{
		tbyte sw_counter ;
		tbyte samples_counter ;
		SW_timer_counter = 0;

		for (sw_counter =  0 ; sw_counter < SWs_COUNT ; sw_counter++)
		{
			for (samples_counter =  N_SAMPLES-1 ; samples_counter > 0 ; samples_counter--)
			{
				SWs[sw_counter].SW_SAMPLES[samples_counter] = SWs[sw_counter].SW_SAMPLES[samples_counter -1 ] ;
			}
		SWs[sw_counter].SW_SAMPLES[0] = GPIO_PIN_GET_STATE( SWs[sw_counter].SW_PORT ,SWs[sw_counter].SW_PIN  );
		}
		////////////////////add the case switcher for switch state/////////////////////////////////
	}
	return  NO_ERORR ;
}

tERORR SW_SET_DATA (tSW SW_NO, tGPIO_PORT_NO SW_PORT ,tGPIO_PIN_NO SW_PIN)
{
	tERORR ret = NO_ERORR ;
	SWs[SW_NO].SW_PORT = SW_PORT;
	SWs[SW_NO].SW_PIN = SW_PIN;
	return  NO_ERORR ;
}


inline tSW_STATE SW_GET_STATE (tSW SW_NO)
{
	tSW_STATE ret = SW_RELEASED ; 
	ret = SWs[SW_NO].SW_STATE ; 
	return ret ;
}

tERORR SWs_INIT (void)
{
	tERORR ret = NO_ERORR ;
	tbyte SW_Counter ;
	tbyte Samples_Counter;
	for (SW_Counter =0 ; SW_Counter < SWs_COUNT ; SW_Counter++)
	{
		GPIO_PIN_INIT ( SWs[SW_Counter].SW_PORT, SWs[SW_Counter].SW_PIN , GPIO_PIN_IN );
		GPIO_PIN_SET_STATE ( SWs[SW_Counter].SW_PORT , SWs[SW_Counter].SW_PIN  , SW_RELEASED );
		
		for (Samples_Counter =0 ; Samples_Counter < N_SAMPLES ; Samples_Counter++)
		{
			SWs->SW_SAMPLES[Samples_Counter] = SW_RELEASED_LEVEL ;
		}
	}
	return  NO_ERORR ;
}