#include <unistd.h>
#include <stdarg.h>
#include "my_io.h"

int str_to_int(const char *str, int base);

void my_scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[32];
    int *int_ptr;
    char *str;
    int num_read;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'd':
                    num_read = read(0, buffer, 32);
                    buffer[num_read - 1] = '\0';  // Eliminar el '\n'
                    int_ptr = va_arg(args, int *);
                    *int_ptr = str_to_int(buffer, 10);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    num_read = read(0, str, 32);
                    str[num_read - 1] = '\0';  // Eliminar el '\n'
                    break;
                case 'x':
                    num_read = read(0, buffer, 32);
                    buffer[num_read - 1] = '\0';  // Eliminar el '\n'
                    int_ptr = va_arg(args, int *);
                    *int_ptr = str_to_int(buffer, 16);
                    break;
                case 'b':
                    num_read = read(0, buffer, 32);
                    buffer[num_read - 1] = '\0';  // Eliminar el '\n'
                    int_ptr = va_arg(args, int *);
                    *int_ptr = str_to_int(buffer, 2);
                    break;
                default:
                    break;
            }
        }
    }

    va_end(args);
}

int str_to_int(const char *str, int base) {
    int result = 0, i = 0;
    while (str[i] != '\0') {
        result = result * base + (str[i] - '0');
        i++;
    }
    return result;
}
