/*
 * STEPPER_Prog.c
 *
 *  Created on: Aug 30, 2022
 *      Author: manar
 */
#include "../../../Common/Bit_math.h"
#include "../../../Common/typedef.h"
#include "../../../Common/Macro's.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/STEPPER_Config.h"
#include "../Header/STEPPER_interface.h"

void STEPPER_VoidInit (void)
{
	DIO_VoidSetPortDir(STEPPER_Group, Max_Output);
}
void STEPPER_VoidRotateCW (void)
{
	DIO_VoidSetPinValue(STEPPER_Group,RED,Low);
}
void STEPPER_VoidRotateUCW (void)
{

}
