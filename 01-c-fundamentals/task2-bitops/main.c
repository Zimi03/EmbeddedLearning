#include <stdio.h>
#include <stdint.h>
int main(){
    
    uint32_t rejestr = 0;
    uint32_t* reg = &rejestr;
    
    
    *reg |= (uint32_t)1<<5;
    printf("0x%08X\n", *reg);
    
    *reg |= (uint32_t)1<<3;
    printf("0x%08X\n", *reg);
    
    *reg &= ~((uint32_t)1<<5);
    printf("0x%08X\n", *reg);
    
    
    return 0;
}
