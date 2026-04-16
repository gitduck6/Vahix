#pragma once

#include <stdint.h>

uint32_t random(void);
uint32_t get_hwrng_seed();
uint32_t get_seed_from_rdtsc();