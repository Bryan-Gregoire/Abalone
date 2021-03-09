#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>
#include <string>

namespace abalone
{
namespace utils
{

class Observer;

class Observable
{
  private:
    std::set<Observer *> _observers { };

  public:
    virtual ~Observable() = default;    // polymorphism

    //void notify() const;
    void notify(const std::string & propertyName = "No property") const;
    inline void addObserver(Observer *);
    inline void deleteObserver(Observer *);
};

// implements inline methods
void Observable::addObserver(Observer * observer)
{
    _observers.insert(observer);
}

void Observable::deleteObserver(Observer * observer)
{
    _observers.erase(observer);
}


} // end namespace utils
} // end namespace abalone

#endif // OBSERVABLE_H
