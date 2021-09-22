#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class Encoding
{
public:
	static string viginereEncode(string inputString, string key);
	static string viginereDecode(string inputString, string key);

	static string caesarEncode(string inputString, string Key);
	static string caesarDecode(string inputString, string Key);

	static string caesarDecodeFile(string inputString, string Key);
	static string caesarEncodeFile(string inputString, string Key);

	static string xorEncode(string inputString, string Key);

	static string enochEncode(string inputString);
	static string enochDecode(string inputString);

	static string matEncode(string inputString, string Key);
	static string matDecode(string inputString, string Key);
};
