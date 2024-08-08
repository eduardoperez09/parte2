#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_to_int(const char *str, int base) {
    return (int)strtol(str, NULL, base);
}

void int_to_str(int num, char *str, int base) {
    char buffer[32];
    int i = 0, sign = 0;
    if (num < 0 && base == 10) {
        sign = 1;
        num = -num;
    }
    do {
        int digit = num % base;
        buffer[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
        num /= base;
    } while (num);
    if (sign) buffer[i++] = '-';
    buffer[i] = '\0';
    // Reverse buffer
    for (int j = 0; j < i; j++) {
        str[j] = buffer[i - j - 1];
    }
    str[i] = '\0';
}
