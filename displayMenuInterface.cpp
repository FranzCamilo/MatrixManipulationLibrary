/*
This function performs an interface to get the
task to be executated on matrix manipulation from the user.
*/
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int displayMenuInterface()
{
	char 	chosenOption[10];
	int 	chosenOptionInt;
	bool 	tryAgainFlag = 1;
	
	while(tryAgainFlag == 1)
	{	
		cout << "Enter the number of your option:\n\n";
		cout << "1. Matrices multiplication;\n";
		cout << "2. Solve Linear Equation System;\n";
		cin >> chosenOption;
				
		if(strcmp(chosenOption,"1")!=0 && strcmp(chosenOption,"2")!=0)
		{
			cout << "Invalid option! Try again.\n\n";
		}
		else
		{
			tryAgainFlag = 0;
		}			
	}	
	
	chosenOptionInt = atoi(chosenOption);

	return chosenOptionInt;
}