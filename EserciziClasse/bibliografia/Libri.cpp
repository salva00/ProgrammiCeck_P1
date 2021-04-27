//
// Created by Salvatore Bramante on 26/04/21.
//

#include "Libri.h"

Libri::Libri(const std::string &title, const std::vector<std::string> &authors,
             const std::string &isbn,const std::string &publisher, const int &year)
        : Pubblicazioni(title, authors,year){
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

std::string Libri::getISBN() const{
    return ISBN;
}

std::string Libri::getPublisher() const{
    return publisher;
}

std::string Libri::toString() const {
    std::ostringstream output;
    output<<"Book:"<<Pubblicazioni::toString()<<"\nISBN"<< getISBN()<<"\nPublisher:"<<getPublisher();
    return output.str();
}
