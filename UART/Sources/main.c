#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "ftoa.h"
#include "itoa.h"
#include "uart.h"

UART_MemMapPtr uartch = UART0_BASE_PTR;
int sysclk = 24000;
int baud = 115200;

int main(void) {

	uart_init(uartch, sysclk, baud);
	char ch[] = "Hello";

	while(1){
		size_t length = sizeof(ch);
		uint8_t * str = ch;
		LOG_0(str, length);
	}

//    /* Send the character */
//    char ch[] = "Hello";
//    while(1){
//    	int length = sizeof(ch);
//    	for( int i = 0; i < length - 1; i++){
//    		while(!(UART_S1_REG(uartch) & UART_S1_TDRE_MASK));
//    		UART_D_REG(uartch) = (uint8_t)ch[i];
//    	}
//
//    }

    while(1);


}

void UART0_IRQHandler (void){
	char c = 0;
	if(UART_S1_REG(uartch) & UART_S1_RDRF_MASK){
		c = UART_D_REG(uartch);
		if ((UART_S1_REG(uartch) & UART_S1_TDRE_MASK)
				||(UART_S1_REG(uartch) & UART_S1_TC_MASK)){
			UART_D_REG(uartch) = (uint8_t)c;
		}

	}
}


