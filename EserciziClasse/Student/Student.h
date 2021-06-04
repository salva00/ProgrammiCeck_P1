// Student.h
// Student class that stores a student name and average. 3 #include <string>
#include <string>

class Student {
public:
	// constructor initializes data members
	Student(std::string studentName, int studentAverage)
		: name(studentName) {
		// sets average data member if studentAverage is valid
		setAverage(studentAverage);
}
	// sets the Student's name
	void setName(std::string studentName) {
		name = studentName;
	}

	// retrieves the Student's name
	std::string getName() const {
		return name;
	}
	// sets the Student's average
	void setAverage(int studentAverage) {
	// validate that studentAverage is > 0 and<= 100; otherwise,
	// keep data member average's current value
		if (studentAverage > 0) {
			if (studentAverage <= 100) {
				average = studentAverage; // assign to data member
			}
		}
	}
	// retrieves the Student's average
	int getAverage() const {
		return average;
	}
 	// determines and returns the Student's letter grade
std::string getLetterGrade() const {
	// initialized to empty string by class string's constructor
	std::string letterGrade;
	if (average >= 90) {
		letterGrade  = "A";
	}
	else if (average >= 80) {
		letterGrade = "B";
	}
	else if (average >= 70) {
		letterGrade = "C";
	}
	else if (average >= 60) {
		letterGrade = "D";
	}
	else {
		letterGrade = "F";
	}

	return letterGrade;
}
private:
	std::string name;
	int average{0}; // initialize average to 0
}; //  end class Student











	//
