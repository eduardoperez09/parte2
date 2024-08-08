#ifndef MY_IO_H
#define MY_IO_H

void my_printf(const char *format, ...);
void my_scanf(const char *format, ...);

int str_to_int(const char *str, int base);
void int_to_str(int num, char *str, int base);

#endif // MY_IO_H
