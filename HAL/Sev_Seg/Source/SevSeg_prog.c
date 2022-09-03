/*
 * Seven_Segment_prog.c
 *
 *  Created on: Aug 9, 2022
 *      Author: Manar
 */
#include "../../../Common/Bit_math.h"
#include "../../../Common/Macro's.h"
#include "../../../Common/typedef.h"
#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/SevSeg_Private.h"
#include "../Header/SevSeg_Config.h"
#include "../Header/SevSeg_interface.h"
#include <util/delay.h>

#if SevSeg_Type == SevSeg_CA
		static u8 SevSeg_Numbers[10] = {CA_ZERO,
								CA_ONE,
								CA_TWO,
								CA_THREE,
								CA_FOUR,
								CA_FIVE,
								CA_SIX,
								CA_SEVEN,
								CA_EIGHT,
								CA_NINE};
#elif SevSeg_Type == SevSeg_AN
		static u8 SevSeg_Numbers[10] = {AN_ZERO,
								AN_ONE,
								AN_TWO,
								AN_THREE,
								AN_FOUR,
								AN_FIVE,
								AN_SIX,
								AN_SEVEN,
								AN_EIGHT,
								AN_NINE};
#endif

void SevSeg_VoidInit(void)
{
	//DIO_interface already included in ConfigFile
	DIO_VoidSetPortDir(SevSeg_Group,Max_Output);
}
void SevSeg_VoidDisplayNo(u8 Local_Number)
{
	if (Local_Number <= 9 && Local_Number >= 0)
	{
		DIO_VoidSetPortValue(SevSeg_Group, SevSeg_Numbers[Local_Number]);
	}
}
void SevSeg_VoidDisplayRange(void)
{
	u8 Local_counter = 0;
	for (Local_counter = 0; Local_counter < 10 ; Local_counter++)
	{
		DIO_VoidSetPortValue(SevSeg_Group, SevSeg_Numbers[Local_counter]);
		_delay_ms(1000);
	}
}
void SevSeg_VoidClear(void)
{
	DIO_VoidSetPortValue(SevSeg_Group, SevSeg_Numbers[0]);
}
void SevSeg_VoidTurnOff(void)
{
	DIO_VoidSetPortValue(SevSeg_Group,SevSeg_TurnOff);
}


/*void SEVENSEG_VoidSetSegDir(u8 Local_Groupname)
{
	DIO_VoidSetPortDir(Local_Groupname,0xff);
}
void SEVENSEG_VoidSetSegValue(u8 Local_Groupname, u8 Local_CA_num)
{
	DIO_VoidSetPortValue(Local_Groupname, Local_CA_num);
}*/

