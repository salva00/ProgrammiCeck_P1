#include "Libri.h"

Libri::Libri(const std::string &title, const std::vector<std::string> &authors,
             const std::string &isbn,const std::string &publisher)
        : Pubblicazioni(title, authors){
    setISBN(isbn);
    setPublisher(publisher);
}

void Libri::setISBN(const std::string& isbn) {
    if(isbn.empty()|| isbn.length()!=13){
        throw std::invalid_argument("ISBN incorret");
    }
    ISBN=isbn;
}

void Libri::setPublisher(const std::string& publisher) {
    if(publisher.empty()){
        throw std::invalid_argument("publisher empty");
    }
    this->publisher=publisher;
}

std::string Libri::getISBN() {
    return ISBN;
}

std::string Libri::getPublisher() {
    return publisher;
}
