#pragma once
#include <qwidget.h>
#include "abstractGui.h"
#include "encodeGui.h"

class convertGui : public QWidget, public abstractGui
{
public:
	convertGui()
	{
		initGui();
		connectGui();
	}
private:
	void initGui() override;
	void connectGui() override;
};

