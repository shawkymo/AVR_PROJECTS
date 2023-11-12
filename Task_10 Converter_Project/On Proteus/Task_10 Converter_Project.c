#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"
#include "Converter.h"


void GetFullNumberInDecimal( u64 *pnum ,u8 key)
{
	if(key >= '0' && key <= '9')
	{
	  *pnum = (*pnum) * 10 + (key -'0') ; 
	}
}

void ConvertFromHexToDecimal(u64 *pnum ,u8 key)
{
	if(key >= '0' && key <= '9')
	{
		*pnum = (*pnum) * 16 + (key -'0') ;
	}
	switch(key)
	{
		case 'A':
		*pnum = (*pnum) *16 + 10 ;
		break;
		case 'B':
		*pnum = (*pnum) *16 + 11 ;
		break;
		case 'E':
		*pnum = (*pnum) *16 + 14 ;
		break;
		case 'F':
		*pnum = (*pnum) *16 + 15 ;
		break;
	}
}

void ConvertFromBinaryToDecimal(u64 *pnum ,u8 key)
{
	if(key == '0' || key == '1')
	{
		if( key == '1' )
		{
			*pnum = ((*pnum) << 1 ) | 1  ;
		}
		if( key == '0' )
		{
			*pnum = ((*pnum) << 1 ) | 0  ;
		}
	}
}

CONVERT_type GetFromValue()
{
	u8 volatile	key , from ;
	s8 from_value = -1 ;
	while(1)
	{
		key = KEYPAD_GetKey();
		LCD_GoToWriteString(0,0,"Convert From :");
		LCD_GoToWriteString(1,0,"1-Hex 2-Dec 3-Bin");
		if(key != NO_KEY)
		{
			from = key - '0';
			LCD_Clear();
			LCD_GoToWriteChar(0,0,key);
			if(((from == HEX) || (from == DEC) || (from == BIN) ))
			{
				if(from == HEX )
				{
					from_value = HEX ;
				}
				else if(from == DEC)
				{
					from_value = DEC ;
				}
				else if(from == BIN)
				{
					from_value = BIN ;
				}
			}
			else
			{
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(500);
			}
			if(from_value == HEX || from_value == DEC || from_value == BIN )
			{
				return from_value;
			}
		}
	}
}

CONVERT_type GetToValue(CONVERT_type from)
{
	u8 key ,to ; 
	s8 to_value = -1 ;
	LCD_Clear();
	if(from == HEX)
	{
		LCD_GoToWriteString(0,0,"Con From Hex to:");
		LCD_GoToWriteString(1,0,"1-Hex 2-Dec 3-Bin");
	}
	else if (from == DEC)
	{
		LCD_GoToWriteString(0,0,"Con From Dec to:");
		LCD_GoToWriteString(1,0,"1-Hex 2-Dec 3-Bin");
	}
	else if (from == BIN)
	{
		LCD_GoToWriteString(0,0,"Con From Bin to:");
		LCD_GoToWriteString(1,0,"1-Hex 2-Dec 3-Bin");
	}
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			to = key - '0';
			LCD_Clear();
			if(((to == HEX) || (to == DEC) || (to == BIN) ))
			{
				if(to == HEX )
				{
					to_value = HEX ;
				}
				else if(to == DEC)
				{
					to_value = DEC ;
				}
				else if(to == BIN)
				{
					to_value = BIN ;
				}
			}
			else
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
			}
			if(to_value == HEX || to_value == DEC || to_value == BIN )
			{
				return to_value;
			}
		}
	}
}

