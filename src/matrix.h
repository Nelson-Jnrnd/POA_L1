//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H

#include "iostream"
#include "Operation.h"

class matrix {

    unsigned int n, m, modulo;
    unsigned int** data;

    matrix(unsigned int n, unsigned int m, unsigned int modulo, bool initRandom);

    unsigned int getValueOrZero(int i, int j) const;

public:

    friend std::ostream& operator<<(std::ostream& os, const matrix& dt);
   friend std::ostream& operator<<(std::ostream& os, matrix* dt);

   matrix();
   matrix(unsigned n, unsigned m, unsigned modulo);
   matrix(const matrix& other);

   matrix operator+(const matrix& a);
   matrix operator-(const matrix& a);
    matrix operator*(const matrix& a);

   matrix operator+=(matrix& a);
   matrix operator-=(matrix& a);
    matrix operator*=(matrix& a);
   
    matrix& operator= (const matrix& other);
    matrix& operator= (const matrix* other);

    virtual ~matrix();

    matrix operation(const matrix& other, const Operation& op);
};


#endif //POA_L1_MATRIX_H
