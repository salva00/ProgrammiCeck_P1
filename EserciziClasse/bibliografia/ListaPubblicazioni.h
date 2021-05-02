
#ifndef BIBLIOGRAFIA_BIBLIOGRAFIA_H
#define BIBLIOGRAFIA_BIBLIOGRAFIA_H

#include "Pubblicazioni.h"
#include "ArticoliConvegni.h"
#include "ArticoliRiviste.h"
#include "Libri.h"
#include <vector>

enum PubType { Libro, ArticoloRivista, ArticoloConvegno, Generico };

PubType getType(Pubblicazioni*);

bool pubPtrMinus(Pubblicazioni*, Pubblicazioni*);

class ListaPubblicazioni {
private:
  std::vector<Pubblicazioni*> list;
public:
  ListaPubblicazioni(std::vector<Pubblicazioni*>);
  ~ListaPubblicazioni();

  Pubblicazioni& operator[](size_t);

  Pubblicazioni* getPub(size_t) const;
  void setPub(Pubblicazioni*,size_t);

  void setList(std::vector<Pubblicazioni*>);

  void sort();

  void print(size_t);
  void print();
};

#endif
