/*
This function multiplies two matrices.

OBS: Accoding to mathematical rules, the number of columns
of the first matrix must have the same number of rows of the
second one.
*/

#include <iostream>
#include "MyMatrixLib.h"

using namespace std;

Matrix *multiplyMatrices(Matrix *matrix1, Matrix *matrix2)
{
	if( matrix1->numColumns != matrix2->numRows )
	{
		cout << "The number of columns of the first matrix and rows of second one must be the same."<<endl;
		cout << "Try again!"<<endl;
		
		return createNullSingleElementMatrix();
	}
	else
	{
		Matrix *resultMatrix = createNullMatrix(matrix1->numRows, matrix2->numColumns);
		
		for(int i=0; i < matrix1->numRows; i++)
		{		
			for(int j=0; j < matrix2->numColumns; j++)
			{
				resultMatrix->entry[i][j] = 0;
			
				for(int k=0; k < matrix1->numColumns; k++)				
					resultMatrix->entry[i][j]+=matrix1->entry[i][k]*matrix2->entry[k][j];				
	  	  	    	
			}
	    }
			
	return resultMatrix;
	}	
}