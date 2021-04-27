
#include "CreateAndDestroy.h"


CreateAndDestroy::CreateAndDestroy(int ID, std::string messageString)
    : objectID{ID}, message{messageString} {
    std::cout << "Object " << objectID << " costructor runs"<< message<< std::endl;

}

CreateAndDestroy::~CreateAndDestroy() {
    std::cout << "Object " << objectID << " destruction runs"<< message<< std::endl;
}
