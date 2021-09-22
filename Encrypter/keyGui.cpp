#include "keyGui.h"
#include "qboxlayout.h"
#include "qformlayout.h"
#include "qpixmap.h"
#include "qpalette.h"
#include "qmessagebox.h"
#include <exception>
#include <algorithm>
#include "iostream"
#include <random>
#include "qlabel.h"
using namespace std;

void keyGui::initGui()
{
	setStyleSheet("background-color:#FFD55A;color:#293250;font-family: Times New Roman;font-weight:bold");
	btnGen->setStyleSheet("QPushButton{background-color:#293250;color:#6DD473;font-size:18px;border-radius:20px}QPushButton:pressed{color:#FFD55A}");
	txtGen->setStyleSheet("background-color:#293250;color:#6DD473");
	spnLength->setStyleSheet("background-color:#6DD473");

	auto lyMain = new QVBoxLayout;

	auto lyForm = new QFormLayout;
	lyForm->addRow("Uppercase( A-Z ): ",chkLettersUp);
	lyForm->addRow("Lowercase( a-z ): ",chkLettersLow);
	lyForm->addRow("Digits( 0-9 ): ",chkDigits);
	lyForm->addRow("Symbols( ~`!@#$%^&*()_-+=|:;'.?/ ): ",chkSymbols);
	lyForm->addRow("Length: ", spnLength);
	lyMain->addLayout(lyForm);
	lyMain->addWidget(btnGen);
	lyMain->addWidget(txtGen);
	txtGen->setReadOnly(true);

	setLayout(lyMain);
}

void keyGui::connectGui()
{
	connect(btnGen, &QPushButton::clicked, [&](){
		QWidget* displayGui = new QWidget;
		auto lyMain = new QVBoxLayout;
		QLineEdit* txtGenerate = new QLineEdit;
		QLabel* lblGenerate = new QLabel;
		lyMain->addWidget(lblGenerate);
		displayGui->setLayout(lyMain);
		srand(time(0));
		string key;
		
		int keyLength = spnLength->value();
		int numUppercase = 0;
		int numLowercase = 0;
		int numDigits = 0;
		int numSymbols = 0;

		bool pressedUppercase = false;
		bool pressedLowercase = false;
		bool pressedDigits = false;
		bool pressedSymbols = false;

		int numTypes = 0;

		if (chkLettersUp->isChecked())
		{
			pressedUppercase = true;
			numTypes++;
		}

		if (chkLettersLow->isChecked())
		{
			pressedLowercase = true;
			numTypes++;
		}

		if (chkDigits->isChecked())
		{
			pressedDigits = true;
			numTypes++;
		}

		if (chkSymbols->isChecked())
		{
			pressedSymbols = true;
			numTypes++;
		}

		
		int numOthers = numTypes-1;
		if (pressedUppercase)
		{
			if (numOthers == 0)
				numUppercase = keyLength;
			else
			{
				numUppercase = rand() % (keyLength - numOthers) + 1;
				keyLength -= numUppercase;
				numOthers--;
			}
			for (int i = 0;i < numUppercase;i++)
			{
				int generated = rand() % 26;
				char generatedUpper = generated + 'A';
				key += generatedUpper;
			}
		}
		if (pressedLowercase)
		{
			if (numOthers == 0)
				numLowercase = keyLength;
			else
			{
				numLowercase = rand() % (keyLength - numOthers) + 1;
				keyLength -= numLowercase;
				numOthers--;

			}
			for (int i = 0;i < numLowercase;i++)
			{
				int generated = rand() % 26;
				char generatedLower = generated + 'a';
				key += generatedLower;
			}
		}
		if (pressedDigits)
		{
			if (numOthers == 0)
				numDigits = keyLength;
			else
			{
				numDigits = rand() % (keyLength - numOthers) + 1;
				keyLength -= numDigits;
				numOthers--;
			}
			for (int i = 0;i < numDigits;i++)
			{
				int generated = rand() % 10;
				char generatedDigit = generated + '0';
				key += generatedDigit;
			}
		}
		if (pressedSymbols)
		{
			numSymbols = keyLength;
			for (int i = 0;i < numSymbols;i++)
			{
				int generated = rand() % 15;
				char generatedSymbol = generated + '!';
				key += generatedSymbol;
			}
		}

		random_device dev;
		shuffle(key.begin(), key.end(),dev);
		txtGen->setText(QString::fromStdString(key));
			
		});
}