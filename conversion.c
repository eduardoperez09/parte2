#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void int_to_str(int num, char *buffer, int base) {
    if (base == 2) {
        // Convierto a binario manualmente
        for (int i = 31; i >= 0; i--) {
            buffer[31 - i] = (num & (1 << i)) ? '1' : '0';
        }
        buffer[32] = '\0';
    } else if (base == 16) {
        // Convierto a hexadecimal, sólo los 4 dígitos necesarios
        snprintf(buffer, 5, "%04X", num & 0xFFFF);
    } else {
        snprintf(buffer, 12, "%d", num);
    }
}

int str_to_int(char *str, int base) {
    return (int)strtol(str, NULL, base);
}
