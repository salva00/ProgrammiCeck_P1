
#include<iostream>
#include"dictionary.h"

/*
•	Implement a simple dictionary program that translates English
   words to Italian. The program should allow the user to repeatedly
   search for English words to translate, add new words to the
   dictionary, view the contents of the dictionary, and quit
   the program. The dictionary should be written to a file so
   that all changes made to the dictionary are persistent.
•	The program can define an dictionary entry class containing
  the English word and the Italian word
•	The dictionary is stored in a text file with a pair
  English-italian word on every row
•	At the start the program load the d¾ctionary in a
  vector of entries
•	Then the menu present the various choices to the user
•	Implement the cases when the dictionary vector is sorted
  and the case when it is not sorted.
•	Before the exit the program store the new dictionary
  in the text files
*/
using std::cout;
using std::cin;


// > SEARCH
// > ADD(SEARCH)
// > DELETE(SEARCH)

// inline std::string getString(std::string dialogue = "Insert string") {
//   std::string str;
//   cout << dialogue << ' ';
//   getline(cin, str);
//   return str;
// }

int main() {
  int choice{-1};

  Dict mydict("words.txt","English","Italian");
  while(true) {
    std::cout << "Select an option:\n";

    cout << "0 - Read stored values in the dictionary\n";
    cout << "1 - Search for a value in english\n";
    cout << "2 - Search for a value in italian\n";
    cout << "3 - Insert a value\n";
    cout << "4 - Save to file\n";
    cin >> choice;
    std::string word;
    switch(choice) {
      case 0: {
        mydict.print();
        break;
      }
      case 1: {
        int index{-1};
        cout << "Insert a name to search: ";
        cin >> word;
        mydict.search(word, 0);
        if(index >= 0) {
          cout << "Translation is: " << mydict.getWord(index,1);
        } else cout << "Couldn't find that\n";
        break;
      }
      case 2: {
        int index{-1};
        cout << "Insert a name to search: ";
        cin >> word;
        mydict.search(word, 1);
        if(index >= 0) {
          cout << "Translation is: " << mydict.getWord(index,0);
        } else cout << "Couldn't find that\n";
        break;
      }
      case 3: {
        std::string word2;
        cout << "Insert an english word: ";
        cin >> word;
        cout << "Insert its translation in italian: ";
        cin >> word2;
        mydict.append(word,word2);
        break;
      }
      case 4: {
        mydict.load("words.txt");
        break;
      }
      default: {
        break;
      }
    }
  //mydict.load("words.txt");
  system("pause");
  }
  return 0;
}












//
