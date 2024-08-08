#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    return write(1, buffer, strlen(buffer));
}
