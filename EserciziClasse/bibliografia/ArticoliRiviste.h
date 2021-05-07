
#ifndef BIBLIOGRAFIA_ARTICOLIRIVISTE_H
#define BIBLIOGRAFIA_ARTICOLIRIVISTE_H

#include "Pubblicazioni.h"
//include<vector>
//include<string>

class ArticoliRiviste : public Pubblicazioni {
private:
	  std::string titoloRiv;
    int numRiv;
    int start;
    int stop;
public:
    ArticoliRiviste(std::string title, std::vector<std::string> authors,
			int year, std::string titoloRiv, int numRiv, int start, int stop);

    virtual ~ArticoliRiviste()=default;

	  void setTitoloRiv(std::string);
    void setNumRiv(int);
    void setStart(int);
    void setStop(int);
    std::string getTitoloRiv() const;
    int getNumRiv() const;
    int getStart() const;
    int getStop() const;

};


#endif //BIBLIOGRAFIA_ARTICOLIRIVISTE_H
