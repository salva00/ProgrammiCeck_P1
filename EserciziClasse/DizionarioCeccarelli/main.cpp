#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include "Word.h"

int binarySearchWord(const std::string&, const std::vector<Word>&);
void addWord(const std::string&,const std::string&,std::vector<Word>&);
void loadDictionary(const std::string&,std::vector<Word>&);
int writeDictionary(const std::string&, const std::vector<Word>&);


int main() {
    int choice{0};
    const std::string DICTIONARY{"eng.dict"};
    std::string word;
    std::vector<Word> words;    //list

    //load dictionary
    loadDictionary(DICTIONARY,words);

    std::cout << "Welcome to the English-talian Dictionary!" << std::endl;
    while(true) {
        std::cout << "Choose one:" << std::endl
                  << "1-Search" << std::endl
                  << "2-Add Word" << std::endl
                  << "3-Search" << std::endl
                  << "4-quit" << std::endl;
        std::cout<<": ";
        std::cin>>choice;

        switch (choice) {
            case 1:
                std::string word;
                std::cout << "Enter eng word:" << std::endl;
                std::cin>>word;
                int pos= binarySearchWord(word,words);
                if(pos<0){
                    std::cout<<"---\n"<< std::endl;
                    std::cout<<"\n"<<word<<"not found"<< std::endl;
                }else{
                    std::cout<<"---\n"<< std::endl;
                    std::cout<<"\n"<<word<<" means "<< w.getIdWord() << std::endl;
                    std::cout<<"---\n"<< std::endl;

                }
                break;
            case 2:
                std::string engWord,itWord;
                std::cout << "Enter eng word:" << std::endl;
                std::cin>>engWord;
                std::cout << "Enter meaning:" << std::endl;
                std::cin>>engWord;
                int p = binarySearchWord(engWord,words);
                break;
        }

    }

    return 0;
}


//TODO:controllare se è ordinato (meglio fare come la ricerca binaria per ottimizzare l'ordine)
void loadDictionary(const std::string& dictFile,std::vector<Word>& words){
    std::string engWord, itWord;
    std::ifstream inFile(dictFile,std::ios::in);
    if(!inFile){
        std::cerr<<"Can't open directory."<<std::endl;
        exit(EXIT_FAILURE);
    }

    while(inFile>> engWord >> itWord){
        words.push_back(Word(engWord,itWord));
    }
    inFile.close();
}

void addWord(const std::string& engWord,const std::string& itWord,std::vector<Word>& dict){
    Word w(engWord,itWord);
    int i =0;
    while (i<dict.size()){
        Word c(dict[i]);
        if(c.getEngWord()< engWord){
            i++;
        }else{
            break;
        }
    }
}
int binarySearchWord(const std::string& searchWd, const std::vector<Word>& words){
    std::string itWord, engWord;
    int n = words.size();
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (right+left)/2;
        Word w{words[mid]};
        if(w.getEngWord() == searchWd){
            return mid;
        }
        if(w.getEngWord()< searchWd){
            left = mid+1;
        }else{
            right= mid-1;
        }
        return -1;
    }
}
int writeDictionary(const std::string&, const std::vector<Word>&){}