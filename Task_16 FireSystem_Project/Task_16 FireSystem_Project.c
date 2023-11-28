#include "FireSystem_Project.h"

u8 const  shape1[]={0x0E,0x0A,0x0E,0x00,0x00,0x00,0x00,0x00};
u8 const  shape2[]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};


	
u16 temp = 0 , pres = 0 , key = 0 , password = 12345 , num = 0 ;
 
void FireSystem_CaseFine(void)
{
	while (1)
	{
		DIO_WritePin(ORNG_LED,LOW);
		DIO_WritePin(RED_LED,LOW);
		MOTOR_Stop(M1);
		LCD_GoToWriteString(0,0,"Temp:");
		LM35_StartConversion();
		temp = LM35_GetReadTemp();
		LCD_GoToWriteNumber(0,5,temp);
		LCD_Create_Character(shape1,0);
		LCD_GoToWriteChar(0,7,0);
		LCD_WriteString("         ");
		LCD_GoToWriteString(1,0,"      Fine      ");
		LCD_WriteString("        ");
		if(temp > FINE)
		{
		    break ;
		}
	}	
}

void FireSystem_CaseHeat(void)
{
	while(1)
	{
		DIO_TogglPin(ORNG_LED);
		DIO_WritePin(RED_LED,LOW);
		MOTOR_Stop(M1);
		
		LCD_GoToWriteString(0,0,"Temp:");
		LM35_StartConversion();
		temp = LM35_GetReadTemp();
		LCD_GoToWriteNumber(0,5,temp);
		LCD_Create_Character(shape1,0);
		LCD_GoToWriteChar(0,7,0);
		
		MPX4115_StartConversion();
		LCD_Create_Character(shape2,1);
		LCD_GoToWriteChar(0,8,1);
		
		LCD_GoToWriteString(0,9,"SMK:");
		pres = MPX4115_GetReadPressurePercent();
		LCD_GoToWriteNumber(0,13,pres);
		LCD_GoToWriteChar(0,15,'%');
		
		LCD_GoToWriteString(1,0,"      Heat      ");
		
		if(temp < FINE || pres > FIRE)
		{
			break;
		}

	}
	
}

void FireSystem_CaseFire(void)
{
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if(key >= '0' && key <= '9')
			{
				num = num * 10 + (key -'0');
			}
			else if(key == 'C')
			{
				num = 0 ;
			}
			else if(key == '=')
			{
				if(password == num)
				{
					break ;
				}
				else if(password != num)				
				{
					LCD_GoToWriteString(1,0,"  WrongPassword");
					_delay_ms(100);
				}
			}
			//LCD_GoToWriteString(1,0,"      Fire      ");
		}
		
		DIO_TogglPin(ORNG_LED);
		DIO_TogglPin(RED_LED);
		//Stepper_UniPolar_CW();
		MOTOR_CW(M1);
				
		LCD_GoToWriteString(0,0,"Temp:");
		LM35_StartConversion();
		temp = LM35_GetReadTemp();
		LCD_GoToWriteNumber(0,5,temp);
		LCD_Create_Character(shape1,0);
		LCD_GoToWriteChar(0,7,0);
				
		MPX4115_StartConversion();
		LCD_Create_Character(shape2,1);
		LCD_GoToWriteChar(0,8,1);
				
		LCD_GoToWriteString(0,9,"SMK:");
		pres = MPX4115_GetReadPressurePercent();
		LCD_GoToWriteNumber(0,13,pres);
		LCD_GoToWriteChar(0,15,'%');
		LCD_GoToWriteString(1,0,"      Fire      ");
	}
		
}
