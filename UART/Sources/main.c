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

void read_console();
void put_buffer(char * item);
void put_console();
void delay(int val);

UART_MemMapPtr uartch = UART0_BASE_PTR;
int sysclk = 24000;
int baud = 115200;
CircBuf_t recBuff;
CircBuf_t tranBuff;

int main(void) {

	uart_init(uartch, sysclk, baud);


#if DEBUG_MODE == DEBUG
	//initialize buffer
	CircBuf_t * rec_buff = & recBuff;
	CircBuf_t * tran_buff = & tranBuff;
	CircBuf_init(rec_buff, 10, 1);
	CircBuf_init(tran_buff, 10, 1);
//	char c = 'a';
//	const char *item = &c;
//	CircBuf_push(rec_buff, item);
//
//	char *return_item = malloc(sizeof(char));
//	CircBuf_pop(rec_buff, return_item);
//
//	LOG_char(return_item);


//	LOG_int(ch_ptr, length, num_ptr, 4);

//	float number = 1543.321;
//	float * num_ptr = &number;
//	char ch[] = "This is a floating point number: ";
//	uint8_t *ch_ptr = ch;
//	LOG_float(ch_ptr, sizeof(ch), num_ptr, 12);

/* receive buffer test code */
//	while(1){
//    	delay(8000000);
//    	read_console();
//	}

/* transmit buffer test code */


//	char t = 'T';
//	put_buffer(&t);
//	delay(8000000);
//
//	put_console();

/*unit test code for circular buffer*/


	if(full(rec_buff) == 1){
		char test[] = "CB UNIT TEST 1 -- full test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 1 -- full test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);

	if(empty(rec_buff) == 1){
		char test[] = "CB UNIT TEST 2 -- empty test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 2 -- empty test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);

	if(head_edge(rec_buff) == 1){
		char test[] = "CB UNIT TEST 3 -- head_edge test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 3 -- head_edge test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);

	if(tail_edge(rec_buff) == 1){
		char test[] = "CB UNIT TEST 3 -- tail_edge test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 3 -- tail_edge test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);

	if(head_inc(rec_buff) == 1){
		char test[] = "CB UNIT TEST 3 -- head_inc test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 3 -- head_inc test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);

	if(tail_inc(rec_buff) == 1){
		char test[] = "CB UNIT TEST 3 -- tail_inc test -- PASS   ";
		LOG_0(test, sizeof(test));
	}else{
		char test[] = "CB UNIT TEST 3 -- tail_inc test -- FAIL   ";
		LOG_0(test, sizeof(test));
	}

	CircBuf_free(rec_buff);
	CircBuf_init(rec_buff, 10, 1);


#endif

	return 0;

}

#if DEBUG_MODE == DEBUG
void UART0_IRQHandler (void){

	if(UART_S1_REG(uartch) & UART_S1_RDRF_MASK){
		char c = UART_D_REG(uartch);
		const char *item = &c;


		CircBuf_t *rec_buff = &recBuff;
		CircBuf_push(rec_buff, item);

	}
}


//read data from console, meaning from the buffer
void read_console(){
	char *return_item = malloc(sizeof(char));
	CircBuf_t *rec_buff = &recBuff;
	if ((UART_S1_REG(uartch) & UART_S1_TDRE_MASK)
		||(UART_S1_REG(uartch) & UART_S1_TC_MASK)){


		if(CircBuf_pop(rec_buff, return_item) == 1){
			LOG_char(return_item);
		}else{
			char ch[] = "no data to read from buffer \n";
			LOG_0(ch, sizeof(ch));
		}

	}
}


void put_buffer(char * item){
	CircBuf_t *tran_buff = &tranBuff;
	CircBuf_push(tran_buff, item);
}

void put_console(){
	char *return_item = malloc(sizeof(char));
	CircBuf_t *tran_buff = &tranBuff;
	if ((UART_S1_REG(uartch) & UART_S1_TDRE_MASK)
		||(UART_S1_REG(uartch) & UART_S1_TC_MASK)){


		if(CircBuf_pop(tran_buff, return_item) == 1){
			LOG_char(return_item);
		}else{
			char ch[] = "no data to put from buffer \n";
			LOG_0(ch, sizeof(ch));
		}

	}
}

#endif


void delay(int val){
	for(;val;val--);
}

