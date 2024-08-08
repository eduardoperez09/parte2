#include <stdio.h>
#include <stdlib.h>

int str_to_int(const char *str, int base) {
    return strtol(str, NULL, base);
}

void int_to_str(int num, char *str, int base) {
    if (base == 16) {
        snprintf(str, 5, "%04X", num & 0xFFFF);
    } else if (base == 10) {
        snprintf(str, 12, "%d", num);
    } else if (base == 2) {
        for (int i = 0; i < 4; i++) {
            str[3 - i] = (num & (1 << i)) ? '1' : '0';
        }
        str[4] = '\0';
    }
}
