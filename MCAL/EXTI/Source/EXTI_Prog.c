/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 17, 2022
 *      Author: manar
 */
#include "../../../Common/typedef.h"
#include "../../../Common/Bit_math.h"
#include "../../../Common/Macro's.h"

#include "../../DIO/Header/DIO_interface.h"
#include "../Header/EXTI_Register.h"
#include "../Header/EXTI_Config.h"
#include "../Header/EXTI_Private.h"
#include "../Header/EXTI_Interface.h"

static void (*GPTF[3])(void);

void EXTI0_VoidInit(void)
{
	/*Set INT0 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDir(EXTI0_PORT,EXTI0_PIN,Input);
	DIO_VoidSetPinValue(EXTI0_PORT, EXTI0_PIN, High);
	/*set INT0 bit in GICR --> enable external interrupt of pin 0*/
	Set_Bit(EXTI_GICR, EXTI_INT0);
/*Check for the Trigger mode*/
#if EXTI0_TriggerMode == EXTI_LowLevel
		clear_Bit(EXTI_MCUCR, EXTI_ISC00);
		clear_Bit(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_OnChangeEdge
		Set_Bit(EXTI_MCUCR, EXTI_ISC00);
		clear_Bit(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_FallingEdge
		clear_Bit(EXTI_MCUCR, EXTI_ISC00);
		Set_Bit(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_RisingEdge
		Set_Bit(EXTI_MCUCR, EXTI_ISC00);
		Set_Bit(EXTI_MCUCR, EXTI_ISC01);
#endif
}

void EXTI1_VoidInit(void)
{
	/*Set INT1 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDir(EXTI1_PORT,EXTI1_PIN,Input);
	DIO_VoidSetPinValue(EXTI1_PORT, EXTI1_PIN, High);
	/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
	Set_Bit(EXTI_GICR, EXTI_INT1);

#if EXTI1_TriggerMode == EXTI_LowLevel
		clear_Bit(EXTI_MCUCR, EXTI_ISC10);
		clear_Bit(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_OnChangeEdge
		Set_Bit(EXTI_MCUCR, EXTI_ISC10);
		clear_Bit(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_FallingEdge
		clear_Bit(EXTI_MCUCR, EXTI_ISC10);
		Set_Bit(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_RisingEdge
		Set_Bit(EXTI_MCUCR, EXTI_ISC10);
		Set_Bit(EXTI_MCUCR, EXTI_ISC11);
#endif
}

void EXTI2_VoidInit(void)
{
	/*Set INT1 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDir(EXTI2_PORT,EXTI2_PIN,Input);
	DIO_VoidSetPinValue(EXTI1_PORT, EXTI2_PIN, High);
	/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
	Set_Bit(EXTI_GICR, EXTI_INT2);

#if EXTI2_TriggerMode == EXTI_FallingEdge
		clear_Bit(EXTI_MCUCR, EXTI_ISC2);
#elif EXTI2_TriggerMode == EXTI_RisingEdge
		Set_Bit(EXTI_MCUCR, EXTI_ISC2);
#endif
}

void EXT_VoidInit(u8 Local_INT_number, u8 Local_ControlState)
{
	switch(Local_INT_number)
	{
	case EXTI_INT0:
		/*Set INT0 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDir(EXTI0_PORT,EXTI0_PIN,Input);
		DIO_VoidSetPinValue(EXTI0_PORT, EXTI0_PIN, High);
		/*set INT0 bit in GICR --> enable external interrupt of pin 0*/
		Set_Bit(EXTI_GICR, EXTI_INT0);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;
	case EXTI_INT1:
		/*Set INT1 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDir(EXTI1_PORT,EXTI1_PIN,Input);
		DIO_VoidSetPinValue(EXTI1_PORT, EXTI1_PIN, High);
		/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
		Set_Bit(EXTI_GICR, EXTI_INT1);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;
	case EXTI_INT2:
		/*Set INT1 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDir(EXTI2_PORT,EXTI2_PIN,Input);
		DIO_VoidSetPinValue(EXTI1_PORT, EXTI2_PIN, High);
		/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
		Set_Bit(EXTI_GICR, EXTI_INT2);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;

	}
}

void EXT_VoidSetSenceControl(u8 Local_INT_number, u8 Local_ControlState)
{
	switch(Local_INT_number)
	{
		case EXTI_INT0:

			if(EXTI0_TriggerMode == EXTI_LowLevel)
			{
					clear_Bit(EXTI_MCUCR, EXTI_ISC00);
					clear_Bit(EXTI_MCUCR, EXTI_ISC01);
			}
			else if(EXTI0_TriggerMode == EXTI_OnChangeEdge)
			{
					Set_Bit(EXTI_MCUCR, EXTI_ISC00);
					clear_Bit(EXTI_MCUCR, EXTI_ISC01);
			}
			else if(EXTI0_TriggerMode == EXTI_FallingEdge)
			{
					clear_Bit(EXTI_MCUCR, EXTI_ISC00);
					Set_Bit(EXTI_MCUCR, EXTI_ISC01);
			}
			else if(EXTI0_TriggerMode == EXTI_RisingEdge)
			{
					Set_Bit(EXTI_MCUCR, EXTI_ISC00);
					Set_Bit(EXTI_MCUCR, EXTI_ISC01);
			}
			break;

		case EXTI_INT1:
			if(EXTI0_TriggerMode == EXTI_LowLevel)
			{
				clear_Bit(EXTI_MCUCR, EXTI_ISC10);
				clear_Bit(EXTI_MCUCR, EXTI_ISC11);
			}
			else if(EXTI0_TriggerMode == EXTI_OnChangeEdge)
			{
				Set_Bit(EXTI_MCUCR, EXTI_ISC10);
				clear_Bit(EXTI_MCUCR, EXTI_ISC11);
			}

			else if(EXTI0_TriggerMode == EXTI_FallingEdge)
			{
				clear_Bit(EXTI_MCUCR, EXTI_ISC10);
				Set_Bit(EXTI_MCUCR, EXTI_ISC11);
			}

			else if(EXTI0_TriggerMode == EXTI_RisingEdge)
			{
				Set_Bit(EXTI_MCUCR, EXTI_ISC10);
				Set_Bit(EXTI_MCUCR, EXTI_ISC11);
			}
			break;

		case EXTI_INT2:
			if(EXTI2_TriggerMode == EXTI_FallingEdge)
			{
				clear_Bit(EXTI_MCUCR, EXTI_ISC2);
			}
			else if(EXTI2_TriggerMode == EXTI_RisingEdge)
			{
				Set_Bit(EXTI_MCUCR, EXTI_ISC2);
			}
			break;
	}
}

void EXT0_CallBackFunction(void(*PTF)(void))
{
	GPTF[0] = PTF;
}
void EXT1_CallBackFunction(void(*PTF)(void))
{
	GPTF[1] = PTF;
}
void EXT2_CallBackFunction(void(*PTF)(void))
{
	GPTF[2] = PTF;
}
void __vector_1(void)
{
	GPTF[0]();
}
void __vector_2(void)
{
	GPTF[1]();
}
void __vector_3(void)
{
	GPTF[2]();
}

