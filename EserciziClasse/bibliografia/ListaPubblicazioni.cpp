
#include "ListaPubblicazioni.h"
#include <algorithm>
#include <iostream>

ListaPubblicazioni::ListaPubblicazioni(std::vector<Pubblicazioni*> vec) {
  setList(vec);
}

ListaPubblicazioni::~ListaPubblicazioni() {
  for(auto pub: this->list) delete pub;
}

Pubblicazioni& ListaPubblicazioni::operator[](size_t index) {
  return *this->list[index];
}

Pubblicazioni* ListaPubblicazioni::getPub(size_t index) const {
  return this->list[index];
}

void ListaPubblicazioni::setPub(Pubblicazioni* pub, size_t index) {
  this->list[index] = pub;
  return;
}

void ListaPubblicazioni::setList(std::vector<Pubblicazioni*> vec) {
  if(std::is_sorted(vec.begin(), vec.end()) == false)
    std::sort(vec.begin(), vec.end());
  this->list = vec;
}

bool pubPtrMinus(Pubblicazioni* pub1, Pubblicazioni* pub2) {
  return (*pub1 < *pub2);
}

void ListaPubblicazioni::sort() {
  std::sort(this->list.begin(), this->list.end(), pubPtrMinus);
  return;
}; //TODO

PubType getType(Pubblicazioni* pub) {
  if(dynamic_cast<Libri*>(pub) != nullptr) return PubType::Libro;
  else if(dynamic_cast<ArticoliConvegni*>(pub) != nullptr) return PubType::ArticoloConvegno;
  else if(dynamic_cast<ArticoliRiviste*>(pub) != nullptr) return PubType::ArticoloRivista;
  else return PubType::Generico;
}

void ListaPubblicazioni::print(size_t index) {
  Pubblicazioni* pubPtr = getPub(index);
  std::cout << pubPtr->getTitle() << ' ';

  for(int i = 0; i < pubPtr->getAuthors().size(); i++) {
    std::cout << pubPtr->getAuthors()[i];
    if(i < pubPtr->getAuthors().size() - 1) std::cout << ', ';
  }

  if(getType(pubPtr) == Libro) {
    Libri* newPtr = dynamic_cast<Libri*>(pubPtr);
    std::cout << ' ' << newPtr->getISBN() << ' ' << newPtr->getPublisher();
  } else if(getType(pubPtr) == ArticoloRivista) {
    ArticoliRiviste* newPtr = dynamic_cast<ArticoliRiviste*>(pubPtr);
    std::cout << ' ' << newPtr->getTitoloRiv() << ' ' << newPtr->getNumRiv() <<
      ' ' << newPtr->getStart() << '-' << newPtr->getStop();
  } else if(getType(pubPtr) == ArticoloConvegno) {
    ArticoliConvegni* newPtr = dynamic_cast<ArticoliConvegni*>(pubPtr);
    std::cout << ' ' << newPtr->getTitoloConvegno() << ' ' <<
      newPtr->getSedeConvegno() << ' ' << newPtr->getNumPagine();
  }
  return;
}










//
