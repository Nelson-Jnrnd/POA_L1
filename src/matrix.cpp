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
    this->data = new unsigned* [m];

    for (int i = 0; i < m; ++i) {
        this->data[i] = new unsigned [n];
    }
    fillWithRandomData();
}

void matrix::fillWithRandomData() {
    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            this->data[i][j] = rand() % this->modulo;
        }
    }
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

matrix::~matrix() {
    delete[] this->data;
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

matrix::matrix(const matrix &other) {
    std::cout << "copy matrix" << std::endl << other;
    // TODO factoriser les constructeurs
    this->n = other.n;
    this->m = other.m;
    this->modulo = other.modulo;
    this->data = new unsigned* [this->m];

    for (int i = 0; i < this->m; ++i) {
        this->data[i] = new unsigned [this->n];
    }

    for (int i = 0; i < this->m; ++i) {
        for (int j = 0; j < this->n; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }
    //std::copy(&other.data[0][0], &other.data[0][0] + other.n * other.m, &this->data[0][0]); TODO ça pourrait être mieux mais ça bug jsp pk
}

matrix &matrix::operator=(const matrix &other) {
    if(&other != this){
        delete this->data;

        std::cout << "operator = matrix" << std::endl << other;
        // TODO factoriser les constructeurs
        this->n = other.n;
        this->m = other.m;
        this->modulo = other.modulo;
        this->data = new unsigned* [this->m];

        for (int i = 0; i < this->m; ++i) {
            this->data[i] = new unsigned [this->n];
        }

        for (int i = 0; i < this->m; ++i) {
            for (int j = 0; j < this->n; ++j) {
                this->data[i][j] = other.data[i][j];
            }
        }
    }

    return *this;
}

matrix &matrix::operator=(const matrix *other) {
    if(other != this){
        delete this->data;

        std::cout << "operator = matrix" << std::endl << other;
        // TODO factoriser les constructeurs
        this->n = other->n;
        this->m = other->m;
        this->modulo = other->modulo;
        this->data = new unsigned* [this->m];

        for (int i = 0; i < this->m; ++i) {
            this->data[i] = new unsigned [this->n];
        }

        for (int i = 0; i < this->m; ++i) {
            for (int j = 0; j < this->n; ++j) {
                this->data[i][j] = other->data[i][j];
            }
        }
    }

    return *this;
}
