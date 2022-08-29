/*
This function applies back substitution on a linear
equation system reduced to its upper triangular matrix form
and returns the value found for each variable in the system.

More details on the backSubstitutionFunction.pdf
*/
#include "MyMatrixLib.h"

Matrix *applyBackSubstitution(Matrix* upperTriangularMatrix)
{
	Matrix *foundUnknownsVector = createNullMatrix(upperTriangularMatrix->numRows,1);
	
	const int FOUND_UNKNOWNS_VECTOR_COLUMN = 0;
	
	int foundUnknownsVectorRow,
		upperTriangularMatrixRow,
	    upperTriangularMatrixColumn;
	
	//Back substitution:
	for(foundUnknownsVectorRow = 0; foundUnknownsVectorRow < upperTriangularMatrix->numRows; foundUnknownsVectorRow++)
	{
		foundUnknownsVector->entry[foundUnknownsVectorRow][FOUND_UNKNOWNS_VECTOR_COLUMN] = upperTriangularMatrix->entry[foundUnknownsVectorRow][upperTriangularMatrix->numColumns - 1];
	}
			
	for(upperTriangularMatrixRow = (upperTriangularMatrix->numRows - 1); upperTriangularMatrixRow >= 0; upperTriangularMatrixRow--)
	{
		for(upperTriangularMatrixColumn = (upperTriangularMatrix->numColumns - 2); upperTriangularMatrixColumn > upperTriangularMatrixRow; upperTriangularMatrixColumn--)
		{
			foundUnknownsVector->entry[upperTriangularMatrixRow][FOUND_UNKNOWNS_VECTOR_COLUMN] -= upperTriangularMatrix->entry[upperTriangularMatrixRow][upperTriangularMatrixColumn]*foundUnknownsVector->entry[upperTriangularMatrixColumn][FOUND_UNKNOWNS_VECTOR_COLUMN];
		}
			
		if(upperTriangularMatrix->entry[upperTriangularMatrixRow][upperTriangularMatrixRow] != 0)
		{
			foundUnknownsVector->entry[upperTriangularMatrixRow][FOUND_UNKNOWNS_VECTOR_COLUMN] /= upperTriangularMatrix->entry[upperTriangularMatrixRow][upperTriangularMatrixRow];	
		}
		else if(foundUnknownsVector->entry[upperTriangularMatrixRow][FOUND_UNKNOWNS_VECTOR_COLUMN] == 0)
				{
				   	cout << "This system has many solutions: 0.x = 0!\n";	
					return createNullSingleElementMatrix();
				}
				else
				{
					cout << "This system has no solution: 0.x = b!\n";
					return createNullSingleElementMatrix();
				}
	}
		
	//Display found unknowns	
	for(foundUnknownsVectorRow = 0; foundUnknownsVectorRow < foundUnknownsVector->numRows; foundUnknownsVectorRow++)
	{
		cout << "x" << (foundUnknownsVectorRow + 1) << " = " << foundUnknownsVector->entry[foundUnknownsVectorRow][FOUND_UNKNOWNS_VECTOR_COLUMN] << endl;
	}
	
	return foundUnknownsVector;
}