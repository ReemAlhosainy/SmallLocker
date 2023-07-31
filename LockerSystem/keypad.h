/*
 * keypad.h
 *
 * Created: 7/29/2022 10:54:13 AM
 *  Author: DELL
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_Types.h"
#include "STD_MACROS.h"
/* PC0 TO PC3 INPUT PULL UP */

#define KEYPAD_INIT_PORT() DDRC=0b11110000; PORTC=0b00001111;

//inputs:
#define K0()   READ_BIT(PINC,0)
#define K1()   READ_BIT(PINC,1)
#define K2()   READ_BIT(PINC,2)
#define K3()   READ_BIT(PINC,3)

//outputs:
#define K4(val)  if(val==0) CLR_BIT(PORTC,4); else  SET_BIT(PORTC,4)
#define K5(val)  if(val==0) CLR_BIT(PORTC,5); else  SET_BIT(PORTC,5)
#define K6(val)  if(val==0) CLR_BIT(PORTC,6); else  SET_BIT(PORTC,6)
#define K7(val)  if(val==0) CLR_BIT(PORTC,7); else  SET_BIT(PORTC,7)



void keypad_init(void);

s8 keypad_scan(void);

#endif /* KEYPAD_H_ */