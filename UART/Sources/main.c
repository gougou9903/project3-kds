#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "uart.h"
#include "debugConfig.h"

#if DEBUG_MODE == DEBUG
#include "ftoa.h"
#include "itoa.h"
#include "log.h"
#include "buffer.h"
#endif

UART_MemMapPtr uartch = UART0_BASE_PTR;
int sysclk = 24000;
int baud = 115200;

int main(void) {

	uart_init(uartch, sysclk, baud);


#if DEBUG_MODE == DEBUG
	char ch[] = "This is an integer number: ";
	size_t length = sizeof(ch);

	uint32_t number = 123456;
	uint32_t *num_ptr = &number;

	LOG_int32(ch, length, num_ptr, 7);


//	LOG_int(ch_ptr, length, num_ptr, 4);
//	float number = 123456.1234;
//	float * num_ptr = &number;
//	LOG_float(ch_ptr, length, num_ptr, 12);

#endif

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

#if DEBUG_MODE == DEBUG
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
#endif



