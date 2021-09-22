#include "Encoding.h"
#include "qdebug.h"

string Encoding::viginereEncode(string inputString, string key)
{

	if (inputString.empty() || key.empty())
		throw exception("The fields must not be empty");

	for (auto c : key)
	{
		if (c < 'A' || (c > 'Z' && c < 'a') || c>'z')
			throw exception("The key must contain only letters");
	}


	int keyIndex = 0;
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		int ok = 0;
		if (inputString[i]>='a' && inputString[i]<='z' || (inputString[i] >= 'A' && inputString[i] <= 'Z'))
		{
			if (inputString[i] >= 'A' && inputString[i] <= 'Z')
			{
				ok = 1;
				inputString[i] += 32;
			}
			// i did this because the value became greater than 128 and the comparison did not work
			if ('z' - inputString[i] < key[keyIndex] - 'a')
				outputString[i] = inputString[i] - 'a' - ('z' - 'a' + 1) + key[keyIndex];
			else
				outputString[i] = (inputString[i] - 'a' + key[keyIndex]);

			keyIndex++;
			if (keyIndex == key.length())
				keyIndex = 0;
			if(ok==1)
				outputString[i] -= 32;
		}
		else
		{
			outputString[i] = inputString[i];
		}
	}
	return outputString;
}


string Encoding::viginereDecode(string inputString, string key)
{
	if (inputString.empty() || key.empty())
		throw exception();
	int keyIndex = 0;
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		int ok = 0;
		if ((inputString[i] >= 'a' && inputString[i] <= 'z') || (inputString[i] >= 'A' && inputString[i] <= 'Z'))
		{
			if (inputString[i] >= 'A' && inputString[i] <= 'Z')
			{
				ok = 1;
				inputString[i] += 32;
			}
			outputString[i] = inputString[i] - key[keyIndex] + 'a';
			if (outputString[i] < 'a')
				outputString[i] += 'z' - 'a' + 1;
			keyIndex++;
			if (keyIndex == key.length())
				keyIndex = 0;
			if (ok == 1)
				outputString[i] -= 32;
		}
		else
		{
			outputString[i] = inputString[i];
		}
	}
	return outputString;
}

string Encoding::caesarEncode(string inputString, string key)
{
	int keyInt = atoi(key.c_str());
	if (keyInt > 128)
		keyInt = keyInt % 128;
	qDebug()<<QString::number(keyInt);
	if (inputString.empty() || key.empty())
		throw exception("the fields must not be empty");
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		int a, b;
		a = inputString[i];
		b = keyInt;
		if (a + b > 128)
		{
			outputString[i] = a + b - 128;
		}
		else
		{
			outputString[i] = inputString[i] + keyInt;
		}
		outputString[i] = inputString[i] + keyInt;
	}
	return outputString;
}

string Encoding::caesarDecode(string inputString, string key)
{
	int keyInt = atoi(key.c_str());
	if (keyInt > 128)
		keyInt = keyInt % 128;
	if (inputString.empty() || key.empty())
		throw exception("the fields must not be empty");
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		int a, b;
		a = inputString[i];
		b = keyInt;
		if (a - b < 0)
		{
			outputString[i] = 128 + a - b;
		}
		else
		{
			outputString[i] = inputString[i] - keyInt;
		}
		outputString[i] = inputString[i] - keyInt;
	}
	return outputString;
}

string Encoding::caesarEncodeFile(string inputString, string key)
{
	int keyInt = atoi(key.c_str());
	if (keyInt > 128)
		keyInt = keyInt % 128;
	qDebug() << QString::number(keyInt);
	if (inputString.empty())
		throw exception();
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		outputString[i] = inputString[i] + keyInt;
	}
	return outputString;
}

string Encoding::caesarDecodeFile(string inputString, string key)
{
	int keyInt = atoi(key.c_str());
	if (keyInt > 128)
		keyInt = keyInt % 128;
	if (inputString.empty())
		throw exception();
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		outputString[i] = inputString[i] - keyInt;
	}
	return outputString;
}

string Encoding::xorEncode(string inputString, string key)
{
	string outputString;
	outputString.resize(inputString.length());
	for (int i = 0;i < inputString.length();i++)
	{
		outputString[i] = inputString[i] ^ key[i%key.length()];
	}
	return outputString;
}


string Encoding::enochEncode(string inputString)
{
	unordered_map<string, string> dictEnoch({ 
		{ "a","un"}, { "b","pa"}, { "c","vehc"}, { "k","vehk"}, { "e","graph"}, { "d","gal"},
		{ "f","or"}, { "g","gedg"}, { "h","na"}, { "i","goni"}, { "y","gony"}, { "l","ur"},
		{ "m","tall"}, { "n","drux"}, { "o","med"}, { "p","mals"}, { "q","ger"}, { "r","don"},
		{ "s","fam"}, { "t","gisg"}, { "u","vanu"}, { "v","vanv"}, { "x","pal"}, { "z","ceph"}
		});

	string outputString;

	for (int i = 0;i < inputString.length();i++)
	{
		string character="";
		character += inputString[i];
		outputString = outputString + dictEnoch[character];
	}

	return outputString;
}

string Encoding::enochDecode(string inputString)
{
	unordered_map<string, string> dictEnoch({
		{ "a","un"}, { "b","pa"}, { "c","vehc"}, { "k","vehk"}, { "e","graph"}, { "d","gal"},
		{ "f","or"}, { "g","gedg"}, { "h","na"}, { "i","goni"}, { "y","gony"}, { "l","ur"},
		{ "m","tall"}, { "n","drux"}, { "o","med"}, { "p","mals"}, { "q","ger"}, { "r","don"},
		{ "s","fam"}, { "t","gisg"}, { "u","vanu"}, { "v","vanv"}, { "x","pal"}, { "z","ceph"}
		});
	string outputString="";


	string tempString = "";
	for (int i = 0;i < inputString.length();i++)
	{
		tempString += inputString[i];
		for (auto elem : dictEnoch)
		{
			if (elem.second == tempString)
			{
				outputString += elem.first;
				tempString = "";
				break;
			}
		}
	}
	return outputString;
}

string Encoding::matEncode(string inputString, string key)
{
	string codedString = enochEncode(inputString);
	string codedKey = enochEncode(key);

	string outputString = viginereEncode(codedString, codedKey);

	return outputString;
}

string Encoding::matDecode(string inputString, string key)
{
	string codedKey = enochEncode(key);
	string codedString = viginereDecode(inputString, codedKey);

	string outputString = enochDecode(codedString);
	
	return outputString;
}
