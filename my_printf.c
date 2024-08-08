#include <unistd.h>
#include <stdarg.h>
#include "my_io.h"

void int_to_str(int num, char *str, int base);

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[32];
    char *str;
    int int_val;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'd':
                    int_val = va_arg(args, int);
                    int_to_str(int_val, buffer, 10);
                    write(1, buffer, 32);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    write(1, str, 32);
                    break;
                case 'x':
                    int_val = va_arg(args, int);
                    int_to_str(int_val, buffer, 16);
                    write(1, buffer, 32);
                    break;
                case 'b':
                    int_val = va_arg(args, int);
                    int_to_str(int_val, buffer, 2);
                    write(1, buffer, 32);
                    break;
                default:
                    write(1, &format[i], 1);
                    break;
            }
        } else {
            write(1, &format[i], 1);
        }
    }

    va_end(args);
}

void int_to_str(int num, char *str, int base) {
    char digits[] = "0123456789ABCDEF";
    char temp[32];
    int i = 0, j, rem;

    do {
        rem = num % base;
        temp[i++] = digits[rem];
        num /= base;
    } while (num != 0);

    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0';
}
