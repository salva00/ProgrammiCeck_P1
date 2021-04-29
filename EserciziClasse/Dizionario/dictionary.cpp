
#include"dictionary.h"
#include<fstream>
#include<iostream>
#include<iomanip>

#define SEPARATOR_CHAR ':'
#define COLUMN_WIDTH 35

size_t charSearch(std::string str, char c) {
  size_t pos{str.size()};
  while(pos >= 0) {
    if(str[pos] == c) break;
    pos--;
  }
  return pos;
}

std::string trimSpaces(std::string in) {
  std::string str{in};
  int i = 0, j = str.length()-1;
  while(str[i] == ' ') i++;
  while(str[j] == ' ') j--;
  //if(i > j) return " ";
  str.resize(j+1);
  str.erase(0,i);
  return str;
}

Dict::Dict(const std::string& filename, std::string l1, std::string l2) :
  lang1{l1}, lang2{l2} {
  std::ifstream wordfile{filename};
  if(!wordfile) {
    std::cerr << "File not found";
    exit(EXIT_FAILURE);
  }
  std::string temp;
  size_t separator{0};
  while(getline(wordfile,temp)) {
    separator = charSearch(temp, SEPARATOR_CHAR);
    if(separator == -1) break;//separator not found(maybe one word per row)
    lang1w.push_back(
      trimSpaces( temp.substr(0,separator)) );
    lang2w.push_back(
      trimSpaces( temp.substr(separator+1,temp.size()-separator)) );
  }
  this->sort(0);
  wordfile.close();
}

void Dict::print() {
  std::cout << "Translations stored:\n";
  std::cout << std::setw(COLUMN_WIDTH) << std::left << this->lang1 << this->lang2 << '\n';
  for(size_t i = 0; i < lang1w.size(); i++) {
    std::cout << std::setw(COLUMN_WIDTH) << std::left << lang1w[i] << lang2w[i] << '\n';
  }
  return;
}

void Dict::print(int index) {
  std::cout << index << ": " << this->lang1w[index] << ' ' << this->lang2w[index] << '\n';
  return;
}

std::string Dict::getWord(int index, bool which) {
  return which? this->lang2w[index] : this->lang1w[index];
}


std::string Dict::getLang1() const {return this->lang1;}
std::string Dict::getLang2() const {return this->lang2;}


void Dict::swap(bool which, int ind1, int ind2) {
  std::string temp = this->lang1w[ind1];
  this->lang1w[ind1] = this->lang1w[ind2];
  this->lang1w[ind2] = temp;
  temp = this->lang2w[ind1];
  this->lang2w[ind1] = this->lang2w[ind2];
  this->lang2w[ind2] = temp;
  return;
}

int Dict::partition(bool which, int l, int h) {
  std::string x;
  if(which == 0) x = this->lang1w[h];
  if(which == 1) x = this->lang2w[h];
  int i = (l - 1);
    for (int j = l; j <= h - 1; j++) {
      if (which == 0 && this->lang1w[j] <= x) {
          i++; this->swap(which, i, j);}
      if (which == 1 && this->lang2w[j] <= x) {
          i++; this->swap(which, i, j);}
  }
  swap(which, i + 1, h);
  return (i + 1);
}

void Dict::sort(bool which, int l, int h) {
  if(h <= 0) h = this->lang1w.size()-1;
  int stack[h - l + 1];
    int top = -1;
    stack[++top] = l;
  stack[++top] = h;
    while (top >= 0) {
        h = stack[top--];
      l = stack[top--];
        int p = this->partition(which, l, h);
        if (p - 1 > l) {
          stack[++top] = l;
          stack[++top] = p - 1;
      }
        if (p + 1 < h) {
          stack[++top] = p + 1;
          stack[++top] = h;
      }
  }
  return;
}

void Dict::append(std::string wl1, std::string wl2) {
  int n = this->lang1w.size();
  int left = 0;
  int right = n-1;
  int position{0};

  while (left<=right){
      int mid = (right+left)/2;
      if (this->lang1w[mid] <= wl1 && this->lang1w[mid+1] > wl1){
          position = mid;
          break;
      }
      if (this->lang1w[mid] < wl1){
          left = mid + 1;
      } else {
          right = mid - 1;
      }
  }
  this->lang1w.insert(this->lang1w.begin()+position+1,wl1);
  this->lang2w.insert(this->lang2w.begin()+position+1,wl2);
  return;
}

int Dict::search(std::string what, bool which){
    int n = this->lang1w.size();
    int left = 0;
    int right = n-1;

    while (left<=right){
        int mid = (right+left)/2;
        if (which == 0 && this->lang1w[mid] == what){
            return mid;
        }
        if (which == 1 && this->lang2w[mid] == what){
            return mid;
        }
        if (which == 0 && this->lang1w[mid] < what){
            left = mid + 1;
        } else if(which == 1 && this->lang2w[mid] < what) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}








//
