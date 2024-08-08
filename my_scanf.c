#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void my_scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    int len = read(0, buffer, sizeof(buffer) - 1);
    buffer[len] = '\0';

    char *str_ptr;
    int *int_ptr;

    int i = 0, j = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'd':
                    int_ptr = va_arg(args, int *);
                    sscanf(buffer + j, "%d", int_ptr);
                    while (buffer[j] != ' ' && buffer[j] != '\n') j++;
                    break;
                case 's':
                    str_ptr = va_arg(args, char *);
                    sscanf(buffer + j, "%s", str_ptr);
                    while (buffer[j] != ' ' && buffer[j] != '\n') j++;
                    break;
            }
        } else {
            j++;
        }
        i++;
    }

    va_end(args);
}
