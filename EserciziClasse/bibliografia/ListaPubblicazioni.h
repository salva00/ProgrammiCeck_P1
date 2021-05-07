
#ifndef BIBLIOGRAFIA_BIBLIOGRAFIA_H
#define BIBLIOGRAFIA_BIBLIOGRAFIA_H

#include "ArticoliConvegni.h"
#include "ArticoliRiviste.h"
#include "Libri.h"
#include "iomanager.h"
//include<vector>
//include<string>

enum class PubType {Libro = 0,
                    ArticoloRivista = 1,
                    ArticoloConvegno = 2,
                    Generico = 3,
                    Invalid = -1};

PubType getType(const Pubblicazioni*);

bool pubPtrMinus(Pubblicazioni*, Pubblicazioni*);

bool operator<(const Pubblicazioni&, const Pubblicazioni&);

class ListaPubblicazioni {
private:
  std::vector<Pubblicazioni*> list;
public:
  ListaPubblicazioni(std::vector<Pubblicazioni*> = std::vector<Pubblicazioni*>());
  ~ListaPubblicazioni();

  Pubblicazioni& operator[](size_t);

  Pubblicazioni* getPub(size_t) const;
  void setPub(Pubblicazioni*,size_t);

  void setList(std::vector<Pubblicazioni*>);

  void sort();

  void print(size_t);
  void print();

  void addPub(Pubblicazioni*);
};

Pubblicazioni* askPub(PubType);

#endif
