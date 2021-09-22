#pragma once
#include <string>
#include <iostream>
using namespace std;

class Encrypting
{
public:
	void encryptFile(string(*algorithm)(string, string), string key, string inName, string outName);
};

