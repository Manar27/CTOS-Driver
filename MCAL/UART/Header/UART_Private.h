/*
 * UART_Private.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Manar
 */

#ifndef MCAL_UART_HEADER_UART_PRIVATE_H_
#define MCAL_UART_HEADER_UART_PRIVATE_H_

#define UART_Parity_Disabled			1
#define UART_Parity_EnabledEven			2
#define UART_Parity_EnabledODD			3

#define UART_Asynchronous				1
#define UART_Synchronous				2

#define UART_Stop_1bit					1
#define UART_Stop_2bit					2

#define UART_CharacterSize_5			1
#define UART_CharacterSize_6			2
#define UART_CharacterSize_7			3
#define UART_CharacterSize_8			4
#define UART_CharacterSize_9			5

#define UART_NorSpe_9600				51

#define UART_Send						1
#define UART_Receive					2
#endif /* MCAL_UART_HEADER_UART_PRIVATE_H_ */
