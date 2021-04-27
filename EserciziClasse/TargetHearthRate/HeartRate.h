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
#include <string>
#include <ctime>
#define SECONDS_IN_YEAR 31536000
#define SECONDS_IN_DAY 86400

using std::string;
using std::to_string;

class HeartRate {
public:
  HeartRate(string inName, string inSurname, int inDay, int inMonth, int inYear) :
    name(inName), surname(inSurname), day(inDay), month(inMonth), year(inYear) {
  }
  int getAge() {
    time_t now_temp = time(0);
    tm* now = localtime(&now_temp);
    int age = 1900 + now->tm_year - this->year;
    if (this->month > (1 + now->tm_mon)) {
      age--;
    } else if(this->month == (1 + now->tm_mon) && this->day > now->tm_mday) {
      age --;
    }
    return age;
  }
  int getMaxHrate() {
    return 220 - getAge();
  }
  string getTargetHrate() {
    return to_string((int)(getMaxHrate()*0.5)) + '-' + to_string((int)(getMaxHrate()*0.85));
  }
  void print() {
    std::cout << this->name << ' ' << this->surname <<
    "\nBorn in " << this->day << '/' << this->month << '/' << this->year << "\n";
    return;
  }
private:
  string name;
  string surname;
  int day;
  int month;
  int year;
};
