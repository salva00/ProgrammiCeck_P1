//
// Created by Salvatore Bramante on 31/05/21.
//

#include "Container.h"

#include <utility>

int Container::getIdContainer() const {
    return id_container;
}

void Container::setIdContainer(int idContainer) {
    id_container = idContainer;
}

std::string Container::getState_orig() const {
    return state_orig;
}

void Container::setState_orig(std::string stateorig) {
    state_orig=std::move(stateorig);
}

std::string Container::getId_carrier() const {
    return id_carrier;
}

void Container::setId_carrier(std::string idcarrier) {
    id_carrier=std::move(idcarrier);
}

Container::Container(int idContainer, std::string stateOrig, std::string idCarrier, int nBox)
        : id_container(idContainer), state_orig(stateOrig), id_carrier(idCarrier), n_box(nBox) {

}

int Container::getNBox() const {
    return n_box;
}

void Container::setNBox(int nBox) {
    n_box = nBox;
}

void Container::addToBoxes(const Box &box) {
    boxes.addFront(box);
}
