//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H


#include "Emplouyee.h"

class SalariedEmployee : public Employee{
private:
    double weeklySalary;
public:
    SalariedEmployee(const std::string &, const std::string &,const std::string &, double =0.00);
    virtual ~SalariedEmployee() = default;
    void setWeeklySalary(double );
    double getWeeklySalary() const;

    virtual double earnings() const override;

    virtual std::string toString() const override;   //virtual
};


#endif //EMPLOYEESALARY_SALARIEDEMPLOYEE_H
