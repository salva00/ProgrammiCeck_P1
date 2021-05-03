//
// Created by Salvatore Bramante on 03/05/21.
//

#include "Word.h"

Word::Word(const std::string &eng, const std::string &it) : engWord(eng), itWord(it) {}

std::string Word::getEngWord() {
    return engWord;
}

std::string Word::getItWord() {
    return itWord;
}

void Word::setEngWord(const std::string & eng) {
    engWord=eng;
}

void Word::setItWord(const std::string &it) {
    itWord=it;
}
