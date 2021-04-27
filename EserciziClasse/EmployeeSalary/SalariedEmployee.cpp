
#include <sstream>
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const std::string &first, const std::string &last,
                                   const std::string &ssn, double salary)
                                   : Employee(first,last,ssn){
    setWeeklySalary(salary);

}

void SalariedEmployee::setWeeklySalary(double salary) {
    if(salary<=0){
        throw std::invalid_argument("insert >=0 salaryy");
    }
    weeklySalary=salary;
}

double SalariedEmployee::getWeeklySalary() const {
    return weeklySalary;
}

double SalariedEmployee::earnings() const {
    return getWeeklySalary();
}

std::string SalariedEmployee::toString() const {
    std::ostringstream output;
    output<<"salaried employee"<<Employee::toString()<<"\nWeekly salary"<< getWeeklySalary();
    return output.str();
}
