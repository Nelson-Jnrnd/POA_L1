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

matrix::matrix(unsigned int n, unsigned int m, unsigned int modulo, bool initRandom) {

    this->n = n;
    this->m = m;
    this->modulo = modulo;
    this->data = new unsigned* [m];

    for (int i = 0; i < m; ++i) {
        this->data[i] = new unsigned [n];
    }
    if(initRandom) {
        for (int i = 0; i < this->m; ++i) {
            for (int j = 0; j < this->n; ++j) {
                this->data[i][j] = rand() % this->modulo;
            }
        }
    }
}
// TODO check les paramètres !
matrix::matrix(unsigned int n, unsigned int m, unsigned int modulo) : matrix(n, m, modulo, true) {

}


matrix::matrix(const matrix &other) : matrix(other.n, other.m, other.modulo, false){
    std::cout << "copy matrix" << std::endl << other;
    // TODO factoriser les constructeurs
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }
    //std::copy(&other.data[0][0], &other.data[0][0] + other.n * other.m, &this->data[0][0]); TODO ça pourrait être mieux mais ça bug jsp pk
}


matrix::~matrix() {
    for (int i = 0; i < m; ++i) {
        delete this->data[i];
    }
    delete[] this->data;
}

std::ostream &operator<<(std::ostream &os, const matrix &dt) {
    for (int i = 0; i < dt.m; ++i) {
        for (int j = 0; j < dt.n; ++j) {
            os << dt.data[i][j];
            if(j + 1 < dt.n)
                os << " ";
        }
        os << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, matrix* dt) {
    os << *dt;
    return os;
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

matrix matrix::operator+=(matrix &a) {
   *this = *this + a;
   return *this;
}

matrix matrix::operator-=(matrix &a) {
   *this = *this - a;
   return *this;
}


matrix &matrix::operator=(const matrix &other) {
    return operator=(&other);
}

matrix &matrix::operator=(const matrix *other) {

    if(other != this){
        // We use a temporary variable to not leave the object in a broken state
        // in case the allocation throws an exception.
        unsigned ** tmpData = new unsigned* [other->m];
        for (int i = 0; i < other->m; ++i) {
            tmpData[i] = new unsigned [other->n];
        }
        this->n = other->n;
        this->m = other->m;
        this->modulo = other->modulo;

        delete this->data;
        this->data = tmpData;

        for (int i = 0; i < this->m; ++i) {
            for (int j = 0; j < this->n; ++j) {
                this->data[i][j] = other->data[i][j];
            }
        }
    }

    return *this;
}

matrix matrix::multiply(const matrix &) {
    return matrix(0, 0, 0);
}

matrix matrix::operator-(const matrix &a) {
   return matrix();
}

matrix matrix::operation(const matrix &other, Operation op) {
   if(other.modulo != this->modulo)
      throw std::runtime_error("Error : Not the same modulus");

   matrix* res = new matrix(std::max(this->n, other.n),std::max(this->m, other.m), this->modulo, false);

   for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {

         res->data[i][j] = op.calculate(this->getValueOrZero(i,j), other.getValueOrZero(i,j));//TODO unsigned partout
      }
   }

   return *res;
}

unsigned int matrix::getValueOrZero(int i, int j) const {
   return i < this->n && j < this->m ? this->data[i][j] : 0;
}


