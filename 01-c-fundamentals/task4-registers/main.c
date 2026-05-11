#include<stdio.h>
#include<stdint.h>

#define BIT4 (1UL << 4)
#define BIT20 (1UL << 20)
#define BIT21 (1UL << 21)
#define BIT22 (1UL << 22)
#define BIT23 (1UL << 23)

int main(){

    uint32_t RCC_APB2ENR = 0;
    uint32_t GPIO_CRH = 0;

    RCC_APB2ENR |= BIT4;


    GPIO_CRH |= BIT20;
    

    printf("0x%08X\n", RCC_APB2ENR);
    printf("0x%08X\n", GPIO_CRH);

    return 0;
}