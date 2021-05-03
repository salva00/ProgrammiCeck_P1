//
// Created by Salvatore Bramante on 03/05/21.
//

#ifndef DIZIONARIOCECCARELLI_WORD_H
#define DIZIONARIOCECCARELLI_WORD_H
#include <string>


class Word {
private:
    std::string engWord;
    std::string itWord;

public:
    Word(const std::string&,const std::string&);
    std::string getEngWord();
    std::string getItWord();
    void setEngWord(const std::string&);
    void setItWord(const std::string&);

};


#endif //DIZIONARIOCECCARELLI_WORD_H
