#include "functions.h"

int main() {
    printf("-----------------------------------------\n");
    printf("----------------- EXO 1 -----------------\n");
    printf("-----------------------------------------\n\n");
    unsigned nbElem = 0;
    unsigned number = 84;
    unsigned * decomposition = primeFactorsA(&nbElem, number);
    printf("%d = ", number);
    for (unsigned i = 0; i < nbElem; ++i) {
        printf("%d ", decomposition[i]);
    }
    printf("\n");
    free(decomposition);

    printf("\n-----------------------------------------\n");
    printf("----------------- EXO 2 -----------------\n");
    printf("-----------------------------------------\n\n");

    unsigned * facteurs = NULL;
    unsigned * multiplicites = NULL;
    unsigned nbElemEx2;
    for (int i = 2; i <= 100; ++i) {
        number = i;
        int calcul = 1;
        nbElemEx2 = primeFactorsB(&facteurs, &multiplicites, number);
        printf("%d = ", number);
        for (unsigned i = 0; i < nbElemEx2; ++i) {
            printf("%d ^ %d", facteurs[i], multiplicites[i]);
            if (i != nbElemEx2 - 1) {
                printf(" * ");
            }
            calcul = calcul * pow(facteurs[i], multiplicites[i]);
        }
        printf(" = %d\n", calcul);
        free(facteurs);
        free(multiplicites);
    }

    printf("\n-----------------------------------------\n");
    printf("----------------- EXO 3 -----------------\n");
    printf("-----------------------------------------\n\n");

    for (int i = 2; i <= 100; ++i) {
        unsigned nbElemEx3 = 0;
        int calcul = 1;
        number = i;
        printf("%d = ", number);
        PrimeFactor * decompositionEx3 = primeFactorsC(&nbElemEx3, number);
        for (unsigned i = 0; i < nbElemEx3; ++i) {
            printf("%d ^ %d", decompositionEx3[i].value,
                   decompositionEx3[i].multiplicity);
            if (i != nbElemEx3 - 1) {
                printf(" * ");
            }
            calcul = calcul * pow(decompositionEx3[i].value,
                                  decompositionEx3[i].multiplicity);
        }
        printf(" = %d\n", calcul);
        free(decompositionEx3);
    }

    printf("\n-----------------------------------------\n");
    printf("----------------- EXO 4 -----------------\n");
    printf("-----------------------------------------\n\n");

    for (int i = 2; i <= 100; ++i) {
        PrimeFactorization f = { i, 0, NULL };
        primeFactorsD(&f);

        int calcul = 1;
        printf("%d = ", i);
        for (unsigned j = 0; j < f.count; ++j) {
            printf("%d ^ %d", f.primeFactors[j].value,
                   f.primeFactors[j].multiplicity);
            if (j != f.count - 1) {
                printf(" * ");
            }
            calcul = calcul * pow(f.primeFactors[j].value,
                                  f.primeFactors[j].multiplicity);
        }
        printf(" = %d\n", calcul);
        free(f.primeFactors);
    }
    return 0;
}
