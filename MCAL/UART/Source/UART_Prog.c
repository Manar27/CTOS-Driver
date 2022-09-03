/*
 * UART_Prog.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Manar
 */
#include "../../../Common/Bit_math.h"
#include "../../../Common/Macro's.h"
#include "../../../Common/typedef.h"

#include "../Header/UART_Register.h"
#include "../Header/UART_Private.h"
#include "../Header/UART_Config.h"
#include "../Header/UART_Interface.h"

/*------------------------------------Polling----------------------------------*/
void UART_VoidInit (void)
{
	/*Get access to UCSRC -> UMSEL = 1*/
	Set_Bit(UART_UCSRC,UART_URSEL);

	/*Select Operating Mood*/
#if USART_Mode == UART_Asynchronous
	/*Select Asynchronous mood*/
	clear_Bit(UART_UCSRC,UART_UMSEL);
#elif USART_Operation == UART_Synchronous
	/*Select Synchronous mood*/
	Set_Bit(UART_UCSRC,UART_UMSEL);
#endif

	/*Select Parity Mood*/
#if UART_ParityMode == UART_Parity_Disabled
	clear_Bit(UART_UCSRC,UART_UPM1);
	clear_Bit(UART_UCSRC,UART_UPM0);
#elif UART_ParityMode == UART_Parity_EnabledEven
	Set_Bit(UART_UCSRC,UART_UPM1);
	clear_Bit(UART_UCSRC,UART_UPM0);
#elif UART_ParityMode == UART_Parity_EnabledODD
	Set_Bit(UART_UCSRC,UART_UPM1);
	Set_Bit(UART_UCSRC,UART_UPM0);
#endif

	/*Select Stop Bits*/
#if UART_StopBits == UART_Stop_1bit
	clear_Bit(UART_UCSRC,UART_USBS);
#elif UART_StopBits == UART_Stop_2bit
	Set_Bit(UART_UCSRC,UART_USBS);
#endif

	/*Select Character size*/
#if UART_CharacterSize == UART_CharacterSize_5		//000
	clear_Bit(UART_UCSRB,UART_UCSZ2);
	clear_Bit(UART_UCSRC,UART_UCSZ1);
	clear_Bit(UART_UCSRC,UART_UCSZ0);
#elif UART_CharacterSize == UART_CharacterSize_6	//001
	clear_Bit(UART_UCSRB,UART_UCSZ2);
	clear_Bit(UART_UCSRC,UART_UCSZ1);
	Set_Bit(UART_UCSRC,UART_UCSZ0);
#elif UART_CharacterSize == UART_CharacterSize_7 	//010
	clear_Bit(UART_UCSRB,UART_UCSZ2);
	Set_Bit(UART_UCSRC,UART_UCSZ1);
	clear_Bit(UART_UCSRC,UART_UCSZ0);
#elif UART_CharacterSize == UART_CharacterSize_8 	//011
	clear_Bit(UART_UCSRB,UART_UCSZ2);
	Set_Bit(UART_UCSRC,UART_UCSZ1);
	Set_Bit(UART_UCSRC,UART_UCSZ0);
#elif UART_CharacterSize == UART_CharacterSize_9	//111
	Set_Bit(UART_UCSRB,UART_UCSZ2);
	Set_Bit(UART_UCSRC,UART_UCSZ1);
	Set_Bit(UART_UCSRC,UART_UCSZ0);
#endif

	/*Set baud rate*/
	UART_UBRRL = UART_BaudRate;
}
void UART_VoidSend (u8 Local_Data)
{
	/*Send data to the UDR register to start sending*/
	UART_UDR = Local_Data;
	/*Enable TX circuit*/
	Set_Bit(UART_UCSRB,UART_TXEN);
	/*(Polling) Check on Data Register Empty flag until it's 1*/
	while((Get_Bit(UART_UCSRA,UART_UDRE)) == 0);

	/*(Polling) Check on Transmit Complete flag*/
	/*while(Get_Bit(UART_UCSRA,UART_TXC) == 0);*/
}
u8 UART_u8Receive (void)
{
	/*Enable TX circuit*/
	Set_Bit(UART_UCSRB,UART_RXEN);
	/*(Polling) Check on Receive Complete flag*/
	while((Get_Bit(UART_UCSRA,UART_RXC)) == 0);
	/*Return The Received Data*/
	return UART_UDR;
}
void UART_VoidTransiver	(u8 Local_Mode)
{

}
/*------------------------------------Interrupt--------------------------------*/
void UART_VoidInitInterrupt (void)
{

}
void UART_StartSend (u8 Local_Data)
{

}
void UART_StartReceive (void)
{

}
