#include <lib/random.h>

int random(void){
    uint64_t seed;
    __asm__ volatile ("rdrand %0" : "=r"(seed));
    return seed;
}