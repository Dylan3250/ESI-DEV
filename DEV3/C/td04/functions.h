#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct PrimeFactor PrimeFactor;
struct PrimeFactor {
    unsigned value;
    unsigned multiplicity;
};

typedef struct PrimeFactorization PrimeFactorization;
struct PrimeFactorization {
    unsigned number;
    unsigned count;
    PrimeFactor * primeFactors;
};

bool isPrime(unsigned int number);
unsigned * primeFactorsA(unsigned * count, unsigned number);
unsigned primeFactorsB(unsigned * * factor, unsigned * * multiplicity,
                       unsigned number);
struct PrimeFactor * primeFactorsC(unsigned * count, unsigned number);
void primeFactorsD(struct PrimeFactorization * pf);

#endif // FUNCTIONS_H
