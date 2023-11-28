#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"
/******************** LDR Pin config ****************/
#define LDR_CH          CH_3
/******************* LM35 Pin config ****************/
#define LM35_CH         CH_0
/************** Potentiometer Pin config ************/
#define POT_CH          CH_2
/************** Potentiometer Pin config ************/
#define MPX4115_CH      CH_1
/****************************************************/



/******************* LDR ************************/
u16 LDR_GetLightIntinisty(void);

void LDR_StartConversion();

u16 LDR_GetReadLightIntinisty();

u8 LDR_GetReadLightIntinisty_PeriodicCheck(u16 *pdata);

/******************* TEMP ***********************/
u16 LM35_GetTemp(void); 

void LM35_StartConversion();

u16 LM35_GetReadTemp();

u8 LM35_GetReadTemp_PeriodicCheck(u16 *pdata);

/******************* POT ************************/
u8 POT_GetPercent(void);

void POT_StartConversion();

u8 POT_GetReadPrecent();

u8 POT_GetReadPercent_PeriodicCheck(u8 *pdata);

/******************* Pres ***********************/
u16 MPX4115_GetPressure(void);

void MPX4115_StartConversion();

u16 MPX4115_GetReadPressure();

u8 MPX4115_GetReadPressure_PeriodicCheck(u16 *pdata);

u8 MPX4115_GetReadPressurePercent();

u8 MPX4115_GetReadPressurePercent_PeriodicCheck(u16 *pdata);

#endif /* SENSORS_H_ */