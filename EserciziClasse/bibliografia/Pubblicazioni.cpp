//
// Created by Salvatore Bramante on 26/04/21.
//

#include "Pubblicazioni.h"

Pubblicazioni::Pubblicazioni(const std::string &title, std::vector<std::string> authors, const int &year){
    setTitle(title);
    setAuthors(authors);
    setYear(year);
}

void Pubblicazioni::setTitle(const std::string& title) {
    if (title.empty()){
        throw std::invalid_argument("autors can't be empty");
    }
    this->title=title;
}

void Pubblicazioni::setAuthors(std::vector<std::string> authors) {
    if(authors.empty()){
        throw std::invalid_argument("autors can't be empty");
    }
    this->authors=authors;
}

void Pubblicazioni::setYear(int year) {
    if (year<0){
        throw std::invalid_argument("year must be positive");
    }
    this->year=year;
}

std::string Pubblicazioni::getTitle() const {
    return title;
}

std::vector<std::string> Pubblicazioni::getAuthors() const {
    return authors;
}

int Pubblicazioni::getYear() const{
    return year;
}

std::string Pubblicazioni::toString() const {
    return "\nTitle:" + getTitle() + "\nAuthors:" +getStringAuthors()+ "\nYear: " + std::to_string(getYear());
}

std::string Pubblicazioni::getStringAuthors() const {
    std::string autori;
    for (const std::string a : authors){
        autori+= a +",";
    }
    return autori;}

