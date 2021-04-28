
#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<iostream>
#include<iomanip>
#include<cstdlib>

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

  void colSwap(size_t, size_t);
  void rowSwap(size_t, size_t);

  Matrix<T>& operator=(const Matrix<T>&);
  Matrix<T> operator*(Matrix<T>) const;
  Matrix<T> operator*(T) const;
  Matrix<T> operator+(const Matrix<T>&) const;
  Matrix<T> operator-(const Matrix<T>&) const;
  Matrix<T>& operator*=(T);
  Matrix<T>& operator*=(const Matrix<T>&);
  Matrix<T>& operator+=(const Matrix<T>&);
  Matrix<T>& operator-=(const Matrix<T>&);

  Matrix<T> gauss() const;

  T diag() const;

private:
  size_t rows;
  size_t cols;
  std::vector<T> elements;
  bool inverted{0};
};

template<typename T>
Matrix<T> operator*(T, const Matrix<T>&);

/***********************************************/

//  class definitions


template<typename T>
//construct r x c matrix filled with to_fill
Matrix<T>::Matrix(size_t r, size_t c, T to_fill) : rows(r),
  cols(c), elements(r*c,to_fill) {}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& input) : rows(input.size()), cols(input[0].size()), elements{} {
  elements.resize(input.size()*input[0].size());
  for(size_t i = 0; i < input.size(); i++) {
    for(size_t j = 0; j < input[0].size(); j++) {
      this->put(input[i][j], i, j);
    }
  }
}


template<typename T>
//safe access elements
T Matrix<T>::at(size_t row, size_t col) const {
    return this->elements.at(row * this->cols + col);
  }

template<typename T>
const size_t Matrix<T>::getRows() const {return this->rows;}

template<typename T>
const size_t Matrix<T>::getCols() const {return this->cols;}

template<typename T>
//change elements
void Matrix<T>::put(T what, size_t row, size_t col) {
    this->elements[(row * this->cols) + col] = what;
}

template<typename T>
//randomise matrix
void Matrix<T>::random(int max, unsigned int seed, int min) {
  srand(seed);
  if(max < 0 || min > max) return;
  for(size_t i = 0; i < this->rows; i++) {
    for(size_t j = 0; j < this->cols; j++) {
      elements[(i*this->cols)+j] = (rand() % (max-min+1)) + min;
    }
  }
}

template<typename T>
//print matrix
void Matrix<T>::print() const {
  for(size_t i = 0; i < this->rows; i++) {
    for(size_t j = 0; j < this->cols; j++) {
      std::cout << std::setw(4) << elements[(i*this->cols)+j] << " ";
    }
    std::cout << '\n';
  }
  return;
}


template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  this->elements = rhs.elements;
  this->rows = rhs.rows;
  this->cols = rhs.cols;
  return *this;
}

template<typename T>
//executes dot product
Matrix<T> Matrix<T>::operator*(Matrix<T> mult) const {
  // takes m*n and n*p , returns m*p
  // this * mult
  if(mult.getRows() != this->cols)
    throw std::invalid_argument("Left operand rows must match second operand columns");
  size_t m = this->rows, n = this->cols;
  size_t p = mult.getCols();
  int temp{0};
  Matrix<T> res(m,p);
  for(size_t i = 0; i < m; i++) {
    for(size_t j = 0; j < p; j++) {
      for(size_t k = 0; k < n; k++) {
        temp += (this->elements[i*n + k] * mult.at(k,j));
        // std::cout << "(i,j) is " << i << " " << j << " ~ k is " << k << " ~~~";
        // std::cout << "doing " << this->elements[i*n + k]
        // << " * " <<  mult.at(k,j) << "\n";
      }
      res.put(temp,i,j);
      temp = 0;
    }
  }
  return res;
}

