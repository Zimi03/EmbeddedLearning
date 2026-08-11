#include <stdint.h>

#define RCC_IOPENR   (*(volatile uint32_t*)0x40021034)
#define GPIOC_MODER  (*(volatile uint32_t*)0x50000800)
#define GPIOA_MODER  (*(volatile uint32_t*)0x50000000)
#define GPIOA_ODR    (*(volatile uint32_t*)0x50000014)
#define RCC_APBENR1 (*(volatile uint32_t*)0x4002103C)
#define TIM3_CR1 (*(volatile uint32_t*)0x40000400)
#define TIM3_DIER (*(volatile uint32_t*)0x4000040C)
#define TIM3_SR (*(volatile uint32_t*)0x40000410)
#define TIM3_CNT (*(volatile uint32_t*)0x40000424)
#define TIM3_PSC (*(volatile uint32_t*)0x40000428)
#define TIM3_ARR (*(volatile uint32_t*)0x4000042C)
#define NVIC_ISER (*(volatile uint32_t*)0xE000E100)

int main(){

    RCC_IOPENR |= (1UL<<0);
    GPIOA_MODER &= ~(3UL<<10);
    GPIOA_MODER |= (1UL<<10);

    while(1){

    }

    return 0;
}