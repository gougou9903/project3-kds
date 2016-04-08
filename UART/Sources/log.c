/*
 * log.c
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */
#include "log.h"

void LOG_0(uint8_t * str, size_t length){
	/* Send characters */

	for( int i = 0; i < length - 1; i++){
		while(!(UART_S1_REG(UART0_BASE_PTR) & UART_S1_TDRE_MASK));
		UART_D_REG(UART0_BASE_PTR) = (uint8_t)*(str + i);
	}

}



