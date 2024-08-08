#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[1024];
    char temp[64];
    char *str;
    int int_val;
    double dbl_val;

    int index = 0, i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'd':
                    int_val = va_arg(args, int);
                    snprintf(temp, sizeof(temp), "%d", int_val);
                    strcpy(&buffer[index], temp);
                    index += strlen(temp);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    strcpy(&buffer[index], str);
                    index += strlen(str);
                    break;
                case 'f':
                    dbl_val = va_arg(args, double);
                    snprintf(temp, sizeof(temp), "%.6f", dbl_val);
                    strcpy(&buffer[index], temp);
                    index += strlen(temp);
                    break;
                case 'x':
                    int_val = va_arg(args, int);
                    snprintf(temp, sizeof(temp), "%04X", int_val & 0xFFFF);
                    strcpy(&buffer[index], temp);
                    index += strlen(temp);
                    break;
                case 'b':
                    int_val = va_arg(args, int);
                    snprintf(temp, sizeof(temp), "%04X", int_val & 0xFFFF); // Convert binary to 4 digit hexadecimal
                    strcpy(&buffer[index], temp);
                    index += strlen(temp);
                    break;
            }
        } else {
            buffer[index++] = format[i];
        }
        i++;
    }

    buffer[index] = '\0';
    write(1, buffer, strlen(buffer));
    va_end(args);
}
