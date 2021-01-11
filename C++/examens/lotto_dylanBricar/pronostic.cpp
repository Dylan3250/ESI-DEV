#include "pronostic.h"
#include <algorithm>

namespace g54027 {

Pronostic::Pronostic(unsigned max,
                     const std::vector<unsigned> & value) :
    max_ {max},
    values_ {value} {
    if (max == 0) {
        throw std::invalid_argument("Valeur du tirage nulle");
    } else if (values_.size() == 0) {
        throw std::invalid_argument("Taille des valeurs = 0");
    }
    for_each(values_.begin(), values_.end(), [max](const auto & o) {
        if (o > max || o < 1) {
            throw std::invalid_argument("Trop grand ou trop petit");
        }
    });
    for (unsigned i = 0; i < values_.size(); i++) {
        unsigned valueInt = values_.at(i);
        for (unsigned j = 0; j < values_.size(); j++) {
            if (j != i && values_.at(j) == valueInt) {
                throw std::invalid_argument("Nombre dupliqué");
            }
        }
    }
    for_each(values_.begin(), values_.end(), [max](const auto & o) {
        if (o > max || o < 1) {
            throw std::invalid_argument("Trop grand ou trop petit");
        }
    });
}

Pronostic::Pronostic(unsigned max,
                     const std::initializer_list<unsigned> & value) :
    max_ {max},
    values_ {value} {
    if (max == 0) {
        throw std::invalid_argument("Valeur du tirage nulle");
    } else if (values_.size() == 0) {
        throw std::invalid_argument("Taille des valeurs = 0");
    }
    std::vector<unsigned> checkValue = value;
    for_each(checkValue.begin(), checkValue.end(), [max](const auto & o) {
        if (o > max || o < 1) {
            throw std::invalid_argument("Trop grand ou trop petit");
        }
    });
    for (unsigned i = 0; i < values_.size(); i++) {
        unsigned valueInt = checkValue.at(i);
        for (unsigned j = 0; j < values_.size(); j++) {
            if (j != i && checkValue.at(j) == valueInt) {
                throw std::invalid_argument("Nombre dupliqué");
            }
        }
    }
    for_each(checkValue.begin(), checkValue.end(), [max](const auto & o) {
        if (o > max || o < 1) {
            throw std::invalid_argument("Trop grand ou trop petit");
        }
    });
}

std::string Pronostic::to_string() const {
    std::string str;
    unsigned maxValue = 0;
    for (unsigned long long i = 0; i < values_.size(); i++) {
        if (maxValue < values_.at(i)) {
            maxValue = values_.at(i);
        }
    }
    str += std::to_string(values_.size()) + "\n"
           + std::to_string(maxValue) + "\n";

    for (unsigned long long i = 0; i < values_.size(); i++) {
        str += std::to_string(values_.at(i)) + " ";
    }

    return str;
}

std::set<unsigned> set;
inline const std::set<unsigned> & Pronostic::value() const {
    std::copy(values_.begin(),
              values_.end(),
              std::inserter(set, set.end()));
    return set;
}

}
