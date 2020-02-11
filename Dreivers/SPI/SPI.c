/*
 * SPI.c
 *
 * Created: 31/01/2020 08:36:00 PM
 *  Author: Embedded_PC
 */ 
#include "SPI.h"

static tbyte master_mode = 0 ; 
static void SPI_SET_PINS(void);

tERORR SPI_CONFIGURE (tSPI_MODE  MODE ,tSPI_SPEED  SPEED ,tSPI_MASTER_SLAVE_MODE MASTER_SLAVE_MODE,tSPI_DATA_ORDER DATA_ORDER)
{
	tERORR ret = NO_ERORR;	
	SPI_SET_CLOCK_PHASE(MODE);
	SPI_SET_CLOCK_POLARTIY(MODE);
	SPI_SET_SET_SPEED(SPEED); 
	SPI_SET_MASTER_SLAVE_MODE(MASTER_SLAVE_MODE);
	master_mode = MASTER_SLAVE_MODE ; 
	SPI_SET_DATA_ORDER(DATA_ORDER);
	SPI_SET_PINS();
	return ret;
}
tERORR SPI_START (void)
{
	tERORR ret = NO_ERORR;
	SPI_ENABLE;
	return ret;
}
tERORR SPI_STOP (void)
{
	tERORR ret = NO_ERORR;
	SPI_DISABLE;
	return ret;
}
tERORR SPI_SEND_DATA (tSPI_DATA SPI_DATA)
{
	tERORR ret = NO_ERORR;
	BUFFER_WRITE (SPI_DATA, TX);
	return ret;
}
tSPI_DATA SPI_RECIEVE_DATA (void)
{
	tSPI_DATA ret ; 
	ret = BUFFER_READ ( RX );
	return ret;
}
tERORR SPI_UPDATE ( void )
{
	tERORR ret = NO_ERORR ;
	static tbyte SPI_timer_counter = 0;
	SPI_timer_counter += OS_TICK_MS;

	if (SPI_timer_counter >= SPI_PERIOD_MS)
	{
		SPI_timer_counter = 0;
		if ( master_mode ) 
		{
			GPIO_PIN_SET_STATE(SS_PORT, SS_PIN, GPIO_PIN_OFF);
		}
		tSPI_DATA EXCHANCE_DATA ; 
		if (SPI_FINISHED )
		{
			EXCHANCE_DATA = SPI_READ;
			BUFFER_WRITE (EXCHANCE_DATA ,RX);
			EXCHANCE_DATA = BUFFER_READ(TX);
			SPI_WRITE(EXCHANCE_DATA);
			SPI_HANDLING_FINISHED;
		}
	}
	return ret;
}	



void SPI_SET_PINS(void)
{
	switch (master_mode)
	{
		case SPI_MASTER:
			GPIO_PIN_INIT(MOSI_PORT, MOSI_PIN, GPIO_PIN_OUT);
			GPIO_PIN_INIT(SCK_PORT, SCK_PIN, GPIO_PIN_OUT);
			GPIO_PIN_INIT(SS_PORT, SS_PIN, GPIO_PIN_OUT);
		break;
		case SPI_SLAVE:
			GPIO_PIN_INIT(MISO_PORT, MISO_PIN, GPIO_PIN_OUT);
		break;
	}
}