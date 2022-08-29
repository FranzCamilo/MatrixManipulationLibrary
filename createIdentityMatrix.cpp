/*
Create an identity matrix with dimensions numRows x numRows.
*/

#include "MyMatrixLib.h"

Matrix *createIdentityMatrix(int numRows)
{
	int numCols;
	Matrix *matrix;
	
	numCols = numRows;	
	matrix = createNullMatrix(numRows,numCols);
	
	
	for(int i=0 ; i < numRows; i++)
	{
		matrix->entry[i][i] = 1;
	}
	
	return matrix;
}