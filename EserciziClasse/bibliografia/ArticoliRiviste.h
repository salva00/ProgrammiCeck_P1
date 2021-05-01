#ifndef BIBLIOGRAFIA_ARTICOLIRIVISTE_H
#define BIBLIOGRAFIA_ARTICOLIRIVISTE_H

#include <iterator>
#include "Pubblicazioni.h"
#include <string>

class ArticoliRiviste: public Pubblicazioni {
private:
	  std::string titoloRiv;
    int numRiv;
    int start;
    int stop;
public:


    ArticoliRiviste(const std::string &title, const std::vector<std::string> &authors, int year, const std::string& titoloRiv, int numRiv, int start, int stop);

    virtual ~ArticoliRiviste()=default;

	  void setTitoloRiv(const std::string&);
    void setNumRiv(const int&);
    void setStart(const int&);
    void setStop(const int&);
    std::string getTitoloRiv() const;
    int getNumRiv() const;
    int getStart() const;
    int getStop() const;

};


#endif //BIBLIOGRAFIA_ARTICOLIRIVISTE_H
