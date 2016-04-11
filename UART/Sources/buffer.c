/*
 * buffer.c
 *
 *  Created on: Apr 10, 2016
 *      Author: HaoranFang
 */

#include "buffer.h"

void CircBuf_init(CircBuf_t *cb, size_t size, size_t item_size){
	cb->buffer = malloc(size * item_size);
	cb->buffer_end = (char *)cb->buffer + size * item_size;

	cb->size = size;
	cb->item_size = item_size;
	cb->num_items = 0;

	cb->head = cb->buffer;
	cb->tail = cb->buffer;
}

int CircBuf_push(CircBuf_t *cb,const void *item){
	if(cb->num_items == cb->size){
		return 0;
	}

	memcpy(cb->head, item, cb->item_size);
	cb->head = (char *)cb->head + cb->item_size;
	if(cb->head == cb->buffer_end) cb->head = cb->buffer;
	cb->num_items = cb->num_items + 1;
	return 1;
}

int CircBuf_pop(CircBuf_t *cb, void * return_item){
	if(cb->num_items == 0) return 0;
	memcpy(return_item, cb->tail, cb->item_size);
	cb->tail = (char *)cb->tail + cb->item_size;
	//edge condition
	if(cb->tail == cb->buffer_end) cb->tail = cb->buffer;
	cb->num_items = cb->num_items - 1;
	return 1;
}

void CircBuf_free(CircBuf_t *cb)
{
    free(cb->buffer);
    // clear out other fields too, just to be safe
}
