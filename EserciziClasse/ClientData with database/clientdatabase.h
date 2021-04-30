
#include"clientdata.h"
#include<exception>

struct search_failure : public std::exception {
  const char* what() const throw();
};

//append object at the end of file
void storeClient(ClientData&, std::string);

//return reference to n-th object in database
ClientData& getClient(int, std::string);

//return index of the object from account number
size_t searchClient(int, std::string);

//print everything in database, if bool = false skip empty objects
void printAllClient(std::string, bool = false);

//replace objects with an empty one
void deleteClient(int, std::string);

//replace an object in database
void setClient(ClientData&, int, std::string);
