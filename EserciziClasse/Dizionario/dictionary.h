
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<string>
#include<vector>

size_t charSearch(std::string, char);
std::string trimSpaces(std::string);

class Dict {
private:
  std::vector<std::string> lang1w; //ENGLISH
  std::vector<std::string> lang2w; //ITALIAN
  std::string lang1;
  std::string lang2;
public:
  Dict(const std::string&, std::string = "Language1", std::string = "Language2");
  void print() const;
  void print(int) const;
  std::string getWord(int, bool = 0) const;
  void sort(bool = 0, int = 0, int = -1);
  int partition(bool, int, int);
  void swap(bool, int, int);
  std::string getLang1() const;
  std::string getLang2() const;

  int search(const std::string&, bool = 0) const;
  void append(std::string, std::string);

  void load(const std::string&);
};


#endif
