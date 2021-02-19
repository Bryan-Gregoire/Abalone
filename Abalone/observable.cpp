#include "utils/observable.h"
#include "utils/observer.h"
#include <string>

namespace abalone
{
namespace utils
{

void Observable::notify(
    const std::string & propertyName) const
{
    for (auto * observer : _observers) {
        observer->update(propertyName);
    }
}

} // end utils
} // end abalone
