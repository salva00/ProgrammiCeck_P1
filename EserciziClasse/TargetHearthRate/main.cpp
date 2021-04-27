/*
  •While exercising, you can use a heart-rate monitor to see that your heart rate
stays within a safe range suggested by your trainers and doctors. According to
the American Heart Association (AHA) (http://bit.ly/AHATargetHeartRates), the
formula for calculating your maximum heart rate in beats per minute is:220 -age.
  •Your target heart rate is a range that’s 50–85% of your maximum heart rate. [
  •Create a class called HeartRates. The class attributes should include the
person’s first name, last name and date of birth
  •Your class should have a constructor that receives this data as parameters.
For each attribute provide set and get functions.
  •The class also should include a member function that
calculates and returns the person’s age (in years), a member function that
calculates and returns the person’s maximum heart rate and a member
function that calculates and returns the person’s target heart rate.
  •Write a program that prompts for the person’s information, instantiates
an object of class HeartRates and prints the information from that
object—including the person’s first name, last name and date of
birth—then calculates and prints the person’s age in (years),
max-imumheart rate and target-heart-rate range.
*/

#include <iostream>
#include <ctime>
#include "HeartRate.h"

using std::cout;
using std::cin;

int main() {
  int day, month, year;
  string name, surname;
  cout << "Insert name: ";
  getline(cin, name);
  cout << "Insert surname: ";
  getline(cin, surname);
  cout << "Born in day (1-31): ";
  cin >> day;
  cout << "Born in month (1-12): ";
  cin >> month;
  cout << "Born in year: ";
  cin >> year;
  HeartRate user1(name,surname,day,month,year);
  cout << "\n";
  cout << "age of " << user1.getAge() << "\n";
  user1.print();
  cout << "Suggested heart rate of " << user1.getTargetHrate()
  << " for a maximum of " << user1.getMaxHrate() << "\n";

  system("pause");
  return 0;
}
