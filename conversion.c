#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_int(const char *str, int base) {
    return strtol(str, NULL, base);
}

void int_to_str(int num, char *str, int base) {
    if (base == 2) {
        char buffer[33];
        buffer[32] = '\0';
        int index = 31;
        unsigned int number = (unsigned int) num;
        if (num < 0) {
            number = ~number + 1;
        }
        while (index >= 0) {
            buffer[index--] = (number % 2) ? '1' : '0';
            number /= 2;
        }
        strcpy(str, buffer);
    } else if (base == 16) {
        sprintf(str, "%x", num);
    } else {
        sprintf(str, "%d", num);
    }
}
