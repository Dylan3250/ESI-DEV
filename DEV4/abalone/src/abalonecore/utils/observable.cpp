#include "observable.h"
#include "observer.h"
#include <string>

namespace pbt::utils {

void Observable::notify(const std::string &propertyName) const {
    for (auto *observer : _observers) {
        observer->update(propertyName);
    }
}

} // end namespace pbt
