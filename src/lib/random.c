#include <lib/random.h>

int random(char * seed){
    (*seed) = ((*seed * 1664525) + 1013904223);
    return *seed;
}