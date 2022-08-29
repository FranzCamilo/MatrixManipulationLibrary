
#include<iostream>
#include <string>
#include "myFileLib.h"

using namespace std;

string getValidFileAddress()
{
	string fileName;
	bool tryAgainFlag = true;
	
	while(tryAgainFlag)
	{
		cout << "Enter file name or its complete address:\n";
		cin >> fileName;
		
		if(checkFileFound(fileName))
		{
			tryAgainFlag = false;
		}
		else
		{
			cout << "\nFile wasn't found!\n";
			cout << "Check file folder or if you have typed the file extension (.txt) and try again.\n\n";
		}	
	}

	return fileName;
}