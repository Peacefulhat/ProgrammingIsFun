#ifndef BIGINT_H
#define BIGINT_H
#include<stdio.h>
#include<string.h>
#define MAX_DIGITS 1000

typedef struct {
    int digits[MAX_DIGITS]; 
    int length;        
} BigInt;

void init_bigint(BigInt *num, const char *str);
void print_bigint(const BigInt *num);
void add_bigint(const BigInt *a, const BigInt *b, BigInt *result);
void multiply_bigint(const BigInt *a, const BigInt *b, BigInt *result);
void subtract_bigint(const BigInt *a, const BigInt *b, BigInt *result);
void divide_bigint(const BigInt *a, const BigInt *b, BigInt *quotient, BigInt *remainder);
int compare_bigint(const BigInt *a, const BigInt *b);
void modulo_bigint(const BigInt *a, const BigInt *b, BigInt *result);
void power_bigint(const BigInt *base, const BigInt *exponent, BigInt *result);
void gcd_bigint(const BigInt *a, const BigInt *b, BigInt *result);

#endif
