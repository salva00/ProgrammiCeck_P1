
#include <iostream>
#include <string>

namespace myutils {
  enum class Types {
	  VOID,
	  INT,
	  FLOAT,
	  STRING,
	  DOUBLE,
	  BOOL,
	  CHAR,
	};
  typedef Types t;

	class Type {
	public:
	  virtual Types getType() = 0;
		// virtual void setValue(Types value) = 0;
	};

	class Int : public Type {
	public:
	  Int(int value) { this->value = value; }
	  virtual Types getType() { return Types::INT; }
	  int getValue() { return value; }
	  void setValue(int value) { this->value = value; }
	private:
	  int value;
	};

	class Double : public Type {
	public:
	  Double(double value) { this->value = value; }
	  virtual Types getType() { return Types::DOUBLE; }
	  int getValue() { return value; }
	  void setValue(double value) { this->value = value; }
	private:
	  double value;
	};

	class Float : public Type {
	public:
	  Float(float value) { this->value = value; }
	  virtual Types getType() { return Types::FLOAT; }
	  int getValue() { return value; }
	  void setValue(float value) { this->value = value; }
	private:
	  float value;
	};

	class String : public Type {
	public:
	  String(std::string value) { this->value = value; }
	  virtual Types getType() { return Types::STRING; }
	  std::string getValue() { return value; }
	  void setValue(std::string value) { this->value = value; }
	private:
	  std::string value;
	};

	class Bool : public Type {
	public:
	  Bool(bool value) { this->value = value; }
	  virtual Types getType() { return Types::BOOL; }
	  bool getValue() { return value; }
	  void setValue(bool value) { this->value = value; }
	private:
	  bool value;
	};

	class Char : public Type {
	public:
	  Char(char value) { this->value = value; }
	  virtual Types getType() { return Types::CHAR; }
	  char getValue() { return value; }
	  void setValue(char value) { this->value = value; }
	private:
	  char value;
	};
};
















//
