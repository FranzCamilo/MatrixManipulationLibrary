/*
This function displays the interface to perform linear
equation system solving.
*/
#include<iostream>
#include"myFileLib.h"
#include"MyMatrixLib.h"
using namespace std;

void displaySolveSystemInterface()
{
	Matrix *equationSystem, *result;
	string 	fileName;
			
	cout << "\nSave linear equation system augmented matrix (A|b) in a text file.\n";
	cout << "===========================\n";
	cout << "Ex: If your system is:\n x1 + x2 = 2\n    - x2 = 3\n\n";
	cout << "The augmented matrix A|b would be:\n 1\t1\t2\n 0\t-1\t3\n";
	cout << "===========================\n";
	cout << "Make sure there is no blank space after the matrix last entry in the text file.\n";
	fileName = getValidFileAddress();
			
	equationSystem = getMatrixFromFile(fileName);
	cout << "===========================\n";
	cout << "\nThe solution for the system \n\n";
	displayLinearEqSystem(equationSystem);
	cout << "\nis \n\n";
			
	result = solveLinearEquationSystem(equationSystem);
}