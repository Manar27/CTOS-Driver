/*
 * main.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Manar
 */
#include "../Common/Bit_Math.h"
#include "../Common/TypeDef.h"
#include "../Common/Macro's.h"

#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../HAL/TEMP/Header/TEMPL35_Interface.h"
#include "../HAL/LCD/Header/LCD_Interface.h"
#include "../MCAL/Timer1/Header/Timer1_Interface.h"

u16 PeriodTicks = 0;
u16 ONTicks		= 0;

void main(void)
{
	while (1)
	{

	}
	/*LCD_Void8BitInit();
	TEMPL35_VoidInit();
	u8 temp = 0;
	while(1)
	{
		temp = TEMPL35_u8GetTemp(0x00);
		LCD_VoidSendNumber(temp);
		_delay_ms(500);
		LCD_VoidSendCommand(0x01);
	}*/
	/*
	 * normal mode
	 * timer 0 -> 8 bits
	 * prescaller 1024
	 * tov = (prescaller/systemfreq)*256=> 32.7m
	 * Req>tov : #ofcount = req/tov => 30.5
	 * preload = 256 (1-0.5)=> 128  */
	/*GIE_VoidControl(Enable);
	Timer0_VoidInitNormal(128);
	Timer0_CallBackFunctionNormal(toggle);
	while(1)
	{

	}*/

}

void ICU_Void (void)
{
	u16 Reading1, Reading2, Reading3;
	static u8 Local_u8Counter = 0;
	Local_u8Counter++;
	if (Local_u8Counter == 1)
	{
		//at first ICIE = Rising
		Reading1 = ICU_u16ReadInputCapture();
		ICU_VoidSetTrigger(ICU_FALLING_EDGE);
	}
	else if (Local_u8Counter == 2)
	{
		/**/
		Reading2 = ICU_u16ReadInputCapture();
		ONTicks = Reading2 - Reading1;
		ICU_VoidSetTrigger(ICU_RISING_EDGE);
	}
	else if (Local_u8Counter == 3)
	{
		Reading3 =ICU_u16ReadInputCapture();
		PeriodTicks = Reading3 - Reading1;
		ICU_VoidDisableInterrupt();
	}
}
