/*
 ============================================================================
 Name        : a.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ftoa.h"
/*    parameters:
 *            - Buffer must be 8 chars long
 *            - 3 digits precision max
 *            - absolute range is -524,287 to 524,287
 *            - resolution (epsilon) is 0.125 and
 *              always rounds down
 **************************************************/

int main(void) {
	float n = 1543.321;
	char ch[20];

	ftoa_(n, ch);
	printf("%s", n);
	return 0;
}
