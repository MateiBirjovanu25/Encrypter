#include "encodeGui.h"
#include "qboxlayout.h"
#include "qformlayout.h"
#include "qpixmap.h"
#include "qpalette.h"
#include "qmessagebox.h"
#include <exception>

void encodeGui::initGui()
{
	
	QPalette pal = txtKey->palette();
	pal.setColor(QPalette::PlaceholderText, Qt::green);
	txtKey->setPalette(pal);

	setStyleSheet("background-color:#393E46;color:#00ADB5");
	txtInput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:gray;font-size:20px;font-family: Times New Roman;border-color:white}");
	txtOutput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:gray;font-size:20px;font-family: Times New Roman}");
	btnGo->setStyleSheet("QPushButton{background-color:#00ADB5}QPushButton:pressed{border-radius:0px;border-color:white}");
	combOptions->setStyleSheet("color:#00ADB5;font-size:20px;background-color:#222831");
	combType->setStyleSheet("color:#00ADB5;font-size:20px;background-color:#222831");
	txtKey->setStyleSheet("QLineEdit{background-color:#EEEEEE;color:#222831;font-size:20px;font-family: Times New Roman}QLineEdit[text=\"\"]{ color:gray; }");

	QPixmap pixmap = QPixmap("btnGo5.png");
	//btnGo->setMask(pixmap.mask());
	btnGo->setIcon(pixmap);
	btnGo->setIconSize(pixmap.rect().size());
	//btnGo->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);


	auto lyMain = new QVBoxLayout;
	setLayout(lyMain);

	auto lyType = new QHBoxLayout;
	//lyType->addWidget(lblType);
	lyType->addWidget(combOptions);
	combOptions->addItem("Algorithm");
	combOptions->addItem("Viginere");
	combOptions->addItem("Caesar");
	combOptions->addItem("XOR");
	combOptions->addItem("MatCrypt");
	//combOptions->addItem("Huffman");


	auto lyEncode = new QHBoxLayout;
	//lyEncode->addWidget(lblEncode);
	lyEncode->addWidget(combType);
	combType->addItem("Encode/Decode");
	combType->addItem("Encode");
	combType->addItem("Decode");

	auto lyText = new QHBoxLayout;
	lyText->addWidget(txtInput);
	txtInput->setPlaceholderText("input");
	lyText->addWidget(txtOutput);
	txtOutput->setPlaceholderText("output");
	
	lyMain->addLayout(lyType);
	lyMain->addLayout(lyEncode);
	lyMain->addLayout(lyText);

	txtKey->setPlaceholderText("Key");
	lyMain->addWidget(txtKey);
	
	lyMain->addWidget(btnGo);

	
}

void encodeGui::connectGui()
{
	connect(txtKey, &QLineEdit::textChanged, [=] { style()->polish(txtKey); });

	connect(txtInput, &QTextEdit::textChanged, [=] { 
		if (txtInput->toPlainText()!="")
			txtInput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:#222831;font-size:20px;font-family: Times New Roman}");
		else
			txtInput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:gray;font-size:20px;font-family: Times New Roman;border-color:white}");
		});

	connect(txtOutput, &QTextEdit::textChanged, [=] { 
		if (txtOutput->toPlainText() != "")
			txtOutput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:#222831;font-size:20px;font-family: Times New Roman}");
		else
			txtOutput->setStyleSheet("QTextEdit{background-color:#EEEEEE;color:gray;font-size:20px;font-family: Times New Roman;border-color:white}");
		});

	Encoding encoder;
	connect(btnGo, &QPushButton::clicked, [&]() {
			if (combOptions->currentText() == "Viginere")
			{
				try
				{
					if (combType->currentText() == "Encode")
						txtOutput->setText(QString::fromStdString(encoder.viginereEncode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
					else
						txtOutput->setText(QString::fromStdString(encoder.viginereDecode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
				}
				catch (exception a)
				{
					QMessageBox::information(0,"error", a.what());
				}
			}
			else if (combOptions->currentText() == "Caesar")
			{
				try
				{
					if (combType->currentText() == "Encode")
						txtOutput->setText(QString::fromStdString(encoder.caesarEncode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
					else
						txtOutput->setText(QString::fromStdString(encoder.caesarDecode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
				}
				catch (exception a)
				{
					QMessageBox::information(0, "error", a.what());
				}
			}
			else if (combOptions->currentText() == "XOR")
			{
				try
				{
					txtOutput->setText(QString::fromStdString(encoder.xorEncode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
				}
				catch (exception a)
				{
					QMessageBox::information(0, "error", a.what());
				}
			}

			else if (combOptions->currentText() == "MatCrypt")
			{
				try
				{
					if (combType->currentText() == "Encode")
						txtOutput->setText(QString::fromStdString(encoder.matEncode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
					else
						txtOutput->setText(QString::fromStdString(encoder.matDecode(txtInput->toPlainText().toStdString(), txtKey->text().toStdString())));
				}
				catch (exception a)
				{
					QMessageBox::information(0, "error", a.what());
				}
			}
		});
}