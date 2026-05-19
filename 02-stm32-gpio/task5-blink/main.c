#include <stdint.h>

#define RCC_IOPENR   (*(volatile uint32_t*)0x40021034)
#define GPIOA_MODER  (*(volatile uint32_t*)0x50000000)
#define GPIOA_ODR    (*(volatile uint32_t*)0x50000014)

int main(){
  RCC_IOPENR |= (1UL<<0);
  GPIOA_MODER &= ~(3UL<<10);
  GPIOA_MODER |= (1UL<<10);

  while(1){
    GPIOA_ODR |= (1UL << 5);
    for(volatile int i = 0; i<100000;i++);
    GPIOA_ODR &= ~(1UL << 5);
    for(volatile int i = 0; i<100000;i++);
  }
}