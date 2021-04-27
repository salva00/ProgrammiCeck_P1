
#include "BasePlusCommisionEmployee.h"
#include <sstream>
#include <iomanip>

BasePlusCommisionEmployee::BasePlusCommisionEmployee(const std::string &first, const std::string &last,
                                                     const std::string &ssn, double sales, double rate,double salary)
                                                     : CommissionEmplyee(first,last,ssn,sales,rate){
    setBaseSalary(salary);
}

void BasePlusCommisionEmployee::setBaseSalary(double salary) {
    if(salary<0.0){
        throw std::invalid_argument(" salary must be >=0");
    }
    baseSalary=salary;
}

double BasePlusCommisionEmployee::getBaseSalary() const {
    return baseSalary;
}

std::string BasePlusCommisionEmployee::toString() const {
    std::ostringstream output;
    output<<std::fixed<<std::setprecision(2);
    output<< "\nbase salaried:"<< CommissionEmplyee::toString()<< "\nBase commition:"<< getBaseSalary() <<"\n\n";
    return output.str();
}

double BasePlusCommisionEmployee::earnings() const {
    return getBaseSalary()+ CommissionEmplyee::earnings();
}
