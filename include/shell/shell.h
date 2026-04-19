#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "lib/string.h"
#include "drivers/keyboard.h"
#include "drivers/vga.h"
#include "kernel/io.h"
#include "lib/random.h"

void execute_command(char *command);
void shell(void);
const char * cpuid(void);