template<typename T>
//executes scalar product
Matrix<T> Matrix<T>::operator*(T mult) const {
  Matrix<T> res = *this;
  for(size_t i = 0; i < this->rows; i++) {
    for(size_t j = 0; j < this->cols; j++) {
      res.put(this->elements[(i*this->cols)+j] * mult, i, j);
    }
  }
  return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
  if(this->rows != rhs.rows || this->cols != rhs.cols)
    throw std::invalid_argument("Matrix dimensions does not match");
  Matrix<T> res = *this;
  for(size_t i = 0; i < this->rows; i++) {
    for(size_t j = 0; j < this->cols; j++) {
      res.put(this->at(i,j) + rhs.at(i,j),i,j);
    }
  }
  return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const {
  return (rhs*(-1))+(*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(T rhs) {
  *this = this->operator*(rhs);
  return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
  *this = this->operator*(rhs);
  return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
  *this = this->operator+(rhs);
  return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
  *this = this->operator-(rhs);
  return *this;
}

template<typename T>
//swap column a and b
void Matrix<T>::colSwap(size_t a, size_t b) {
  T temp;  // a>>temp b>>a temp>>b
  for(size_t i = 0; i < this->rows; i++) {
    temp = this->at(i,a);
    put(this->at(i,b), i, a);
    put(temp,i,b);
  }
}

template<typename T>
//swap row a and b
void Matrix<T>::rowSwap(size_t a, size_t b) {
  T temp;  // a>>temp b>>a temp>>b
  for(size_t i = 0; i < this->cols; i++) {
    temp = this->at(a,i);
    put(this->at(b,i), a, i);
    put(temp,b,i);
  }
}

template<typename T>
//returns the gauss-reduced version of the matrix
Matrix<T> Matrix<T>::gauss() const {
  Matrix<T> res = *this;
  size_t n = (res.getCols() < res.getRows()) ?
    res.getCols() : res.getRows();
    T r;
  for(size_t i = 0; i < n; i++) {
    try {
      for(size_t l = i+1; res.at(i,i) == 0 && l < res.getRows(); l++) {
        // std::cout << "checking is (" << l << "," << i << ") = " << res.at(i,l) << "is 0\n";
        if(res.at(l,i) != 0) {
          res.rowSwap(i,l);
          res.inverted = !(res.inverted);
        }
      }
    } catch(...) {std::cout << "yeah";}
    // swap if 0
    for(size_t j = i+1; j < res.getRows(); j++) {
      //computes R = (j..,i) / (i,i)  and multiples
      // every () by R*(i,k)
      if(res.at(j,i) == 0) continue;
      res.print();
      system("pause");
      // std::cout << "i = " << i << " ~ j = " << j << "\n"
      // << "r = " << res.at(j,i) << "/" << res.at(i,i) << " = " << res.at(j,i)/res.at(i,i) << "\n";
      r = res.at(j,i)/res.at(i,i);
      for(size_t k = i; k < res.getCols(); k++) { // reduce rows
        // for every element in row, takes the element at raw i (same col),
        // multiplies it by r, which is subtracted
        // std::cout << "i = " << i << " ~ j = " << j << "~ k = " << k << "\n"
        // << res.at(j,k) << " is subtracted by " << res.at(i,k)*r << "\n";
        //this->elements[(j * this->cols) + k] -= this->at(i,k) * r;
        res.put((res.at(j,k)-res.at(i,k)*r),j,k);
      }
    }
  }
  return res;
}

template<typename T>
//returns the determinant of a diagonal matrix
T Matrix<T>::diag() const {
  size_t n = (this->cols < this->rows) ? this->cols : this->rows;
  T res{1};
    for(size_t i = 0; i < n; i++) {
      res *= this->at(i,i);
    }
    if(this->inverted) {
      return -res;
    } else return res;
}

template<typename T>
Matrix<T> operator*(T lhs, const Matrix<T>& mat) {
  return mat*lhs;
}

#endif

//
//   a  b  c
//   d  e  f
//   g  h  i
//
//   d - a*(d/a)









//
