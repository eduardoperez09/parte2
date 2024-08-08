#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c) {
    write(1, &c, 1);
}

void my_puts(const char *str) {
    while (*str) {
        my_putchar(*str++);
    }
}

void my_put_int(int num) {
    char buffer[12];
    int i = 0, sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);
    if (sign == -1) my_putchar('-');
    while (--i >= 0) {
        my_putchar(buffer[i]);
    }
}

void my_put_hex(unsigned int num) {
    char hex_chars[] = "0123456789abcdef";
    char buffer[8];
    int i = 0;
    do {
        buffer[i++] = hex_chars[num % 16];
        num /= 16;
    } while (num);
    while (--i >= 0) {
        my_putchar(buffer[i]);
    }
}

void my_put_bin(unsigned int num) {
    char buffer[32];
    int i = 0;
    if (num == 0) {
        my_putchar('0');
        return;
    }
    while (num) {
        buffer[i++] = (num % 2) + '0';
        num /= 2;
    }
    while (--i >= 0) {
        my_putchar(buffer[i]);
    }
}

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char c;
    while ((c = *format++)) {
        if (c != '%') {
            my_putchar(c);
            continue;
        }
        switch (*format++) {
            case 'd': {
                int num = va_arg(args, int);
                my_put_int(num);
                break;
            }
            case 's': {
                char *str = va_arg(args, char*);
                my_puts(str);
                break;
            }
            case 'x': {
                unsigned int num = va_arg(args, unsigned int);
                my_put_hex(num);
                break;
            }
            case 'b': {
                unsigned int num = va_arg(args, unsigned int);
                my_put_bin(num);
                break;
            }
            default:
                my_putchar('%');
                my_putchar(c);
        }
    }
    va_end(args);
}
