//Environment to manipulate matrices with a proper library.

#include "myMatrixLib.h"
#include "myFileLib.h"
#include"myInterfaceLib.h"
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int chosenOption;
	
	cout << "MATRIX CALCULATOR\n\n";
			
	chosenOption = displayMenuInterface();
	
	switch(chosenOption){	
		case 1:
			displayMatrixMultInterface();
		break;
	
		case 2:
			displaySolveSystemInterface();
		break;
	}
	
	return 0;
}