#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_to_int(const char *str, int base) {
    return strtol(str, NULL, base);
}

void int_to_str(int num, char *str, int base) {
    if (base == 2) {
        char buffer[33];
        itoa(num, buffer, base);
        strcpy(str, buffer);
    } else if (base == 16) {
        sprintf(str, "%x", num);
    } else {
        sprintf(str, "%d", num);
    }
}
