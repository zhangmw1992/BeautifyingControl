#ifndef BC_ROUNDPROGRESSBARPANEL_H
#define BC_ROUNDPROGRESSBARPANEL_H

#include <QWIdget>
#include <QCheckBox>
#include <QSlider>
#include <QLabel>

#include "../Bc-progressbar/Bc_roundprogressbar.h"

class RoundProgressBarPanel : public QWidget
{
	Q_OBJECT
public:
	explicit RoundProgressBarPanel(QWidget *parent = Q_NULLPTR);
	~RoundProgressBarPanel();

private:
	RoundProgressBar *bar1;
	RoundProgressBar *bar2;
	RoundProgressBar *bar3;
	RoundProgressBar *bar4;
	RoundProgressBar *bar5;
	RoundProgressBar *bar6;
};

#endif // BC_ROUNDPROGRESSBARPANEL_H