void ConvertFromHexToDec()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  hex=0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9') || (key == 'A')|| (key == 'B')|| (key == 'E')|| (key == 'F'))
			{
				LCD_WriteChar(key);
				ConvertFromHexToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				hex = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Hex:");
				LCD_GoToWriteString(1,0,"Dec:");
				LCD_GoToWriteHexu64Number(0,4,hex);
				LCD_GoToWriteNumber(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromHexToBin()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  hex=0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1500);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9') || (key == 'A')|| (key == 'B')|| (key == 'E')|| (key == 'F'))
			{
				LCD_WriteChar(key);
				ConvertFromHexToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				hex = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Hex:");
				LCD_GoToWriteString(1,0,"Bin:");
				LCD_GoToWriteHexu64Number(0,4,hex);
				LCD_GoToWriteBinaryNumber(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}

			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromHexToHex()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  hex=0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9') || (key == 'A')|| (key == 'B')|| (key == 'E')|| (key == 'F'))
			{
				LCD_WriteChar(key);
				ConvertFromHexToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				hex = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Hex:");
				LCD_GoToWriteString(1,0,"Hex:");
				LCD_GoToWriteHexu64Number(0,4,hex);
				LCD_GoToWriteHexu64Number(1,4,hex);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}

			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromDecToHex()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  Dec = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9'))
			{
				LCD_WriteChar(key);
				GetFullNumberInDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Dec = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Dec:");
				LCD_GoToWriteString(1,0,"Hex:");
				LCD_GoToWriteNumber(0,4,Dec);
				LCD_GoToWriteHexu64Number(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromDecToBin()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  Dec = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9'))
			{
				LCD_WriteChar(key);
				GetFullNumberInDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Dec = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Dec:");
				LCD_GoToWriteString(1,0,"Bin:");
				LCD_GoToWriteNumber(0,4,Dec);
				LCD_GoToWriteBinaryNumber(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0 )
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromDecToDec()
{
	u8 key  ,sel_mode_flag = 0 ;
	u64 num = 0,  Dec = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key >= '0' && key <= '9'))
			{
				LCD_WriteChar(key);
				GetFullNumberInDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Dec = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Dec:");
				LCD_GoToWriteString(1,0,"Dec:");
				LCD_GoToWriteNumber(0,4,Dec);
				LCD_GoToWriteNumber(1,4,Dec);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromBinToHex()
{
	u8 key  ,sel_mode_flag = 0  ;
	u64 num = 0,  Bin = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();		
		if(key != NO_KEY)
		{
			if((key == '0' || key == '1'))
			{
				LCD_WriteChar(key);
				ConvertFromBinaryToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Bin = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Bin:");
				LCD_GoToWriteString(1,0,"Hex:");
				LCD_GoToWriteBinaryNumber(0,4,Bin);
				LCD_GoToWriteHexu64Number(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromBinToDec()
{
	u8 key  ,sel_mode_flag = 0  ;
	u64 num = 0,  Bin = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key == '0' || key == '1'))
			{
				LCD_WriteChar(key);
				ConvertFromBinaryToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Bin = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Bin:");
				LCD_GoToWriteString(1,0,"Dec:");
				LCD_GoToWriteBinaryNumber(0,4,Bin);
				LCD_GoToWriteNumber(1,4,num);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

void ConvertFromBinToBin()
{
	u8 key  ,sel_mode_flag = 0  ;
	u64 num = 0,  Bin = 0 ;
	LCD_Clear();
	LCD_WriteString("To Go To SelMenu");
	LCD_GoToWriteString(1,0,"Pres 3times on C");
	_delay_ms(1000);
	LCD_Clear();
	while(1)
	{
		key = KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			if((key == '0' || key == '1'))
			{
				LCD_WriteChar(key);
				ConvertFromBinaryToDecimal(&num , key);
			}
			else if (key == 'C')
			{
				LCD_Clear();
				num = 0 ;
				sel_mode_flag ++ ;

			}
			else if(key == '=')
			{
				Bin = num ;
				LCD_Clear();
				LCD_GoToWriteString(0,0,"Bin:");
				LCD_GoToWriteString(1,0,"Bin:");
				LCD_GoToWriteBinaryNumber(0,4,Bin);
				LCD_GoToWriteBinaryNumber(1,4,Bin);
				sel_mode_flag = 0 ;
			}
			else if (num == 0)
			{
				LCD_GoToWriteString(0,0,"Wrong Choice");
				LCD_GoToWriteString(1,0,"Try Again");
				_delay_ms(1000);
				LCD_Clear();
			}
			if( sel_mode_flag > 2 )
			{
				return;
			}
		}
	}
}

