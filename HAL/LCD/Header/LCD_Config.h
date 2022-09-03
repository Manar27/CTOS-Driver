/*
 * LCD_Config.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Manar
 */

#ifndef HAL_LCD_HEADER_LCD_CONFIG_H_
#define HAL_LCD_HEADER_LCD_CONFIG_H_

#define LCD_Control_Group 	Group_C
#define LCD_DataGroup		Group_D

#define LCD_RS_Pin			Pin_C0
#define LCD_RW_Pin			Pin_C1
#define LCD_E_Pin			Pin_C2

#define Rows_Number 		2
#define Cols_Number			16

#define Line0_Address		0x00
#define Line1_Address		0x40

#define Total_blocks_Num 	32

#define Line_1				0
#define Line_2				1

#define CGRAM_MaxSize		8		//64/8

#endif /* HAL_LCD_HEADER_LCD_CONFIG_H_ */
