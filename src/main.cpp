#include <iostream>
#include "Matrix.h"
using std::cout;
using std::endl;

int main() {
    cout << "Test initialisation" << endl;

    Matrix* m1 = new Matrix(3, 3, 10);

    Matrix* m2 = new Matrix(3, 3, 10);

    Matrix* m3 = new Matrix(5,5,10);

    Matrix* m4 = new Matrix(3,3,6);

    cout << "m1 : " << endl << m1 << endl;
    cout << "m2 : " << endl << m2 << endl;
    cout << "m3 : " << endl << m3 << endl;
    cout << "m4 : " << endl << m4 << endl;

    cout << "test constructor copy : " << endl;
    Matrix c(*m1);
    cout << "c : " << endl << c << endl;

    cout << "test operator = : " << endl;
    Matrix d = *m2;
    cout << "d : " << endl << d << endl;

    cout << "test operator : " << endl;

    cout << "ADD with same modulus and size : " << endl;
    cout << "Inline : " << endl;
    m1->add(*m2);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->addByValue(*m2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = m1->addByPtr(*m2);
    cout << "d : " << endl << d << endl;

    cout << "ADD with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    m1->add(*m3);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->addByValue(*m3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = m1->addByPtr(*m3);
    cout << "d : " << endl << d << endl;

    /*cout << "ADD with different modulus : " << endl;
    cout << "Inline : " << endl;
    m1->add(*m4);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->addByValue(*m4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = m1->addByPtr(*m4);
    cout << "d : " << endl << d << endl;*/

    cout << "SUB with same modulus and size : " << endl;
    cout << "Inline : " << endl;
    m1->sub(*m2);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->subByValue(*m2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = m1->subByPtr(*m2);
    cout << "d : " << endl << d << endl;

    cout << "SUB with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    m1->sub(*m3);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->subByValue(*m3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = m1->subByPtr(*m3);
    cout << "d : " << endl << d << endl;

    /*cout << "SUB with different modulus : " << endl;
    cout << "Inline : " << endl;
    m1->sub(*m4);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->subByValue(*m4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = m1->subByPtr(*m4);
    cout << "d : " << endl << d << endl;*/

    cout << "MULTIPLY with same modulus and size : " << endl;
    cout << "Inline : " << endl;
    m1->mult(*m2);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->multByValue(*m2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = m1->multByPtr(*m2);
    cout << "d : " << endl << d << endl;

    cout << "MULTIPLY with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    m1->mult(*m3);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->multByValue(*m3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = m1->multByPtr(*m3);
    cout << "d : " << endl << d << endl;

    /*cout << "MULTIPLY with different modulus : " << endl;
    cout << "Inline : " << endl;
    m1->mult(*m4);
    cout << "m1 : " << endl << m1 << endl;
    m1 = &c;
    cout << "by value : " << endl;
    d = m1->multByValue(*m4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = m1->multByPtr(*m4);
    cout << "d : " << endl << d << endl;*/

    delete m1;
    delete m2;
    delete m3;
    delete m4;

    return 0;
}