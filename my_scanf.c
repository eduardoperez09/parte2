#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 1024

int my_scanf(const char *format, ...) {
    char buf[MAX_BUF_SIZE];
    int read_bytes = read(0, buf, MAX_BUF_SIZE - 1);
    if (read_bytes <= 0) return -1;
    buf[read_bytes] = '\0';

    va_list args;
    va_start(args, format);
    char *str;
    int *int_ptr;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int_ptr = va_arg(args, int*);
                    sscanf(buf, "%d", int_ptr);
                    break;
                }
                case 's': {
                    str = va_arg(args, char*);
                    sscanf(buf, "%s", str);
                    break;
                }
                case 'x': {
                    int_ptr = va_arg(args, int*);
                    sscanf(buf, "%x", int_ptr);
                    break;
                }
                case 'b': {
                    int_ptr = va_arg(args, int*);
                    sscanf(buf, "%d", int_ptr); // %b no es estándar, usa %d y maneja la conversión
                    break;
                }
                default:
                    return -1;
            }
        }
        format++;
    }
    va_end(args);
    return 0;
}
