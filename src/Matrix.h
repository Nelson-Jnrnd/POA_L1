//
// Created by NelsonWork on 24.02.2022.
//

#ifndef POA_L1_MATRIX_H
#define POA_L1_MATRIX_H

#include "iostream"
#include "Operation.h"

class Matrix {

    /**
     * the number of rows in the matrix
     */
    unsigned int n;
    /**
     * the number of rows in the matrix
     */
    unsigned int m;
    /**
     * Modulo for the numbers contained in the matrix
     */
    unsigned int modulo;
    /**
     * Array containing the numbers of the matrix
     */
    unsigned int** data;

    /**
     * Create a matrix with n rows and m columns
     * 
     * @param n the number of rows in the matrix
     * @param m the number of rows in the matrix
     * @param modulo the modulo for the numbers contained in the matrix
     * @param initRandom if true, the matrix will be initialized with random values.
     */
    Matrix(unsigned int n, unsigned int m, unsigned int modulo, bool initRandom);

    /**
     * If the indices are valid, return the value at the specified indices. Otherwise, return 0
     *
     * @param i The row of the matrix.
     * @param j The column index.
     * @return The value of the element at position (i, j) or zero if the position is out of bounds.
     */
    unsigned int getValueOrZero(unsigned i, unsigned j) const;

public:

    friend std::ostream& operator<<(std::ostream& os, const Matrix& dt);
    friend std::ostream& operator<<(std::ostream& os, Matrix* dt);

    Matrix& operator= (const Matrix& other);
    Matrix& operator= (const Matrix *other);

    Matrix();

    /**
      * Create a matrix with n rows and m columns
      *
      * @param n the number of rows in the matrix
      * @param m the number of rows in the matrix
      * @param modulo the modulo for the numbers contained in the matrix
      */
    Matrix(unsigned n, unsigned m, unsigned modulo);
    /**
     * The function creates a new matrix with the same dimensions as the other matrix and copies the values
     * from the other matrix into the new matrix
     *
     * @param other the matrix to copy
     */
    Matrix(const Matrix& other);

    virtual ~Matrix();

    /**
     * This function adds the values of the two matrices and returns the result
     *
     * @param other The matrix to add to this one.
     * @return a reference to this object
     */
    Matrix add(const Matrix& other);
    /**
     * Add two matrices together by value
     *
     * @param other The matrix to add to the current matrix.
     * @return The result of the addition operation.
     */
    Matrix addByValue(const Matrix& other) const;
    /**
     * This function adds two matrices together and returns a pointer to the resulting matrix
     * The resulting matrix is created dynamically
     *
     * @param other the other matrix to be added to this matrix.
     * @return A new Matrix object.
     */
    Matrix* addByPtr(const Matrix& other) const;

    /**
     * Subtracts the other matrix from this matrix
     *
     * @param other The matrix to subtract from this matrix.
     * @return a reference to this object.
     */
    Matrix sub(const Matrix& other);
    /**
     * Subtracts the values of the other matrix from the values of this matrix
     *
     * @param other The matrix to subtract from this matrix.
     * @return The result of the subtraction operation.
     */
    Matrix subByValue(const Matrix& other) const;
    /**
     * This function subtracts the values of the other matrix from the values of this matrix and returns a
     * new dynamically allocated matrix
     *
     * @param other the matrix to subtract from this matrix
     * @return A new Matrix object.
     */
    Matrix* subByPtr(const Matrix& other) const;

    /**
     * Multiply the matrix by another matrix
     *
     * @param other The matrix to subtract from this matrix.
     * @return a reference to this object.
     */
    Matrix mult(const Matrix& other);
    /**
      * Multiply the matrix by a another matrix
      *
      * @param other The matrix to multiply by.
      * @return The result of the multiplication.
      */
    Matrix multByValue(const Matrix& other) const;
    /**
      * Multiply the matrix by another matrix
      *
      * @param other the matrix to multiply by
      * @return A pointer to a new Matrix object.
      */
    Matrix* multByPtr(const Matrix& other) const;

    /**
     * Given two matrices, this function returns the result of the operation between the two matrices
     *
     * @param other the matrix to be added
     * @param op the operation to perform
     * @return A new Matrix object.
     */
    Matrix operation(const Matrix& other, const Operation& op) const;
    /**
     * Set the value of the element at row i and column j to value
     *
     * @param i The row of the matrix.
     * @param j The column index of the value to be set.
     * @param value the value to be set
     */
    void setValue(unsigned i, unsigned j, unsigned value);
};


#endif //POA_L1_MATRIX_H
