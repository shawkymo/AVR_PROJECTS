
#ifndef RC_PROJECT_H_
#define RC_PROJECT_H_
#include "DIO_Interface.h"
#include "MOTOR.h"

#ifndef CONVERTER_H_
#define CONVERTER_H_
#include "KeyPad.h"
typedef enum{
	HEX = 1,
	DEC,
	BIN
}CONVERT_type;


void GetFullNumberInDecimal( u64 *pnum ,u8 key);

void ConvertFromHexToDecimal(u64 *pnum ,u8 key);

void ConvertFromDecimalToHex(u64 num ) ;

CONVERT_type GetFromValue(void);

CONVERT_type GetToValue(CONVERT_type from);

void ConvertFromHexToDec(void);

void ConvertFromHexToBin(void);

void ConvertFromHexToHex(void);

void ConvertFromDecToHex(void);

void ConvertFromDecToBin(void);

void ConvertFromDecToDec(void);

void ConvertFromBinToHex(void);

void ConvertFromBinToDec(void);

void ConvertFromBinToBin(void);



#endif /* CONVERTER_H_ */