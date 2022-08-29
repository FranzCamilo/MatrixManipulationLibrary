/*
This function creates a modified indentity matrix
that includes an extra nozero entry -L.
 
Elimination matrices are used for entry elimination
in linear algebra methods such as linear equation system solving
through the Gauss Elimination Method, for instance.
Thus,

L(i,j) = target entry to eliminate in row "nthRow"/corresponding pivot above target entry in the same column "nthCol";;

Example for a 4x4 elimination matrix:
1	0	0	0
0	1	0	0
0  -L	1	0
0	0	0	1

REMINDER: indexes start from zero.
*/

#include "MyMatrixLib.h"

Matrix *createEliminationMatrix(int targetMatrixNumRows, int targetEntryRow, int targetEntryCol, double targetEntryPivot, double targetEntry)
{
	Matrix *eliminationMatrix = createIdentityMatrix(targetMatrixNumRows);

	eliminationMatrix->entry[targetEntryRow][targetEntryCol] = -targetEntry/targetEntryPivot;	
		
	return eliminationMatrix;	
}