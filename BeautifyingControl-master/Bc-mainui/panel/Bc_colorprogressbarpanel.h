#ifndef BC_COLORPROGRESSBARPANEL_H
#define BC_COLORPROGRESSBARPANEL_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>

#include "../Bc-progressbar/Bc_colorprogressbar.h"

class ColorProgressBarPanel : public QWidget
{
	Q_OBJECT
public:
	explicit ColorProgressBarPanel(QWidget *parent = Q_NULLPTR);
	~ColorProgressBarPanel();

private:
	QSlider *slider;

	ColorProgressBar *colorProgressBar1;
	ColorProgressBar *colorProgressBar2;
	ColorProgressBar *colorProgressBar3;
};

#endif // BC_COLORPROGRESSBARPANEL_H
