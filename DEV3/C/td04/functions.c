#include "functions.h"

unsigned * primeFactorsA(unsigned * count, unsigned number) {
    unsigned * array = malloc(number * sizeof(unsigned));
    unsigned * saveAdress = array;
    unsigned countFactor = number - 1;
    unsigned actualFactor = 0;

    while (number != 1) {
        while (number % countFactor != 0 ) {
            countFactor--;
        }

        actualFactor = number / countFactor;
        number = countFactor;
        countFactor = number - 1;

        *array = actualFactor;
        array++;
        (*count)++;
    }
    return saveAdress;
}

bool isPrime(unsigned int number) {
    if (number % 2 == 0) {
        return false;
    }

    for (unsigned div = 3; div < sqrt(number); div += 2) {
        if (number % div == 0) {
            return false;
        }
    }
    return true;
}

unsigned primeFactorsB(unsigned * * factor, unsigned * * multiplicity,
                       unsigned number) {
    unsigned modulo = 2;
    unsigned cntCurrentMod = 0;
    unsigned countFactors = 0;
    unsigned * allFactors = malloc(number / 2 * sizeof (int));
    unsigned * allMultiplicities = malloc(number / 2 * sizeof (int));
    *factor = allFactors;
    *multiplicity = allMultiplicities;

    while (modulo <= number) {
        if (number % modulo == 0) {
            cntCurrentMod++;
            number = number / modulo;
            if (number % modulo != 0) {
                allMultiplicities[countFactors] = cntCurrentMod;
                allFactors[countFactors] = modulo;
                countFactors++;
            }
        } else {
            cntCurrentMod = 0;
            modulo++;
        }
    }

    allMultiplicities[countFactors] = cntCurrentMod;
    allFactors[countFactors] = number;

    return countFactors;
}

PrimeFactor * primeFactorsC(unsigned * count,
                            unsigned number) {
    unsigned modulo = 2;
    unsigned cntCurrentMod = 0;
    unsigned countFactors = 0;
    PrimeFactor * allPrimeFactor = malloc(number * sizeof (PrimeFactor));

    while (modulo <= number) {
        if (number % modulo == 0) {
            cntCurrentMod++;
            number = number / modulo;
            if (number % modulo != 0) {
                allPrimeFactor[countFactors].multiplicity = cntCurrentMod;
                allPrimeFactor[countFactors].value = modulo;
                countFactors++;
            }
        } else {
            cntCurrentMod = 0;
            modulo++;
        }
    }

    allPrimeFactor[countFactors].multiplicity = cntCurrentMod;
    allPrimeFactor[countFactors].value = number;

    *count = countFactors;
    return allPrimeFactor;
}

void primeFactorsD(PrimeFactorization * pf) {
    pf->primeFactors = primeFactorsC(&pf->count, pf->number);
}
