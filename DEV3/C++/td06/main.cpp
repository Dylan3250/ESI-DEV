#include "mathesi.h"
#include <iostream>

int main() {
    // EXERCICE 1
    std::cout << "Est-ce premier ? : " << isPrime(7) << std::boolalpha <<
              std::endl;

    // EXERCICE 2
    isPrimeBetween(200, 349);

    // EXERCICE 3
    auto eDiv = euclidianDivision(30, 7);
    std::cout << "30 = 7 * "
              << eDiv.first << " + " << eDiv.second << std::endl;

    // EXERCICE 4
    std::cout << "euclidianDivision : division by zero" << std::endl;
    showAllEuclidian(27);
}
