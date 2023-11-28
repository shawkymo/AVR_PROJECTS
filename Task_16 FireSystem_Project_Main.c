#include "FireSystem_Project.h"

int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(ADC_VCC,ADC_SCALER_64);
	while (1)
	{
       FireSystem_CaseFine();
	   
	   if((temp > FINE) && (pres < FIRE))
	   {
		   FireSystem_CaseHeat();
	   }
	   if(pres > FIRE)
	   {
		  FireSystem_CaseFire();
	   }
	}
}

