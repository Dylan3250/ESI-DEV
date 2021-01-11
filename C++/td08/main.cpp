#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "sign.h"
//#include "fraction.h"
#include "fraction_constexpr.h"
#include "random.hpp"
#include "data_fraction.h"

void ex1(void) {
    std::cout << "0 * - = "
              << g54027::sign(0) * g54027::sign(-1) << std::endl;
    std::cout << "0 * + = "
              << g54027::sign(0) * g54027::sign(1) << std::endl;
    std::cout << "+ * + = "
              << g54027::sign(1) * g54027::sign(1) << std::endl;
    std::cout << "- * - = "
              << g54027::sign(-1) * g54027::sign(-1) << std::endl;
    std::cout << "- * + = "
              << g54027::sign(-1) * g54027::sign(1) << std::endl;
}

void ex2(void) {
    g54027::Fraction f1 (3, 2);
    g54027::Fraction f2 (3, 5);
    g54027::Fraction f3 (-3, 5);
    g54027::Fraction f4 (3, -5);
    g54027::Fraction f5 (-3, -5);
    g54027::Fraction f6 (g54027::Sign::MINUS, 3, 5);
    // g54027::Fraction fDenoNull = g54027::Fraction(3, 0); -- make error
    g54027::Fraction fDenoEmpty (3);
    std::cout << f1.to_string() << std::endl;
    std::cout << "Inversed :" << (-f1).to_string() << std::endl;
    std::cout << f2.to_string() << std::endl;
    std::cout << f3.to_string() << std::endl;
    std::cout << f4.to_string() << std::endl;
    std::cout << f5.to_string() << std::endl;
    std::cout << fDenoEmpty.to_string() << std::endl;
    std::cout << (f1 * f2).to_string() << std::endl;
    std::cout << (f1 + f2).to_string() << std::endl;
    std::cout << (f1 - f2).to_string() << std::endl;
    std::cout << (f1 / f2).to_string() << std::endl;
    std::cout << (f1 / -f2).to_string() << std::endl;
    std::cout << "Inverse annuled :" << (-f1 / -f2).to_string() <<
              std::endl;
    std::cout << f6.to_string() << std::endl;
}

void ex3(void) {
    auto vector { nvs::data_signed(50, nvs::Random::UNIQUE) };
    std::vector<g54027::Fraction> vectorFraction;
    unsigned countError = 0;
    for (auto value : vector) {
        try {
            g54027::Fraction f {value.first, value.second};
            vectorFraction.push_back(f);
        } catch (const std::invalid_argument & e) {
            countError++;
        }
    }
    std::cout << "Erreurs : " << countError << std::endl;
    std::cout << "Nombre de fractions : "
              << vectorFraction.size() << std::endl;

    // Vector with pointer of fraction
    std::vector<const g54027::Fraction *> pointeurFraction;
    for (unsigned long long i = 0; i < vectorFraction.size(); i++) {
        pointeurFraction.push_back(&vectorFraction[i]);
    }

    std::cout << "\nAvant le tri : " << std::endl;
    for (auto value : pointeurFraction) {
        std::cout << (*value).to_string() << " | ";
    }

    std::sort(pointeurFraction.begin(),
              pointeurFraction.end(), [](
    const g54027::Fraction * a, const g54027::Fraction * b) {
        return a > b;
    });

    std::cout << "\n\nApres le tri : " << std::endl;
    for (auto value : pointeurFraction) {
        std::cout << (*value).to_string() << " | ";
    }
    std::cout << std::endl;
}

void ex4(void) {
    auto vector { nvs::data_unsigned(100, nvs::Random::REPRODUCTIBLE) } ;
    std::vector<g54027::Fraction> vectorFraction;
    unsigned countError { 0 };
    for (auto value : vector) {
        try {
            g54027::Fraction f {g54027::sign(std::get<0>(value)),
                                std::get<1>(value), std::get<2>(value)};
            vectorFraction.push_back(f);
        } catch (const std::invalid_argument & e) {
            countError++;
        }
    }
    std::cout << "Erreurs : " << countError << std::endl;
    std::cout << "Nombre de fractions : " << vectorFraction.size() <<
              std::endl;
    std::cout << std::endl;

    // Reference_wrapper with pointer of fraction
    std::vector<std::reference_wrapper<const g54027::Fraction>>
            fractionWrapper;
    for (unsigned long long i = 0; i < vectorFraction.size(); i++) {
        fractionWrapper.push_back(vectorFraction[i]);
    }

    std::cout << "Avant le tri : " << std::endl;
    for (auto value : fractionWrapper) {
        std::cout << value.get().to_string() << " | ";
    }

    std::sort(fractionWrapper.begin(),
              fractionWrapper.end(), [](
                  const std::reference_wrapper<const g54027::Fraction> a,
    const std::reference_wrapper<const g54027::Fraction> b) -> bool {
        return a.get() > b.get();
    });

    std::cout << "\n\nApres le tri : " << std::endl;
    for (auto value : fractionWrapper) {
        std::cout << value.get().to_string() << " | ";
    }
    std::cout << std::endl;
}

int main() {
    // ex1();
    // ex2();
    // ex3();
    ex4();
}
