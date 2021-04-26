//
// Created by Salvatore Bramante on 26/04/21.
//

#include "Pubblicazioni.h"

Pubblicazioni::Pubblicazioni(const std::string &title, std::vector<std::string> authors){
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

std::string Pubblicazioni::getTitle() {
    return title;
}

std::vector<std::string> Pubblicazioni::getAuthors() {
    return authors;
}

int Pubblicazioni::getYear() {
    return year;
}
