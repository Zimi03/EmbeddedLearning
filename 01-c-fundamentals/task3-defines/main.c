#define PIN3 (1UL << 3)
#define PIN5 (1UL << 5)

#include <stdio.h>
#include <stdint.h>

int main (){

    uint32_t rejestr = 0;
    uint32_t* reg = &rejestr;
    
    *reg |= PIN5;
    printf("0x%08X\n", *reg);
    *reg |= PIN3;
    printf("0x%08X\n", *reg);
    *reg &= ~PIN5;
    printf("0x%08X\n", *reg);


    return 0;
}