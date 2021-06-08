#include "draw.h"

#include <stdexcept>
#include <string>
#include <typeinfo>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

#include "random/random.hpp"

namespace {

template <typename T>
std::string message(const char * title, const char * classname,
                    const char * methodname, const char * membername,
                    T value) {
    std::string msg {title};
    if (!msg.empty()) msg.append(" : ");
    msg.append(classname).append("::").append(methodname).append(
        " : ").append(membername).append(" equals ").append(
            std::to_string(value));
    return msg;
}

} // anonymous namespace

namespace nvs {

namespace lotto {

// méthodes

Draw::Draw(unsigned size, unsigned max) :
    max_ { max == 0 ?
           throw std::invalid_argument { message("problem",
                                         typeid(*this).name(),
                                         __func__,
                                         "max_",
                                         max) } :
           (max < size ?
            throw std::invalid_argument { message("problem",
                                          typeid(*this).name(),
                                          __func__,
                                          "max_",
                                          max).append(
                                                  " but ").append(
                                                          message("",
                                                                  typeid(*this).name(),
                                                                  __func__,
                                                                  "size_",
                                                                  size)) } :
            max)
         } {
    using namespace std;

    if (size == 0) {
        throw invalid_argument { message("problem",
                                         typeid(*this).name(),
                                         __func__,
                                         "size_",
                                         size) };
    }

    vector<unsigned> universe(max_);
    iota(begin(universe), end(universe), 1);
    shuffle(begin(universe), end(universe), nvs::urng());
    copy(cbegin(universe), cbegin(universe) + size,
         inserter(value_, begin(value_)));
}

std::string Draw::to_string() const {
    std::string result { "[ s : " };
    result += std::to_string(size());
    result += ", m : ";
    result += std::to_string(max_);
    result += ", v : [ ";
    for (auto e : value_) {
        result += std::to_string(e);
        result += " ";
    }
    result += "] ]";

    return result;
}

// fonctions

std::ostream & operator<<(std::ostream & out, const Draw & draw) {
    out << "[ s : " << draw.size()
        << ", m : " << draw.max()
        << ", v : [ ";
    for (auto e : draw.value()) out << e << " ";
    out << "] ]";
    return out;
}

} // namespace lotto

} // namespace nvs
