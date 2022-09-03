/*
 * Timer0_Prog.c
 *
 *  Created on: Aug 23, 2022
 *      Author: manar
 */

#include "../../../Common/Bit_math.h"
#include "../../../Common/Macro's.h"
#include "../../../Common/typedef.h"
#include "../Header/Timer1_Config.h"

#include "../Header/Timer1_Interface.h"
#include "../Header/Timer1_Private.h"
#include "../Header/Timer1_Register.h"

static void (*GPTF_Timer1) (void) = NULL;

void Timer0_VoidInit (void)
{
	/*Set Prescaler*/
	Set_Bit(Timer1_TCCR1B, 1);
	clear_Bit(Timer1_TCCR1B, 0);
	clear_Bit(Timer1_TCCR1B, 2);
}
void ICU_VoidSetTrigger (u8 Copy_u8Edge)
{
	if (Copy_u8Edge == ICU_FALLING_EDGE)
	{
		clear_Bit(Timer1_TCCR1B,6);
	}
	else if (Copy_u8Edge == ICU_RISING_EDGE)
	{
		Set_Bit(Timer1_TCCR1B,6);
	}
}
void ICU_VoidEnableInterrupt (void)
{
	Set_Bit(Timer1_TIMSK, 5);
}
u16 ICU_u16ReadInputCapture (void)
{
	return Timer1_ICR1;
}

void ICU_VoidDisableInterrupt (void)
{
	clear_Bit(Timer1_TIMSK, 5);
}
void ICU_CallBackFunction(void (*PTF)(void))
{
	GPTF_Timer1 = PTF;
}
void __vector_6(void)
{
	GPTF_Timer1();
}
