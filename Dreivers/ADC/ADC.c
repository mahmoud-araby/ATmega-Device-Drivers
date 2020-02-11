/*
 * ADC.c
 *
 * Created: 30/01/2020 09:16:26 AM
 *  Author: Embedded_PC
 */ 
#include "ADC.h"

static volatile tWORD  ADC_VALUES [CHANNELs_COUNT];
static tbyte resolution ;
static tbyte PORTS [CHANNELs_COUNT];
static void AUTO_CONFIG_CLOCK(void);

tWORD ADC_GET_VALUE (tADC_CHANNEL ADC_NO)
{
	tWORD ret = NO_ERORR ; 
	ret = ADC_VALUES[ADC_NO];
	return ret ;
}

tERORR ADC_START (void)
{
	tERORR ret = NO_ERORR;
	ADC_ENABLE ; 
	ADC_START_CONVERSION;
	return ret ;
}

tERORR ADC_SET_PORTs (tADC_CHANNEL ADC_CHANNEL , tCHANNELS CHANNEL )
{	
	tERORR ret = NO_ERORR;
	PORTS [CHANNEL] = ADC_CHANNEL ; 
	return ret ;

}


tERORR ADC_STOP (void)
{
	tERORR ret = NO_ERORR;
	ADC_STOP_CONVERSION;
	ADC_DISABLE;
	return ret ;
}

tERORR ADC_CONFIGURE (tADC_CLK_PRESCALER PRESCALER , tADC_RESOLUTION RESOLUTION , tADC_VOLT_REFRENCE REFRENCE , tADC_TRIGGERING TRIGGERING )
{
	tERORR ret = NO_ERORR;
	
	ADC_SET_LEFT_ADJUST(RESOLUTION); 
	resolution = RESOLUTION;
	ADC_SET_REFRENCE(REFRENCE);
	ADC_AUTO_TRIGIRRER(TRIGGERING); 
	ADC_SET_CHANNEL(PORTS[0]);
	
	
	
	switch (PRESCALER)
	{
		case(ADC_Auto_CONFIGURE):
			AUTO_CONFIG_CLOCK();
		break;
	default:
		if (PRESCALER > CLK_128 )
		{
			ret = PARAMETERS_ERORR ;
		}
		else 
		{
			ADC_SET_PRESCALER(PRESCALER);
		}
	}

/*
#if ( ADC_MODE == INTERRUPT_MODE )
ADC_ENABLE_INTERRUPT;

#elif ( ADC_MODE == NORMAL_MODE )*/
ADC_DISABLE_INTERRUPT;
/*
#endif 
*/
	
	return ret ;
}

tERORR ADC_UPDATE (void){
	
	
	tERORR ret = NO_ERORR ;
	static tbyte ADC_timer_counter = 0;
	ADC_timer_counter += OS_TICK_MS;

	if (ADC_timer_counter >= ADC_PERIOD_MS)
	{
		ADC_timer_counter = 0; 
		static tbyte Current_channel = 0 ;
	
		if ( ADC_FINISHED )	
		{
			switch(resolution)
			{
				case (ADC_10_BIT_RESOLUTION):
					ADC_VALUES[Current_channel] = ADC_GET_VALUE_10_bit;
					break;
				case (ADC_8_BIT_RESOLUTION):
					ADC_VALUES[Current_channel] = ADC_GET_VALUE_8_bit;
					break;
			}
			if ( Current_channel == CHANNELs_COUNT -1 )
			{
				Current_channel = 0;
			}
			else 
			{
				Current_channel++;
			}
			ADC_SET_CHANNEL(PORTS [Current_channel]);
			ADC_HANDLING_FINISHED;
			ADC_START_CONVERSION;
		}
	}
	return ret ; 
}


void AUTO_CONFIG_CLOCK (void)
{
	if((ADC_CLK_AUTO > 0) & (ADC_CLK_AUTO <= 2))
	{
		ADC_SET_PRESCALER(CLK_2);
	}
	else if ((ADC_CLK_AUTO > 2) & (ADC_CLK_AUTO <= 4))
	{
		ADC_SET_PRESCALER(CLK_4);
	}
	else if ((ADC_CLK_AUTO > 4) & (ADC_CLK_AUTO <= 8))
	{
		ADC_SET_PRESCALER(CLK_8);
	}
	else if ((ADC_CLK_AUTO > 8) & (ADC_CLK_AUTO <= 16))
	{
		ADC_SET_PRESCALER(CLK_16);
	}
	else if ((ADC_CLK_AUTO >= 16) & (ADC_CLK_AUTO < 32))
	{
		ADC_SET_PRESCALER(CLK_32);
	}
	else if ((ADC_CLK_AUTO >= 32) & (ADC_CLK_AUTO < 64))
	{
		ADC_SET_PRESCALER(CLK_64);
	}
	else if ((ADC_CLK_AUTO >= 64) & (ADC_CLK_AUTO < 128))
	{
		ADC_SET_PRESCALER(CLK_128);
	}
}