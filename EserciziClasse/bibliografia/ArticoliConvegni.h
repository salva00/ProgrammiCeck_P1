//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef BIBLIOGRAFIA_ARTICOLICONVEGNI_H
#define BIBLIOGRAFIA_ARTICOLICONVEGNI_H


#include "Pubblicazioni.h"

class ArticoliConvegni: public Pubblicazioni {
private:
    std::string titoloConvegno;
    std::string sedeConvegno;
    int numPagine;
public:


    ArticoliConvegni(const std::string &title, const std::vector<std::string> &authors,
                     const std::string &titoloConvegno,const std::string &sedeConvegno,int numPagine);

    void setTitoloConvegno(const std::string&);
    void setSedeConvegno(const std::string&);
    void setNumPagine(const int&);

    std::string getTitoloConvegno();
    std::string getSedeConvegno();
    int getNumPagine();

};


#endif //BIBLIOGRAFIA_ARTICOLICONVEGNI_H
