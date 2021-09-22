#pragma once
#include <qwidget.h>
#include "abstractGui.h"
#include "encodeGui.h"
#include "qcombobox.h"
#include "qtextedit.h"
#include "qpushbutton.h"
#include "Encoding.h"
#include "qlineedit.h"
#include "qlabel.h"

class encodeGui : public QWidget, public abstractGui
{
public:
	encodeGui()
	{
		initGui();
		connectGui();
	}
private:
	void initGui() override;
	void connectGui() override;

	QComboBox* combOptions = new QComboBox;
	QComboBox* combType = new QComboBox;

	QTextEdit* txtInput = new QTextEdit;
	QTextEdit* txtOutput = new QTextEdit;

	QPushButton* btnGo = new QPushButton;


	QLineEdit* txtKey = new QLineEdit;
};

