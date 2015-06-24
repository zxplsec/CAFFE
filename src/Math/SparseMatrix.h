/**
 * @file    SparseMatrix.h
 * @author  Adam O'Brien <obrienadam89@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Contains the interface for class SparseMatrix, which is for sparse
 * storage of large linear systems. This class is built using the Petsc
 * library.
 */

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <petsc.h>

#include "SparseVector.h"
#include "Input.h"

class SparseMatrix
{
private:

    Mat A_;
    KSP ksp_;
    PC pc_;

    int maxIters_;
    double rToler_, absToler_;
    PetscErrorCode errorCode_;

public:

    SparseMatrix();
    SparseMatrix(int m, int n, int nnz);
    ~SparseMatrix();

    void allocate(int m, int n, int nnz);
    void setValue(int i, int j, double value, InsertMode insertMode = INSERT_VALUES);

    int solve(const SparseVector &b, SparseVector& x);

    void print();
};

#endif
