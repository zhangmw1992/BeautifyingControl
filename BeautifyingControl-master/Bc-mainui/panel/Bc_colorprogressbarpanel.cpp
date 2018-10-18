#include "Bc_colorprogressbarpanel.h"

ColorProgressBarPanel::ColorProgressBarPanel(QWidget *parent)
	: QWidget(parent)
{
	colorProgressBar1 = new ColorProgressBar;
	colorProgressBar1->setDecimal(0);
	colorProgressBar1->setBarBackGroundColor(QColor(Qt::white));
	colorProgressBar1->setBarColor(QColor(100, 184, 255));
	colorProgressBar1->setShowBarSplitLine(false);

	colorProgressBar2 = new ColorProgressBar;
	colorProgressBar2->setDecimal(1);
	colorProgressBar2->setBarBackGroundColor(QColor(Qt::white));
	colorProgressBar2->setBarColor(QColor(255, 107, 107));
	colorProgressBar2->setShowBarSplitLine(true);
	colorProgressBar2->setBarSplitLineDelta(3);
	colorProgressBar2->setBarSplitLineColor(QColor(242, 242, 242));

	colorProgressBar3 = new ColorProgressBar;
	colorProgressBar3->setDecimal(1);
	colorProgressBar3->setBarBackGroundColor(QColor(250, 250, 250));
	colorProgressBar3->setBarColor(QColor(24, 189, 155));
	colorProgressBar3->setShowBarSplitLine(true);
	colorProgressBar3->setBarSplitLineDelta(5);
	colorProgressBar3->setBarSplitLineColor(QColor(242, 242, 242));

	slider = new QSlider(Qt::Horizontal);
	connect(slider, &QSlider::valueChanged, this, [&](int value){
		colorProgressBar1->setValue(value);
		colorProgressBar2->setValue(value);
		colorProgressBar3->setValue(value);
	});

	slider->setValue(45);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(colorProgressBar1);
	layout->addWidget(colorProgressBar2);
	layout->addWidget(colorProgressBar3);
	layout->addWidget(slider);
	layout->setSpacing(30);
	layout->setContentsMargins(20, 20, 20, 60);
}

ColorProgressBarPanel::~ColorProgressBarPanel()
{

}
