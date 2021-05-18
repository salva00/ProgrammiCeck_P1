#include <iostream>
#include <stack>
#include <string>
#include <exception>

void evaluate(const std::string&, std::stack<std::string>&); // converte espressione in input in stack notazione post-fissa
double solve(std::stack<std::string>&); // risolve lo stack ritornando il risultato numerico
bool invalidCharacter(const char); // ritorna vero se il carattere non e' uno dei sottostanti
bool isNum(const char); // ritorna vero se il carattere e' di tipo numerico (compreso '.')
bool isOpt(const char); // ritorna vero se il carattere e' un segno di operazione
bool isParenthesis(const char); // ritorna vero se il carattere e' una parentesi
bool hasPriority(const char, const char); // ritorna vero se l' operatore passato come primo argomento ha priorita' maggiore o uguale al secondo
bool stringIsOpt(const std::string&); // ritorna vero se la stringa passata rappresenta un segno di operazione

int main() {
	std::string expression; // l' espressione di input
	std::stack<std::string> expressionStack; // lo stack che andra' risolto
	std::getline(std::cin, expression); // leggo l'espressione di input
	evaluate(expression, expressionStack);
	std::cout << solve(expressionStack);
	return 0;
}

void evaluate(const std::string& _expression, std::stack<std::string>& _output) {
	std::string number; // stringa di appoggio per memorizzare char per char il numero che sto leggendo
	std::string operatorSign; // stringa di appoggio per memorizzare al più 2 operatori
	for (size_t idx{ 0 }; idx < _expression.length(); idx++) {
		char inputChar = _expression[idx];
		if (invalidCharacter(inputChar))
			throw std::invalid_argument("Errore di sintassi!");
		if (isNum(inputChar))
			number += inputChar;
		else if (isOpt(inputChar)) {
			if (!number.empty())
				_output.push(number); // aggiungo il numero letto in cima allo stack
			if (!operatorSign.empty()) // va fatto controllo di priorita' con un opeartore precedente
				if (hasPriority(operatorSign[operatorSign.length() - 1], inputChar))
					for (size_t i{ 0 }; i < operatorSign.length(); i++)
						_output.push(std::string({ operatorSign[operatorSign.length() - 1 - i] })); // se avevo già memorizzato uno o più operatori, li aggiungo allo stack
			operatorSign.clear(); // svuoto operatorSign prima di memorizzare nuovo operatore
			operatorSign += inputChar; // memorizzo  l' operatore per aggiungerlo successivamente allo stack
			number.clear(); // preparo number a leggere nuovo numero
		}
		else if (inputChar == '(') {
			int stop{ 1 };
			size_t end{ idx };
			for (size_t i{ idx + 1 }; i < _expression.length(); i++) {
				if (_expression[i] == ')')
					stop--;
				else if (_expression[i] == '(')
					stop++;
				if (stop == 0) {
					end = i; // trovo posizione della parentesi di teminazione
					break;
				}
			}
			if (stop > 0)
				throw std::invalid_argument("Errore di sintassi!"); // manca parentesi di chiusura
			if (!number.empty()) { // espressione del tipo x(y)
				_output.push(number); // aggiungo il numero letto in cima allo stack
				number.clear(); // preparo number a leggere nuovo numero
			}
			std::string subExpression = _expression.substr(idx + 1, end - 1 - idx); // taglio le parentesi
			evaluate(subExpression, _output); // valuto espressione chiusa tra parentesi
			if (idx > 0)  // escludo il caso in cui la parentesi di apertura sia all' inizio dell' espressione
				if (!isOpt(_expression[idx - 1]))
					_output.push(std::string("*")); // considero la scrittura x(y) come x * y
			idx = end;
			if (idx < _expression.length() - 1) // escludo il caso in cui la parentesi di chiusura sia alla fine dell' espressione
				if (isNum(_expression[idx + 1])) // espressione del tipo (x)y
					operatorSign += std::string("*"); // considero la scrittura (x)y come x * y
		}
	}
	//inserisco ultimi elementi
	if (!number.empty()) {
		_output.push(number); // aggiungo il numero letto in cima allo stack
	}
	for (size_t i{ 0 }; i < operatorSign.length(); i++)
		_output.push(std::string({ operatorSign[operatorSign.length() - 1 - i] })); // se avevo già memorizzato uno o più operatori, li aggiungo allo stack
}

double solve(std::stack<std::string>& _inputStack) {
	if (_inputStack.empty())
		throw std::invalid_argument("espressione vuota!");
	std::string stackElement = _inputStack.top(); // questo elemento deve necessariamente essere un operatore
	_inputStack.pop();
	if (!stringIsOpt(stackElement))
		throw std::invalid_argument("errore di sintassi!");
	double op1;
	double op2;
	if (stringIsOpt(_inputStack.top()))
		op2 = solve(_inputStack);
	else {
		op2 = std::stod(_inputStack.top());
		_inputStack.pop();
	}
	if (stringIsOpt(_inputStack.top()))
		op1 = solve(_inputStack);
	else {
		op1 = std::stod(_inputStack.top());
		_inputStack.pop();
	}
	switch (stackElement[0]) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

bool invalidCharacter(const char _char) {
	return !(isNum(_char) || isOpt(_char) || isParenthesis(_char));
}

bool isNum(const char _char) {
	return ((_char >= '0') && (_char <= '9')) || (_char == '.');
}

bool isOpt(const char _char) {
	return (_char == '+' || _char == '-' || _char == '*' || _char == '/');
}

bool isParenthesis(const char _char) {
	return (_char == '(' || _char == ')');
}

bool hasPriority(const char firstOpt, const char secondOpt) {
	if (firstOpt == '*' || firstOpt == '/')
		return true;
	if (secondOpt == '*' || secondOpt == '/')
		return false;
	return true; // entrambi sono operatori di somma algebrica, stessa priorita'
}

bool stringIsOpt(const std::string& _string) {
	if (_string.length() == 1)
		return isOpt(_string[0]);
	return false;
}