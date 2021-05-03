
#include "ListaPubblicazioni.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

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

bool operator<(const Pubblicazioni& lhs, const Pubblicazioni& rhs) {
  if(getType(&lhs) < getType(&rhs)) return true;
  if(getType(&lhs) > getType(&rhs)) return false;
  else if(lhs.getAuthors()[0] < rhs.getAuthors()[0]) return true;
  else return false;
}

bool pubPtrMinus(Pubblicazioni* pub1, Pubblicazioni* pub2) {
  return (*pub1 < *pub2);
}

void ListaPubblicazioni::sort() {
  std::sort(this->list.begin(), this->list.end(), pubPtrMinus);
  return;
}

#define SET_SPACE(num) std::left << std::setw(num)
#define TITLE_SPACE 25
#define AUTHORS_SPACE 50

void ListaPubblicazioni::print(size_t index) {
  Pubblicazioni* pubPtr = getPub(index);
  std::cout << SET_SPACE(TITLE_SPACE) << pubPtr->getTitle() << ' ';

  std::string authors = "";
  for(size_t i = 0; i < pubPtr->getAuthors().size(); i++) {
    authors += pubPtr->getAuthors()[i];
    if(i < pubPtr->getAuthors().size() - 1) authors += ", ";
  }
  std::cout << SET_SPACE(AUTHORS_SPACE) << authors << ' ';
  std::cout << SET_SPACE(5) << pubPtr->getYear();

  if(getType(pubPtr) == PubType::Libro) { //ISBN + Publisher
    Libri* newPtr = dynamic_cast<Libri*>(pubPtr);
    std::cout << ' ' << SET_SPACE(14) << newPtr->getISBN() << ' ' << newPtr->getPublisher();
  } else if(getType(pubPtr) == PubType::ArticoloRivista) { //titolo + num + pagrange
    ArticoliRiviste* newPtr = dynamic_cast<ArticoliRiviste*>(pubPtr);
    std::cout << ' ' << SET_SPACE(TITLE_SPACE) << newPtr->getTitoloRiv() << ' ' << SET_SPACE(15) << newPtr->getNumRiv() <<
    ' ' << newPtr->getStart() << '-' << newPtr->getStop();
  } else if(getType(pubPtr) == PubType::ArticoloConvegno) { //titolo + sede + numpag
    ArticoliConvegni* newPtr = dynamic_cast<ArticoliConvegni*>(pubPtr);
    std::cout << ' ' << SET_SPACE(TITLE_SPACE) << newPtr->getTitoloConvegno() << ' ' <<
    SET_SPACE(15) << newPtr->getSedeConvegno() << ' ' << newPtr->getNumPagine();
  }
  return;
}

