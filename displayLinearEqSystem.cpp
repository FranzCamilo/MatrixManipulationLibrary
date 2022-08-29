/*
This function displays an augmented matrix A|b in the format
of an equation system.
*/

#include<iostream>
#include <cmath>
#include"MyMatrixLib.h"
using namespace std;

void displayLinearEqSystem(Matrix *eqSystemAugmentedMatrixAb)
{
	int			numEquations = eqSystemAugmentedMatrixAb->numRows,
				numVariables = eqSystemAugmentedMatrixAb->numColumns-1;
	int const 	B_COL_INDEX = eqSystemAugmentedMatrixAb->numColumns-1;

	
	for(int i = 0; i < numEquations; i++)
	{		
		for(int j = 0; j < numVariables; j++)
		{
			if(eqSystemAugmentedMatrixAb->entry[i][j] < 0)
			{
				cout << "- ";
			}
			else if(j!=0)
			{
				cout << "+ ";
			}
			//----------------------
			if(abs(eqSystemAugmentedMatrixAb->entry[i][j]) != 1)
			{
				cout << abs(eqSystemAugmentedMatrixAb->entry[i][j]) << ".";
			}
		
			cout << "x" << (j+1) << " ";			
		}
				
		cout << " = " << eqSystemAugmentedMatrixAb->entry[i][B_COL_INDEX] << endl;
	}
}