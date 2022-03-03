//
// Created by NelsonWork on 24.02.2022.
//

#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "project is working" << endl;

    matrix* m = new matrix(30, 10, 10);


    cout << "test operator : " << endl << m;

    matrix c(*m);

    cout << "test constructor copy : " << endl << c;
    delete m;
}