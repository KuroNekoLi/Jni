#include "Person.h"

#include <utility>

Person::Person(std::string firstName, std::string lastName)
    : firstName(std::move(firstName)), lastName(std::move(lastName)) {}

std::string Person::getFullName() const {
    return firstName + " " + lastName;
}

