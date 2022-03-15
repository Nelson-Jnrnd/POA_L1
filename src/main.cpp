//
// Created by NelsonWork on 24.02.2022.
//

#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "project is working" << endl;


    matrix* m = new matrix(5, 5, 10);

    matrix* p = new matrix(5, 5, 10);

    cout << "test operator : " << endl << m;

    matrix c(*m);

    cout << "test constructor copy : " << endl << c;


    cout << "m : " << endl << m;
    cout << "p : " << endl << p;
    *m = *p;

    cout << "test = operator copy : " << endl << m;


    cout << "m : " << endl << m;
    cout << "p : " << endl << p;

    cout << "test + operator : " << endl;

    cout << "m + p " << endl << *m + *p;

    cout << "test - operator : " << endl;

    cout << "m - p " << endl << *m - *p;

    cout << "test * operator : " << endl;

    cout << "m * p " << endl << *m * *p;



    delete m;
    delete p;

}