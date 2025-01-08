#include"bigint.h"

void init_bigint(BigInt *num, const char *str) {
    num->length = strlen(str);
    for (int i = 0; i < num->length; i++) {
        num->digits[i] = str[num->length - i - 1] - '0';  // Store in reverse order
    }
}

void print_bigint(const BigInt *num) {
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

void add_bigint(const BigInt *a, const BigInt *b, BigInt *result) {
    int carry = 0, i;
    result->length = (a->length > b->length ? a->length : b->length);
    for (i = 0; i < result->length || carry; i++) {
        int digit_a = (i < a->length) ? a->digits[i] : 0;
        int digit_b = (i < b->length) ? b->digits[i] : 0;
        int sum = digit_a + digit_b + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    result->length = i;
}

void multiply_bigint(const BigInt *a, const BigInt *b, BigInt *result) {
    memset(result->digits, 0, sizeof(result->digits));
    result->length = a->length + b->length;
    for (int i = 0; i < a->length; i++) {
        int carry = 0;
        for (int j = 0; j < b->length || carry; j++) {
            int digit_b = (j < b->length) ? b->digits[j] : 0;
            int product = result->digits[i + j] + a->digits[i] * digit_b + carry;
            result->digits[i + j] = product % 10;
            carry = product / 10;
        }
    }

    // Remove leading zeros
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}


void subtract_bigint(const BigInt *a, const BigInt *b, BigInt *result) {
    int borrow = 0;

    result->length = a->length;

    for (int i = 0; i < result->length; i++) {
        int digit_a = (i < a->length) ? a->digits[i] : 0;
        int digit_b = (i < b->length) ? b->digits[i] : 0;

        int diff = digit_a - digit_b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->digits[i] = diff;
    }

    // Remove leading zeros
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}


void divide_bigint(const BigInt *a, const BigInt *b, BigInt *quotient, BigInt *remainder) {
    BigInt temp_a = *a;
    BigInt temp_b = *b;
    BigInt one;
    init_bigint(&one, "1");

    memset(quotient->digits, 0, sizeof(quotient->digits));
    quotient->length = 0;

    init_bigint(remainder, "0");

    while (compare_bigint(&temp_a, &temp_b) >= 0) {
        add_bigint(quotient, &one, quotient);
        subtract_bigint(&temp_a, &temp_b, &temp_a);
    }

    *remainder = temp_a;
}


int compare_bigint(const BigInt *a, const BigInt *b) {
    if (a->length > b->length) return 1;
    if (a->length < b->length) return -1;

    for (int i = a->length - 1; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) return 1;
        if (a->digits[i] < b->digits[i]) return -1;
    }
    return 0;  // Numbers are equal
}


void modulo_bigint(const BigInt *a, const BigInt *b, BigInt *result) {
    BigInt quotient, remainder;
    divide_bigint(a, b, &quotient, &remainder);
    *result = remainder;
}


void power_bigint(const BigInt *base, const BigInt *exponent, BigInt *result) {
    BigInt temp_base = *base;
    BigInt temp_exponent = *exponent;
    BigInt one;
    init_bigint(&one, "1");

    *result = one;

    while (compare_bigint(&temp_exponent, &one) > 0) {
        multiply_bigint(result, &temp_base, result);
        subtract_bigint(&temp_exponent, &one, &temp_exponent);
    }
}


void gcd_bigint(const BigInt *a, const BigInt *b, BigInt *result) {
    BigInt temp_a = *a;
    BigInt temp_b = *b;
    BigInt remainder;

    while (compare_bigint(&temp_b, &(BigInt){ .length = 1, .digits = {0} }) != 0) {
        modulo_bigint(&temp_a, &temp_b, &remainder);
        temp_a = temp_b;
        temp_b = remainder;
    }

    *result = temp_a;
}
