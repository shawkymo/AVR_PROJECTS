#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_Interface.h"

/********************** Pin Config **************************/
//The 4 output Must be Sequential and The 4 input Must be sequential
#define  FIRST_OUTPUT       PINC0
#define  FIRST_INPUT        PINC4

#define  ROWS                4
#define  COLS                4 
#define  NO_KEY             'M'
/********************** Config **************************/

static u8 KeysArray[ROWS][COLS]={{'7','8','9','/'},
	                             {'4','5','6','*'},
					             {'1','2','3','-'},
					             {'C','0','=','+'}
					            };		  
/********************************************************/

u8 KEYPAD_GetKey(void);
	






#endif /* KEYPAD_H_ */