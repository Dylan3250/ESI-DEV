#include <vector>
#include <utility>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "../random/random.hpp"

namespace nvs
{

namespace lotto
{

std::vector<std::pair<unsigned, std::vector<unsigned>>>
data(unsigned pronostic_size, unsigned pronostic_max, unsigned size)
{
    using namespace std;
    using namespace nvs;

    if (pronostic_size == 0 ||
            pronostic_max == 0 ||
            pronostic_max < pronostic_size)
    {
        throw invalid_argument { "boom !" };
    }

    vector<pair<unsigned, vector<unsigned>>> result(size);
    const int delta { 1 };

    const unsigned pronostic_max_min { pronostic_max < 1 + delta ?
                                       1 : pronostic_max - delta } ;
    const unsigned pronostic_max_max { pronostic_max + delta };

    vector<unsigned> pronostic(pronostic_max_max);
    iota(begin(pronostic), end(pronostic), 1);

    const unsigned pronostic_size_min { pronostic_size < 1 + delta ?
                                        1 : pronostic_size - delta };
    const unsigned pronostic_size_max { pronostic_size + delta };

    for (unsigned u { 0 }; u < size; ++u)
    {
        shuffle(begin(pronostic), end(pronostic), nvs::urng());

        result[u] = { random_value(pronostic_max_min,
                                   pronostic_max_max),
        {
            cbegin(pronostic),
            cbegin(pronostic) + random_value(pronostic_size_min,
                                             pronostic_size_max)
        }
                    };

        unsigned duplicate_period { 49 };
        if (!nvs::random_value(0u, duplicate_period))
        {
            const auto idx_max = result[u].second.size() - 1;
            const decltype (idx_max) zero { };
            result[u].second[nvs::random_value(zero, idx_max)] =
                result[u].second[nvs::random_value(zero, idx_max)];
        }
    }

    return result;
}

} // namespace lotto

} // namespace nvs
