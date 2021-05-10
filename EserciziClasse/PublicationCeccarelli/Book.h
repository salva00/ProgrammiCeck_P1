//
// Created by Salvatore Bramante on 10/05/21.
//

#ifndef PUBLICATIONCECCARELLI_BOOK_H
#define PUBLICATIONCECCARELLI_BOOK_H
#include "Publication.h"
#include <vector>
#include <string>

class Book : public Publication{
public:
    static  int  nBooks;
    Book(std::string ti, std::vector<std::string> au,
         int yr, std::string pub, std::string is)
         : Publication(ti,au,yr), publisher(pub),ISBN(){++nBooks;}
    ~Book(){nBooks--;}
    std::string toString(){
        std::ostringstream out;
        out << Publication::toString() << ", ";
        out << publisher<< ", " <<ISBN;
        return out.str();
    }
private:
    std::string publisher;
    std::string ISBN;



};


#endif //PUBLICATIONCECCARELLI_BOOK_H
