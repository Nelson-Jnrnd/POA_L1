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


    matrix(unsigned n, unsigned m, unsigned modulo);

    matrix(const matrix& other);

    virtual ~matrix();
private:
    unsigned n, m, modulo;
    unsigned** data;

    void fillWithRandomData();
};


#endif //POA_L1_MATRIX_H
