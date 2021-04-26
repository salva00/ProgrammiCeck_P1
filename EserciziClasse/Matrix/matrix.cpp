#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using std::vector;

template<typename T>
class Matrix {
public:
  // costructors
  Matrix(size_t r, size_t c, T to_fill = 0) : rows(r),
    cols(c), elements(r*c,to_fill) {}
  Matrix(const vector<vector<T>>& input) : rows(input.size()), cols(input[0].size()) {
    for(size_t i = 0; i < input.size(); i++) {
      for(size_t j = 0; j < input[0].size(); j++) {
        this->elements.push_back(input[i][j]);
      }
    }
  }
  // getter-setters
  T at(size_t row, size_t col) { // to access elements
    return this->elements.at(row * this->cols + col);
  }
  const size_t& getRows() const {return this->rows;}
  const size_t& getCols() const {return this->cols;}
  void put(T what, size_t row, size_t col) {
    this->elements[(row * this->cols) + col] = what;
  }

  void random(int max, unsigned int seed = 0, int min = 0) {
    srand(seed);
    if(max < 0 || min > max) return;
    for(size_t i = 0; i < this->rows; i++) {
      for(size_t j = 0; j < this->cols; j++) {
        elements[(i*this->cols)+j] = (rand() % (max-min+1)) + min;
      }
    }
  }

  void print() const {
    for(size_t i = 0; i < this->rows; i++) {
      for(size_t j = 0; j < this->cols; j++) {
        std::cout << std::setw(4) << elements[(i*this->cols)+j] << " ";
      }
      std::cout << std::endl;
    }
    return;
  }

  Matrix<T> operator*(Matrix<T> mult) {
    // takes m*n and n*p , returns m*p
    // this * mult
    if(mult.getRows() != this->cols) throw;

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

  Matrix<T> operator*(T mult) {
    Matrix<T> res = *this;
    for(size_t i = 0; i < this->rows; i++) {
      for(size_t j = 0; j < this->cols; j++) {
        res.put(this->elements[(i*this->cols)+j] * mult,i,j);
      }
    }
    return res;
  }

  void colSwap(size_t a, size_t b) {
    T temp;  // a>>temp b>>a temp>>b
    for(size_t i = 0; i < this->rows; i++) {
      temp = this->at(i,a);
      put(this->at(i,b),i,a);
      put(temp,i,b);
    }
  }
  void rowSwap(size_t a, size_t b) {
    T temp;  // a>>temp b>>a temp>>b
    for(size_t i = 0; i < this->cols; i++) {
      temp = this->at(a,i);
      put(this->at(b,i),a,i);
      put(temp,b,i);
    }
  }

  Matrix<T> gauss() const {
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

  T diag() const {
    size_t n = (this->cols < this->rows) ? cols : rows;
    T res{1};
      for(size_t i = 0; i < n; i++) {
        res *= this->at(i,i);
      }
      if(this->inverted) {
        return -res;
      } else return res;
  }

private:
  const size_t rows;
  const size_t cols;
  std::vector<T> elements;
  bool inverted{0};
};


//
//   a  b  c
//   d  e  f
//   g  h  i
//
//   d - a*(d/a)









//
