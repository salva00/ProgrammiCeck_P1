
#include "container.h"
#include "..\lib\mystl\LinkedQueue.h"

double getTotalWeight(const Container&);
double getTotalValue(const Container&);

class Customs : public mystl::LinkedQueue<Container> {
private:
	constexpr static double max_value{2000};
	mystl::LinkedList<StoredBox> storage;
public:
	Customs();
	void print() const;
	void printStorage() const;
	void clearance();
	void clearence_excess(int);
	void append_from(std::string);
	void load_from(std::string);
};
