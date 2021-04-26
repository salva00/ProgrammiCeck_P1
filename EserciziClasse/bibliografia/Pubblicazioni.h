//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef BIBLIOGRAFIA_PUBBLICAZIONI_H
#define BIBLIOGRAFIA_PUBBLICAZIONI_H

#include <vector>
#include <string>

class Pubblicazioni {
public:
    Pubblicazioni(const std::string &title, std::vector<std::string> authors);

private:
    std::string title;
    std::vector<std::string> authors;
    int year;
public:
    void setTitle(std::string);
    void setAuthors(std::vector<std::string>);
    void setYear(int);
    std::string getTitle();
    std::vector<std::string> getAuthors();
    int getYear();

};


#endif //BIBLIOGRAFIA_PUBBLICAZIONI_H
