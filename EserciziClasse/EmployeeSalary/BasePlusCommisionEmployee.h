//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef EMPLOYEESALARY_BASEPLUSCOMMISIONEMPLOYEE_H
#define EMPLOYEESALARY_BASEPLUSCOMMISIONEMPLOYEE_H


#include "CommissionEmplyee.h"

class BasePlusCommisionEmployee : public CommissionEmplyee{
private:
    double baseSalary;
public:
    BasePlusCommisionEmployee(const std::string&, const std::string&,const std::string&,double =0.00,double=0.00,double =0.00);
    virtual ~BasePlusCommisionEmployee()=default;

    void setBaseSalary(double );
    double getBaseSalary() const;

    double earnings() const override;

    virtual std::string toString() const override;   //virtual
};


#endif //EMPLOYEESALARY_BASEPLUSCOMMISIONEMPLOYEE_H
