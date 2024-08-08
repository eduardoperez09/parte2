#include "my_printf.h"
#include "my_scanf.h"
#include "arithmetic_operations.h"
#include "conversion.h"

int main() {
    int num1_bin, num2_bin, sum_bin, diff_bin, prod_bin, quot_bin;
    int num1_hex, num2_hex, sum_hex, diff_hex, prod_hex, quot_hex;
    char bin1[32], bin2[32], hex1[20], hex2[20];

    my_printf("Enter two binary numbers (format: bin1 bin2):\n");
    my_scanf("%b %b", &num1_bin, &num2_bin);
    sum_bin = add(num1_bin, num2_bin);
    diff_bin = subtract(num1_bin, num2_bin);
    prod_bin = multiply(num1_bin, num2_bin);
    quot_bin = divide(num1_bin, num2_bin);

    my_printf("Binary Operations:\n");
    my_printf("Sum: %b\n", sum_bin);
    my_printf("Difference: %b\n", diff_bin);
    my_printf("Product: %b\n", prod_bin);
    my_printf("Quotient: %b\n", quot_bin);

    my_printf("Enter two hexadecimal numbers (format: hex1 hex2):\n");
    my_scanf("%x %x", &num1_hex, &num2_hex);
    sum_hex = add(num1_hex, num2_hex);
    diff_hex = subtract(num1_hex, num2_hex);
    prod_hex = multiply(num1_hex, num2_hex);
    quot_hex = divide(num1_hex, num2_hex);

    my_printf("Hexadecimal Operations:\n");
    my_printf("Sum: %x\n", sum_hex);
    my_printf("Difference: %x\n", diff_hex);
    my_printf("Product: %x\n", prod_hex);
    my_printf("Quotient: %x\n", quot_hex);

    return 0;
}
