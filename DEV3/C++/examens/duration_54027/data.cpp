#include "data.h"

#include <vector>
#include <tuple>

#include "sign.h"
#include "random/random.hpp"

using namespace std;

namespace g54027 {

std::vector<std::tuple<Sign, unsigned, unsigned>>
data_sidase(unsigned size, Reproductible reproductible) {
    if (reproductible == Reproductible::FALSE) {
        g54027::randomize();
    }

    vector<tuple<Sign, unsigned, unsigned>> result { size };

    for (auto & e : result) {
        e = { random_value(0, 1) ? Sign::PLUS : Sign::MINUS,
              random_value(0u, 10u), random_value(0u, 200'000u)
            };
    }

    return result;
}

std::vector<std::tuple<Sign, long unsigned>>
data_sise(unsigned size, Reproductible reproductible) {
    if (reproductible == Reproductible::FALSE) {
        g54027::randomize();
    }

    vector<tuple<Sign, long unsigned>> result { size };

    for (auto & e : result) {
        e = { random_value(0, 1) ? Sign::PLUS : Sign::MINUS,
              random_value(0ul, 50'000'000ul)
            };
    }

    return result;
}

}
