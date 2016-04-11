/*
 * unit_test.c
 *
 *  Created on: Apr 10, 2016
 *      Author: HaoranFang
 */
#include "unit_test.h"

//assume the size of the buffer is > 2
int full(CircBuf_t * cb){
	char item = 'T';
	for(int i = 1; i <= cb->size + 1; i++){


		if(CircBuf_push(cb, &item) == 0 && cb->num_items == cb->size){
			return 1;
		}

		if(cb->num_items != i) return 0;
	}

	return 0;
}

int empty(CircBuf_t * cb){
	char *return_item = malloc(sizeof(char));
	for(int i = cb->size; i >= 0; i--){
		if(CircBuf_pop(cb, &return_item) == 0){
			return 1;
		}

		if(cb->num_items != i - 1) return 0;
	}

	return 0;
}

int head_edge(CircBuf_t * cb){
	char item = 'T';

	//add to full first
	for(int i = 1; i < cb->size; i++){
		if(CircBuf_push(cb, &item) == 0){
			break;
		}
	}

	//pop two items

	char *return_item = malloc(sizeof(char));
	for(int i = 1; i <= 2; i++){
		CircBuf_pop(cb, return_item);
	}

	CircBuf_push(cb, &item); // push over the boundary
	if(cb->head == cb->buffer) return 1;
	else return 0;
}

int tail_edge(CircBuf_t * cb){
	char item = 'T';

	//add to full first
	for(int i = 1; i < cb->size; i++){
		if(CircBuf_push(cb, &item) == 0){
			break;
		}
	}

	//pop two items

	char *return_item = malloc(sizeof(char));
	for(int i = 1; i <= 2; i++){
		CircBuf_pop(cb, return_item);
	}



	//push two items
	CircBuf_push(cb, &item);
	CircBuf_push(cb, &item);

	uint8_t diff = cb->buffer_end - cb->tail;

	//move tail to the edge
	for(int i = 0; i < diff-1; i++){

		CircBuf_pop(cb, return_item);
	}

	//move tail over the boundary
	CircBuf_pop(cb, &return_item);
	if(cb->tail == cb->buffer) return 1;
	else return 0;
}

int head_inc(CircBuf_t * cb){
	//add one element
	char item = 'T';
	CircBuf_push(cb, &item);

	uint8_t diff = cb->head - cb->buffer;
	if(diff == 1) return 1;
	else return 0;
}

int tail_inc(CircBuf_t * cb){
	//add one element
	char item = 'T';
	CircBuf_push(cb, &item);


	//remove one element
	char *return_item = malloc(sizeof(char));
	CircBuf_pop(cb, return_item);

	uint8_t diff = cb->tail - cb->buffer;
	if(diff == 1) return 1;
	else return 0;
}
