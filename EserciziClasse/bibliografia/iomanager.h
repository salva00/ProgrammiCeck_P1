
#ifndef BIBLIOGRAFIA_IOMANAGER_H
#define BIBLIOGRAFIA_IOMANAGER_H
/*
Pubblicazioni:
	title
	authors[]
	year

ArticoliConvegni:
	titoloConvegno string
	sedeConvegno string
	numPagine int
ArticoliRiviste:
	titoloRiv string
	numRiv int
	start int
	stop int
Libri:
	ISBN string
	publisher string
*/
//#include"ListaPubblicazioni.h"
//include "ArticoliConvegni.h"
//include "ArticoliRiviste.h"
//include "Libri.h"
#include<vector>
#include<string>
// #include<iostream>

inline void uppercase(char&);
inline void lowercase(char&);

inline bool isAZ(char);
inline bool isAZ(const std::string&);
inline bool isNum(const std::string&);
inline bool isAuthorlist(const std::string&);
void format(std::string&);
size_t charSearch(const std::string&, char);
inline int charCount(std::string, char);
std::string trimSpaces(std::string);

std::string askText(std::string  = "Inserisci testo:"); //get text a-zA-Z from Publisher
std::vector<std::string> askAuthor(); //get author from cin
int askNumber(int, long long int, std::string = "Inserisci numbero:"); //get number
std::string askNumberS(std::string = "Inserisci un numbero:");
















#endif
