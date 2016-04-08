/*
 * log.h
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */

#ifndef INCLUDES_LOG_H_
#define INCLUDES_LOG_H_

#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "ftoa.h"
#include "itoa.h"

void LOG_0(uint8_t * str, size_t length);

#endif /* INCLUDES_LOG_H_ */
