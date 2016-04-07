#include <stdint.h>
#include <stdio.h>
#include <math.h>


typedef struct ex {
    int8_t var1 __attribute__ ((aligned (8)));
    int32_t var2 __attribute__ ((aligned (8)));
    int8_t var3 __attribute__ ((aligned (8)));
}__attribute__((aligned (32))) ex_t;

ex_t example;
static const int8_t conVar;
static const int16_t conVar2 = 0;
static const int32_t conVar3 = 200;
int main(void) {

    example.var1 = 0xFF;
    example.var2 = 0x12345678;
    example.var3 = 0xAA;

    return 0;
}
