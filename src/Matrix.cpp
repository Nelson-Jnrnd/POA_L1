#include "Matrix.h"
#include "iostream"
#include "Add.h"
#include "Sub.h"
#include "Multiply.h"
#include "Random.h"


const static Add ADD = Add();
const static Sub SUB = Sub();
const static Multiply MUL = Multiply();

Matrix::Matrix() {
    this->n = 0;
    this->m = 0;
    this->modulo = 0;
    this->data = nullptr;
}


Matrix::Matrix(unsigned int n, unsigned int m, unsigned int modulo, bool initRandom) {
    Random* rand = Random::getInstance();
    this->n = n;
    this->m = m;
    this->modulo = modulo;
    this->data = new unsigned* [m];

    for (int i = 0; i < m; ++i) {
        this->data[i] = new unsigned [n];
    }
    if(initRandom) {
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->m; ++j) {
                this->data[i][j] = rand->getRandom(this->modulo) % this->modulo ;
            }
        }
    }
}

Matrix::Matrix(unsigned int n, unsigned int m, unsigned int modulo) : Matrix(n, m, modulo, true) {}

Matrix::Matrix(const Matrix &other) : Matrix(other.n, other.m, other.modulo, false){
    std::cout << "copy Matrix" << std::endl;
    for (unsigned i = 0; i < this->m; ++i) {
        for (unsigned j = 0; j < this->n; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }
}


/**
 * Deletes the dynamically allocated memory for the data member
 */
Matrix::~Matrix() {
    deleteValues();
}

void Matrix::deleteValues(){
    for (int i = 0; i < m; ++i) {
        delete[] this->data[i];
    }
    delete[] this->data;
}

std::ostream &operator<<(std::ostream &os, const Matrix &dt) {
    for (int i = 0; i < dt.m; ++i) {
        for (int j = 0; j < dt.n; ++j) {
            os << dt.data[i][j];
            if(j + 1 < dt.n)
                os << " ";
        }
        os << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, Matrix* dt) {
    os << *dt;
    return os;
}

Matrix &Matrix::operator=(const Matrix &other){
    return operator=(&other);
}

Matrix & Matrix::operator=(const Matrix *other) {

    if(other != this){
        // We use a temporary variable to not leave the object in a broken state
        // in case the allocation throws an exception.
        unsigned** tmpData = new unsigned* [other->n];
        for (int i = 0; i < other->n; ++i) {
            tmpData[i] = new unsigned [other->m];
        }

        deleteValues();

        this->n = other->n;
        this->m = other->m;
        this->modulo = other->modulo;


        this->data = tmpData;
        for (int i = 0; i < this->n; ++i) {
            for (int j = 0; j < this->m; ++j) {
                this->data[i][j] = other->data[i][j];
            }
        }
    }

    return *this;
}


unsigned int Matrix::getValueOrZero(unsigned i, unsigned j) const {
    return i < this->n && j < this->m ? this->data[i][j] : 0;
}

Matrix& Matrix::operation(const Matrix &other, const Operation &op) {
    if(other.modulo != this->modulo)
        throw std::invalid_argument("Error : Not the same modulus");
    
    unsigned newN = std::max(this->n, other.n);
    unsigned newM = std::max(this->m, other.m);

    unsigned** tmpData = new unsigned* [newN];
    for (int i = 0; i < newN; ++i) {
        tmpData[i] = new unsigned [newM];
    }

    for (unsigned i = 0; i < newM; ++i) {
        for (unsigned j = 0; j < newN; ++j) {
            tmpData[i][j] = op.calculate(this->getValueOrZero(i,j), other.getValueOrZero(i,j)) % modulo; //TODO unsigned partout
        }
    }

    this->n = newN;
    this->m = newM;

    deleteValues();
    this->data = tmpData;
    return *this;
}


Matrix *Matrix::operationByPtr(const Matrix &other, const Operation &op) const {
    if(other.modulo != this->modulo)
        throw std::invalid_argument("Error : Not the same modulus");

    Matrix* res = new Matrix(std::max(this->n, other.n), std::max(this->m, other.m), this->modulo, false);

    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {

            res->setValue(i, j, op.calculate(this->getValueOrZero(i,j), other.getValueOrZero(i,j)));
        }
    }

    return res;
}

Matrix Matrix::operationByValue(const Matrix &other, const Operation &op) const {
    return *operationByPtr(other, op);
}

void Matrix::setValue(unsigned int i, unsigned int j, unsigned int value) {
    if(i >= n || j >= m)
        throw std::runtime_error("Error out of bounds");

    data[i][j] = value % modulo;
}

Matrix& Matrix::add(const Matrix &other) {
    return this->operation(other, ADD);
}

Matrix Matrix::addByValue(const Matrix &other) const {
    return this->operationByValue(other, ADD);
}

Matrix *Matrix::addByPtr(const Matrix &other) const {
    return this->operationByPtr(other, ADD);
}

Matrix& Matrix::sub(const Matrix &other) {
    return this->operation(other, SUB);
}

Matrix Matrix::subByValue(const Matrix &other) const {
    return this->operationByValue(other, SUB);
}

Matrix *Matrix::subByPtr(const Matrix &other) const {
    return this->operationByPtr(other, SUB);
}

Matrix& Matrix::mult(const Matrix &other) {
    return this->operation(other, SUB);
}

Matrix Matrix::multByValue(const Matrix &other) const {
    return this->operationByValue(other, MUL);
}

Matrix *Matrix::multByPtr(const Matrix &other) const {
    return this->operationByPtr(other, MUL);
}
