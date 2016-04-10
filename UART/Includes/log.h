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
void LOG_int8(uint8_t * str, size_t len, uint8_t *param, size_t param_len);
void LOG_int16(uint8_t * str, size_t len, uint16_t *param, size_t param_len);
void LOG_int32(uint8_t * str, size_t len, uint32_t *param, size_t param_len);
void LOG_float(uint8_t * str, size_t len, float * param, size_t param_len);
#endif /* INCLUDES_LOG_H_ */
