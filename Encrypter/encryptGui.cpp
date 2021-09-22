#include "encryptGui.h"
#include "qboxlayout.h"
#include "qformlayout.h"
#include <iostream>
#include <fstream>
#include <string>
#include "qmessagebox.h"
#include "Encoding.h"
#include "Encrypting.h"
using namespace std;

void encryptGui::initGui()
{

	setStyleSheet("background-color: #b9bbdf; font-weight: bold");
	combEnDe->setStyleSheet("background-color: #dde7f2");
	combType->setStyleSheet("background-color: #dde7f2");
	txtKey->setStyleSheet("background-color: #dde7f2");
	btnFile->setStyleSheet("background-color: #dde7f2");
	txtInName->setStyleSheet("background-color: #dde7f2");
	txtOutName->setStyleSheet("background-color: #dde7f2");
	btnGo->setStyleSheet("background-color: #878ecd");

	QPixmap pixmap = QPixmap("btnGo4.png");
	btnGo->setMask(pixmap.mask());
	btnGo->setIcon(pixmap);
	btnGo->setIconSize(pixmap.rect().size());
	btnGo->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

	auto lyMain = new QVBoxLayout;

	auto lyForm = new QFormLayout;
	lyForm->addRow("Select algorithm", combType);
	combType->addItem("Viginere");
	combType->addItem("Caesar");
	combType->addItem("XOR");
	combType->addItem("MatCrypt");

	lyForm->addRow("Select action", combEnDe);
	combEnDe->addItem("Encode");
	combEnDe->addItem("Decode");
	lyForm->addRow("Key", txtKey);
	lyForm->addRow("Select File", btnFile);
	lyForm->addRow("Input File Name", txtInName);
	lyForm->addRow("Output file Name", txtOutName);

	
	lyMain->addLayout(lyForm);
	lyMain->addWidget(btnGo);
	setLayout(lyMain);
}

void encryptGui::connectGui()
{
	connect(btnFile, &QPushButton::clicked, [&]() {
			QString fileName = QFileDialog::getOpenFileName(this, "Select a file", "C://");
			txtInName->setText(fileName);
		});


	connect(btnGo, &QPushButton::clicked, [&]() {
		if (txtOutName->text() == "" || txtInName->text() == "")
		{
			QMessageBox::information(0, "error", "output or input empty");
		}
		else
		{
			Encrypting encrypter;
			string inName = txtInName->text().toStdString();
			string outName = txtOutName->text().toStdString();
			string key = txtKey->text().toStdString();
			if (combType->currentText() == "Viginere")
			{
				if (combEnDe->currentText() == "Encode")
				{
					encrypter.encryptFile(Encoding::viginereEncode, key, inName, outName);
				}
				else
				{
					encrypter.encryptFile(Encoding::viginereDecode, key, inName, outName);
				}
				
			}
			else if (combType->currentText() == "Caesar")
			{
				if (combEnDe->currentText() == "Encode")
				{
					encrypter.encryptFile(Encoding::caesarEncodeFile, key, inName, outName);
				}
				else
				{

					encrypter.encryptFile(Encoding::caesarDecodeFile, key, inName, outName);
				}
			}
			else if (combType->currentText() == "XOR")
			{
				encrypter.encryptFile(Encoding::xorEncode, key, inName, outName);
			}
			else if (combType->currentText() == "MatCrypt")
			{
				if (combEnDe->currentText() == "Encode")
				{
					encrypter.encryptFile(Encoding::matEncode, key, inName, outName);
				}
				else
				{

					encrypter.encryptFile(Encoding::matDecode, key, inName, outName);
				}
			}
		}
			
		});

}