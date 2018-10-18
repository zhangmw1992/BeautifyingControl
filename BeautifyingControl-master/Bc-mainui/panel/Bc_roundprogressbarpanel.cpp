#include "Bc_roundprogressbarpanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

RoundProgressBarPanel::RoundProgressBarPanel(QWidget *parent)
	: QWidget(parent)
{
	bar1 = new RoundProgressBar;
	bar2 = new RoundProgressBar;
	bar3 = new RoundProgressBar;
	bar4 = new RoundProgressBar;
	bar5 = new RoundProgressBar;
	bar6 = new RoundProgressBar;

	bar1->setFormat("%v");
	bar1->setDecimals(0);

	bar2->setStartAngle(RoundProgressBar::PositionRight);
	bar2->setBarStyle(RoundProgressBar::StylePie);
	bar2->setDecimals(0);

	bar3->setStartAngle(RoundProgressBar::PositionTop);
	bar3->setBarStyle(RoundProgressBar::StyleLine);
	bar3->setOutlinePenWidth(4);
	bar3->setDataPenWidth(4);
	bar3->setDecimals(0);

	QGradientStops grandientPoints;
	grandientPoints << QGradientStop(0, Qt::red) << QGradientStop(1, Qt::yellow);
	bar4->setStartAngle(RoundProgressBar::PositionLeft);
	bar4->setDecimals(0);
	bar4->setDataColors(grandientPoints);

	bar5->setStartAngle(RoundProgressBar::PositionLeft);
	bar5->setBarStyle(RoundProgressBar::StylePie);
	bar5->setDecimals(0);

	bar6->setStartAngle(RoundProgressBar::PositionTop);
	bar6->setBarStyle(RoundProgressBar::StyleLine);
	bar6->setDecimals(2);
	bar6->setClockwise(false);
	bar6->setOutlinePenWidth(18);
	bar6->setDataPenWidth(10);

	QCheckBox *box1 = new QCheckBox(QString(QStringLiteral("外圆")));
	QCheckBox *box2 = new QCheckBox(QString(QStringLiteral("数据圆")));
	QCheckBox *box3 = new QCheckBox(QString(QStringLiteral("内圆")));
	QCheckBox *box4 = new QCheckBox(QString(QStringLiteral("文字")));

	box1->setChecked(true);
	box2->setChecked(true);
	box3->setChecked(true);
	box4->setChecked(true);

	connect(box1, &QCheckBox::toggled, this, [&](bool visable){
		bar1->setBaseCircleVisible(visable);
		bar2->setBaseCircleVisible(visable);
		bar3->setBaseCircleVisible(visable);
		bar4->setBaseCircleVisible(visable);
		bar5->setBaseCircleVisible(visable);
		bar6->setBaseCircleVisible(visable);
	});

	connect(box2, &QCheckBox::toggled, this, [&](bool visable){
		bar1->setDataCircleVisible(visable);
		bar2->setDataCircleVisible(visable);
		bar3->setDataCircleVisible(visable);
		bar4->setDataCircleVisible(visable);
		bar5->setDataCircleVisible(visable);
		bar6->setDataCircleVisible(visable);
	});

	connect(box3, &QCheckBox::toggled, this, [&](bool visable){
		bar1->setCenterCircleVisible(visable);
		bar2->setCenterCircleVisible(visable);
		bar3->setCenterCircleVisible(visable);
		bar4->setCenterCircleVisible(visable);
		bar5->setCenterCircleVisible(visable);
		bar6->setCenterCircleVisible(visable);
	});

	connect(box4, &QCheckBox::toggled, this, [&](bool visable){
		bar1->setTextVisible(visable);
		bar2->setTextVisible(visable);
		bar3->setTextVisible(visable);
		bar4->setTextVisible(visable);
		bar5->setTextVisible(visable);
		bar6->setTextVisible(visable);
	});

	QSlider *slider = new QSlider(Qt::Horizontal);
	slider->setValue(25);
	slider->setRange(0, 100);
	connect(slider, &QSlider::valueChanged, [&](int value){
		bar1->setValue(value);
		bar2->setValue(value);
		bar3->setValue(value);
		bar4->setValue(value);
		bar5->setValue(value);
		bar6->setValue(value);
	});

	QLabel *lab1 = new QLabel(QString(QStringLiteral("圆环风格")));
	QLabel *lab2 = new QLabel(QString(QStringLiteral("饼状风格")));
	QLabel *lab3 = new QLabel(QString(QStringLiteral("线条风格")));

	lab1->setAlignment(Qt::AlignCenter);
	lab2->setAlignment(Qt::AlignCenter);
	lab3->setAlignment(Qt::AlignCenter);

	QGridLayout *lay1 = new QGridLayout;
	lay1->addWidget(lab1, 0, 0);
	lay1->addWidget(lab2, 0, 1);
	lay1->addWidget(lab3, 0, 2);
	lay1->addWidget(bar1, 1, 0);
	lay1->addWidget(bar2, 1, 1);
	lay1->addWidget(bar3, 1, 2);
	lay1->addWidget(bar4, 2, 0);
	lay1->addWidget(bar5, 2, 1);
	lay1->addWidget(bar6, 2, 2);
	lay1->setRowStretch(0, 0);
	lay1->setRowStretch(1, 1);
	lay1->setRowStretch(2, 1);
	lay1->setSpacing(40);

	QHBoxLayout *lay2 = new QHBoxLayout;
	lay2->addWidget(box1);
	lay2->addWidget(box2);
	lay2->addWidget(box3);
	lay2->addWidget(box4);
	lay2->setContentsMargins(0, 40, 0, 40);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addLayout(lay2);
	layout->addWidget(slider);
	layout->setContentsMargins(20, 40, 20, 40);
	setLayout(layout);
}

RoundProgressBarPanel::~RoundProgressBarPanel()
{

}
