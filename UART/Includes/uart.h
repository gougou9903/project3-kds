/*
 * uart.h
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "ftoa.h"
#include "itoa.h"

void uart_init(UART_MemMapPtr uartch, int sysclk, int baud);

#endif /* INCLUDES_UART_H_ */
