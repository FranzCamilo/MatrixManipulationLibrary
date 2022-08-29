/*
This function checks out whether a file was found or not.
If it was found,this functions returns "true".
Otherwise, it returns "false".
*/

#include<iostream>
#include<fstream>
using namespace std;

bool checkFileFound(string fileName)
{
	ifstream textFile;
	
	textFile.open(fileName.c_str());
	
	if(textFile)
	{
		return true;
	}
	else
	{
		return false;
	}
}