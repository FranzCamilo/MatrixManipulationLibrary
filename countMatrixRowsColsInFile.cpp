/*This function returns the number of rows and columns of a 
matrix saved in a text file.

IMPORTANT: Make sure you didn't left a blank space or line after the
last matrix element in the text file, which will be incorrectly
recognized as another element in the matrix.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int *countMatrixRowsColsInFile(string fileName)
{
	int numRows = 0, numCols = 0, numEntries = 0;
	int *matrixDimensions;
	double matrixEntry;
	string matrixEntireRow;
	ifstream textFile;
	
	matrixDimensions = (int *)malloc(2*sizeof(int));
			
	//---------------------------------
	textFile.open(fileName.c_str());
	while(!textFile.eof())
	{
		textFile >> matrixEntry;
		numEntries++;
	}
	textFile.close();

	
	textFile.open(fileName.c_str());
	while(!textFile.eof())
	{
		getline(textFile, matrixEntireRow);
		numRows++;
	}
	textFile.close();
	//---------------------------------
		
	numCols = numEntries/numRows;
	
	matrixDimensions[0] = numRows;
	matrixDimensions[1] = numCols;
			
	return matrixDimensions;
}