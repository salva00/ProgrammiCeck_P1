//
// Created by Salvatore Bramante on 29/04/21.
//

#include "Articoli.h"

Articoli::Articoli(const std::string& name, int productCode, int qnt, float price) {
    setName(name);
    setProductCode(productCode);
    setQnt(qnt);
    setPrice(price);
}

void Articoli::setName(const std::string & name) {
    if (name.empty()){
        throw std::invalid_argument("Name must not be empty ");
    }
    this->name=name;
}

std::string Articoli::getName() const {
    return name;
}

void Articoli::setProductCode(int productCode) {
/*    if (productCode < 0 || productCode>99){
        throw std::invalid_argument("productCode must be between 0 and 99 ");
    }*/
    this->productCode=productCode;
}

int Articoli::getProductCode() const {
    return productCode;
}

void Articoli::setQnt(int qnt) {
/*    if (qnt<=0){
        throw std::invalid_argument("Quantity must be >=0 ");
    }*/
    this->qnt = qnt;
}

int Articoli::getQnt() const{
    return qnt;
}

void Articoli::setPrice(float price) {
/*    if (price<=0){
        throw std::invalid_argument("Quantity must be >=0 ");
    }*/
    this->price = price;
}

float Articoli::getPrice() const{
    return price;
}
