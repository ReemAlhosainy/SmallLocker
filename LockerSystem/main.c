/*
 * LockerSystem.c
 *
 * Created: 2/2/2023 5:10:41 PM
 * Author : Reem Ahmad
 */ 

#include <avr/io.h>
#include "keypad.h"
#include "LCD.h"
#include "EEPROM.h"
s8 key_; u8 res;
u16 addr=100;
u8 flag=0; //locker is closed by default at first
u8 CheckPass();
void EnterPass();
void ResetPass();
void EnableBuzzer_vid_for_ms(u16 interval);
void OpenLocker();
void CloseLocker();
void ChangePass();

int main(void)
{
    /* Replace with your application code */
	LCD_init();
	keypad_init();
	SET_BIT(DDRD,0); //buzzer
	SET_BIT(DDRB,0); //locker
	u8 iterator=0;
    while (1) 
    {
	    	key_=keypad_scan();
	    	if(key_!= -1)
	    	{
				if(key_ !='/') EnableBuzzer_vid_for_ms(100);
				if (key_=='x')
				{
					CloseLocker();
				}
				if(key_=='/'&&flag==1)
				 {
			    while(key_ != -1 )  key_=keypad_scan();//it is -1 if it is not pressed
				LCD_write_command(LCD_CLEAR);
			   	 LCD_vidWriteString("Enter new Password");
				EnableBuzzer_vid_for_ms(3000);
				 LCD_VidGotoRawCol(1,0);
				 while ((key_=keypad_scan())==-1); 
				  ChangePass();			
				EnableBuzzer_vid_for_ms(3000);	
			 }				
			 LCD_write_command(LCD_CLEAR);
		//Reset Password:	
		while(flag==1&&key_=='0'&&iterator<10)
		{
			while(key_ != -1)  key_=keypad_scan();
			iterator++;
			LCD_vid_num_to_str(iterator);
			if (iterator==10)
			{
				ResetPass();
				LCD_vidWriteString("Password has been Reset");
				iterator=0;
				break;
			}
		}
		
		if ((key_!='x'&&key_!='/'&&flag==0)||res==3)
		{
			 LCD_write_command(LCD_CLEAR);
			EnterPass();
		    res=CheckPass();
			if(res==1)
			{
			LCD_vidWriteString("Correct");
			OpenLocker();
			}
			else
			{
				LCD_vidWriteString("Wrong Try Again");

			}
		}
		 while(key_ != -1)  key_=keypad_scan();
    }
	}
}
void ResetPass()
{
	for(u8 i=5;i<9;i++)
		eeprom_write('0',i);
}
u8 CheckPass()
{   /*
	Default Password at address 5
	Checked Password at address 100
	*/
    //if(addr!=104) 
	//{
		//return 3; //The length is wrong	
	//}
	for (u8 i=5;i<9;i++)
	{
		if (eeprom_read(i+95)!=eeprom_read(i))
		{
			LCD_write_command(LCD_CLEAR);
			SET_BIT(DDRB,6);
			return 3; //The password is wrong
		}
	}
	return 1; //The password is right
}


void EnableBuzzer_vid_for_ms(u16 interval)
{
	if(interval==100)
	{
		SET_BIT(PORTD,0);
		_delay_ms(100);
		CLR_BIT(PORTD,0);
	}
	else if (interval==3000)
	{
		
		SET_BIT(PORTD,0);
		_delay_ms(3000);
		CLR_BIT(PORTD,0);
		
	}
	 
}
void CloseLocker(){
	
	CLR_BIT(PORTB,0);
	flag=0; //then locker is closed

}
void OpenLocker(){
	SET_BIT(PORTB,0);
	flag=1; //then locker is opened
}
void EnterPass()
{ 
	addr=100;
	for (u8 y=0;y<4;y++)
	{
		EnableBuzzer_vid_for_ms(100);
		LCD_write_char(key_);
		eeprom_write(key_,addr++);
		while(key_ != -1 )  key_=keypad_scan();//it is -1 if it is not pressed
		while (key_==-1 &&y!=3) key_=keypad_scan();
	}
		  
}
void ChangePass()
{
	static u8 j=5;
	 if (key_ !=-1)
	 {
		 EnableBuzzer_vid_for_ms(100);
		 LCD_write_char('*');
		 eeprom_write(key_,j++);
		 while(key_ != -1 )  key_=keypad_scan();//it is -1 if it is not pressed
		 while((key_=keypad_scan())!='/') ChangePass();
	 }
}
