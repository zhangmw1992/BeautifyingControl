#ifndef BC_FLATPANEL_H
#define BC_FLATPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>
#include <QSlider>
#include <QRadioButton>
#include <QCheckBox>
#include <QScrollBar>

#include "../Bc-flatui/Bc_flatui.h"

class FlatPanel : public QWidget
{
	Q_OBJECT

public:
	explicit FlatPanel(QWidget *parent = Q_NULLPTR);
	~FlatPanel();

private:
	void initUi();
	
};

#endif // BC_FLATPANEL_H
