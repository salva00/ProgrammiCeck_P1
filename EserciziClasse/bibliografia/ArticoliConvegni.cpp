#include "ArticoliConvegni.h"
#include <stdexcept>

ArticoliConvegni::ArticoliConvegni(std::string title, std::vector<std::string> authors, int year,
                                   std::string titoloConvegno, std::string sedeConvegno,int numPagine)
                                   : Pubblicazioni(title, authors, year) {
    setNumPagine(numPagine);
    setSedeConvegno(sedeConvegno);
    setTitoloConvegno(titoloConvegno);
}

void ArticoliConvegni::setTitoloConvegno(std::string t) {
    if (t.empty()){
        throw std::invalid_argument("titolo must be not empty");
    }
    titoloConvegno=t;
}

void ArticoliConvegni::setSedeConvegno(std::string t) {
    if (t.empty()){
        throw std::invalid_argument("sede must be not empty");
    }
    sedeConvegno=t;
}

void ArticoliConvegni::setNumPagine(int t) {
    if (t<0){
        throw std::invalid_argument("num must be <=0");
    }
    numPagine=t;
}

std::string ArticoliConvegni::getTitoloConvegno() const {
    return titoloConvegno;
}

std::string ArticoliConvegni::getSedeConvegno() const {
    return sedeConvegno;
}

int ArticoliConvegni::getNumPagine() const {
    return numPagine;
}
