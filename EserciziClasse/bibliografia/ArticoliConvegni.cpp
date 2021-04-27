#include "ArticoliConvegni.h"


ArticoliConvegni::ArticoliConvegni(const std::string &title, const std::vector<std::string> &authors,
                                   const std::string &titoloConvegno,const std::string &sedeConvegno,int numPagine)
                                   : Pubblicazioni(title, authors) {
    setNumPagine(numPagine);
    setSedeConvegno(sedeConvegno);
    setTitoloConvegno(titoloConvegno);
}

void ArticoliConvegni::setTitoloConvegno(const std::string &t) {
    if (t.empty()){
        throw std::invalid_argument("titolo must be not empty");
    }
    titoloConvegno=t;
}

void ArticoliConvegni::setSedeConvegno(const std::string &t) {
    if (t.empty()){
        throw std::invalid_argument("sede must be not empty");
    }
    sedeConvegno=t;
}

void ArticoliConvegni::setNumPagine(const int &t) {
    if (t<0){
        throw std::invalid_argument("num must be <=0");
    }
    numPagine=t;
}

std::string ArticoliConvegni::getTitoloConvegno() {
    return titoloConvegno;
}

std::string ArticoliConvegni::getSedeConvegno() {
    return sedeConvegno;
}

int ArticoliConvegni::getNumPagine() {
    return numPagine;
}

