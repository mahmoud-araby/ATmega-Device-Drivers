/*
 * GPIO.c
 *
 * Created: 27/01/2020 02:28:05 PM
 *  Author: Embedded_PC
 */ #include "GPIO.h"
	
	tERORR GPIO_PIN_INIT ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO , tGPIO_DIR GPIO_DIRECTION )
	{
		tERORR ret = NO_ERORR;	
		SET_PIN_STATE( (PORT_DIR(GPIO_PORTx)) , GPIO_PIN_NO , GPIO_DIRECTION );	
		return  NO_ERORR ;
	}
	tERORR GPIO_PORT_INIT (tGPIO_PORT_NO GPIO_PORTx , tGPIO_DIR GPIO_DIRECTION)
	{
		tERORR ret = NO_ERORR;
		PORT_DIR(GPIO_PORTx) = GPIO_DIRECTION ? (0xff) : (0x00) ;
		return  NO_ERORR ;	
	}

	tERORR GPIO_PIN_SET_STATE ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO , tGPIO_STATE GPIO_PIN_STATE )
	{
		tERORR ret = NO_ERORR ;
		SET_PIN_STATE( PORT_WRITE(GPIO_PORTx)  ,GPIO_PIN_NO,GPIO_PIN_STATE);
		return  NO_ERORR ;
	}
	
	tERORR GPIO_PORT_SET_STATE ( tGPIO_PORT_NO GPIO_PORTx ,tGPIO_STATE GPIO_PORT_STATE )
	{
		tERORR ret = NO_ERORR ;
		PORT_WRITE( GPIO_PORTx )  =  GPIO_PORT_STATE ;
		return  NO_ERORR ;
	}

	tGPIO_STATE GPIO_PIN_GET_STATE ( tGPIO_PORT_NO GPIO_PORTx , tGPIO_PIN_NO GPIO_PIN_NO )
	{
		tGPIO_STATE ret = GET_PIN_STATE( PORT_READ(GPIO_PORTx) , GPIO_PIN_NO );
		return ret ;
	}
	
	tGPIO_STATE GPIO_PORT_GET_STATE ( tGPIO_PORT_NO  GPIO_PORTx )
	{
		tGPIO_STATE ret =  PORT_READ(GPIO_PORTx) ;
		return ret;
	}
