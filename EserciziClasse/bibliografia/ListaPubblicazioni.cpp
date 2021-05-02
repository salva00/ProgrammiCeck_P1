
#include "ListaPubblicazioni.h"
#include <algorithm>

ListaPubblicazioni::ListaPubblicazioni(std::vector<Pubblicazioni*> vec) {
  setList(vec);
}

ListaPubblicazioni::~ListaPubblicazioni() {
  for(auto pub: this->list) delete pub;
}

Pubblicazioni& ListaPubblicazioni::operator[](size_t index) {
  return *this->list[index];
}

Pubblicazioni ListaPubblicazioni::getPub(size_t index) const {
  return *this->list[index];
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

void ListaPubblicazioni::sort() {}; //TODO
