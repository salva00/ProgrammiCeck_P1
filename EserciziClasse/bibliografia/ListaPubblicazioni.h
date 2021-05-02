
#ifndef BIBLIOGRAFIA_BIBLIOGRAFIA_H
#define BIBLIOGRAFIA_BIBLIOGRAFIA_H

#include "Pubblicazioni.h"
#include "ArticoliConvegni.h"
#include "ArticoliRiviste.h"
#include "Libri.h"
#include <vector>

class ListaPubblicazioni {
private:
  std::vector<Pubblicazioni*> list;
public:
  ListaPubblicazioni(std::vector<Pubblicazioni*>);
  ~ListaPubblicazioni();

  Pubblicazioni& operator[](size_t);

  Pubblicazioni getPub(size_t) const;
  void setPub(Pubblicazioni*,size_t);

  void setList(std::vector<Pubblicazioni*>);

  void sort();
};

#endif
