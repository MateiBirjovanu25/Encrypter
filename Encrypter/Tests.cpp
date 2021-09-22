#include "Tests.h"
#include "Encoding.h"
#include "Encrypting.h"
#include <assert.h>
#include <qdebug.h>
#include <qstring.h>

void testVigenere()
{
	Encoding vigEncode;
	//qDebug() << QString::fromStdString(vigEncode.viginereEncode("today is friday", "hotdog"));
	assert(vigEncode.viginereEncode("today is friday", "hotdog") == "acwdm oz tklrgf");
	assert(vigEncode.viginereEncode("finally it worked...", "hotdog") == "mwgdzrf wm zcxrsw...");

	//qDebug() << QString::fromStdString(vigEncode.viginereDecode("acwdm oz tklrgf", "hotdog"));
	assert(vigEncode.viginereDecode("acwdm oz tklrgf", "hotdog") == "today is friday");
	assert(vigEncode.viginereDecode("mwgdzrf wm zcxrsw...", "hotdog") == "finally it worked...");
}

void testCaesar()
{
	Encoding vigEncode;
	assert(vigEncode.caesarEncode("aaa", "1") == "bbb");
}


void testEncryptFile()
{
	Encrypting encrypter;
	//encrypter.encryptFile(Encoding::viginereDecode, "hotdog", "eu.png", "pudel.png");
}

void testXor()
{
	Encoding xoryEncode;
	//qDebug()<< QString::fromStdString(xoryEncode.xorEncode("today is thursday", "hotdog"));
	//assert(xoryEncode.xorEncode("today is thursday", "hotdog") == );
}

void testEnoch()
{
	Encoding enoch;
	assert(enoch.enochEncode("aaa") == "ununun");
	assert(enoch.enochEncode("abz") == "unpaceph");

	qDebug() << QString::fromStdString(enoch.enochEncode("unpaceph"));
	assert(enoch.enochDecode("unpaceph") == "abz");
	assert(enoch.enochDecode("ununun") == "aaa");	
}

void testMat()
{
	Encoding mat;
	mat.matEncode("caine", "abc");
	mat.matDecode("caine", "abc");
}