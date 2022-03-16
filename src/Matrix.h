//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H

#include "iostream"
#include "Operation.h"

class Matrix {

    unsigned int n, m, modulo;
    unsigned int** data;

    Matrix(unsigned int n, unsigned int m, unsigned int modulo, bool initRandom);

    unsigned int getValueOrZero(unsigned i, unsigned j) const;

public:

   friend std::ostream& operator<<(std::ostream& os, const Matrix& dt);
   friend std::ostream& operator<<(std::ostream& os, Matrix* dt);

   Matrix();
   Matrix(unsigned n, unsigned m, unsigned modulo);
   Matrix(const Matrix& other);
   virtual ~Matrix();

   Matrix& operator= (const Matrix& other);


   Matrix add(const Matrix& other);
   Matrix addByValue(const Matrix& other);
   Matrix* addByPtr(const Matrix& other);

   Matrix sub(const Matrix& other);
   Matrix subByValue(const Matrix& other);
   Matrix* subByPtr(const Matrix& other);

   Matrix mult(const Matrix& other);
   Matrix multByValue(const Matrix& other);
   Matrix* multByPtr(const Matrix& other);

   Matrix operation(const Matrix& other, const Operation& op) const;
   void setValue(unsigned i, unsigned j, unsigned value);
};


#endif //POA_L1_MATRIX_H
