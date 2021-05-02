
#include<iostream>
#include"clientdata.h"
#include"clientdatabase.h"
/*
A transaction processing program
• Lets’ write a complete program that allow the management of
a set of account records
• The program present a menu where the user is asked to:
1. Enter a new record
2. Update an existing record (ex deposit or debit some amount)
3. Delete an exist record
4. Print the list of existing accounts
*/
#define CLIENT_DATABASE "database.dat"

// create a new ClientData from cin
void askRecord(std::string);

// prompts user to change balance to a ClientData object
void touchClient(std::string filename);

int main() {

// for debug purposes only (feel free to delete)
// so you don't have to insert a lot of name to test
/**/
  system("erase database.dat");
  ClientData acc1(0,"robert","red",0);
  ClientData acc2(1,"harry","green",10);
  ClientData acc3(2,"john","yellow",20);
  ClientData acc4(3,"david","blue",30);
  storeClient(acc1, "database.dat");
  storeClient(acc2, "database.dat");
  storeClient(acc3, "database.dat");
  storeClient(acc4, "database.dat");
/**/


  int choice{-1};
  while(true) {
    std::cout << "Select an option:\n";

    std::cout << "0 - Enter a new record\n";
    std::cout << "1 - Update an existing record\n";
    std::cout << "2 - Delete existing record\n";
    std::cout << "3 - Print the list of existing records\n";
    std::cout << "4 - Exit\n> ";
    std::cin >> choice;

    int number;

    switch(choice) {
      case 0:
        askRecord(CLIENT_DATABASE);
        break;
      case 1:
        touchClient(CLIENT_DATABASE);
        break;
      case 2:
        std::cout << "Insert account number of account to delete: \n";
        std::cin >> number;
        deleteClient(number,CLIENT_DATABASE);
        break;
      case 3:
        printAllClient(CLIENT_DATABASE);
        break;
      case 4:
        exit(EXIT_SUCCESS);
        break;
      }
  //mydict.load("words.txt");
    system("pause");
  }
  system("pause");
  return 0;
}

void askRecord(std::string filename) {
  std::cout << "Insert account number, name, surname, initial balance (space separated)\n";
  int accnum;
  std::string name;
  std::string surname;
  double balance;
  std::cin >> accnum >> name >> surname >> balance;
  ClientData res{accnum,name,surname,balance};
  storeClient(res, filename);
  return;
}

void touchClient(std::string filename) {
  int number;
  double money;
  std::cout << "Insert account number to edit: ";
  std::cin >> number;
  ClientData data = getClient(number, filename);
  std::cout << "Insert amount to deposit (+) or withdraw (-): ";
  std::cin >> money;
  data.addBalance(money);
  setClient(data,number,filename);
  return;
}





//
