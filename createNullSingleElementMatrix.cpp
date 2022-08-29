/*
This function creates a single element null matrix
to return in some exception cases.
*/

#include "MyMatrixLib.h"

Matrix *createNullSingleElementMatrix()
{
	Matrix *nullSingleElementMatrix = createNullMatrix(1,1);
	
	return nullSingleElementMatrix;
}