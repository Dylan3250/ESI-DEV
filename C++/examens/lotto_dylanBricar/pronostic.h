#ifndef PRONOSTIC_H
#define PRONOSTIC_H

#include <iostream>
#include <vector>
#include <string>
#include <set>

namespace g54027 {

class Pronostic {
    const unsigned max_;
    const std::vector<unsigned> values_;

  public:
    Pronostic(unsigned max, const std::vector<unsigned> & value);

    Pronostic(unsigned max,
              const std::initializer_list<unsigned> & value);

    unsigned max() const;

    unsigned size () const;

    const std::set<unsigned> & value() const;

    std::string to_string() const;
};

inline unsigned Pronostic::max() const {
    return max_;
}

inline unsigned Pronostic::size() const {
    return values_.size();
}

}

#endif // PRONOSTIC_H
