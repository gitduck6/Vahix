#include <lib/random.h>

uint32_t get_hwrng_seed() { // Not working on QEMU, but should work on real hardware with RDRAND support
    uint32_t seed;
    __asm__ volatile ("rdrand %0" : "=r" (seed));
    return seed;
}

uint32_t get_seed_from_rdtsc() { // This one works on QEMU and real hardware
    uint32_t low, high; // RDTSC returns the number of cycles since reset in EDX:EAX
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return low; // The lower bits change the fastest and are the most "random"
}

uint32_t random(void){ // Your way of doing this always resulted in the same thing
    uint32_t random_number = get_seed_from_rdtsc(); // So I switched to a simple LCG algorithm with the RDTSC seed
    random_number = (random_number * 1103515245 + 12345) & 0x7fffffff;
    return random_number;
}