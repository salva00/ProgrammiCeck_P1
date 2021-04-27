//
// Created by Salvatore Bramante on 26/04/21.
//

#ifndef BIBLIOGRAFIA_PUBBLICAZIONI_H
#define BIBLIOGRAFIA_PUBBLICAZIONI_H

#include <vector>
#include <string>
#include <sstream>

class Pubblicazioni {

public:
    Pubblicazioni(const std::string &title, std::vector<std::string> authors, const int& year);
    virtual ~Pubblicazioni() = default;

private:
    std::string title;
    std::vector<std::string> authors;
    int year;
public:
    void setTitle(const std::string&);
    void setAuthors(std::vector<std::string>);
    void setYear(int);
    std::string getTitle() const;
    std::vector<std::string> getAuthors() const;
    std::string getStringAuthors() const;
    virtual std::string toString() const;
    bool operator<(const std::string&);
    int getYear() const;
};


#endif //BIBLIOGRAFIA_PUBBLICAZIONI_H
