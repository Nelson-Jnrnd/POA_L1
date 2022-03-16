#include <iostream>
#include "Matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "project is working" << endl;


    Matrix* m = new Matrix(5, 5, 10);

    Matrix* p = new Matrix(5, 5, 10);

    cout << "test operator : " << endl << m;
   m->add(*p);
    Matrix c(*m);

    cout << "test constructor copy : " << endl << c;


    cout << "m : " << endl << m;
    cout << "p : " << endl << p;
    *m = *p;

    cout << "test = operator copy : " << endl << m;


    cout << "m : " << endl << m;
    cout << "p : " << endl << p;

    cout << "test + operator : " << endl;

    cout << "m + p " << endl << (*m + *p);

    cout << "test - operator : " << endl;

    cout << "m - p " << endl << (*m - *p);

    cout << "test * operator : " << endl;

    cout << "m * p " << endl << (*m * *p);

    Matrix a(5, 5, 5), b(5, 5, 5), d(5, 5, 5);

    //(a + b) = d;

    delete m;
    delete p;

}