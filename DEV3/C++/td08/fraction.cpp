// TODO : include manquants

#include "fraction.h"

namespace g54027 {

// méthodes

Fraction::Fraction(int numerator, int denominator) :
    sign_ { g54027::sign(numerator) * g54027::sign(denominator)},
    numerator_ { static_cast<unsigned>(numerator > 0 ? numerator : -numerator)},
    denominator_ { static_cast<unsigned>(denominator == 0 ? 1 : (denominator > 0 ? denominator : -denominator)) } {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator can't be 0");
    }
}

Fraction::Fraction(Sign sign, unsigned numerator,
                   unsigned denominator) :
    sign_ { denominator == 0 ?
            throw std::invalid_argument { "denominator can't be ZERO" } :
            numerator == 0 ?
            Sign::ZERO :
            sign == Sign::ZERO ?
            throw std::invalid_argument { "sign can't be ZERO" } :
            sign },
    numerator_ { numerator > 0 ? numerator : -numerator},
    denominator_ { denominator == 0 ? 1 : denominator } {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator can't be 0");
    }
}

//std::string Fraction::to_string() const {
//    if (this->sign() == Sign::ZERO) {
//        return "0";
//    }
//    if (this->denominator() == 1) {
//        return g54027::to_string(this->sign()) + std::to_string(
//                   this->numerator());
//    }
//    return g54027::to_string(this->sign()) + std::to_string(
//               this->numerator()) + " / " + std::to_string(this->denominator());
//}

// fonctions

bool operator<(const Fraction & lhs,
               const Fraction & rhs) {
    return static_cast<int>(lhs.sign()) * lhs.numerator() *
           rhs.denominator() <
           static_cast<int>(rhs.sign()) * rhs.numerator() * lhs.denominator();
}

Fraction operator+(const Fraction & lhs,
                   const Fraction & rhs) {
    int num = static_cast<int>(lhs.sign()) * lhs.numerator() *
              rhs.denominator() +
              static_cast<int>(rhs.sign()) * rhs.numerator() * lhs.denominator();
    int denom = lhs.denominator() * rhs.denominator();
    return Fraction(num, denom);
}

Fraction operator*(const Fraction & lhs,
                   const Fraction & rhs) {
    int num = static_cast<int>(lhs.sign()) * static_cast<int>
              (rhs.sign()) * lhs.numerator() * rhs.numerator();
    int denom = lhs.denominator() * rhs.denominator();
    return Fraction(num, denom);
}

Fraction operator/(const Fraction & lhs, const Fraction & rhs) {
    Fraction inversed = Fraction(
                            rhs.sign(),
                            rhs.denominator(),
                            rhs.numerator());
    return inversed * lhs;
}

} // namespave g54027
