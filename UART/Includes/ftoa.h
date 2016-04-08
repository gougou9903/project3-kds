/*
 * ftoa.h
 *
 *  Created on: Apr 7, 2016
 *      Author: HaoranFang
 */

#ifndef INCLUDES_FTOA_H_
#define INCLUDES_FTOA_H_

#include<stdio.h>
#include<stdint.h>
#include<math.h>

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);
void ftoa(float n, char *res, int afterpoint);

#endif /* INCLUDES_FTOA_H_ */
