#include "polynomial.h"

#include <string>

namespace nvs {

// méthodes

std::string Polynomial::to_string() const {
    return std::string { std::to_string(polynomial().at(0)) + " x^" + std::to_string(polynomial().at(1)) };
}

// fonctions

}
