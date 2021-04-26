#include <iostream>
#include <string>

bool recPalindrome(std::string word){
    if(word.length()<=1){
        return true;
    }else{
        return word.at(0) == word.at(word.length()-1) && recPalindrome(word.substr(1,word.length()-2));
    }
}

int main() {
    std::string word;
    std::cout << "enter a word: " << std::endl;
    std::cin>>word;
    if(recPalindrome(word)){
        std::cout << "is Palindrome! :)" << std::endl;
    }else{
        std::cout << "is not Palindrome! :(" << std::endl;
    }
    return 0;
}
