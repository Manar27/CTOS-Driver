/*
 * KPD_Config.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Manar
 */

#ifndef HAL_KPD_HEADER_KPD_CONFIG_H_
#define HAL_KPD_HEADER_KPD_CONFIG_H_

#define ROW 		4
#define Column		4

#define ROWStart	0
#define ROWEnd		3

#define ColumnStart	4
#define ColumnEnd	7

#define KPD_RowGroup 		Group_A
#define KPD_Row0			Pin_A0
#define KPD_Row1			Pin_A1
#define KPD_Row2			Pin_A2
#define KPD_Row3			Pin_A3

#define KPD_ColumnGroup 	Group_A
#define KPD_Column0			Pin_A4
#define KPD_Column1			Pin_A5
#define KPD_Column2			Pin_A6
#define KPD_Column3			Pin_A7


u8 KPD_Values[ROW][Column] =
{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
};

#endif /* HAL_KPD_HEADER_KPD_CONFIG_H_ */
