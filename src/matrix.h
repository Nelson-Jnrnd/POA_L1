//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H


class matrix {
public:

   matrix(unsigned n, unsigned m, unsigned modulo);


private:
    unsigned n, m, modulo;
    unsigned** data;

    void fillWithRandomData();

    void print();
};


#endif //POA_L1_MATRIX_H
