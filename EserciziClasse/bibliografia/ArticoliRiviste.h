//
// Created by Salvatore Bramante on 26/04/21.
//

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


    ArticoliRiviste(const std::string &title, const std::vector<std::string> &authors,const int &year,
                    const int & numRiv,const int & start, const int & stop);

    virtual ~ArticoliRiviste()=default;


    void setNumRiv(const int&);
    void setStart(const int&);
    void setStop(const int&);
    int getNumRiv() const;
    int getStart() const;
    int getStop() const;

    std::string toString() const override;


};


#endif //BIBLIOGRAFIA_ARTICOLIRIVISTE_H
