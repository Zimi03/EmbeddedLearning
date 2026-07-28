#include <stdint.h>

#define RCC_IOPENR   (*(volatile uint32_t*)0x40021034)
#define GPIOC_MODER  (*(volatile uint32_t*)0x50000800)
#define GPIOA_MODER  (*(volatile uint32_t*)0x50000000)
#define GPIOA_ODR    (*(volatile uint32_t*)0x50000014)
#define EXTI_FTSR1 (*(volatile uint32_t*)0x40021804)
#define EXTI_IMR1 (*(volatile uint32_t*)0x40021880)
#define EXTI_FPR1 (*(volatile uint32_t*)0x40021810)
#define EXTI_EXTICR4 (*(volatile uint32_t*)0x4002186C)
#define NVIC_ISER (*(volatile uint32_t*)0xE000E100)
#define PWR_PUCRC (*(volatile uint32_t*)0x40007030)
#define PWR_CR3 (*(volatile uint32_t*)0x40007008)

int main(){
  RCC_IOPENR |= (1UL<<2);
  GPIOC_MODER &= ~(3UL<<26);
  GPIOA_MODER &= ~(3UL<<10);
  GPIOA_MODER |= (1UL<<10);
  EXTI_FTSR1 |= (1UL<<13);
  EXTI_IMR1 |= (1UL<<13);
  EXTI_EXTICR4 &= ~(0xFFUL<<8);
  EXTI_EXTICR4 |= (2UL<<8);
  NVIC_ISER |= (1UL << 14);
  PWR_PUCRC &= ~(1UL << 13);
  PWR_PUCRC |= (1UL << 13);
  PWR_CR3 |= (1UL << 10);

  while(1){
    if (EXTI_FPR1 & (1UL << 13)) {
        GPIOA_ODR ^= (1UL << 5);
        EXTI_FPR1 |= (1UL << 13);
    }
  }
  return 0;
}
void EXTI4_15_IRQHandler(void){
  if(EXTI_FPR1 & (1UL << 13)){
    GPIOA_ODR ^= (1UL << 5);

    EXTI_FPR1 |= (1UL << 13);
  }
}