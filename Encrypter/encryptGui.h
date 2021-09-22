#pragma once
#include <qwidget.h>
#include "abstractGui.h"
#include "encodeGui.h"
#include "qfiledialog.h"
#include "qpushbutton.h"
#include "qlineedit.h"
#include "qcombobox.h"
#include "qlabel.h"

class encryptGui : public QWidget, public abstractGui
{
public:
	encryptGui()
	{
		initGui();
		connectGui();
	}
private:
	void initGui() override;
	void connectGui() override;

	QPushButton* btnFile = new QPushButton("Open");

	QLabel* txtInName = new QLabel;
	QLineEdit* txtOutName = new QLineEdit;
	QLineEdit* txtKey = new QLineEdit;
	QComboBox* combType = new QComboBox;
	QComboBox* combEnDe = new QComboBox;
	QPushButton* btnGo = new QPushButton;
};

