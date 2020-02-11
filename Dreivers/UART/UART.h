/*
 * UART.h
 *
 * Created: 06/02/2020 12:03:38 AM
 *  Author: Embedded_PC
 */ 


#ifndef UART_H_
#define UART_H_
#include "../Main.h"
#include "../GPIO/GPIO.h"
#include "../BUFFER/Buffer.h"

#define UART_DATA_TYPES      ENUM


#define UART_MODE_SELECT(UART_MODE)									  (UCSRC =( (UCSRC &0b00111111) | (UART_MODE <<UMSEL) | (1<<URSEL) ))
#define UART_STOP_BITS_SET(UART_STOP_BITS)                            (UCSRC =( (UCSRC &0b01110111) | (UART_STOP_BITS <<USBS) | (1<<URSEL) ))
#define UART_SET_PARITY_MODE(UART_STOP_BITS)                          (UCSRC =( (UCSRC &0b01001111) | (UART_STOP_BITS << 4) | (1<<URSEL) ) )
#define UART_SET_CHARACTER_SIZE(UART_CHARACTER_SIZE)                  (UCSRC =( (UCSRC &0b01111001) | ((UART_CHARACTER_SIZE&0b00000011)<<1) | (1<<URSEL)) );\
     															      (UCSRB =( (UCSRB &0b11111011) | (UART_CHARACTER_SIZE) ) )
#define UART_SET_BAUD_RATE(UART_BAUD_RATE)						      (UBRRL =(char)UART_BAUD_RATE );\
																	  (UBRRH =( (char)((UART_BAUD_RATE>>8)& (~(1<<URSEL)) ) ) )


#define  UART_RECIEVER_TRANSMITER_MODE_SET(UART_RECIEVER_TRANSMITER_MODE)		  ( UCSRB = ( (UCSRB &0b11100111)|((UART_RECIEVER_TRANSMITER_MODE) << TXEN) ) )
#define UART_RECIEVE_ENABLE											  (SET_PIN_STATE(UCSRB , RXEN , GPIO_PIN_ON))
#define UART_TRANSMIT_ENABLE										  (SET_PIN_STATE(UCSRB , TXEN , GPIO_PIN_ON))
#define UART_RECIEVE_DISABLE										  (SET_PIN_STATE(UCSRB , RXEN , GPIO_PIN_OFF))
#define UART_TRANSMIT_DISABLE										  (SET_PIN_STATE(UCSRB , TXEN , GPIO_PIN_OFF))

#define UART_RECIEVE_INTERUPT_ENABLE								  (SET_PIN_STATE(UCSRB , RXCIE , GPIO_PIN_ON))
#define UART_TRANSMIT_INTERUPT_ENABLE								  (SET_PIN_STATE(UCSRB , TXCIE , GPIO_PIN_ON))
#define UART_RECIEVE_INTERUPT_DISABLE								  (SET_PIN_STATE(UCSRB , RXCIE , GPIO_PIN_OFF))
#define UART_TRANSMIT_INTERUPT_DISABLE								  (SET_PIN_STATE(UCSRB , TXCIE , GPIO_PIN_OFF))

#define UART_TRANSMIT_READY         								  (GET_PIN_STATE(UCSRA , TXC ))
#define UART_TRANSMIT_SART         								     (SET_PIN_STATE(UCSRA , TXC ,GPIO_PIN_ON))
#define UART_DATA_RECIEVED         								      (GET_PIN_STATE(UCSRA , RXC ))
#define UART_FRAME_ERORR_CHECK        								  (GET_PIN_STATE(UCSRA , FE ))
#define UART_PARITY_ERORR_CHECK        								  (GET_PIN_STATE(UCSRA , UPE ))
#define UART_DATA_OVER_RUN_ERORR_CHECK        						  (GET_PIN_STATE(UCSRA , DOR ))

#define UART_DATA_ninth_bit_RECIEVED         					      (GET_PIN_STATE(UCSRB , RXB8 ))
#define UART_DATA_ninth_bit_TRANSMIT                  				  (GET_PIN_STATE(UCSRB , TXB8 ))

#define UART_READ													  (UDR)
#define UART_WRITE(DATA)											  (UDR = DATA )


typedef tWORD tUART_DATA ;
typedef tWORD tUART_BAUD_RATE ;


#if ( UART_DATA_TYPES == MACROS )

#define ASYNCHRONOUS_MODE
#define SYNCHRONOUS_MODE
typedef tbyte tUART_MODE;

#define ONE_BIT			((tbyte)0)
#define TWO_BITS		((tbyte)1)
typedef tbyte tUART_STOP_BITS;

#define NO_PARITY		((tbyte)0)
#define EVEN_PARIT		((tbyte)2)
#define ODD_PARITY		((tbyte)3)
typedef tbyte tUART_PARITY_MODE;

#define FIVE_BITS		((tbyte)0)
#define SIX_BITS		((tbyte)1)
#define SEVEN_BITS		((tbyte)2)
#define EIGHT_BITS		((tbyte)3)
#define NINE_BITS		((tbyte)7)
typedef tbyte tUART_CHARACTER_SIZE;

#define TX_ONLY		((tbyte)0)
#define RX_ONLY		((tbyte)2)
#define RX_TX		((tbyte)3)
typedef tbyte tUART_RECIEVER_TRANSMITER;

#elif ( UART_DATA_TYPES == ENUM )

typedef enum {
	ASYNCHRONOUS_MODE ,
	SYNCHRONOUS_MODE
}tUART_MODE;

typedef enum {
	ONE_BIT ,
	TWO_BITS
}tUART_STOP_BITS;

typedef enum {
	NO_PARITY =0,
	EVEN_PARIT =2,
	ODD_PARITY =3
}tUART_PARITY_MODE;


typedef enum {
	FIVE_BITS  =0,
	SIX_BITS,
	SEVEN_BITS,
	EIGHT_BITS,
	NINE_BITS = 7
}tUART_CHARACTER_SIZE;

typedef enum {
	TX_ONLY  =1,
	RX_ONLY  =2,
	RX_TX  =3
}tUART_RECIEVER_TRANSMITER;

#endif


tERORR UART_CONFIGURE (tUART_BAUD_RATE BAUD_RATE ,tUART_RECIEVER_TRANSMITER RECIEVER_TRANSMITER_MODE,tUART_MODE  MODE ,tUART_STOP_BITS STOP_BITS , tUART_PARITY_MODE PARITY_MODE, tUART_CHARACTER_SIZE CHARACTER_SIZE  );
tERORR UART_START (void);
tERORR UART_STOP (void);
tERORR UART_SEND_DATA (tUART_DATA DATA);
tUART_DATA UART_RECIEVE_DATA (void);
tERORR UART_UPDATE ( void );



#endif /* UART_H_ */