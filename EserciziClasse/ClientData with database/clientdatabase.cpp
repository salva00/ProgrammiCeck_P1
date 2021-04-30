
#include"clientdatabase.h"
#include<fstream>
#include<iostream>

const char * search_failure::what () const throw () {
   return "Couldn't find occurance\n";
}

void storeClient(ClientData& client, std::string filename) {
  std::ofstream writefile{filename, std::ios::out | std::ios::binary | std::ios::app};
  // writefile.seekp(writefile.cur);
  writefile.write(reinterpret_cast<const char*>(&client),sizeof(ClientData));
  writefile.close();
  return;
}


ClientData& getClient(int position, std::string filename) {
  std::ifstream readfile{filename, std::ios::in | std::ios::binary};
  if(!readfile.is_open()) {
    throw std::invalid_argument("File could not be found");
  }
  ClientData* temp = new ClientData{};

  readfile.seekg(0,readfile.end);
  size_t len = readfile.tellg();
  readfile.seekg(0,readfile.beg);
  len -= readfile.tellg();
  if((position+1)*sizeof(ClientData) > len) throw search_failure();

  readfile.seekg(sizeof(ClientData)*position, readfile.beg);
  readfile.read(reinterpret_cast<char*>(temp), sizeof(ClientData));
  readfile.close();
  return *temp;
}


size_t searchClient(int accountNumber, std::string filename) {
  std::ifstream readfile{filename, std::ios::in | std::ios::binary};
  if(!readfile.is_open()) {
    throw std::invalid_argument("File could not be found");
  }
  ClientData* temp = new ClientData{};
  size_t index{0};
  while(readfile.read(reinterpret_cast<char*>(temp), sizeof(ClientData))) {
    // readfile.read(reinterpret_cast<char*>(temp), sizeof(ClientData));
    if(temp->getAccNum() == accountNumber) break;
    index++;
  }
  if(readfile.eof()) throw search_failure();
  readfile.close();
  delete temp;
  return index;
}

void printAllClient(std::string filename, bool showAll) {
  std::ifstream readfile{filename, std::ios::in | std::ios::binary};
  if(!readfile.is_open()) {
    throw std::invalid_argument("File could not be found");
  }
  ClientData* temp = new ClientData{};
  while(readfile.read(reinterpret_cast<char*>(temp), sizeof(ClientData))) {
    // readfile.read(reinterpret_cast<char*>(temp), sizeof(ClientData));
    if(temp->getAccNum() >= 0 || showAll == 1) temp->print();
  }
  readfile.close();
  delete temp;
  return;
}

void deleteClient(int position, std::string filename) {
  ClientData emptyData{};
  setClient(emptyData, position, filename);
  return;
}

void setClient(ClientData& acc, int position , std::string filename) {
  std::ofstream writefile{filename, std::ios::in | std::ios::out | std::ios::binary};
  if(!writefile.is_open()) {
    throw std::invalid_argument("File could not be found");
  }

  writefile.seekp(0,writefile.end);
  size_t len = writefile.tellp();
  writefile.seekp(0,writefile.beg);
  if((position+1)*sizeof(ClientData) > len) throw search_failure();

  writefile.seekp(sizeof(ClientData)*position, writefile.beg);
  writefile.write(reinterpret_cast<const char*>(&acc), sizeof(ClientData));
  writefile.close();
  return;
}











//
