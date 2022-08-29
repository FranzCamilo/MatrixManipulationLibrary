/*
This function reads a matrix in a text file and saves it
in a dynamically allocated "Matrix" struct.
*/

#include <fstream>
#include "MyMatrixLib.h"

Matrix *getMatrixFromFile(string fileName)
{
	int numRows, numCols;
	int *matrixDimensions;
	Matrix *matrix;
	ifstream textFile;
	
	//---------------------
	matrixDimensions = countMatrixRowsColsInFile(fileName);
	numRows = matrixDimensions[0];
	numCols = matrixDimensions[1];
			
	matrix = createNullMatrix(numRows,numCols);

	//---------------------	
	textFile.open(fileName.c_str());
	
	for(int i=0; i < numRows; i++)
	{
		for(int j=0; j < numCols; j++)
		{
			textFile >> matrix->entry[i][j];
		}
	}
	
	textFile.close();
	//---------------------
	
	return matrix;	
}