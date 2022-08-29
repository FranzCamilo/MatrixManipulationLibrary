/*
This function applies back substitution on a linear
equation system reduced to its upper triangular matrix form
and returns the value found for each variable in the system.

More details on the backSubstitutionFunction.pdf
*/
#include "MyMatrixLib.h"

Matrix *applyBackSubstitution(Matrix* reducedSystemMatrix)
{
	const int 	SINGLE_COL = 0,
				LAST_COL = reducedSystemMatrix->numColumns - 1,
				LAST_ROW = reducedSystemMatrix->numRows - 1;
					
	Matrix *systemSolution = createNullMatrix(reducedSystemMatrix->numRows,1);
	
	
	//Back substitution:
	for(int k = 0; k < reducedSystemMatrix->numRows; k++)
		systemSolution->entry[k][SINGLE_COL] = reducedSystemMatrix->entry[k][LAST_COL];
				
	for(int i = LAST_ROW; i >= 0; i--)
	{
		for(int j = (LAST_COL - 1); j > i; j--)
			systemSolution->entry[i][SINGLE_COL] -= reducedSystemMatrix->entry[i][j]*systemSolution->entry[j][SINGLE_COL];
		
		if(reducedSystemMatrix->entry[i][i] != 0)
		{
			systemSolution->entry[i][SINGLE_COL] /= reducedSystemMatrix->entry[i][i];	
		}
		else if(systemSolution->entry[i][SINGLE_COL] == 0)
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
		
	//Display final solution	
	for(int k = 0; k < systemSolution->numRows; k++)
	{
		cout << "x" << (k + 1) << " = "; 
		cout << systemSolution->entry[k][SINGLE_COL] << endl;
	}
	
	return systemSolution;
}