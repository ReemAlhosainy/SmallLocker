/*
 * EEPROM.h
 *
 * Created: 1/31/2023 5:11:50 PM
 *  Author: REEM AHMAD
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "STD_MACROS.h"
#include "STD_Types.h"

void eeprom_write(uint8_t data,uint16_t address);

uint8_t eeprom_read(uint16_t address);


#endif /* EEPROM_H_ */