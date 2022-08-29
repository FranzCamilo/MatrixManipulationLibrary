/*
Create a matrix dynamically allocated with dimension
numRows x numCols in struct form "Matrix".
*/

#include "MyMatrixLib.h"
#include <stdlib.h>

Matrix *createNullMatrix(int numRows, int numCols)
{
	double **newMatrixEntry;
	Matrix *newMatrix;

	//---------------------------	
	newMatrixEntry = (double **) malloc(numRows*sizeof(double *));
	
	for(int i=0; i < numRows; i++)
	{
		newMatrixEntry[i] = (double *) malloc(numCols*sizeof(double));
	}
	//---------------------------
	
	for(int i=0; i < numRows ; i++)
	{
		for(int j=0 ;j < numCols; j++)
		{
			newMatrixEntry[i][j] = 0;
		}
	}
	//-----------------------------
	
	newMatrix = (Matrix *) malloc(sizeof(Matrix));
	
	newMatrix->numRows = numRows;
	newMatrix->numColumns = numCols;
	newMatrix->entry = newMatrixEntry;
		
	return newMatrix;
}
