//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H


class matrix {
public:

   matrix();
   matrix(unsigned n, unsigned m, unsigned modulo);
   matrix operator+(const matrix& a);
   matrix operator-(const matrix& a);

   matrix operator+=(matrix& a);
   matrix operator-=(matrix& a);

private:
    unsigned n{}, m{}, modulo{};
    unsigned** data{};

    void fillWithRandomData();
    matrix checkMatrixes(const matrix& a, const matrix& b);
    void print();

};


#endif //POA_L1_MATRIX_H
