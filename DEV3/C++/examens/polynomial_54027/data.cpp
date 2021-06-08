#include "data.h"

#include <vector>
#include <utility>
#include <map>

#include <algorithm>

#include "random/random.hpp"

namespace nvs
{

std::vector<std::pair<char, std::map<unsigned, int>>>
data(Reproductible reproductible)
{
    if (reproductible == Reproductible::FALSE)
    {
        nvs::randomize();
    }

    std::vector<std::pair<char, std::map<unsigned, int>>> result;

    unsigned nb_value { nvs::random_value(50u, 1000u) };

    while (--nb_value)
    {
        char m_or_p { random_value(0, 4) ? 'p' : 'm' };
        unsigned nb_term { m_or_p == 'm' ? 1 : random_value(0u, 10u) };
        std::map<unsigned, int> deg_coef;
        for (unsigned u { 0 }; u < nb_term; ++u)
        {
            deg_coef[random_value(0u, 20u)] += random_value(-20, 20);
        }
        result.push_back(std::make_pair(m_or_p, deg_coef));
    }

    return result;
}

}
