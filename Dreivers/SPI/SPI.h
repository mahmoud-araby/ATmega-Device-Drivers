/*
 * SPI.h
 *
 * Created: 31/01/2020 08:36:12 PM
 *  Author: Embedded_PC
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../Main.h"
#include "../GPIO/GPIO.h"
#include "../BUFFER/Buffer.h"

#define SPI_DATA_TYPES      ENUM

typedef tbyte tSPI_DATA ;


#define SPI_SET_CLOCK_PHASE(SPI_MODE)                         SET_PIN_STATE(SPCR , CPHA , (SPI_MODE&0x01))
#define SPI_SET_CLOCK_POLARTIY(SPI_MODE)                      SET_PIN_STATE(SPCR , CPOL , (SPI_MODE&0x02))
#define SPI_SET_MASTER_SLAVE_MODE(SPI_MASTER_SLAVE_MODE)      SET_PIN_STATE(SPCR , MSTR , SPI_MASTER_SLAVE_MODE)
#define SPI_SET_DATA_ORDER(SPI_DATA_ORDER)                    SET_PIN_STATE(SPCR , CPOL , SPI_DATA_ORDER)
#define SPI_ENABLE											  SET_PIN_STATE(SPCR , SPE  , GPIO_PIN_ON)
#define SPI_DISABLE											  SET_PIN_STATE(SPCR , SPE  , GPIO_PIN_OFF)
#define SPI_INTERRUPT_ENABLE								  SET_PIN_STATE(SPCR , SPIE  , GPIO_PIN_ON)
#define SPI_INTERRUPT_DISABLE							      SET_PIN_STATE(SPCR , SPIE  , GPIO_PIN_OFF)
#define SPI_SET_SET_SPEED(SPI_SPEED)					      (SPCR  = ( (SPCR &0b11111100) | (SPI_SPEED&0b00000011) ) );\
														      (SPSR  = ( (SPSR &0b11111110) | (SPI_SPEED >> 2) ) )
#define SPI_CHECK_WRITE_COLLISION                             SET_PIN_STATE(SPCR , CPHA , SPI_MODE&0x01)
#define SPI_FINISHED                                          (GET_PIN_STATE (SPSR , SPIF ) )
#define SPI_HANDLING_FINISHED								  (SET_PIN_STATE (SPSR , SPIF , GPIO_PIN_OFF) )
#define SPI_READ                                              (SPDR)
#define SPI_WRITE(SPI_DATA)                                   ( SPDR = SPI_DATA )

#define SS_PIN		4
#define MOSI_PIN	5
#define MISO_PIN	6
#define SCK_PIN		7
#define SS_PORT		GPIO_PORTB
#define MOSI_PORT	GPIO_PORTB
#define MISO_PORT	GPIO_PORTB
#define SCK_PORT	GPIO_PORTB



#if ( SPI_DATA_TYPES == MACROS )

#define 	SPI_MODE_0		((tbyte)0)
#define 	SPI_MODE_1		((tbyte)1)
#define 	SPI_MODE_2		((tbyte)2)
#define 	SPI_MODE_3		((tbyte)3)
typedef tbyte  tSPI_MODE;
	
#define 	SPI_SLAVE		((tbyte)0)
#define 	SPI_MASTER		((tbyte)1)
typedef tbyte tSPI_MASTER_SLAVE_MODE;
	
#define 	MSB_FIRST		((tbyte)0)
#define 	LSB_FIRST		((tbyte)1)
typedef tbyte tSPI_DATA_ORDER;
	
#define 	CLK_4		((tbyte)0)
#define 	CLK_16		((tbyte)1)
#define 	CLK_64		((tbyte)2)
#define 	CLK_128		((tbyte)3)
#define 	CLK_2		((tbyte)4)
#define 	CLK_8		((tbyte)5)
#define 	CLK_32		((tbyte)6)
typedef tbyte tSPI_SPEED;

#elif ( SPI_DATA_TYPES == ENUM )

typedef enum {
	SPI_MODE_0 =0,
	SPI_MODE_1,
	SPI_MODE_2,
	SPI_MODE_3
}tSPI_MODE;

typedef enum {
	SPI_SLAVE =0,
	SPI_MASTER
}tSPI_MASTER_SLAVE_MODE;

typedef enum {
	MSB_FIRST =0,
	LSB_FIRST
}tSPI_DATA_ORDER;

typedef enum {
	CLK_4 =0,
	CLK_16,
	CLK_64,
	CLK_128,
	CLK_2,
	CLK_8,
	CLK_32
}tSPI_SPEED;

#endif

tERORR SPI_CONFIGURE (tSPI_MODE  MODE ,tSPI_SPEED  SPEED ,tSPI_MASTER_SLAVE_MODE MASTER_SLAVE_MODE,tSPI_DATA_ORDER DATA_ORDER);
tERORR SPI_START (void);
tERORR SPI_STOP (void);
tERORR SPI_SEND_DATA (tSPI_DATA SPI_DATA);
tSPI_DATA SPI_RECIEVE_DATA (void);
tERORR SPI_UPDATE ( void );



#endif /* SPI_H_ */

