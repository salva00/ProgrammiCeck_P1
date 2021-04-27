//
// Created by Salvatore Bramante on 26/04/21.
//

#include <sstream>
#include "CommissionEmplyee.h"

CommissionEmplyee::CommissionEmplyee(const std::string &first, const std::string &last,
                                     const std::string &ssn, double gs, double cr)
        :Employee(first,last,ssn) {
    setGrossSales(gs);
    setcommissionRate(cr);
}

void CommissionEmplyee::setGrossSales(double gs) {
    if(gs <0.0){
        throw std::invalid_argument("Gross sale will be >=0.0");
    }
    grossSales=gs;
}

void CommissionEmplyee::setcommissionRate(double cr) {
    if(cr <0.0 || cr>1.0){
        throw std::invalid_argument("rate  will be >=0.0 and <= 1.0");
    }
    commissionRate=cr;
}

double CommissionEmplyee::getGrossSales() const {
    return grossSales;
}

double CommissionEmplyee::getCommissionRate() const {
    return commissionRate;
}

std::string CommissionEmplyee::toString() const {
    std::ostringstream output;
    output<< "\ncommition employee:"<< Employee::toString()<< "\nGross sale:"<<getGrossSales()
        << "\nCommission rate:"<< getCommissionRate() <<"\n\n";
    return output.str();
}

double CommissionEmplyee::earnings() const {
    return getCommissionRate()*getGrossSales();
}
