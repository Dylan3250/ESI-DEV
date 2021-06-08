#ifndef LOTTO_H
#define LOTTO_H
#include <iostream>
#include <vector>
#include "pronostic.h"
#include "draw.h"
#include "algorithm"

namespace g54027 {

enum class  Equality {
    STRICT,
    INCLUSIVE
};

class Lotto {
    const unsigned max_;
    const unsigned size_;
    std::vector<Pronostic> pronosticPlayers_;
    Pronostic pronosticLotto_;

  public:
    Lotto (unsigned size = 7, unsigned max = 50);
    inline unsigned size() const;
    inline unsigned max() const;

    inline const std::vector<Pronostic> & pronostics () const;
    inline bool has_draw() const;
    inline nvs::lotto::Draw draw() const;
    inline void add (const Pronostic & pronostic);
    inline void operator+ (const Pronostic & pronostic);
    inline void set_draw ();
    inline std::vector<Pronostic> winner (unsigned n,
                                          Equality type = Equality::STRICT) const;
};

inline unsigned Lotto::size() const {
    return pronosticLotto_.size();
}

inline unsigned Lotto::max() const {
    return pronosticLotto_.max();
}

inline const std::vector<Pronostic> & Lotto::pronostics () const {
    return pronosticPlayers_;
}

inline bool Lotto::has_draw() const {
    return pronosticLotto_.size() > 0;
}

inline nvs::lotto::Draw Lotto::draw() const {
    if (has_draw()) {
        throw std::logic_error("Tirage déjà effectué");
    }
    return nvs::lotto::Draw(size_, max_);
}

inline void Lotto::set_draw () {
    if (has_draw()) {
        throw std::logic_error("Tirage déjà effectué");
    }
    auto drawed = Lotto::draw();
    std::vector<unsigned> vector;
    for (auto const & value : drawed.value()) {
        vector.push_back(value);
    }
    Pronostic pronosticLotto_ {drawed.max(), vector};
}

inline void Lotto::add (const Pronostic & pronostic) {
    if (has_draw()) {
        throw std::logic_error("Tirage déjà effectué");
    } else if (pronostic.size() > max_) {
        throw std::invalid_argument("Trop de nombre tirés");
    }
    for (auto it = pronostic.value().begin();
            it != pronostic.value().end(); ++it) {
        if (*it > max_ || *it < 1) {
            throw std::invalid_argument("Trop grand nombre non autorisé");
        }
    }
    pronosticPlayers_.push_back(pronostic);
}

inline void Lotto::operator+ (const Pronostic & pronostic) {
    Lotto::add(pronostic);
}

inline std::vector<Pronostic> Lotto::winner (
    unsigned n, Equality type) const {
    if (!has_draw()) {
        throw std::logic_error("Tirage pas encore effectué");
    }
    if (n == 0 || n > max_) {
        throw std::logic_error("Nombre demandé de n est impossible");
    }
    std::vector<Pronostic> winners;
    unsigned nb = 0;
    for (unsigned long long i = 0; i < pronosticPlayers_.size() ; i++) {
        nb = 0;
        for (auto const & value : pronosticPlayers_.at(i).value()) {
            pronosticLotto_.value().find(value);
            if (pronosticLotto_.value().find(value) !=
                    pronosticLotto_.value().end()) {
                nb++;
            }
            if (type == Equality::INCLUSIVE) {
                if (nb >= n) {
                    break;
                }
            } else {
                if (nb == n) {
                    break;
                }
            }
        }

        if (type == Equality::INCLUSIVE) {
            if (nb >= n) {
                winners.push_back(pronosticPlayers_.at(i));
            }
        } else {
            if (nb == n) {
                winners.push_back(pronosticPlayers_.at(i));
            }
        }
    }
    return winners;
}
}
#endif // LOTTO_H
