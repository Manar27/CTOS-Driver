/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: manar
 */

#ifndef MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_

#include "Timer1_Private.h"

void Timer0_VoidInit (void);
void ICU_VoidSetTrigger (u8 Copy_u8Edge);
void ICU_VoidEnableInterrupt (void);
void ICU_VoidDisableInterrupt (void);
u16 ICU_u16ReadInputCapture (void);

void ICU_CallBackFunction(void (*PTF)(void));
void __vector_6(void)		__attribute__((signal));

#endif /* MCAL_TIMER0_HEADER_TIMER0_INTERFACE_H_ */
