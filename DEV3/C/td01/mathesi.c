#include "mathesi.h"

bool isPrime(unsigned int number) {
    if(number % 2 == 0) {
        return false;
    }

    for(unsigned div = 3; div < sqrt(number); div += 2) {
        if(number % div == 0) {
            return false;
        }
    }
    return true;
}

void isPrimeBetween(unsigned min, unsigned max) {
    printf("Les nombres premiers entre %d et %d\n", min, max);
    unsigned n = min;
    unsigned col = 0;
    while (n <= max) {
        if (isPrime(n)){
            printf("%4d", n);
        } else {
            printf("   .");
        }
        col++;
        if(col == 10) {
            printf("\n");
            col = 0;
        }
        n++;
    }
}

void printPrimeFactor(unsigned number, bool showPower) {
    unsigned int count = number - 1;
    unsigned int actualFactor = 0;
    unsigned int countFactor = 1;
    unsigned int oldFactor = 0;

    printf("%d = ", number);
    while(number != 1){
        while(number % count != 0 ) {
            count--;
        }

        actualFactor = number/count;
        number = count;
        count = number - 1;
        if(showPower) {
            if(actualFactor == oldFactor) {
                countFactor+=1;
                if (number == 1) {
                    printf(" ^ %d", countFactor);
                }
            } else {
                if(countFactor > 1){
                    printf(" ^ %d", countFactor);
                    countFactor = 1;
                }
                printf(!oldFactor ? "%d" : " x %d", actualFactor);
                oldFactor = actualFactor;
            }
        } else {
            printf(number != 1 ? "%d x " : "%d", actualFactor);
        }
    }
    printf("\n");
}

unsigned gcd(unsigned a, unsigned b) {
    return b == 0 ?  a : gcd(b, a%b);
}

void displayGcd(unsigned a, unsigned b) {
    unsigned saveB = b;
    for (unsigned ln = 0; ln < 6; ln++) {
        b = saveB;
        for (unsigned i = 0; i < 3; i++) {
            printf("gcd(%d, %d) = %2d", a, b, gcd(a, b));
            printf((i != 2) ? " | " : "\n");
            b -= 5;
        }
        a += 3;
    }
}
