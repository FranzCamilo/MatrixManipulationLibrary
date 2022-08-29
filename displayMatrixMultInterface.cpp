/*
This function displays the interface to perform matrix multiplication.
*/
#include<iostream>
#include"myFileLib.h"
#include"MyMatrixLib.h"
using namespace std;

void displayMatrixMultInterface()
{
		Matrix *matrix1, *matrix2, *result;
		string 	fileName;
			
		cout << "\nSave matrix 1 in a text file.\n";
		cout << "Make sure there is no blank space after the matrix last entry in the text file.\n";
		fileName = getValidFileAddress();			
		matrix1 = getMatrixFromFile(fileName);
						
		cout << "\n\nSave matrix 2 in another text file.\n";
		fileName = getValidFileAddress();
		matrix2 = getMatrixFromFile(fileName);
		
		result = multiplyMatrices(matrix1,matrix2);
			
		cout << "===========================\n";
		cout << "The multiplication is:\n\n";
		displayMatrix(matrix1);
		cout << "x\n";
		displayMatrix(matrix2);
		cout << "=\n";
		displayMatrix(result);	
}