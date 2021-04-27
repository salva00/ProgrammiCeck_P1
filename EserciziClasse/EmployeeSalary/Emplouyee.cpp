//
// Created by Salvatore Bramante on 26/04/21.
//

#include "Emplouyee.h"

Employee::Employee(const std::string &first , const std::string &last, const std::string &ssr)
    :firstName(first),lastName(last),socialSecurityNumber(ssr){}

void Employee::setFirstName(const std::string &first) {
    lastName=first;
}

void Employee::setLastName(const std::string &last) {
    lastName=last;
}

void Employee::setSocialSecurityNumber(const std::string &ssr) {
    socialSecurityNumber=ssr;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getLastName() const {
    return lastName;
}

std::string Employee::getSocialSecurityNumber() const {
    return socialSecurityNumber;    //should validate
}

std::string Employee::toString() const {
    return getFirstName()+" "+ getLastName() +
        "\nsocial security number: " + getSocialSecurityNumber();
}
