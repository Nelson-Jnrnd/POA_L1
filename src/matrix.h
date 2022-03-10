//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H

#include "iostream"

class matrix {

public:
    friend std::ostream& operator<<(std::ostream& os, const matrix& dt);
    friend std::ostream& operator<<(std::ostream& os, matrix* dt);



   matrix();
   matrix(unsigned n, unsigned m, unsigned modulo);
   matrix(const matrix& other);

   matrix operator+(const matrix& a);
   matrix operator-(const matrix& a);

   matrix operator+=(matrix& a);
   matrix operator-=(matrix& a);



    matrix& operator= (const matrix& other);
    matrix& operator= (const matrix* other);

    virtual ~matrix();
private:
    unsigned n{}, m{}, modulo{};
    unsigned** data{};

    void fillWithRandomData();

    matrix checkMatrixes(const matrix& a, const matrix& b);
    void print();

};


#endif //POA_L1_MATRIX_H
