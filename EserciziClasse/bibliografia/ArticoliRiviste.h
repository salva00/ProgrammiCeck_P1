#ifndef BIBLIOGRAFIA_ARTICOLIRIVISTE_H
#define BIBLIOGRAFIA_ARTICOLIRIVISTE_H

#include <iterator>
#include "Pubblicazioni.h"

class ArticoliRiviste: public Pubblicazioni {
private:
    int numRiv;
    int start;
    int stop;
public:


    ArticoliRiviste(const std::string &title, const std::vector<std::string> &authors, int numRiv, int start, int stop);

    virtual ~ArticoliRiviste()=default;


    void setNumRiv(const int&);
    void setStart(const int&);
    void setStop(const int&);
    int getNumRiv() const;
    int getStart() const;
    int getStop() const;

};


#endif //BIBLIOGRAFIA_ARTICOLIRIVISTE_H
