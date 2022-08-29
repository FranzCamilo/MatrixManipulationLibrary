/*
Display a Matrix on the screen.
*/
#include "MyMatrixLib.h"
#include <iostream>

using namespace std;

void displayMatrix(Matrix *matrix)
{
	
	for(int i=0; i < matrix->numRows; i++)
	{
		cout<<"|";
		
		for(int j=0; j < matrix->numColumns; j++)
		{
			cout << matrix->entry[i][j];
			
			if(j != (matrix->numColumns-1))
				cout<<"\t";
		}
		
		cout<<"|"<<endl;
	  }	
	  
}