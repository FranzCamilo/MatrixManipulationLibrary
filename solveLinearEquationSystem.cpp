/*
This function solves a linear equation system through
Gauss Elimination Method. It returns the solution or the
reason there is not an only solution.

Let the linear equation system be written in matrix form such as
A.x = b, where "A" is the coefficient matrix, "x" is the vector
of variables, and "b" is the vector of independent components.

The linear equation system to be solved is given as an argument
to this function in the format of an augmented matrix [A | b].

Example:
For the system:
						A.x = b
x  +  y = 1			|1	 1||x1| = |1|
3x - 2y = 5			|3	-2||x2|	  |5|

The augmented matrix [A|b] =|1    1    1|
 	 	 	 	 	        |3   -2    5|
is given as this function argument.

OBS: Flowchart_System Solving Function.xls describes all
this function logic. 
*/

#include "MyMatrixLib.h"

Matrix *solveLinearEquationSystem(Matrix *eqSystemAugmentedMatrixAb)
{
	
	int pivotRow, pivotColumn, subPivotRow, subPivotColumn;     
    
	Matrix *reducedSystemUpperTriangMatrix = eqSystemAugmentedMatrixAb,
	   	   *permutationMatrix,
           *eliminationMatrix,
           *systemVariablesFinalSolution = createNullMatrix(eqSystemAugmentedMatrixAb->numRows,1);	
	  	       
			
	for(pivotRow = 0; pivotRow < (reducedSystemUpperTriangMatrix->numRows - 1); pivotRow++)
	{
		pivotColumn = pivotRow;
		
		//Nonzero pivot check
		if(reducedSystemUpperTriangMatrix->entry[pivotRow][pivotColumn] == 0)
		{
			subPivotRow = (pivotRow + 1);
			subPivotColumn = pivotColumn; 
						
			while(reducedSystemUpperTriangMatrix->entry[subPivotRow][pivotColumn] == 0 && ++subPivotRow < reducedSystemUpperTriangMatrix->numRows);
										
			if(subPivotRow == reducedSystemUpperTriangMatrix->numRows)
			{
				cout << "There is no solution for this system!\n";
				cout << "Inconsistent linear equation system.\n\n";
				
				return createNullSingleElementMatrix();
			}
			else
			{
				permutationMatrix = createPermutationMatrix(reducedSystemUpperTriangMatrix->numRows,pivotRow,subPivotRow);
				reducedSystemUpperTriangMatrix = multiplyMatrices(permutationMatrix,reducedSystemUpperTriangMatrix);
			}
		}
			
		//Elimination Process
		for(subPivotRow =(pivotRow + 1); subPivotRow < reducedSystemUpperTriangMatrix->numRows; subPivotRow++)
		{
			subPivotColumn = pivotColumn;
			
			if(reducedSystemUpperTriangMatrix->entry[subPivotRow][subPivotColumn] != 0)
			{
				eliminationMatrix = createEliminationMatrix(reducedSystemUpperTriangMatrix->numRows, subPivotRow, subPivotColumn, reducedSystemUpperTriangMatrix->entry[pivotRow][pivotColumn], reducedSystemUpperTriangMatrix->entry[subPivotRow][subPivotColumn]);		
				reducedSystemUpperTriangMatrix = multiplyMatrices(eliminationMatrix,reducedSystemUpperTriangMatrix);
			}
		}
	}
	
	//Processing and providing final result
	systemVariablesFinalSolution = applyBackSubstitution(reducedSystemUpperTriangMatrix);
		
	return systemVariablesFinalSolution;
}