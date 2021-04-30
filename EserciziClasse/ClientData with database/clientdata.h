
#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include<string>

#define CHAR_BUFFER 15

class ClientData {
public:

  //default constructor specifies empty objects
  ClientData(int = -1, const std::string& = "empty", const std::string& = "empty", double = 0);

  double getBalance() const;
  void setBalance(double);
  void addBalance(double);

  std::string getName() const;
  std::string getSurname() const;
  void setName(const std::string&);
  void setSurname(const std::string&);

  int getAccNum() const;

  void print();
private:
  int accNum;
  double balance;
  char name[CHAR_BUFFER];
  char surname[CHAR_BUFFER];
};











#endif
