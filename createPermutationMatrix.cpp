/*
Create a permutation matrix, which is an identity matrix of
dimensions numRows x numRows with rowA and rowB switched.

By myltiplying this permutation matrix, one can switch
any row or column of any other matrix, regarding matrix
multiplication rules and if this permutation matrix comes first 
or last in the multiplication.

If permutation matrix comes first in the multiplication 
-> exchange rows;

If permutation matrix comes last in the multiplication 
-> exchange columns.

OBS: The indexes for rowA and rowB start from zero, as any
other indexes in C++.
*/

#include "MyMatrixLib.h"

Matrix *createPermutationMatrix(int numRows, int rowA, int rowB)
{
	int numCols = numRows;
	Matrix *permutationMatrix = createNullMatrix(numRows,numCols);
	
	permutationMatrix->entry[rowA][rowB] = 1;
	permutationMatrix->entry[rowB][rowA] = 1;
	
	for(int i=0; i < numRows; i++)
	{
		if(i != rowA && i != rowB)
			permutationMatrix->entry[i][i] = 1;
	}
	
	return permutationMatrix;
}