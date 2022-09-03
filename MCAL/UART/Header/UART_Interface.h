/*
 * UART_Interface.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Manar
 */

#ifndef MCAL_UART_HEADER_UART_INTERFACE_H_
#define MCAL_UART_HEADER_UART_INTERFACE_H_

/*Polling*/
void UART_VoidInit (void);
void UART_VoidSend (u8 Local_Data);
u8 UART_u8Receive (void);
void UART_VoidTransiver	(u8 Local_Mode);

/*Interrupt*/
void UART_VoidInitInterrupt (void);
void UART_StartSend (u8 Local_Data);
void UART_StartReceive (void);

#endif /* MCAL_UART_HEADER_UART_INTERFACE_H_ */
