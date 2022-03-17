#include <iostream>
#include <sstream>
#include "Matrix.h"
using std::cout;
using std::endl;

/**
 * Test the matrix class
 * 
 * @param n1 number of rows of the first matrix
 * @param m1 the number of columns of the first matrix
 * @param n2 number of rows of the second matrix
 * @param m2 the number of columns of the second matrix
 * @param n the modulo of the matrix
 */
void testMatrix(unsigned n1, unsigned m1, unsigned n2, unsigned m2, unsigned n){
    cout << "Test initialisation" << endl;

    Matrix* matrix1 = new Matrix(n1, m1, n);

    Matrix* matrix2 = new Matrix(n2, m2, n);

    Matrix* matrix3 = new Matrix(n1+1, m1+1, n);

    Matrix* matrix4 = new Matrix(n1, m1, n+1);

    cout << "matrix1 : " << endl << matrix1 << endl;
    cout << "matrix2 : " << endl << matrix2 << endl;
    cout << "matrix3 : " << endl << matrix3 << endl;
    cout << "matrix4 : " << endl << matrix4 << endl;

    cout << "test constructor copy : " << endl;
    Matrix c(*matrix1);
    cout << "c : " << endl << c << endl;

    cout << "test operator = : " << endl;
    Matrix d = *matrix2;
    cout << "d : " << endl << d << endl;

    cout << "test operator : " << endl;

    cout << "ADD with same modulus and size : " << endl;
    cout << "Inline : " << endl;

    matrix1->add(*matrix2);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->addByValue(*matrix2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = matrix1->addByPtr(*matrix2);
    cout << "d : " << endl << d << endl;

    cout << "ADD with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    matrix1->add(*matrix3);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->addByValue(*matrix3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = matrix1->addByPtr(*matrix3);
    cout << "d : " << endl << d << endl;

    /*cout << "ADD with different modulus : " << endl;
    cout << "Inline : " << endl;
    matrix1->add(*matrix4);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->addByValue(*matrix4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = matrix1->addByPtr(*matrix4);
    cout << "d : " << endl << d << endl;*/

    cout << "SUB with same modulus and size : " << endl;
    cout << "Inline : " << endl;
    matrix1->sub(*matrix2);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->subByValue(*matrix2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = matrix1->subByPtr(*matrix2);
    cout << "d : " << endl << d << endl;

    cout << "SUB with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    matrix1->sub(*matrix3);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->subByValue(*matrix3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = matrix1->subByPtr(*matrix3);
    cout << "d : " << endl << d << endl;

    /*cout << "SUB with different modulus : " << endl;
    cout << "Inline : " << endl;
    matrix1->sub(*matrix4);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->subByValue(*matrix4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = matrix1->subByPtr(*matrix4);
    cout << "d : " << endl << d << endl;*/

    cout << "MULTIPLY with same modulus and size : " << endl;
    cout << "Inline : " << endl;
    matrix1->mult(*matrix2);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->multByValue(*matrix2);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = matrix1->multByPtr(*matrix2);
    cout << "d : " << endl << d << endl;

    cout << "MULTIPLY with same modulus and different size : " << endl;
    cout << "Inline : " << endl;
    matrix1->mult(*matrix3);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->multByValue(*matrix3);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    d = matrix1->multByPtr(*matrix3);
    cout << "d : " << endl << d << endl;

    /*cout << "MULTIPLY with different modulus : " << endl;
    cout << "Inline : " << endl;
    matrix1->mult(*matrix4);
    cout << "matrix1 : " << endl << matrix1 << endl;
    matrix1 = &c;
    cout << "by value : " << endl;
    d = matrix1->multByValue(*matrix4);
    cout << "d : " << endl << d << endl;
    cout << "by pointer : " << endl;
    c = matrix1->multByPtr(*matrix4);
    cout << "d : " << endl << d << endl;*/

    delete matrix1;
    delete matrix2;
    delete matrix3;
    delete matrix4;
}

int main(int argc, char* argv[]) {

    if(argc != 6){
        std::cerr << "Usage: " << argv[0] << " N1 M1 N2 M2 N" << std::endl;
        return 1;
    }

    std::istringstream issn1(argv[1]), issm1(argv[2]), issn2(argv[3]), issm2(argv[4]), issn(argv[5]);
    unsigned n1, m1, n2, m2, n;

    if(issn1 >> n1 and issm1 >> m1 and issn2 >> n2 and issm2 >> m2 and issn >> n) {
        testMatrix(n1, m1, n2, m2, n);
        return 0;
    }
    std::cerr << "Error: " << argv[0] << " Arguments are not integers" << std::endl;
    return 1;
}