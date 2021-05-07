#include "Libri.h"
#include <stdexcept>

Libri::Libri(std::string title, std::vector<std::string> authors,
             int year, std::string isbn, std::string publisher)
        : Pubblicazioni(title, authors, year){
    setISBN(isbn);
    setPublisher(publisher);
}

void Libri::setISBN(std::string isbn) {
    if(isbn.empty()|| isbn.length()!=13){
        throw std::invalid_argument("ISBN must be 13 character long");
    }
    ISBN=isbn;
}

void Libri::setPublisher(std::string publisher) {
    if(publisher.empty()){
        throw std::invalid_argument("publisher empty");
    }
    this->publisher=publisher;
}

std::string Libri::getISBN() const {
    return ISBN;
}

std::string Libri::getPublisher() const {
    return publisher;
}
