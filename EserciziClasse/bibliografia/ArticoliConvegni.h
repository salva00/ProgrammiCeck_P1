
#ifndef BIBLIOGRAFIA_ARTICOLICONVEGNI_H
#define BIBLIOGRAFIA_ARTICOLICONVEGNI_H

#include "Pubblicazioni.h"
//include<vector>
//include<string>

class ArticoliConvegni : public Pubblicazioni {
private:
    std::string titoloConvegno;
    std::string sedeConvegno;
    int numPagine;
public:

    ArticoliConvegni(std::string title, std::vector<std::string> authors, int year,
                     std::string titoloConvegno, std::string sedeConvegno,int numPagine);

    virtual ~ArticoliConvegni()=default;

    void setTitoloConvegno(std::string);
    void setSedeConvegno(std::string);
    void setNumPagine(int);

    std::string getTitoloConvegno() const;
    std::string getSedeConvegno() const;
    int getNumPagine() const;

};


#endif //BIBLIOGRAFIA_ARTICOLICONVEGNI_H
