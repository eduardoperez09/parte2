#include <stdarg.h>
#include <unistd.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd': {
                    int num = va_arg(args, int);
                    char buffer[12];
                    snprintf(buffer, sizeof(buffer), "%d", num);
                    write(1, buffer, strlen(buffer));
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    write(1, str, strlen(str));
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    char buffer[32];
                    snprintf(buffer, sizeof(buffer), "%f", num);
                    write(1, buffer, strlen(buffer));
                    break;
                }
                case 'x': {
                    int num = va_arg(args, int);
                    char buffer[12];
                    snprintf(buffer, sizeof(buffer), "%x", num);
                    write(1, buffer, strlen(buffer));
                    break;
                }
                case 'b': {
                    int num = va_arg(args, int);
                    char buffer[33];
                    for (int i = 31; i >= 0; i--) {
                        buffer[31 - i] = (num & (1 << i)) ? '1' : '0';
                    }
                    buffer[32] = '\0';
                    write(1, buffer, 32);
                    break;
                }
                default:
                    write(1, p, 1);
                    break;
            }
        } else {
            write(1, p, 1);
        }
    }

    va_end(args);
}
