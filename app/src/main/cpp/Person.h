#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(std::string firstName, std::string lastName);
    std::string getFullName() const;

private:
    std::string firstName;
    std::string lastName;
};

#endif // PERSON_H
