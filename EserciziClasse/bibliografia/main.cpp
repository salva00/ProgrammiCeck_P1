#include <iostream>
#include <string>
#include "Pubblicazioni.h"

std::vector<std::string> loadAuthors();    //carica vettore di autori
Pubblicazioni& loadPub();                   //carica singola pubblicazione
void makeList();                            //crea lista di pubblicazioni
void printList();                           //stampa lista di pubblicazioni
void getStats();                            //calcola il numero di pubblicazioni di ciascun tipo (le stampo solo?)

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

std::vector<std::string> loadAuthors() {
    //gli autori sono stringhe del tipo Cognome,Nome
    //sono ammessi i punti e gli spazi nel nome, ma non altri caratteri speciali
    //il vettore di autori sarà ordinato per cognome
    std::vector<std::string> authors;
    int num;
    std::cout << "How many Authors? ";
    std::cin >> num;
    while (std::cin.fail() || num < 1) {
        std::cin.clear();
        std::cin.ignore(100000, '\n');       //numero a caso alto
        std::cout << "Numbers of authors must be a positive number!\nHow many Authors? ";
        std::cin >> num;
    }
    std::cin.ignore(100000, '\n');
    std::cout << "Authors must be entered in Surname,Name format\n" <<
        "Valid examples: Poe,Edgar Allan or Poe,Edgar A.\n";
    while (num > 0) {
        std::string input;
        bool valid_input{ false };
        std::cout << "Author: ";
        std::getline(std::cin, input);
        //lettura cognome
        size_t i{ 0 };
        for (; i < input.length() && !valid_input; i++) {
            if (input[i] == ',' && i > 0)
                valid_input = true; //cognome valido
            else if ((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) {
                std::cout << "Invalid surname! Please re-enter ";
                i = input.length();
            }
        }
        if (i < input.length()) {
            //controllo nome
            for (; i < input.length() && valid_input; i++) {
                if (((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) && (input[i] != '.' && input[i] != ' ')) {
                    std::cout << "Invalid name! Please re-enter ";
                    valid_input = false;
                }
            }
        }
        else {  //nome vuoto
            std::cout << "Invalid name! Please re-enter: ";
            valid_input = false;
        }
        if (valid_input) {
            if (authors.size() > 0) {
                if (input >= authors.back())
                    authors.push_back(input);
                else {
                    for (size_t i{ 0 }; i < authors.size(); i++) {
                        if (authors[i] > input) {
                            authors.insert(authors.begin() + i, input);
                            i = authors.size(); //interrompo il for, non voglio usare il break
                        }
                    }
                }
            }
            else
                authors.push_back(input);
            num--;
        }
    }
    return authors;
}

Pubblicazioni& loadPub() {            //TODO: completare interfaccia
    std::string title;
    std::cout << "Titolo: ";
    //std::cin.getline(title);
    std::getline(std::cin,title);
    std::cin.ignore(10000, '\n');
    PublicationType choice{ Invalid };
    std::cout << "Publication Type: ":
    std::cin >> choice;
    while( choice < 0 || choice > 3) {
        std::cout << "Invalid Input. Please re-enter Publication Type: ":
        std::cin >> choice;
    }
    switch(choice):
        case Libro:
            break;
        case ArticoloRivista:
            break;
        case ArticoloConvegno:
            break;
        default:
            break;
}

std::vector<Pubblicazioni> makeList() {
    short input{ 0 };
    std::cout << "How many Publications? ";
    std::cin >> input;
    while (input > 0) {
        loadPub();
        input--;    //o --input se vogliamo far contento il prof;
    }
}
