/*
 * EEPROM.C
 *
 * Created: 1/31/2023 5:09:48 PM
 *  Author: REEM AHMAD
 */ 
#include "EEPROM.h"
void eeprom_write(uint8_t data,uint16_t address)
{
	EEAR=address;	
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}

uint8_t eeprom_read(uint16_t address)
{
    EEAR=address;
	SET_BIT(EECR,EERE);
	return EEDR;
}
