#include "Encrypting.h"
#include "Encoding.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Encrypting::encryptFile(string(*algorithm)(string, string), string key, string inName, string outName)
{
	ifstream fin;
	fin.open(inName.c_str(), ios::binary);
	string inputString;
	char buffer;
	while (!fin.eof())
	{
		fin >>noskipws>>buffer;
		inputString += buffer;
	}
	fin.close();
	string outputString;
	
	outputString = algorithm(inputString, key);

	ofstream fout;
	fout.open(outName.c_str(), ios::binary);
	fout << outputString;
	fout.close();
}


