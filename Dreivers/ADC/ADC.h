/*
 * ADC.h
 *
 * Created: 30/01/2020 09:16:50 AM
 *  Author: Embedded_PC
 */ 

//////////////////////////////need to increase a mode of auto-channel-select  and manual- channel-select /////////////
#ifndef ADC_H_
#define ADC_H_
#include "../Main.h"
#include "../GPIO/GPIO.h"

//////////////////////////need to add the interrupt controller ////////////////////////////////
#define ADC_DATA_TYPES      ENUM
#define ADC_FREQUANCY_MAX 200000
#define ADC_CLK_AUTO      (F_CPU/ADC_FREQUANCY_MAX)
#define ADC_ENABLE							  SET_PIN_STATE(ADCSRA , ADEN , GPIO_PIN_ON)
#define ADC_START_CONVERSION				  SET_PIN_STATE(ADCSRA , ADSC , GPIO_PIN_ON)
#define ADC_ENABLE_INTERRUPT				  SET_PIN_STATE(ADCSRA , ADIE , GPIO_PIN_ON)
#define ADC_DISABLE							  SET_PIN_STATE(ADCSRA , ADEN , GPIO_PIN_OFF)
#define ADC_STOP_CONVERSION					  SET_PIN_STATE(ADCSRA , ADSC , GPIO_PIN_OFF)
#define ADC_DISABLE_INTERRUPT				  SET_PIN_STATE(ADCSRA , ADIE ,GPIO_PIN_OFF)
#define ADC_SET_LEFT_ADJUST(ADC_RESOLUTION)       SET_PIN_STATE(ADMUX , ADLAR , ADC_RESOLUTION)
#define ADC_AUTO_TRIGIRRER(ADC_TRIGGERING)        SET_PIN_STATE(ADCSRA , ADATE, ADC_TRIGGERING)
#define ADC_SET_PRESCALER(ADC_PRESCALER)		  (ADCSRA = ( (ADCSRA & 0b11111000) | (ADC_PRESCALER) ) )
#define ADC_SET_REFRENCE(ADC_REFRENCE)			  (ADMUX  = ( (ADMUX  & 0b00111111) | (ADC_REFRENCE << 6) ) )
#define ADC_SET_CHANNEL(CHANNEL)			  (ADMUX  = ( (ADMUX  & 0b11110000) | (CHANNEL  ) ) )
#define ADC_GET_VALUE_8_bit				      (ADCH)
#define ADC_GET_VALUE_10_bit			      (ADCL | (ADCH << 8))
#define ADC_FINISHED					      (GET_PIN_STATE (ADCSRA , ADIF ) )    
#define ADC_HANDLING_FINISHED				  (SET_PIN_STATE (ADCSRA , ADIF , GPIO_PIN_OFF) )


#if ( SPI_DATA_TYPES == MACROS )


#define	EXTERNAL_SOURCE			((tbyte)0)
#define	VCC_SUPLLY				((tbyte)1)
#define	INTERNAL_SOURC			((tbyte)3)
typedef tbyte tADC_VOLT_REFRENCE;

#define	ADC_10_BIT_RESOLUTION	((tbyte)0)
#define	ADC_8_BIT_RESOLUTION	((tbyte)1)
typedef tbyte tADC_RESOLUTION;

#define	ADC_Auto_CONFIGURE		((tbyte)0)
#define	CLK_2					((tbyte)1)
#define	CLK_4					((tbyte)2)
#define	CLK_8					((tbyte)3)
#define	CLK_16					((tbyte)4)
#define	CLK_32					((tbyte)5)
#define	CLK_64					((tbyte)6)
#define	CLK_128					((tbyte)7)
typedef tbyte  tADC_CLK_PRESCALER;

#define	ADC_0					((tbyte)0)
#define	ADC_1					((tbyte)1)
#define	ADC_2					((tbyte)2)
#define	ADC_3					((tbyte)3)
#define	ADC_4					((tbyte)4)
#define	ADC_5					((tbyte)5)
#define	ADC_6					((tbyte)6)
#define	ADC_7					((tbyte)7)
typedef tbyte tADC_CHANNEL;

#define	NORMAL_TRIGGER			((tbyte)0)
#define	AUTO_TRIGGER			((tbyte)1)
typedef tbyte tADC_TRIGGERING;

#elif ( SPI_DATA_TYPES == ENUM )

typedef enum {
	EXTERNAL_SOURCE = 0,
	VCC_SUPLLY = 1 ,
	INTERNAL_SOURCE = 3
}tADC_VOLT_REFRENCE;

typedef enum {
	ADC_10_BIT_RESOLUTION = 0,
	ADC_8_BIT_RESOLUTION
}tADC_RESOLUTION;

typedef enum {
	ADC_Auto_CONFIGURE = 0,
	CLK_2 ,
	CLK_4 ,
	CLK_8 ,
	CLK_16 ,
	CLK_32 ,
	CLK_64 ,
	CLK_128
}tADC_CLK_PRESCALER;

typedef enum {
	ADC_0 = 0 ,
	ADC_1 ,
	ADC_2 ,
	ADC_3 ,
	ADC_4 ,
	ADC_5 ,
	ADC_6 ,
	ADC_7
}tADC_CHANNEL;

typedef enum {
	NORMAL_TRIGGER =0 ,
	AUTO_TRIGGER =1
}tADC_TRIGGERING;


#endif

tERORR ADC_SET_PORTs (tADC_CHANNEL ADC_CHANNEL , tCHANNELS CHANNEL );


tERORR ADC_START ( void );
tERORR ADC_CONFIGURE (tADC_CLK_PRESCALER PRESCALER , tADC_RESOLUTION RESOLUTION , tADC_VOLT_REFRENCE REFRENCE , tADC_TRIGGERING TRIGGERING );
tERORR ADC_STOP (void);
tWORD  ADC_GET_VALUE (tADC_CHANNEL ADC_NO);
tERORR ADC_UPDATE (void);





#endif /* ADC_H_ */