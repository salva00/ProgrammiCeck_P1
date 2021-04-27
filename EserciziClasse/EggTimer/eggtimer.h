
#ifndef EGGTIMER_H
#define EGGTIMER_H

void repeatChar(char, int = 1);

class Eggtimer {
private:
  const int max;
  int progress{0};
public:
  Eggtimer(int);
  void printProgress() const;
  void next(int = 1);
  void reset();
  bool isCompleted();
};


#endif
