
#include"ArticoliRiviste.h"
#include<iostream>

ArticoliRiviste::ArticoliRiviste(std::string title, std::vector<std::string> authors, int year,
                                 std::string titoloRiv, int numRiv,int start, int stop)
        : Pubblicazioni(title, authors, year){
    setTitoloRiv(titoloRiv);
    setNumRiv(numRiv);
    setStart(start);
    setStop(stop);
}

void ArticoliRiviste::setTitoloRiv(std::string titoloRiv){
	  this->titoloRiv = titoloRiv;
}

void ArticoliRiviste::setNumRiv(int n) {
    if(n<0){
        throw std::invalid_argument("numRiv can't be negative");
    }
    numRiv=n;
}

void ArticoliRiviste::setStart(int n) {
    if(n<0){
        throw std::invalid_argument("start can't be negative");
    }
    start=n;
}

void ArticoliRiviste::setStop(int n) {
    if(n<0){
        throw std::invalid_argument("stop can't be negative");
    }
    stop=n;
}

std::string ArticoliRiviste::getTitoloRiv() const{
	  return titoloRiv;
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
