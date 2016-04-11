/*
 * unit_test.h
 *
 *  Created on: Apr 10, 2016
 *      Author: HaoranFang
 */

#ifndef INCLUDES_UNIT_TEST_H_
#define INCLUDES_UNIT_TEST_H_

#include "buffer.h"
#include "log.h"

int full(CircBuf_t * cb);
int empty(CircBuf_t * cb);
int head_edge(CircBuf_t * cb);
int tail_edge(CircBuf_t * cb);
int head_inc(CircBuf_t * cb);
int tail_inc(CircBuf_t * cb);

#endif /* INCLUDES_UNIT_TEST_H_ */
