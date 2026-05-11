#include<stdio.h>
#include<stdint.h>
int main(){
    uint32_t led_state = 0;
    uint32_t *ptr = &led_state;

    *ptr = 1;
    printf("address: %p\n", (void*)ptr);
    printf("value: %u\n", *ptr);
    return 0;
};
