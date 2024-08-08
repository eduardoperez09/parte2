#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_to_int(const char *str, int base) {
    return strtol(str, NULL, base);
}

void int_to_str(int num, char *str, int base) {
    if (base == 16) {
        snprintf(str, 5, "%04X", num & 0xFFFF);
    } else if (base == 10) {
        snprintf(str, 12, "%d", num);
    } else if (base == 2) {
        // Handle binary conversion here if needed
    }
}

