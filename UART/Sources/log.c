/*
 * log.c
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */
#include "log.h"

//log a single char
void LOG_char(uint8_t * ch){
	while(!(UART_S1_REG(UART0_BASE_PTR) & UART_S1_TDRE_MASK));
	UART_D_REG(UART0_BASE_PTR) = (uint8_t)*(ch);
}

//log string
void LOG_0(uint8_t * str, size_t length){
	/* Send characters */

	for( int i = 0; i < length - 1; i++){
		while(!(UART_S1_REG(UART0_BASE_PTR) & UART_S1_TDRE_MASK));
		UART_D_REG(UART0_BASE_PTR) = (uint8_t)*(str + i);
	}

}

void LOG_int8(uint8_t * str, size_t len, uint8_t *param, size_t param_len){

	//print string
	LOG_0(str, len);
	//print int number
	char number_str[param_len];
	itoa(*param , number_str, 10);
	uint8_t * param_ptr = number_str;
	LOG_0(param_ptr, param_len);
}

void LOG_int16(uint8_t * str, size_t len, uint16_t *param, size_t param_len){

	//print string
	LOG_0(str, len);
	//print int number
	char number_str[param_len];
	itoa(*param , number_str, 10);
	uint8_t * param_ptr = number_str;
	LOG_0(param_ptr, param_len);
}

void LOG_int32(uint8_t * str, size_t len, uint32_t *param, size_t param_len){

	//print string
	LOG_0(str, len);
	//print int number
	char number_str[param_len];
	itoa(*param , number_str, 10);
	uint8_t * param_ptr = number_str;
	LOG_0(param_ptr, param_len);
}
void LOG_float(uint8_t * str, size_t len, float * param, size_t param_len){
	//print string
	LOG_0(str, len);
	//print float number
	char number_str[param_len];
	ftoa_(*param, number_str);
	uint8_t * param_ptr = number_str;
	LOG_0(param_ptr, param_len);
}

