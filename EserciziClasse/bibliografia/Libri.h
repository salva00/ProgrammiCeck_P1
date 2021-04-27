//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef BIBLIOGRAFIA_LIBRI_H
#define BIBLIOGRAFIA_LIBRI_H


#include "Pubblicazioni.h"

class Libri : public Pubblicazioni{
private:
    std::string ISBN;
    std::string publisher;
public:

    Libri(const std::string& , const std::vector<std::string>& , const std::string&,const std::string&,const int&);

    virtual ~Libri()=default;


    void setISBN(const std::string&);
    void setPublisher(const std::string&);
    std::string getISBN() const;
    std::string getPublisher() const;
    std::string toString() const override;
};


#endif //BIBLIOGRAFIA_LIBRI_H
