#include "GUI.h"
#include <random>

void GUI::initGui()
{
	setStyleSheet("background-image:url(galaxy.jpg)");
	setWindowState(Qt::WindowMaximized);
	btnEncode->setStyleSheet("QPushButton{color:#FFFFFF;font-size:20px;font-family: Times New Roman;border-radius:20px;border-color:#ffffff;border:10px}QPushButton:pressed{color:#3EB489}");
	btnEncode->setFixedHeight(40);
	//btnEncode->setFlat(true);
	btnEncrypt->setStyleSheet("QPushButton{color:#FFFFFF;font-size:20px;font-family: Times New Roman;border-radius:20px;border-color:#ffffff;border:10px}QPushButton:pressed{color:#3EB489}");
	btnEncrypt->setFixedHeight(40);
	btnKey->setStyleSheet("QPushButton{color:#FFFFFF;font-size:20px;font-family: Times New Roman;border-radius:20px;border-color:#ffffff;border:10px}QPushButton:pressed{color:#3EB489}");
	btnKey->setFixedHeight(40);
	QPixmap pic1("pic1.jpg");
	QPixmap pic2("pic2.jfif");
	lblImg1->setPixmap(pic1);
	lblImg2->setPixmap(pic2);


	auto lyMain = new QHBoxLayout;
	setLayout(lyMain);

	auto lySec = new QVBoxLayout;

	lySec->addWidget(lblImg1);
	lySec->addStretch();
	lySec->addWidget(btnEncode);
	lySec->addSpacing(10);
	lySec->addWidget(btnEncrypt);
	lySec->addSpacing(10);
	lySec->addWidget(btnKey);
	lySec->addStretch();
	lySec->addWidget(lblImg2);

	lyMain->addStretch();
	lyMain->addLayout(lySec);
	lyMain->addStretch();
}

void GUI::connectGui()
{
	connect(btnEncode, &QPushButton::clicked, []() {
		encodeGui* enCoGui = new encodeGui;
		enCoGui->show();
		});

	connect(btnEncrypt, &QPushButton::clicked, []() {
		encryptGui* enCrGui = new encryptGui;
		enCrGui->show();
		});

	connect(btnKey, &QPushButton::clicked, []() {
		keyGui* keyGenGui = new keyGui;
		keyGenGui->show();
		});
}