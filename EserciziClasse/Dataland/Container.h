//
// Created by Salvatore Bramante on 31/05/21.
//

#ifndef DATALAND_CONTAINER_H
#define DATALAND_CONTAINER_H
#include "Box.h"
#include "LinkedList.h"
#include <iostream>
class Container {
public:
    Container(int idContainer=0, std::string stateOrig="" ,std::string idCarrier="", int nBox=0);
    //Container(const Container&);
    //~Container();
    int getIdContainer() const;
    void setIdContainer(int idContainer);
    std::string getState_orig() const;
    void setState_orig(std::string stateorig);
    std::string getId_carrier() const;
    void setId_carrier(std::string idcarrier);
    int getNBox() const;
    void setNBox(int nBox);
    void addToBoxes(const Box&);
    LinkedList<Box> boxes;
private:
    int id_container;
    std::string state_orig;
    std::string id_carrier;
    int n_box;



};



#endif //DATALAND_CONTAINER_H
