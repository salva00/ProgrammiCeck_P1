
#include"iomanager.h"
#include<iostream>
#define SEPARATOR_CHAR ','


inline void uppercase(char& c) {
  if('a'<=c && c<='z') c += 'A'-'a';
}
inline void lowercase(char& c) {
  if('A'<=c && c<='Z') c -= 'A'-'a';
}
inline bool isAZ(char c) {
  return (('a'<=c && c<='z') || ('A'<=c && c<='Z'));
}
inline bool isAZ(const std::string& str) {
  bool res{true};
  for(char c: str) res &= (isAZ(c) || c == ' ');
  return res;
}
inline bool isAuthorlist(const std::string& str) {
  bool res{true};
  for(char c: str) res &= (isAZ(c) || c == ' ' || c == SEPARATOR_CHAR || c == '.' || c == '\'');
  return res;
}
void format(std::string& str) {
  for(size_t i = 0; i < str.length(); i++) {
    if(i == 0) uppercase(str[i]);
    else if(str[i-1] == ' ') uppercase(str[i]);
    else lowercase(str[i]);
  }
}

size_t charSearch(const std::string& str, char c) {
  size_t pos{str.size()};
  while(pos >= 0) {
    if(str[pos] == c) break;
    pos--; //return -1 if not found
  }
  return pos;
}
inline int charCount(std::string str, char c) {
  int res{0};
  for (std::string::iterator it{str.begin()}; it != str.end(); it++) {
    if(*it == c) res++;
  }
  return res;
}

std::string trimSpaces(std::string in) {
  std::string str{in};
  int i = 0, j = str.length()-1;
  while(str[i] == ' ' || str[i] == '\t') i++;
  while(str[j] == ' ' || str[i] == '\t') j--;
  str.resize(j+1);
  str.erase(0,i);
  return str;
}

std::string askText(std::string message) {
  std::string res;
  do {
    std::cin.clear();
    std::cout << message << ' ';
    std::getline(std::cin, res);

  } while(std::cin.fail() || !isAZ(res));
  format(res);
  return res;
}

int askNumber(int min, long long int max, std::string message) {
  int res;
  do {
    std::cin.clear();
    std::cout << message << ' ';
    std::cin >> res;
  } while(std::cin.fail() || res < min || res > max);
  return res;
}

std::vector<std::string> askAuthor() {
  std::string res;
  do {
    std::cin.clear();
    std::cout << "Inserisci autori (separati da virgole):\n";
    std::getline(std::cin, res);
  } while(std::cin.fail() || !isAuthorlist(res));

  std::vector<std::string> authors;
  size_t index = charSearch(res,SEPARATOR_CHAR);
  if(index < 0) {
    authors.push_back(res);
    return authors;
  }

  std::string buffer;
  size_t leftIt = 0, rightIt = 0;
  while(rightIt <= res.length()) {
    if(res[rightIt] == SEPARATOR_CHAR || rightIt == res.length()) {
      buffer = res.substr(leftIt, rightIt-leftIt);
      if(buffer[0] == ' ' || buffer[buffer.length()-1] == ' ') {
        buffer = trimSpaces(buffer);
      }
      format(buffer);
      if(buffer != "") authors.push_back(buffer);
      leftIt = rightIt+1;
    }
    rightIt++;
  }
  return authors;
}













//
