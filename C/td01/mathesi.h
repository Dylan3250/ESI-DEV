#ifndef ISPRIME_H
#define ISPRIME_H
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isPrime(unsigned number);
void isPrimeBetween(unsigned min, unsigned max);
void printPrimeFactor(unsigned number, bool showPower);
unsigned gcd(unsigned a, unsigned b);
void displayGcd(unsigned a, unsigned b);

#endif // ISPRIME_H
