//
// Created by NelsonWork on 24.02.2022.
//

#include "matrix.h"

matrix::matrix(unsigned int n, unsigned int m, unsigned int modulo) {
    data = new unsigned* [n];

    for (int i = 0; i < n; ++i) {
        data[i] = new unsigned [m];
    }
}

void matrix::fillWithRandomData() {
    for (int i = 0; i < n; ++i) {

    }
}
