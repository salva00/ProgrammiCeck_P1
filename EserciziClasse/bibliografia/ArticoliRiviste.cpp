#include "ArticoliRiviste.h"

ArticoliRiviste::ArticoliRiviste(const std::string &title, const std::vector<std::string> &authors,
                                 int numRiv,int start, int stop)
        : Pubblicazioni(title, authors){
    setNumRiv(numRiv);
    setStart(start);
    setStop(stop);
}

void ArticoliRiviste::setNumRiv(const int &n) {
    if(n<0){
        throw std::invalid_argument("numRiv can't be negative");
    }
    numRiv=n;
}

void ArticoliRiviste::setStart(const int &n) {
    if(n<0){
        throw std::invalid_argument("start can't be negative");
    }
    start=n;
}

void ArticoliRiviste::setStop(const int &n) {
    if(n<0){
        throw std::invalid_argument("stop can't be negative");
    }
    stop=n;
}

int ArticoliRiviste::getNumRiv() const {
    return numRiv;
}

int ArticoliRiviste::getStart() const {
    return start;
}

int ArticoliRiviste::getStop() const {
    return stop;
}
