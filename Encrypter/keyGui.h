#pragma once
#include <qwidget.h>
#include "abstractGui.h"
#include "encodeGui.h"
#include "qcombobox.h"
#include "qtextedit.h"
#include "qpushbutton.h"
#include "Encoding.h"
#include "qlineedit.h"
#include "qcheckbox.h"
#include "qspinbox.h"
#include "qlabel.h"

class keyGui : public QWidget, public abstractGui
{
public:
	keyGui()
	{
		initGui();
		connectGui();
	}
private:
	void initGui() override;
	void connectGui() override;
	
	QCheckBox* chkLettersLow = new QCheckBox;
	QCheckBox* chkLettersUp = new QCheckBox;
	QCheckBox* chkDigits = new QCheckBox;
	QCheckBox* chkSymbols = new QCheckBox;
	QSpinBox* spnLength = new QSpinBox;
	QPushButton* btnGen = new QPushButton("Generate");
	QLineEdit* txtGen = new QLineEdit;
};

