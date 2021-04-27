
#ifndef CREATEANDDESTROY_H
#define CREATEANDDESTROY_H

#include <string>
#include <iostream>

class CreateAndDestroy {
public:
    CreateAndDestroy(int, std::string); //costructor
    ~CreateAndDestroy(); //destructor

private:
    int objectID; //ID number for objecr
    std::string message; //message describing
};


#endif //CREATEANDDESTROY_H
