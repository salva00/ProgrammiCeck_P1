//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef EMPLOYEESALARY_COMMISSIONEMPLYEE_H
#define EMPLOYEESALARY_COMMISSIONEMPLYEE_H


#include "Emplouyee.h"

class CommissionEmplyee : public Employee{
private:
    double grossSales;
    double commissionRate;
public:
    CommissionEmplyee(const std::string&, const std::string&,const std::string&,double =0.00,double=0.00);
    virtual ~CommissionEmplyee()=default;
    void setGrossSales(double);
    void setcommissionRate(double);

    double getGrossSales() const;
    double getCommissionRate() const;

    double earnings() const override;

    virtual std::string toString() const override;
};


#endif //EMPLOYEESALARY_COMMISSIONEMPLYEE_H
