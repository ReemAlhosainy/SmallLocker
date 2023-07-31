/*
 * LCD.c
 *
 * Created: 3/12/2022 1:17:16 PM
 *  Author: safifi
 */
#include "LCD.h"

void LCD_init(void){
	LCD_INIT_PORT();
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);
	LCD_write_command(0x06);
	LCD_write_command(0x0c);
	_delay_ms(20);
}

void LCD_write_command(u8 cmd){ // 0x82
	RS(0);
	D4(READ_BIT(cmd,4));
	D5(READ_BIT(cmd,5));
	D6(READ_BIT(cmd,6));
	D7(READ_BIT(cmd,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	D4(READ_BIT(cmd,0));
	D5(READ_BIT(cmd,1));
	D6(READ_BIT(cmd,2));
	D7(READ_BIT(cmd,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCD_write_char(u8 data){
	RS(1);
	D4(READ_BIT(data,4));
	D5(READ_BIT(data,5));
	D6(READ_BIT(data,6));
	D7(READ_BIT(data,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D4(READ_BIT(data,0));
	D5(READ_BIT(data,1));
	D6(READ_BIT(data,2));
	D7(READ_BIT(data,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCD_VidGotoRawCol (u8 u8RawCopy, u8 u8ColCopy)

{u8 Address;
	switch(u8RawCopy)
	{
		case 0:     Address=u8ColCopy;               break;
		case 1:     Address=u8ColCopy+0x40;          break;
		/*if it 4*16*/
		case 2:     Address=u8ColCopy+0x10;          break;
		case 3:     Address=u8ColCopy+0x50;          break;
	}
	LCD_write_command(Address|LCD_SET_CURSOR );
}

void LCD_vid_num_to_str(u8 u8NumCopy)
{
	u32 i,rem,len=0,n;
	u8 str[20]={0};

	n=u8NumCopy;
	while(n != 0)
	{
		len++;
		n/=10;
	}
	for(i=0;i<len;i++)
	{
		rem=u8NumCopy %10;
		u8NumCopy=u8NumCopy/10;
		str[len-(i+1)]=rem +'0';
	}
	str[len]='\0';
	LCD_vidWriteString(str);
}
void LCD_vidWriteString (u8* pu8StringCopy)
{
	u16 i=0;
	while(pu8StringCopy[i]!='\0')
	{
		LCD_write_char(pu8StringCopy[i]);
		i++;
		_delay_ms(2);
	}
}