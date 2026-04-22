#include "lib/string.h"
#include "lib/math.h"

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) {
        p++;
    }
    return (size_t)(p - s);
}

int strncmp(const char *s1, const char *s2, size_t n) {
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) return 0;
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

uint32_t string_to_hex(char *str) {
    uint32_t val = 0;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) str += 2;
    
    while (*str) {
        uint8_t byte = *str;
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <= 'f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <= 'F') byte = byte - 'A' + 10;

        val = (val << 4) | (byte & 0xF);
        str++;
    }
    return val;
}

void itoa(int n, char *str) {
    int i = 0;

    if (n == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    while (n > 0) {
        int rem = n % 10;
        str[i++] = rem + '0';
        n = n / 10;
    }

    str[i] = '\0';

    reverse(str, i);
}

void reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/*
*    the function is pretty simple, it just goes through the string,
*    multiplies value by 10 then adds DIGIT to value,
*    keeps doing this untill a null terminator
*    ALSO if the character is NOT a digit(between '0' and '9') we break and return 0 just for safety
*    if anyone in the future intends to change this just put something else instead of the break
*/
int atoi(const char *nptr){

    int value = 0;

    for (int i = 0;nptr[i] != '\0';i++)
    {
        if (('0' <= nptr[i]) && ('9' >= nptr[i]))
        {
            value = (value * 10) + (nptr[i] - '0');
        }
        else break;
    }

    return value;
}