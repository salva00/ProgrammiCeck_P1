#include <iostream>
#include "Articoli.h"
#include <fstream>
#include <iomanip>

enum class Choice { ADD, DELETE, UPDATE, PRINT, EXIT };

Choice getChoiche();

void addRecord(std::fstream&);
void deleteRecord(std::fstream&);
void updateRecord(std::fstream&);
void printRecords(std::fstream&);

int selectRecord(const std::string&);
void outputLine(std::ostream&, const Articoli&);

using std::ios;


int main() {

    std::fstream db{ "hardware.dat", ios::binary | ios::in | ios::out };

    if (!db) {
        std::cerr << "Couldn't open the file" << std::endl;
        exit(EXIT_FAILURE);
    }
    Choice c;
    while ((c = getChoiche()) != Choice::EXIT) {
        switch (c) {
        case Choice::ADD:
            addRecord(db);
            break;
        case Choice::DELETE:
            deleteRecord(db);
            break;
        case Choice::UPDATE:
            updateRecord(db);
            break;
        case Choice::PRINT:
            printRecords(db);
            break;
        default:
            std::cerr << "Wrong input" << std::endl;
            break;
        }
        db.clear(); //inutile a fine programma ?
    }
}
Choice getChoiche() {
    int choice;
    do {
        std::cout << "\nEnter choiche:\n" <<
            "\n0-Add record \n" <<
            "\n1-Delete record\n" <<
            "\n2-Update record\n" <<
            "\n3-Print records\n" <<
            "\n4-Exit\n?:";
        std::cin >> choice;
    } while (choice < 0 || choice>5);
    return static_cast<Choice>(choice);
}

void addRecord(std::fstream& db) {
    int recordNumber{ selectRecord("Choose a new product number:") };
    db.seekg((recordNumber - 1) * sizeof(Articoli), db.beg);

    Articoli articolo;
    std::string name;
    int qnt;
    float price;

    std::cout << "Enter name, quantity, price\n";
    std::cin >> std::setw(15) >> name;
    std::cin >> std::setw(10) >> qnt;
    std::cin >> std::setw(5) >> price;

    articolo.setName(name);
    articolo.setQnt(qnt);
    articolo.setPrice(price);
    articolo.setProductCode(recordNumber);

    db.write(reinterpret_cast<char*>(&articolo), sizeof(Articoli));
}

void deleteRecord(std::fstream& db) {
    int recordNumber{ selectRecord("Choose a product number to delete:") };
    db.seekg((recordNumber - 1) * sizeof(Articoli), db.beg);
    Articoli articolo;
    db.read((char*)(&articolo), sizeof(Articoli));

    if (articolo.getProductCode() != 0) {
        Articoli vuoto;
        db.seekp((recordNumber - 1) * sizeof(Articoli));
        db.write((char*)(&vuoto), sizeof(Articoli));
        std::cout << "Product n: " << recordNumber << "successfully deleted\n";
    }
    else {
        std::cerr << "Product n: " << recordNumber << "doesn't exists\n";
    }
}

void updateRecord(std::fstream& db) {
    int recordNumber{ selectRecord("Choose a product number to update:") };
    db.seekg((recordNumber - 1) * sizeof(Articoli));
    Articoli articolo;
    db.read(reinterpret_cast<char*>(&articolo), sizeof(Articoli));

    if (articolo.getProductCode() != 0) {

        outputLine(std::cout, articolo);

        std::string name;
        int qnt;
        float price;
        std::cout << "Enter new name:\n";
        std::cin >> name;
        std::cout << "Enter new quantity:\n";
        std::cin >> qnt;
        std::cout << "Enter new price:\n";
        std::cin >> price;

        articolo.setName(name);
        articolo.setQnt(qnt);
        articolo.setPrice(price);
        articolo.setProductCode(recordNumber);

        db.seekp((recordNumber - 1) * sizeof(Articoli));
        db.write(reinterpret_cast<char*>(&articolo), sizeof(articolo));
    }
    else {
        std::cerr << "Product n: " << recordNumber << "doesn't exists\n";
    }
}

void printRecords(std::fstream& db) {
    //per stampare a console il contenuto del file:
    Articoli articolo;
    db.seekp(0); //parto dall' inizio del file
    while (db) {
        db.read(reinterpret_cast<char*>(&articolo), sizeof(Articoli));
        outputLine(std::cout, articolo);
    }
    /*if (!db){
        std::cerr<<"File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }
    db<<std::left<<std::setw(10)<<"Nome"<<
          std::setw(16)<<"Codice"<<
          std::setw(11)<<"Quantità"<<
          std::setw(10)<<std::right<<"Prezzo"<<std::endl;
    db.seekg(0);*/
}

int selectRecord(const std::string& promnt) {
    std::cout << promnt << std::endl;
    int selectedNumber;
    do {
        std::cout << "Insert the record number:\n";
        std::cin >> selectedNumber;
    } while (selectedNumber < 1 || selectedNumber > 99);
    return selectedNumber;
}

void outputLine(std::ostream& output, const Articoli& articolo) {
    output << std::left << std::setw(10) << articolo.getName() <<
        std::setw(16) << articolo.getProductCode() <<
        std::setw(11) << articolo.getQnt() <<
        std::setw(10) << std::setprecision(2) << std::right <<
        std::fixed << std::showpoint << articolo.getPrice() << std::endl;
}