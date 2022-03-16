#include <iostream>
#include "Matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "Test initialisation" << endl;

    Matrix* m1 = new Matrix(5, 5, 10);

    Matrix* m2 = new Matrix(5, 5, 10);

    Matrix* m3 = new Matrix(3,3,10);

    Matrix* m4 = new Matrix(3,3,6);

    cout << "m1 : " << endl << m1 << endl;
    cout << "m2 : " << endl << m2 << endl;
    cout << "m3 : " << endl << m3 << endl;
    cout << "m4 : " << endl << m4 << endl;

    cout << "test constructor copy : " << endl;
    Matrix c(*m1);
    cout << "c : " << endl << c << endl;

    cout << "test operator= : " << endl;
    c = *m2;
    cout << "c : " << endl << c << endl;

    cout << "test operator : " << endl;

    cout << "ADD with same modulus : " << endl;
    cout << "Inline : " << endl;
    m1->add(*m2);
    cout << "m1 : " << endl << m1 << endl;
    cout << "by value : " << endl;
    c = m1->addByValue(*m2);
    cout << "c : " << endl << c << endl;
    cout << "by pointer : " << endl;
    c = m1->addByPtr(*m2);
    cout << "c : " << endl << c << endl;
    
    delete m1;
    delete m2;
    delete m3;
    delete m4;
}