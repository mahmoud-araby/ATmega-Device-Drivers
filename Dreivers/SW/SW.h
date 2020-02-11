/*
 * SW.h
 *
 * Created: 28/01/2020 12:19:08 AM
 *  Author: Embedded_PC
 */ 


#ifndef SW_H_
#define SW_H_


#include "../Main.h"
#include "../GPIO/GPIO.h"


typedef enum {
	SW_PRESSED,
	SW_PRE_PRESSED,
	SW_PRE_PRE_PRESSED,
	SW_RELEASED,
	SW_PRE_RELEASED,
	SW_PRE_PRE_RELEASED
	}tSW_STATE; 
	




tERORR  SWs_UPDATE (void);
tERORR SW_SET_DATA (tSW SW_NO, tGPIO_PORT_NO SW_PORT ,tGPIO_PIN_NO SW_PIN);
tSW_STATE SW_GET_STATE (tSW SW_NO);
tERORR SWs_INIT (void);
#endif /* SW_H_ */