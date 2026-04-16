#include <lib/random.h>

int random(void){
    static int random_number = 1; // I need a seed to put here
    random_number = (random_number * 1103515245 + 12345) & 0x7fffffff;
    return random_number;
}