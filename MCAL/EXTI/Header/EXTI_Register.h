/*
 * EXTI_Register.h
 *
 *  Created on: Aug 17, 2022
 *      Author: manar
 */

#ifndef MCAL_EXTI_HEADER_EXTI_REGISTER_H_
#define MCAL_EXTI_HEADER_EXTI_REGISTER_H_

#define EXTI_MCUCR 	(*(volatile u8*)0x55)
#define EXTI_ISC00		0
#define EXTI_ISC01		1
#define EXTI_ISC10		2
#define EXTI_ISC11		3

#define EXTI_MCUCSR (*(volatile u8*)0x54)
#define EXTI_ISC2		6

#define EXTI_GICR 	(*(volatile u8*)0x5B)
#define EXTI_INT0		6
#define EXTI_INT1		7
#define EXTI_INT2		5

#define EXTI_GIFR 	(*(volatile u8*)0x5A)

#define EXTI_INTF0		6
#define EXTI_INTF1		7
#define EXTI_INTF2		5
#endif /* MCAL_EXTI_HEADER_EXTI_REGISTER_H_ */
