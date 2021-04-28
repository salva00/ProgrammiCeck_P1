
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<typename T>
class Matrix {
public:
  // costructors
  Matrix(size_t, size_t, T = 0);
  Matrix(const std::vector<std::vector<T>>&);
  // getter-setters
  T at(size_t row, size_t col) const;
  const size_t getRows() const;
  const size_t getCols() const;

  void put(T, size_t, size_t);

  void random(int, unsigned int = 0, int = 0);

  void print() const;

  Matrix<T> operator*(Matrix<T>);
  Matrix<T> operator*(T);
  Matrix<T> operator+(const Matrix<T>&) const;
  void colSwap(size_t, size_t);
  void rowSwap(size_t, size_t);

  Matrix<T> gauss() const;

  T diag() const;

private:
  const size_t rows;
  const size_t cols;
  std::vector<T> elements;
  bool inverted{0};
};

#endif











//
