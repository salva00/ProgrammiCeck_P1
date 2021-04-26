#include "CreateAndDestroy.h"

void create(); //prototype

CreateAndDestroy first{1,"(Global before main)"};   //global object

int main() {
    std::cout << "\nMAIN FUNCTION: EXECTUTION BEGINS" << std::endl;
    CreateAndDestroy second{2,"(local in main)"};   //local object
    static CreateAndDestroy third{3,"(local static in main)"};

    create();   //call function to create objects

    std::cout << "\nMAIN FUNCTION: EXECTUTION RESUMES" << std::endl;
    CreateAndDestroy four{4,"(local in main)"};
    std::cout << "\nMAIN FUNCTION: EXECTUTION ENDS" << std::endl;

    return 0;
}

void create(){
    std::cout << "\nCREATE FUNCTION: EXECTUTION BEGINS" << std::endl;
    CreateAndDestroy fifth{5,"(local in create)"};
    static CreateAndDestroy sixth{6,"(static local in create)"};
    std::cout << "\nCREATE FUNCTION: EXECTUTION ENDS" << std::endl;
}