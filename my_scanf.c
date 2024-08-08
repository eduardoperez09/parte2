#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void my_scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[100];
    read(0, buffer, 100);
    buffer[strcspn(buffer, "\n")] = '\0';

    const char *p = format;
    const char *buf_ptr = buffer;
    while (*p != '\0') {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': {
                    int *int_ptr = va_arg(args, int *);
                    sscanf(buf_ptr, "%d", int_ptr);
                    buf_ptr += strcspn(buf_ptr, " ") + 1;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    sscanf(buf_ptr, "%s", str);
                    buf_ptr += strcspn(buf_ptr, " ") + 1;
                    break;
                }
                case 'f': {
                    float *float_ptr = va_arg(args, float *);
                    sscanf(buf_ptr, "%f", float_ptr);
                    buf_ptr += strcspn(buf_ptr, " ") + 1;
                    break;
                }
                case 'x': {
                    int *int_ptr = va_arg(args, int *);
                    sscanf(buf_ptr, "%x", int_ptr);
                    buf_ptr += strcspn(buf_ptr, " ") + 1;
                    break;
                }
                case 'b': {
                    char *str = va_arg(args, char *);
                    sscanf(buf_ptr, "%s", str);
                    buf_ptr += strcspn(buf_ptr, " ") + 1;
                    break;
                }
            }
        }
        p++;
    }

    va_end(args);
}
