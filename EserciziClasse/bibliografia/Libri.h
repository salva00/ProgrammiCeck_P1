#ifndef BIBLIOGRAFIA_LIBRI_H
#define BIBLIOGRAFIA_LIBRI_H


#include "Pubblicazioni.h"

class Libri : public Pubblicazioni{
private:
    std::string ISBN;
    std::string publisher;
public:

    Libri(const std::string& title, const std::vector<std::string>& authors, int year,const std::string& isbn,const std::string& publisher);

    virtual ~Libri()=default;


    void setISBN(const std::string&);
    void setPublisher(const std::string&);
    std::string getISBN();
    std::string getPublisher();
};


#endif //BIBLIOGRAFIA_LIBRI_H
