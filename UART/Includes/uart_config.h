/*
 * config.h
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */

#ifndef INCLUDES_UART_CONFIG_H_
#define INCLUDES_UART_CONFIG_H_

#ifndef uartch
UART_MemMapPtr uartch = UART0_BASE_PTR;
#endif
#ifndef sysclk
int sysclk = 24000;
#endif
#ifndef baud
int baud = 115200;
#endif


#endif /* INCLUDES_UART_CONFIG_H_ */
