#include <iostream>
#include <array>
#include "random.hpp"
#include <algorithm>
#include <map>

void ex1(unsigned n) {
    std::array<unsigned, 10> hist {};
    for (unsigned i = 0; i < n; ++i) {
        int val = nvs::random_value(0, hist.size());
        hist.at(val) += 1;
    }

    unsigned total = 0;
    for (size_t i = 0; i < hist.size(); ++i) {
        total += hist.at(i);

        std::cout << "Nombre de " << i << " : " << hist.at(i) << " ("
                  << (100. * hist.at(i)) / n << " %)" << std::endl;
    }
    std::cout << std::printf("Total %5s : ", "") << total << " ("
              << (100. * total) / n << " %)" <<  std::endl;
}

void print(const std::vector<int> & data) {
    std::for_each(data.cbegin(), data.cend(), [](const int & n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;
}

void sort(std::vector<int> & data, bool ascending) {
    unsigned int tmp;
    for (unsigned int i = 0; i < data.size() ; i++ ) {
        for (unsigned int j = i + 1; j < data.size() ; j++ ) {
            if (ascending ? data.at(j) < data.at(i) : data.at(j) > data.at(i)) {
                tmp = data.at(i);
                data.at(i) = data.at(j);
                data.at(j) = tmp;
            }
        }
    }
}

unsigned primeFactor(std::map<unsigned, unsigned> & result,
                     unsigned value) {
    unsigned modulo = 2;
    unsigned cntCurrentMod = 0;
    unsigned countFactors = 0;

    while (modulo <= value) {
        if (value % modulo == 0) {
            cntCurrentMod++;
            value = value / modulo;
            if (value % modulo != 0) {
                result.insert(std::pair<unsigned, unsigned> (modulo, cntCurrentMod));
                countFactors++;
            }
        } else {
            cntCurrentMod = 0;
            modulo++;
        }
    }

    result.insert(std::pair<unsigned, unsigned> (modulo, cntCurrentMod));
    return countFactors;
}

void showPrimeFactor(unsigned n, unsigned limit) {
    for (unsigned i = 0; i < limit ; i++) {
        std::map<unsigned, unsigned> primes;
        primeFactor(primes, n + i);

        std::cout << n + i << " = ";
        auto it = primes.begin();
        for (; it != --primes.end(); ++it) {
            std::cout << it->first;
            if (it->second != 1) {
                std::cout << "^" << it->second;
            }
            std::cout << " * ";
        }
        std::cout << it->first;
        if (it->second != 1) {
            std::cout << "^" << it->second;
        }
        std::cout << std::endl;
    }
}

int main() {
    nvs::randomize();
    // ex1(40000);

    // auto vector = std::vector<int> ({-4, -3, 4, 5, 2, 5, 2, -4, 3, 0, -5, 1, 5, -3, 2, -5, -5, -3, 2, 0});
    std::vector<int> vector(20);
    std::generate(vector.begin(), vector.end(), [] { return nvs::random_value(-5, 5); });

    print(vector);
    // sort(vector, true);
    // std::sort(vector.begin(), vector.end()); // croissant
    //std::sort(vector.begin(), vector.end(), [](int a, int b) { return a > b; }); // décroissant
    std::sort(vector.begin(), vector.end(), [](int a, int b) {
        return a % 3 < b % 3;
    }); // croissant mod 3
    print(vector);

    showPrimeFactor(1552521051, 10);
}
