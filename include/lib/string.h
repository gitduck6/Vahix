#pragma once

#include <stdint.h>
#include <stddef.h>

#include "drivers/vga.h"

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlen(const char *s);
size_t strcspn(const char *s1, const char *s2);
uint32_t string_to_hex(char *str);
void itoa(int n, char *str);
void reverse(char *str, int length);