void ListaPubblicazioni::print() {
  PubType actualType = PubType::Invalid;
  for(size_t i = 0; i < this->list.size(); i++) {

    if(getType(this->list[i]) == PubType::Libro && actualType != PubType::Libro) {
      std::cout << "Libri:\n";
      std::cout << SET_SPACE(TITLE_SPACE) << "TITOLO" << ' ' << SET_SPACE(AUTHORS_SPACE) <<
        "AUTORI" << ' ' << SET_SPACE(5) << "ANNO" << ' ' << SET_SPACE(14) << "ISBN" << ' ' << "CASA EDITRICE" << '\n';
      actualType = PubType::Libro;
    } else if(getType(this->list[i]) == PubType::ArticoloRivista && actualType != PubType::ArticoloRivista) {
      std::cout << "Articoli su rivista:\n";
      std::cout << SET_SPACE(TITLE_SPACE) << "TITOLO" << ' ' << SET_SPACE(AUTHORS_SPACE) <<
        "AUTORI" << ' ' << SET_SPACE(5) << "ANNO" << ' ' << SET_SPACE(TITLE_SPACE) << "TITOLO RIVISTA" <<
        ' ' << SET_SPACE(15) << "NUMERO RIVISTA" << ' ' << "INTERVALLO PAGINE" << '\n';
      actualType = PubType::ArticoloRivista;
    } else if(getType(this->list[i]) == PubType::ArticoloConvegno && actualType != PubType::ArticoloConvegno) {
            std::cout << "Articoli su atti di convegni:\n";
      std::cout << SET_SPACE(TITLE_SPACE) << "TITOLO" << ' ' << SET_SPACE(AUTHORS_SPACE) <<
        "AUTORI" << ' ' << SET_SPACE(5) << "ANNO" << ' ' << SET_SPACE(TITLE_SPACE) << "TITOLO CONVEGNO" <<
         ' ' << SET_SPACE(15) << "SEDE" << ' ' << "NUMERO PAGINE" <<'\n';
      actualType = PubType::ArticoloConvegno;
    } else if(getType(this->list[i]) == PubType::Generico && actualType != PubType::Generico) {
      std::cout << "Altre pubblicazioni:\n";
      std::cout << SET_SPACE(TITLE_SPACE) << "TITOLO" << ' ' << SET_SPACE(AUTHORS_SPACE) <<
        "AUTORI" << ' ' << SET_SPACE(5) << "ANNO" << '\n';
      actualType = PubType::Generico;
    }

    print(i);
    std::cout << '\n';
  }
  return;
}

PubType getType(Pubblicazioni const* pub) {
  if(dynamic_cast<Libri const*>(pub) != nullptr) return PubType::Libro;
  else if(dynamic_cast<ArticoliConvegni const*>(pub) != nullptr) return PubType::ArticoloConvegno;
  else if(dynamic_cast<ArticoliRiviste const*>(pub) != nullptr) return PubType::ArticoloRivista;
  else return PubType::Generico;
}

void ListaPubblicazioni::addPub(Pubblicazioni* pub) {
  int n = this->list.size();
  int position{0};

  if(n == 0) {
    this->list.push_back(pub);
    return;
  }
  if(*this->list[0] < *pub) position++;
  while(position > 0 && position < n) {
    if (*(this->list[position-1]) < *pub && *pub < *(this->list[position])) break;
    position++;
  }
  std::cout << "\nfound at pos: " << position << '\n';
  if(position == n) {
    this->list.push_back(pub);
    return;
  } else {
    this->list.insert(this->list.begin()+position, pub);
    return;
  }

}

Pubblicazioni* askPub(PubType type) {
    std::string title;
    std::string publ;

    std::cout<< "Inserisci titolo pubblicazione:"<<std::endl;
    std::cin>> title;
  std::vector<std::string> authors = askAuthor();
  int year = askNumber(0,2030,"Inserisci data di pubblicazione:");
  std::string str1{0}, str2{0};
  int in1{0}, in2{0}, in3{0};
  switch(type) {
    case PubType::Libro:
      str1 = askNumberS("Inserisci ISBN libro:");
          std::cout<< "Inserisci casa editrice:"<<std::endl;
          std::cin>> publ;
      return new Libri(title,authors,year,str1,str2);
    case PubType::ArticoloRivista:
      str1 = askText("Inserisci titolo rivista:");
      in1 = askNumber(0, 999999999, "Inserisci numero rivista:");
      in2 = askNumber(0, 9999, "Inserisci pagina iniziale dell'articolo: ");
      in3 = askNumber(0, in2, "Inserisci pagina finale dell'articolo: ");
      return new ArticoliRiviste(title,authors,year,str1,in1,in2,in3);
    case PubType::ArticoloConvegno:
      str1 = askText("Inserisci titolo convegno:");
      str2 = askText("Inserisci sede del convegno");
      in1 = askNumber(0, 9999, "Inserisci numero di pagine:");
      return new ArticoliConvegni(title,authors,year,str1,str2,in1);
    default:
      return new Pubblicazioni(title,authors,year);
  }
}





//
