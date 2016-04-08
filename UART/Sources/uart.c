/*
 * uart.c
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */
#include "uart.h"

void uart_init(UART_MemMapPtr uartch, int sysclk, int baud){

	register uint16_t sbr;
	uint8_t temp;

	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);

	PORTA_PCR1 |= PORT_PCR_MUX(2);
	PORTA_PCR2 |= PORT_PCR_MUX(2);

	/* Make sure that the transmitter and receiver are disabled while we
	 * change settings.
	 */
	UART_C2_REG(uartch) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

	/* Configure the uart for 8-bit mode, no parity */
	UART_C1_REG(uartch) = 0;	/* We need all default settings, so entire register is cleared */

	/* Calculate baud settings */
	sbr = (uint16_t)((sysclk*1000)/(baud * 17));

	/* Save off the current value of the uartx_BDH except for the SBR field */
	temp = UART_BDH_REG(uartch) & ~(UART_BDH_SBR(0x1F));

	UART_BDH_REG(uartch) = temp |  UART_BDH_SBR(((sbr & 0x1F00) >> 8));
	UART_BDL_REG(uartch) = (uint8_t)(sbr & UART_BDL_SBR_MASK);

	//enable the receiver transmitter interrupt
	NVIC_EnableIRQ(UART0_IRQn);
	UART_C2_REG(uartch) |= UART_C2_RIE_MASK;

	/* Enable receiver and transmitter */
	UART_C2_REG(uartch) |= (UART_C2_TE_MASK | UART_C2_RE_MASK );
}


