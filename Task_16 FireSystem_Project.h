#ifndef FIRESYSTEM_PROJECT_H_
#define FIRESYSTEM_PROJECT_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "MOTOR.h"
#include "STEPPER.h"
#include "Sensors.h"

#define FINE        40
#define FIRE        50
#define ORNG_LED    PINB6
#define RED_LED     PINB7

extern u8 const  shape1[] ;
extern u8 const  shape2[] ;

extern  u16 temp ,pres ,key ,password ,num ;


void FireSystem_CaseFine(void);

void FireSystem_CaseHeat(void);

void FireSystem_CaseFire(void);



#endif /* FIRESYSTEM_PROJECT_H_ */