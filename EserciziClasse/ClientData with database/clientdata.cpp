
#include"clientdata.h"
#include<iostream>

ClientData::ClientData(int an, const std::string& nam, const std::string& sur, double bal) : accNum{an} {
    this->setName(nam);
    this->setSurname(sur);
    this->setBalance(bal);
}

double ClientData::getBalance() const {return this->balance;}
void ClientData::setBalance(double amount) {
  if(amount < 0) throw std::invalid_argument("Money amount cannot be negative");
  else this->balance = amount;
}
void ClientData::addBalance(double amount) {
  this->setBalance(this->getBalance()+amount);
  return;
}
std::string ClientData::getName() const {
  return std::string(this->name);
}

std::string ClientData::getSurname() const {
  return std::string(this->surname);
}

void ClientData::setName(const std::string& str) {
  for(int i = 0; i < CHAR_BUFFER-1; i++) {
    this->name[i] = str[i];
  }
  this->name[CHAR_BUFFER-1] = '\0';
  return;
}
void ClientData::setSurname(const std::string& str) {
  for(int i = 0; i < CHAR_BUFFER-1; i++) {
    this->surname[i] = str[i];
  }
  this->surname[CHAR_BUFFER-1] = '\0';
  return;
}

int ClientData::getAccNum() const {return this->accNum;}


void ClientData::print() {
  std::cout << this->getAccNum() << " " << this->getName() << " " <<
    this->getSurname() << " " << this->getBalance() << '\n';
}












//
