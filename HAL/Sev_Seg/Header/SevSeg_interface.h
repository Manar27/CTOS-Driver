/*
 * Seven_Segment_interface.h
 *
 *  Created on: Aug 9, 2022
 *      Author: Manar
 */

#ifndef HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_
#define HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_

void SevSeg_VoidInit(void);
void SevSeg_VoidDisplayNo(u8 Local_Number);
void SevSeg_VoidDisplayRange(void);
void SevSeg_VoidClear(void);
void SevSeg_VoidTurnOff(void);

/*
void SEVENSEG_VoidSetSegDir(u8 Local_Groupname);
void SEVENSEG_VoidSetSegValue(u8 Local_Groupname, u8 Local_CA_num);
*/

#endif /* HAL_SEV_SEG_HEADER_SEVSEG_INTERFACE_H_ */
