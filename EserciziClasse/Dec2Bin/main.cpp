#include <iostream>
#include <string>

std::string recDec2Bin(int number){
    if(number==0){
        return "0";
    } else{
        return recDec2Bin(number/2) + std::to_string(number%2);
    }
}

int raisePow(int base, int exponent) {
  if(exponent < 0) return 0;
  int res{1};
  for(int i = 0; i < exponent; i++) res *= base;
  return res;
}

int Bin2Dec(std::string number) {
  int res{0};
  for(size_t i = 0; i < number.length(); i++) {
    if(number[i] == '0') continue;
    if(number[i] == '1') res += raisePow(2,number.length()-i-1);
    else throw std::invalid_argument("Number must only contain 0 and 1");
  }
  return res;
}

int main() {
    int number;
    std::cout << "Enter a number: " << std::endl;
    std::cin>>number;
    std::string bin = recDec2Bin(number);
    std::cout << "Binary: " << bin << std::endl;
    std::cout << "Converted back is: " << Bin2Dec(bin) << std::endl;
    return 0;
}
