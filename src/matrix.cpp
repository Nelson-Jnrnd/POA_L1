//
// Created by NelsonWork on 24.02.2022.
//

#include "matrix.h"
#include <cstdlib>
#include "iostream"

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
