#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "kernel/io.h"


#define ARROW_KEY_UP 0x80
#define ARROW_KEY_DOWN 0x81
#define ARROW_KEY_LEFT 0x82
#define ARROW_KEY_RIGHT 0x83


void keyboard_init(void);
int keyboard_poll_char(char *out);
char keyboard_raw_read();
char keyboard_getchar(void);
