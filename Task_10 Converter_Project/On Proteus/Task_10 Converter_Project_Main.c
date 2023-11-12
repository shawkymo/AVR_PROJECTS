#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Converter.h"


int main(void)
{
	DIO_Init();
	LCD_Init();
	u8 key , from_value , to_value ;
	LCD_GoToWriteString(0,0,"My Name Is :");
	LCD_GoToWriteString(1,0,"Abdel-rahman");
	_delay_ms(2000);
	LCD_Clear();
	LCD_GoToWriteString(0,0,"Welcome To My :");
	LCD_GoToWriteString(1,0,"ConverterProject");
	_delay_ms(3000);
	LCD_Clear();
	LCD_GoToWriteString(0,0,"Let's Start :)");
    _delay_ms(1500);
	LCD_Clear();
	while(1)
	{
		from_value = GetFromValue();
		to_value = GetToValue(from_value) ;
		while(1)
		{
		    if(from_value == HEX && to_value == DEC)
			{
					ConvertFromHexToDec();
			}
			else if(from_value == HEX  && to_value == BIN)
			{
					ConvertFromHexToBin();
			}
			else if(from_value == HEX  && to_value == HEX)
			{
					ConvertFromHexToHex();
			}
			else if(from_value == DEC  && to_value == HEX )
			{
					ConvertFromDecToHex();
			}
			else if(from_value == DEC  && to_value == BIN )
			{
					ConvertFromDecToBin();
			}
			else if(from_value == DEC  && to_value == DEC )
			{
					ConvertFromDecToDec();
			}
			else if(from_value == BIN  && to_value == HEX )
			{
					ConvertFromBinToHex();
			}
			else if(from_value == BIN  && to_value == DEC )
			{
					ConvertFromBinToDec();
			}
			else if(from_value == BIN  && to_value == BIN )
			{
					ConvertFromBinToBin();
			}
			break ;
		}
	}	
}



