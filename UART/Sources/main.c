#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>


int main(void) {
	register uint16_t sbr;
	UART_MemMapPtr uartch = UART0_BASE_PTR;
	int sysclk = 24000;
	int baud = 115200;
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

    /* Enable receiver and transmitter */
    UART_C2_REG(uartch) |= (UART_C2_TE_MASK | UART_C2_RE_MASK );

    /* put char */
    /* Wait until space is available in the FIFO */

    /* Send the character */
    char ch[] = "Hello";
    while(1){
    	int length = sizeof(ch);
    	for( int i = 0; i < length - 1; i++){
    		while(!(UART_S1_REG(uartch) & UART_S1_TDRE_MASK));
    		UART_D_REG(uartch) = (uint8_t)ch[i];
    	}

    }


}


