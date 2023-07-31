/*
 * LCD.h
 *
 * Created: 3/12/2022 1:17:29 PM
 *  Author: safifi
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "STD_Types.h"
#include "STD_MACROS.h"
#define LCD_INIT_PORT()  DDRA|=0b11111100;
#define LCD_SET_CURSOR         0x80
#define LCD_CLEAR       0x01

void LCD_VidGotoRawCol (u8 u8RawCopy, u8 u8ColCopy);

void LCD_vid_num_to_str(u8 u8NumCopy);
void LCD_vidWriteString (u8* pu8StringCopy);

#define D7(val) if(val == 0)  CLR_BIT(PORTA,7); else  SET_BIT(PORTA,7);
#define D6(val) if(val == 0)  CLR_BIT(PORTA,6); else  SET_BIT(PORTA,6);
#define D5(val) if(val == 0)  CLR_BIT(PORTA,5); else  SET_BIT(PORTA,5);
#define D4(val) if(val == 0)  CLR_BIT(PORTA,4); else  SET_BIT(PORTA,4);
#define RS(val) if(val == 0)  CLR_BIT(PORTA,3); else  SET_BIT(PORTA,3);
#define EN(val) if(val == 0)  CLR_BIT(PORTA,2); else  SET_BIT(PORTA,2);

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : initialize LCD to work in 4-bit mode - clear lcd - cursor off
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void);

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send a specific command (cmd) to lcd (valid only with 4-bit mode)
* Parameters   : cmd  (command to be done by lcd)
* Return value : void
*****************************************************************************/
void LCD_write_command(u8 cmd);

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Write a specific Ascii char (data) to lcd (valid only with 4-bit mode)
* Parameters   : data  (data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_char(u8 data);



#endif /* LCD_H_ */
