/*
This function creates a modified identity matrix that is used
to cyclically exchange rows or columns of another matrix
by multiplying it.

If permutation matrix comes first in the multiplication 
-> cyclically exchange rows;

If permutation matrix comes last in the multiplication 
-> cyclically exchange columns.

Example for a 4x4 cyclical permutation matrix:
0	1	0	0
0	0	1	0
0	0	0	1
1	0	0	0

*/

#include "MyMatrixLib.h"

Matrix *createCyclicalPermutationMatrix(int numRows)
{
	int numColumns = numRows;
	Matrix *cyclicalPermutationMatrix = createNullMatrix(numRows,numColumns);
	
	cyclicalPermutationMatrix->entry[numRows-1][0] = 1;
	
	for(int i = 0; i < numRows-1; i++)
		cyclicalPermutationMatrix->entry[i][i+1] = 1;
	
	return cyclicalPermutationMatrix;	
} 