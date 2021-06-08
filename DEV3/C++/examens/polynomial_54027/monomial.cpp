#include "monomial.h"

#include <string>

namespace nvs {

std::string Monomial::to_string() const {
    return std::string { std::to_string(coefficient()) + " x^" + std::to_string(degree()) };
}

}
