/*
 * KPD_prog.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Manar
 */
#include "../../../Common/Bit_math.h"
#include "../../../Common/Macro's.h"
#include "../../../Common/typedef.h"

#include "../../../MCAL/DIO/Header/DIO_interface.h"

#include "../Header/KPD_Config.h"
#include "../Header/KPD_interface.h"

void KPD_VoidInit(void)
{
	/*set column as output*/
	DIO_VoidSetPinDir(KPD_ColumnGroup,KPD_Column0,Output);
	DIO_VoidSetPinDir(KPD_ColumnGroup,KPD_Column1,Output);
	DIO_VoidSetPinDir(KPD_ColumnGroup,KPD_Column2,Output);
	DIO_VoidSetPinDir(KPD_ColumnGroup,KPD_Column3,Output);

	/*set Row as input*/
	DIO_VoidSetPinDir(KPD_RowGroup,KPD_Row0,Input);
	DIO_VoidSetPinDir(KPD_RowGroup,KPD_Row1,Input);
	DIO_VoidSetPinDir(KPD_RowGroup,KPD_Row2,Input);
	DIO_VoidSetPinDir(KPD_RowGroup,KPD_Row3,Input);

	/*set Row pin pull up*/
	DIO_VoidSetPinValue(KPD_RowGroup,KPD_Row0,High);
	DIO_VoidSetPinValue(KPD_RowGroup,KPD_Row1,High);
	DIO_VoidSetPinValue(KPD_RowGroup,KPD_Row2,High);
	DIO_VoidSetPinValue(KPD_RowGroup,KPD_Row3,High);

}
u8 KPD_u8ReadButton(void)
{
	/*Create a u8 variable to for the return value and initialize it to NotFound*/
	u8 Local_Return = NotFound;

	/*Create 2 counters for looping*/
	u8 Local_ColCounter		= 0;
	u8 Local_RowCounter		= 0;

	/*Create 2 arrays of the pins of ROWs and Columns */
	u8 Local_u8RowPinArr[ROW] = {KPD_Row0, KPD_Row1, KPD_Row2, KPD_Row3};
	u8 Local_u8ColumnPinArr[Column] = {KPD_Column0, KPD_Column1, KPD_Column2, KPD_Column3};

	/*Loop to initialize the column values to High (1) --> VCC*/
	for(int High_init_count = 0; High_init_count < Column ; High_init_count++)
	{
		DIO_VoidSetPinValue(KPD_ColumnGroup,Local_u8ColumnPinArr[High_init_count],High);
	}
	/*Loop to Get the Pressed Button*/
	for (Local_ColCounter = ColumnStart ; Local_ColCounter <= ColumnEnd ; Local_ColCounter++)
	{
		/*set the column as low (GND) --> Activate*/
		DIO_VoidSetPinValue(KPD_ColumnGroup,Local_ColCounter,Low);

		/*Loop to read the Rows*/
		for(Local_RowCounter = ROWStart; Local_RowCounter <= ROWEnd; Local_RowCounter++)
		{
			u8 Local_PinState = DIO_u8GetPinValue(KPD_RowGroup, Local_u8RowPinArr[Local_RowCounter]);

			/*Check if the Key is Pressed*/
			if(Local_PinState == Pressed)
			//if (DIO_u8GetPinValue(KPD_RowGroup, Local_RowCounter) == Pressed)
			{
				Local_Return = KPD_Values[Local_RowCounter][Local_ColCounter];

				/*Pulling until the button is released*/
				while (DIO_u8GetPinValue(KPD_RowGroup, Local_RowCounter) == Pressed)
				{
					DIO_u8GetPinValue(KPD_RowGroup, Local_RowCounter);
				}

				break;
				//wait till the button released
				//while (DIO_u8GetPinValue(KPD_RowGroup, Local_RowCounter) == Pressed);
			}
			else
			{
				DIO_VoidSetPinValue(KPD_ColumnGroup,Local_ColCounter,High);
			}
		}
	}
	return Local_Return;
}
