#include "my_printf.h"
#include "my_scanf.h"
#include "arithmetic_operations.h"
#include "conversion.h"

int main() {
    int num1_bin, num2_bin, sum_bin, diff_bin, prod_bin, quot_bin;
    int num1_hex, num2_hex, sum_hex, diff_hex, prod_hex, quot_hex;
    char bin1[32], bin2[32], hex1[20], hex2[20];

    // Ejemplo de entrada para números binarios
    my_printf("Enter two binary numbers (format: bin1 bin2):\n");
    my_scanf("%s %s", bin1, bin2); // Lectura de entrada binaria como cadenas
    num1_bin = str_to_int(bin1, 2);
    num2_bin = str_to_int(bin2, 2);

    sum_bin = add(num1_bin, num2_bin);
    diff_bin = subtract(num1_bin, num2_bin);
    prod_bin = multiply(num1_bin, num2_bin);
    quot_bin = divide(num1_bin, num2_bin);

    char sum_bin_str[33], diff_bin_str[33], prod_bin_str[33], quot_bin_str[33];
    int_to_str(sum_bin, sum_bin_str, 2);
    int_to_str(diff_bin, diff_bin_str, 2);
    int_to_str(prod_bin, prod_bin_str, 2);
    int_to_str(quot_bin, quot_bin_str, 2);

    my_printf("Binary Operations:\n");
    my_printf("Sum: %s\n", sum_bin_str);
    my_printf("Difference: %s\n", diff_bin_str);
    my_printf("Product: %s\n", prod_bin_str);
    my_printf("Quotient: %s\n", quot_bin_str);

    // Ejemplo de entrada para números hexadecimales
    my_printf("Enter two hexadecimal numbers (format: hex1 hex2):\n");
    my_scanf("%s %s", hex1, hex2); // Lectura de entrada hexadecimal como cadenas
    num1_hex = str_to_int(hex1, 16);
    num2_hex = str_to_int(hex2, 16);

    sum_hex = add(num1_hex, num2_hex);
    diff_hex = subtract(num1_hex, num2_hex);
    prod_hex = multiply(num1_hex, num2_hex);
    quot_hex = divide(num1_hex, num2_hex);

    char sum_hex_str[5], diff_hex_str[5], prod_hex_str[5], quot_hex_str[5];
    int_to_str(sum_hex, sum_hex_str, 16);
    int_to_str(diff_hex, diff_hex_str, 16);
    int_to_str(prod_hex, prod_hex_str, 16);
    int_to_str(quot_hex, quot_hex_str, 16);

    my_printf("Hexadecimal Operations:\n");
    my_printf("Sum: %s\n", sum_hex_str);
    my_printf("Difference: %s\n", diff_hex_str);
    my_printf("Product: %s\n", prod_hex_str);
    my_printf("Quotient: %s\n", quot_hex_str);

    return 0;
}
