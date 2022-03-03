//
// Created by NelsonWork on 24.02.2022.
//

#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "project is working" << endl;

    matrix* m = new matrix(3, 5, 10);


    cout << "test operator : " << endl << m;
    delete m;
}