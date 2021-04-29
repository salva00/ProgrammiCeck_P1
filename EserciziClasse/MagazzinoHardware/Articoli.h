//
// Created by Salvatore Bramante on 29/04/21.
//

#ifndef MAGAZZINOHARDWARE_ARTICOLI_H
#define MAGAZZINOHARDWARE_ARTICOLI_H


#include <string>
#include <iostream> //per far contento Francesco :)
#include <stdexcept>

class Articoli {
private:
    std::string name;
    int productCode;
    int qnt;
    float price;
public:
    //Articoli(int);//per rendre il codice più flessibile
    Articoli(const std::string& =" ", int = 0, int = 0, float =.0);
    virtual ~Articoli() = default;

    void setName(const std::string&);
    std::string getName() const;

    void setProductCode(int);
    int getProductCode() const;

    void setQnt(int);
    int getQnt() const;

    void setPrice(float);
    float getPrice() const;
};


#endif //MAGAZZINOHARDWARE_ARTICOLI_H
