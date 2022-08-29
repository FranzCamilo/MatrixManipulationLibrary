/*
Library for matrix manipulation and linear algebra methods.
*/
#ifndef _MYMATRIXLIB_H_
#define _MYMATRIXLIB_H_

#include <iostream>
#include <string>
using namespace std;


typedef struct
{
	   int numRows;
	   int numColumns;	
	   double **entry;
	   	
} Matrix;


int *countMatrixRowsColsInFile(string fileName);

Matrix *getMatrixFromFile(string fileName);
Matrix *createNullMatrix(int numRows, int numCols);
Matrix *createNullSingleElementMatrix();
Matrix *createIdentityMatrix(int numRows);
Matrix *createPermutationMatrix(int numRows, int rowA, int rowB);
Matrix *createCyclicalPermutationMatrix(int numRows);
Matrix *createEliminationMatrix(int targetMatrixNumRows, int targetEntryRow, int targetEntryCol, double targetEntryPivot, double targetEntry);

Matrix *multiplyMatrices(Matrix *matrix1, Matrix *matrix2);
Matrix *solveLinearEquationSystem(Matrix *eqSystemAugmentedMatrixAb);
Matrix *applyBackSubstitution(Matrix* reducedSystemMatrix);

void displayMatrix(Matrix *matrix);
void displayLinearEqSystem(Matrix *eqSystemAugmentedMatrixAb);
void testSolveLinearEquationSystemFunction();

#endif