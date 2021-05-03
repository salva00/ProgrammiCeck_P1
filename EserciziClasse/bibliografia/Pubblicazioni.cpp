#include "Pubblicazioni.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

Pubblicazioni::Pubblicazioni(const std::string &title, std::vector<std::string> authors,int year){
    setTitle(title);
    setAuthors(authors);
    setYear(year);
}

void Pubblicazioni::setTitle(const std::string& title) {
    if (title.empty()){
        throw std::invalid_argument("title can't be empty");
    }
    this->title=title;
}

void Pubblicazioni::setAuthors(std::vector<std::string> authors) {
    if(authors.empty()){
        throw std::invalid_argument("authors can't be empty");
    }
    if(std::is_sorted(authors.begin(), authors.end()) == false)
      std::sort(authors.begin(), authors.end());
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

int Pubblicazioni::getYear() const {
    return year;
}








//
