#include <iostream>
#include <vector>
#include <iomanip>
#include "Emplouyee.h"
#include "SalariedEmployee.h"
#include "CommissionEmplyee.h"
#include "BasePlusCommisionEmployee.h"

void virtualViaPointer (const Employee* const);
void virtualViaReference (const Employee&);

int main() {
    std::cout << std::fixed <<std::setprecision(2) << std::endl;

    SalariedEmployee salariedEmployee("Paul","Chambers","111-11-1111",800);
    CommissionEmplyee commissionEmployee("Pippo","JS","444-44-4444",1000,.60);
    BasePlusCommisionEmployee basePlusCommissionEmployee("Pluto","D","555-55-5555",5000,.60,300);

    std::cout << "EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n" <<
        salariedEmployee.toString()<<"earned $ "<< salariedEmployee.earnings()
        <<commissionEmployee.toString()<<"earned $ "<< commissionEmployee.earnings()
        <<basePlusCommissionEmployee.toString()<<"earned $ "<< basePlusCommissionEmployee.earnings()
        << std::endl;

    std::vector<Employee*> employees{&salariedEmployee,&commissionEmployee,&basePlusCommissionEmployee};
    std::cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNIMIC BINDING\n" <<std::endl;

    std::cout << "VIRTUAL FUNCTION CALL MADE BY POINTERS\n" <<std::endl;

    for (const Employee* EmployeePtr : employees){
        virtualViaPointer(EmployeePtr);
    }

    std::cout << "VIRTUAL FUNCTION CALL MADE BY Reference\n" <<std::endl;

    for (const Employee* EmployeePtr : employees){
        virtualViaReference(*EmployeePtr);
    }

    //downcast
    for (Employee* EmployeePtr : employees){
        BasePlusCommisionEmployee* derivatePtr = dynamic_cast<BasePlusCommisionEmployee*>(EmployeePtr);
        if(derivatePtr!=nullptr){
            double oldSalary = derivatePtr->getBaseSalary();
            derivatePtr->setBaseSalary(1.1*oldSalary);
            std::cout << "New salary is: "<< derivatePtr->getBaseSalary() <<std::endl;
        }
        std::cout << "Earned $: "<< derivatePtr->earnings() <<std::endl;

    }

    //deleting objects

    for (Employee* EmployeePtr : employees){
        std::cout << "deleting obj of class: "<< typeid(*EmployeePtr).name() <<std::endl;
        delete EmployeePtr;
    }
    return 0;
}

void virtualViaPointer (const Employee* const basedClassPtr){
    std::cout<<basedClassPtr->toString()<<"\nEarned:"<<basedClassPtr->earnings()<<"\n\n";
}
void virtualViaReference (const Employee& basedClassRef){
    std::cout<<basedClassRef.toString()<<"\nEarned:"<<basedClassRef.earnings()<<"\n\n";
}