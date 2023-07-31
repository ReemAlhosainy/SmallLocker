/*
 * keypad.c
 *
 * Created: 7/29/2022 10:53:59 AM
 *  Author: Reem Ahmad
 */ 

#include "keypad.h"
	u8 keypad_matrix[16] ={ '7', '4', '1', 'c'
		                  , '8', '5', '2', '0', 
						    '9', '6', '3', '=',
						    '/', 'x', '-','+'  };

void keypad_init(void)
{
	KEYPAD_INIT_PORT();
}
s8 keypad_scan(void)
{

	K4(0);	 K5(1);  K6(1);   K7(1); 
	if(K0() == 0)  return keypad_matrix[0];
	if(K1() == 0)  return keypad_matrix[1];
	if(K2() == 0)  return keypad_matrix[2];
	if(K3() == 0)  return keypad_matrix[3];
	_delay_ms(1);
	
	K4(1);	 K5(0);  K6(1);   K7(1);
	if(K0() == 0)  return keypad_matrix[4];
	if(K1() == 0)  return keypad_matrix[5];
	if(K2() == 0)  return keypad_matrix[6];
	if(K3() == 0)  return keypad_matrix[7];
	_delay_ms(1);
	
	K4(1);	 K5(1);  K6(0);   K7(1);
	if(K0() == 0)  return keypad_matrix[8];
	if(K1() == 0)  return keypad_matrix[9];
	if(K2() == 0)  return keypad_matrix[10];
	if(K3() == 0)  return keypad_matrix[11];
	_delay_ms(1);
	
	K4(1);	 K5(1);  K6(1);   K7(0);
	if(K0() == 0)  return keypad_matrix[12];
	if(K1() == 0)  return keypad_matrix[13];
	if(K2() == 0)  return keypad_matrix[14];
	if(K3() == 0)  return keypad_matrix[15];
	_delay_ms(1);
	
	return -1;
	
}
