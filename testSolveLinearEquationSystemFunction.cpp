/*
This function performs 10 cases to test the code for
the function solveLinearEquationSystem().
*/

#include"MyMatrixLib.h"
#include <cstdlib>//itoa

void testSolveLinearEquationSystemFunction()
{
	int 	nthCaseInt;
	char 	nthCaseChar[10];
	string 	fileAdressStandardPart = "./LinearSystemsTestCases/case",
			fullFileAdress;
    	      
	
	cout << "======================================================================" << endl;
	cout << "ALGORITHM TEST PROCEDURE for the function solveLinearEquationSystem();" << endl;
	cout << "======================================================================" << endl;
	
	for(nthCaseInt = 1; nthCaseInt <= 10; nthCaseInt++)
	{
		cout << "Case " << nthCaseInt << "\n\n";
		
		Matrix *eqSystemMatrix;
		
		fullFileAdress = fileAdressStandardPart + itoa(nthCaseInt,nthCaseChar,10) + ".txt";
				
		eqSystemMatrix = getMatrixFromFile(fullFileAdress);
		solveLinearEquationSystem(eqSystemMatrix);
		
		free(eqSystemMatrix);
				
		cout <<"--------------------\n";
	}		
}