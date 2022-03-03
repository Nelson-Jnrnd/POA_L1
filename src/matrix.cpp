//
// Created by NelsonWork on 24.02.2022.
//

#include "matrix.h"
#include <cstdlib>
#include "iostream"

matrix::matrix() {
   this->n = 0;
   this->m = 0;
   this->modulo = 0;
   this->data = nullptr;
}

matrix::matrix(unsigned int n, unsigned int m, unsigned int modulo) {
    this->n = n;
    this->m = m;
    this->modulo = modulo;
    this->data = new unsigned* [n];

    for (int i = 0; i < n; ++i) {
        this->data[i] = new unsigned [m];
    }
    fillWithRandomData();
    print();
}

void matrix::fillWithRandomData() {
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->m; ++j) {
            this->data[i][j] = rand() % this->modulo;
        }
    }
}

// for debug purposes... TODO : remove
void matrix::print(){
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->m; ++j) {
            std::cout << this->data[i][j];
        }
    }
}

matrix matrix::operator+(const matrix& a) {
   auto* result = new matrix(a.n, a.m, a.modulo);
   for(unsigned i = 0; i < result->n; ++i){
      for (unsigned j = 0; j < result->m; ++j) {
         result->data[i][j] = (this->data[i][j] + a.data[i][j]) % result->modulo;
      }
   }
   return *(result);
}

matrix matrix::operator-(const matrix& a) {
   if (this->modulo != a.modulo)
      throw std::invalid_argument("Les deux matrices n'ont pas le même modulo");
   matrix* result = new matrix(a.n, a.m, a.modulo);
   for(unsigned i = 0; i < result->n; ++i){
      for (unsigned j = 0; j < result->m; ++j) {
         result->data[i][j] = (this->data[i][j] - a.data[i][j]) % result->modulo;
      }
   }
   return *(result);
}

matrix matrix::operator+=(matrix &a) {
   *this = *this + a;
   return *this;
}

matrix matrix::operator-=(matrix &a) {
   *this = *this - a;
   return *this;
}

matrix matrix::checkMatrixes(const matrix &a, const matrix &b) {
   unsigned newN = std::max(a.n, b.n);
   unsigned newM = std::max(a.m, b.m);
   unsigned newMod = std::max(a.modulo, b.modulo);


}








