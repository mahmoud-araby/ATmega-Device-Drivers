/*
 * UART.c
 *
 * Created: 06/02/2020 12:03:50 AM
 *  Author: Embedded_PC
 */ 
#include "UART.h"

static tbyte rc_tx_mode ;
static void SET_BAUD_RATE(tUART_BAUD_RATE BAUD_RATE);



tERORR UART_CONFIGURE (tUART_BAUD_RATE BAUD_RATE ,tUART_RECIEVER_TRANSMITER RECIEVER_TRANSMITER_MODE,tUART_MODE  MODE ,tUART_STOP_BITS STOP_BITS , tUART_PARITY_MODE PARITY_MODE, tUART_CHARACTER_SIZE CHARACTER_SIZE  )
{
	tERORR ret = NO_ERORR;
	rc_tx_mode =RECIEVER_TRANSMITER_MODE;
	SET_BAUD_RATE( BAUD_RATE);
	UART_MODE_SELECT(MODE)	;								 
	UART_STOP_BITS_SET(STOP_BITS)  ;                       
	UART_SET_PARITY_MODE(STOP_BITS)   ;                      
	UART_SET_CHARACTER_SIZE(CHARACTER_SIZE) ;              

	return ret;
}



tERORR UART_START (void)
{
		tERORR ret = NO_ERORR;
		UART_RECIEVER_TRANSMITER_MODE_SET(rc_tx_mode);
		return ret;
}

tERORR UART_STOP (void)
{
		tERORR ret = NO_ERORR;
		UART_RECIEVE_DISABLE;
		UART_TRANSMIT_DISABLE;
		return ret;
}

tERORR UART_SEND_DATA (tUART_DATA DATA)
{
		tERORR ret = NO_ERORR;
		BUFFER_WRITE(DATA  , TX);
		return ret;
}

tUART_DATA UART_RECIEVE_DATA (void)
{
		tERORR ret = NO_ERORR;
		BUFFER_READ(RX);
		return ret;
}

tERORR UART_UPDATE ( void )
{
	tERORR ret = NO_ERORR ;
	static tbyte uart_timer_counter = 0;
	uart_timer_counter += OS_TICK_MS;

	if (uart_timer_counter >= UART_PERIOD_MS)
	{
		uart_timer_counter = 0;
		
		tUART_DATA EXCHANCE_DATA ;
		if (UART_DATA_RECIEVED)
		{
			EXCHANCE_DATA = UART_READ;
			BUFFER_WRITE (EXCHANCE_DATA ,RX);
		}
		if(UART_TRANSMIT_READY)
		{
			EXCHANCE_DATA = BUFFER_READ(TX);
			UART_WRITE(EXCHANCE_DATA);
			UART_TRANSMIT_SART;
		}
	}
	return ret;
}


void SET_BAUD_RATE(tUART_BAUD_RATE BAUD_RATE)
{
	
	/////////////////////////////missing the U2X ///////////////////////
	tWORD UBRR_VALUE ; 
	UBRR_VALUE = (( F_CPU / (long)(16*BAUD_RATE) ) - 1 );
	UART_SET_BAUD_RATE( UBRR_VALUE );
}
