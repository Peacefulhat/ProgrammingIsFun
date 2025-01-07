#include"bigint.h"
int main() {
    BigInt num1, num2, sum, diff, product, quotient, remainder, power_result, gcd_result;

    init_bigint(&num1, "987654321987654321987654321");
    init_bigint(&num2, "123456789123456789123456789");

    // Addition
    add_bigint(&num1, &num2, &sum);
    printf("Sum: ");
    print_bigint(&sum);

    // Subtraction
    subtract_bigint(&num1, &num2, &diff);
    printf("Difference: ");
    print_bigint(&diff);

    // Multiplication
    multiply_bigint(&num1, &num2, &product);
    printf("Product: ");
    print_bigint(&product);

    // Division
    divide_bigint(&num1, &num2, &quotient, &remainder);
    printf("Quotient: ");
    print_bigint(&quotient);
    printf("Remainder: ");
    print_bigint(&remainder);

    // Modulo
    modulo_bigint(&num1, &num2, &remainder);
    printf("Modulo: ");
    print_bigint(&remainder);

     // Power
    init_bigint(&num1, "2");
    init_bigint(&num2, "10");
    power_bigint(&num1, &num2, &power_result);
    printf("Power: ");
    print_bigint(&power_result);

    // GCD
    gcd_bigint(&num1, &num2, &gcd_result);
    printf("GCD: ");
    print_bigint(&gcd_result);

    return 0;
}
