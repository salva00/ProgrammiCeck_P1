/*
*  Scrivere un programma c++ che permetta di gestire la bibliografia di un articolo scientifico.
- Il programma deve gestire un elenco di pubblicazioni,
- Tutte le pubblicazioni possono hanno un titolo, uno o piu' autori, ed un anno di pubblicazione
- E possono essere dei
    - Libri, vanno memorizzati le informazioni sulla casa editrice e l'ISBN
    - Articoli su riviste, vanno memorizzati il titolo della Rivista (es IEEE Transaction of Computers),
        il numero della rivista, e le pagine (inizio e fine)
    - Articoli su atti di convegni, vanno memorizzati il titolo del convegno
        (es IEEE Conference on Machine Learning), la sede del convegno, e il numero di pagina
- Il programma deve permettere di memorizzare una lista di pubblicazioni in un vettore,
    stampare la lista, ed calcolare il numero di pubblicazioni di ciascun tipo a partire dai dati memorizzati nel vettore.
- La stampa deve essere fatta in ordine alfabetico di cognome (overload dell'operatore <)
- Implementare l'ordinamento di un vettore di pubblicazioni
*/
/*
Pubblicazioni:
	title
	authors[]
	year

ArticoliConvegni:
	titoloConvegno
	sedeConvegno
	numPagine
ArticoliRiviste:
	titoloRiv
	numRiv
	start
	stop
Libri:
	ISBN
	publisher
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include "Pubblicazioni.h"
#include "ArticoliConvegni.h"
#include "ArticoliRiviste.h"
#include "Libri.h"

// std::vector<std::string> loadAuthors();    //carica vettore di autori
// Libri& loadLibro(std::string&, std::vector<std::string>&);
// ArticoliConvegni& loadArtConv(std::string&, std::vector<std::string>&);
// ArticoliRiviste& loadArtRivs(std::string&, std::vector<std::string>&);
// Pubblicazioni& loadPub();                   //carica singola pubblicazione
// void addToList(std::vector<Pubblicazioni*>);  //crea lista di pubblicazioni
// void printList();                           //stampa lista di pubblicazioni
// void getStats();                            //calcola il numero di pubblicazioni di ciascun tipo (le stampo solo?)
// bool isValidNumericString(std::string&);
// bool isValidPositiveNumber(int);
//
// enum PubType { Libro, ArticoloRivista, ArticoloConvegno, Generico };
//
// std::istream& operator>> (std::istream& in, PubType& publicationType){
// 	  int val;
// 	  if (in >> val){
// 	  	  switch ( val ) {
// 	  	  	  case 0: case 1: case 2:
// 	  	  	  	  publicationType = PubType(val);
// 	  	  	  	  break;
// 	  	  	  default:
// 	  	  	  	  throw std::invalid_argument("Invalid Input! Enter a value in range 0 to 2 ");
// 	  	  }
// 	  }
//
// 	  return in;
// }

#include"ListaPubblicazioni.h"
#include"iomanager.h"

int main() {
  // ListaPubblicazioni mialista{{
  //   new Pubblicazioni("Pubblicazione", {"Ceccarelli Michele","Natella Roberto"}, 2029),
  //   new Pubblicazioni("Citazione", {"Natella Roberto","Botta Alessio"}, 2030),
  //   new ArticoliRiviste("Rivistona", {"Albanese Raffaele","Visone Ciro","Balato Marco"}, 2000, "Circuiti", 31375, 2, 3),
  //   new ArticoliRiviste("Fisica per tutti", {"Pisanti Ofelia"}, 2000, "Teoria quantistica", 442323, 5, 6),
  //   new ArticoliConvegni("Convegno salute",{"Massarotti Davide","Lops Marco"}, 2001, "Salute mentale", "Vienna", 7),
  //   new ArticoliConvegni("Convegno Parigi",{"Velichkov Bozhidar","Zampini Alessandro"}, 2001, "Calcolo differenziale", "Parigi", 8),
  //   new Libri("Dietel", {"Ceccarelli Michele"}, 2001, "1234567890ABC", "Apogeo"),
  //   new Libri("Basi di dati", {"Botta Alessio"}, 2301, "9876543210DFG", "Mondadori"),
  // }};
  //   mialista.sort();
  //   mialista.addPub(new Pubblicazioni("5",{"q"},2000));
  //   mialista.print();
  // int a;
  // std::string b;
  // std::cout << "1\n";
  // std::cin >> a;
  // std::cin.ignore(1,'\n');
  // std::cout << "2\n";
  // std::cin >> b;
  // std::cin.ignore(1,'\n');
  // std::cout << a << " " << b << '\n';

  ListaPubblicazioni lista{};
  int choice{-1}, choice2{-1};
  while(true) {
    std::cout << "Seleziona un'opzione:\n";
    std::cout << "0 - Inserisci nuova pubblicazione\n";
    std::cout << "1 - Mostra lista pubblicazioni\n";
    std::cout << "2 - Termina programma\n> ";
    std::cin >> choice;
    std::cin.ignore(1,'\n');
    if(std::cin.fail() || choice < 0 || choice > 2) {
      std::cin.clear();
      std::cerr << "Opzione non valida\n";
      continue;
    }
    std::string title;
    switch(choice) {
      case 0:
        std::cout << "Seleziona un'opzione:\n";
        std::cout << "0 - Inserisci nuovo libro\n";
        std::cout << "1 - Inserisci nuovo articolo su rivista\n";
        std::cout << "2 - Inserisci nuovo articolo su atto di convegno\n> ";
        std::cin >> choice2;
        std::cin.ignore(1,'\n');
        if(std::cin.fail() || choice < 0 || choice > 2) {
          std::cin.clear();
          std::cerr << "Opzione non valida\n";
          continue;
        }
        lista.addPub(askPub(static_cast<PubType>(choice2)));
        break;
      case 1:
        lista.print();
        break;
      case 2:
        exit(EXIT_SUCCESS);
        break;
      }
    #if defined(__WIN32)
    system("cls");
    #else
    std::cout << "\n\n";
    #endif
  }
  // system("pause");
  return 0;
}
//
// std::vector<std::string> loadAuthors() {
//     //gli autori sono stringhe del tipo Cognome,Nome
//     //sono ammessi i punti e gli spazi nel nome, ma non altri caratteri speciali
//     //il vettore di autori sar� ordinato per cognome
//     std::vector<std::string> authors;
//     int num;
//     std::cout << "How many Authors? ";
//     std::cin >> num;
//     while (std::cin.fail() || num < 1) {
//         std::cin.clear();
//         std::cin.ignore(100000, '\n');       //numero a caso alto
//         throw std::invalid_argument("Numbers of authors must be a positive number!");
//         std::cout << "\nHow many Authors? ";
//         std::cin >> num;
//     }
//     std::cin.ignore(100000, '\n');
//     std::cout << "Authors must be entered in Surname,Name format\n" <<
//         "Valid examples: Poe,Edgar Allan or Poe,Edgar A.\n";
//     while (num > 0) {
//         std::string input;
//         bool valid_input{ false };
//         std::cout << "Author: ";
//         std::getline(std::cin, input);
//         //lettura cognome
//         size_t i{ 0 };
//         for (; i < input.length() && !valid_input; i++) {
//             if (input[i] == ',' && i > 0)
//                 valid_input = true; //cognome valido
//             else if ((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) {
//                 throw std::invalid_argument("Invalid surname! Please re-enter ");
//                 i = input.length();
//             }
//         }
//         if (i < input.length()) {
//             //controllo nome
//             for (; i < input.length() && valid_input; i++) {
//                 if (((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) && (input[i] != '.' && input[i] != ' ')) {
//                     throw std::invalid_argument("Invalid name! Please re-enter ");
//                     valid_input = false;
//                 }
//             }
//         }
//         else {  //nome vuoto
//             throw std::invalid_argument("Invalid name! Please re-enter: ");
//             valid_input = false;
//         }
//         if (valid_input) {
//             if (authors.size() > 0) {
//                 if (input >= authors.back())
//                     authors.push_back(input);
//                 else {
//                     for (size_t i{ 0 }; i < authors.size(); i++) {
//                         if (authors[i] > input) {
//                             authors.insert(authors.begin() + i, input);
//                             i = authors.size(); //interrompo il for, non voglio usare il break
//                         }
//                     }
//                 }
//             }
//             else
//                 authors.push_back(input);
//             num--;
//         }
//     }
//     std::vector<std::string>* vec_pointer = &authors;
//     return *vec_pointer;
// }
//
// Libri& loadLibro(std::string& title, std::vector<std::string>& authors,int year) {
//     std::string publisher;
//     std::string isbn;
//     std::cout << "Publisher: ";
//     std::getline(std::cin, publisher);
//     std::cout << "ISBN: ";
//     std::getline(std::cin, isbn);
//     Libri* new_libro = new Libri(title, authors, year, isbn, publisher);
//     return *new_libro;
// }
//
// ArticoliConvegni& loadArtConv(std::string& title, std::vector<std::string>& authors,int year) {
//     std::string titoloConvegno;
//     std::string sedeConvegno;
// 	  int numPagine;
//     std::cout << "Titolo del Convegno: ";
//     std::getline(std::cin, titoloConvegno);
//     std::cout << "Sede del Convegno: ";
//     std::getline(std::cin, sedeConvegno);
//     std::cout << "Numero di pagine: ";
//     std::cin >> numPagine;
//     while (std::cin.fail() || numPagine < 0) {
//         throw std::invalid_argument("L' argomento deve essere un numero positivo! ");
//         std::cout << "\nNumero di pagine: ";
//         std::cin.clear();
//         std::cin >> numPagine;
//     }
//     std::cin.ignore(100000, '\n');
//
//     ArticoliConvegni* new_artConv = new ArticoliConvegni(title, authors, year, titoloConvegno, sedeConvegno, numPagine);
//     return *new_artConv;
// }
//
// ArticoliRiviste& loadArtRivs(std::string& title, std::vector<std::string>& authors,int year) {
//     std::string titoloRivista;
//     int numRivista;
//     int start;
//     int stop;
//     std::cout << "Titolo della Rivista: ";
//     std::getline(std::cin, titoloRivista);
//     std::cout << "Numero della rivista: ";
//     std::cin >> numRivista;
//     std::cout << "Pagina iniziale: ";
//     std::cin >> start;
//     std::cout << "Pagina finale: ";
//     std::cin >> stop;
//     while (std::cin.fail() || numRivista < 0) {
//         throw std::invalid_argument("L' argomento deve essere un numero positivo! ");
//         std::cout << "\nNumero di pagine: ";
//         std::cin.clear();
//         std::cin >> numRivista;
//     }
//     std::cin.ignore(100000, '\n');
//
//     ArticoliRiviste* new_artRivs = new ArticoliRiviste(title, authors, year, titoloRivista, numRivista, start, stop);
//     return *new_artRivs;
// }
//
// Pubblicazioni& loadPub() {
//     std::string title;
//     std::vector<std::string> authors;
//     int year;
// 	  bool invalid_input{ true };
//     PubType choice;
//     std::cout << "Publication Type: ";
//     do{
//     	  try{
//     	  	  invalid_input = false;
//     	  	  std::cin >> choice;
//     	  }
//    	   	catch(std::invalid_argument& e){
//     	  	  std::cerr << e.what();
//     	  	  std::cout << "\nPlease re-enter Publication type: ";
//     	  	  invalid_input = true;
//     	  }
//     }while(invalid_input);
//
//     std::cout << "Title: ";
//     //std::cin.getline(title);
//     std::getline(std::cin,title);
//     std::cin.ignore(10000, '\n');
//     authors = loadAuthors();
//     std::cout << "Year of publication: ";
//     std::cin >> year;
//     while (year < 0) {
//         throw std::invalid_argument("Invalid year! ");
//         std::cout << "\nYear of publication: ";
//         std::cin >> year;
//     }
//
//     switch(choice){
//         case PubType::Libro:
//             return loadLibro(title, authors, year);
//             break;
//         case PubType::ArticoloRivista:
//             return loadArtConv(title, authors, year);
//             break;
//         case PubType::ArticoloConvegno:
//             return loadArtRivs(title, authors, year);
//             break;
//         default:
//             break;
//     }
// }
//
// void addToList(std::vector<Pubblicazioni*> List) {
//     short input{ 0 };
//     std::cout << "How many Publications? ";
//     std::cin >> input;
//     while (input > 0) {
//         List.push_back( &loadPub() );
//         input--;    //o --input se vogliamo far contento il prof;
//     }
// }
