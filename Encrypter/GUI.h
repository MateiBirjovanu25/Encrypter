#pragma once
#include <qwidget.h>
#include "abstractGui.h"
#include <qboxlayout.h>
#include <qpushbutton.h>
#include "encodeGui.h"
#include "encryptGui.h"
#include "convertGui.h"
#include "qlabel.h"
#include "keyGui.h"

class GUI : public QWidget, public abstractGui
{
public:
	GUI()
	{
		initGui();
		connectGui();
	}
private:
	void initGui() override;
	void connectGui() override;

	QLabel* lblImg2 = new QLabel;
	QPushButton* btnEncode = new QPushButton("Encrypt Text");
	QPushButton* btnEncrypt = new QPushButton("Encrypt Files");
	QPushButton* btnKey = new QPushButton("Generate Key(Password)");
	QLabel* lblImg1 = new QLabel;
	
};

