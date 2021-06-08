#include "mathesi.h"
#include <math.h>

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

void isPrimeBetween(unsigned min, unsigned max) {
    std::cout.sync_with_stdio(false);
    std::cout << "Les nombres premiers entre "
              << min << " et " << max << std::endl;
    unsigned n = min;
    unsigned col = 0;
    while (n <= max) {
        std::cout << std::setw(4) << (isPrime(n) ? std::to_string(n) : ".");
        col++;
        if (col == 10) {
            std::cout << std::endl;
            col = 0;
        }
        n++;
    }
    std::cout.sync_with_stdio(true);
}

std::pair<int, int> euclidianDivision(int dividend, int divisor) {
    return std::make_pair(dividend / divisor, dividend % divisor);
}

void showAllEuclidian(int dividend) {
    int lgDiv = std::to_string(dividend).length();

    for (int i = 1; i <= dividend; ++i) {
        auto currentPair = euclidianDivision(dividend, i);
        std::cout << dividend << " = "
                  << std::setw(lgDiv) << std::setw(lgDiv) << currentPair.first
                  << " * " << i
                  << " + " << currentPair.second
                  << std::endl;
    }
}
