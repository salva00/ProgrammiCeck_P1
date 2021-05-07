
#ifndef BIBLIOGRAFIA_LIBRI_H
#define BIBLIOGRAFIA_LIBRI_H

#include "Pubblicazioni.h"
//include<vector>
//include<string>

class Libri : public Pubblicazioni{
private:
    std::string ISBN;
    std::string publisher;
public:

    Libri(std::string title, std::vector<std::string> authors, int year, std::string isbn, std::string publisher);

    virtual ~Libri()=default;


    void setISBN(const std::string);
    void setPublisher(const std::string);
    std::string getISBN() const;
    std::string getPublisher() const;
};


#endif //BIBLIOGRAFIA_LIBRI_H
