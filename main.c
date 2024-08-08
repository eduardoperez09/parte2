#include "my_io.h"
#include "arithmetic_operations.h"

int main() {
    int num1_bin, num2_bin, sum_bin, diff_bin, prod_bin, quot_bin;
    int num1_hex, num2_hex, sum_hex, diff_hex, prod_hex, quot_hex;
    char bin1[32], bin2[32], hex1[20], hex2[20];
    char result[5];

    // Prompt for and read binary numbers
    my_printf("Enter two binary numbers (format: bin1 bin2):\n");
    my_scanf("%s %s", bin1, bin2);

    // Convert binary strings to integers
    num1_bin = str_to_int(bin1, 2);
    num2_bin = str_to_int(bin2, 2);

    // Perform arithmetic operations on binary numbers
    sum_bin = add(num1_bin, num2_bin);
    diff_bin = subtract(num1_bin, num2_bin);
    prod_bin = multiply(num1_bin, num2_bin);
    quot_bin = divide(num1_bin, num2_bin);

    // Display results for binary operations
    my_printf("Binary Operations:\n");

    int_to_str(sum_bin, result, 2);
    my_printf("Sum: %s\n", result);

    int_to_str(diff_bin, result, 2);
    my_printf("Difference: %s\n", result);

    int_to_str(prod_bin, result, 2);
    my_printf("Product: %s\n", result);

    int_to_str(quot_bin, result, 2);
    my_printf("Quotient: %s\n", result);

    // Prompt for and read hexadecimal numbers
    my_printf("Enter two hexadecimal numbers (format: hex1 hex2):\n");
    my_scanf("%s %s", hex1, hex2);

    // Convert hexadecimal strings to integers
    num1_hex = str_to_int(hex1, 16);
    num2_hex = str_to_int(hex2, 16);

    // Perform arithmetic operations on hexadecimal numbers
    sum_hex = add(num1_hex, num2_hex);
    diff_hex = subtract(num1_hex, num2_hex);
    prod_hex = multiply(num1_hex, num2_hex);
    quot_hex = divide(num1_hex, num2_hex);

    // Display results for hexadecimal operations
    my_printf("Hexadecimal Operations:\n");

    int_to_str(sum_hex, result, 16);
    my_printf("Sum: %s\n", result);

    int_to_str(diff_hex, result, 16);
    my_printf("Difference: %s\n", result);

    int_to_str(prod_hex, result, 16);
    my_printf("Product: %s\n", result);

    int_to_str(quot_hex, result, 16);
    my_printf("Quotient: %s\n", result);

    return 0;
}
