//
// Created by Salvatore Bramante on 26/04/21.
//

#include "ArticoliRiviste.h"

ArticoliRiviste::ArticoliRiviste(const std::string &title, const std::vector<std::string> &authors,const int &year,
                                 const int &numRiv,const int &start, const int &stop)
        : Pubblicazioni(title, authors,year){
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

std::string ArticoliRiviste::toString() const {
    std::ostringstream output;
    output<<"Article:"<<Pubblicazioni::toString()<<"\nNumber:"<< getNumRiv()
          <<"\nFirst page:"<<getStart()<<"\nLast page:"<<getStop();
    return output.str();
}
