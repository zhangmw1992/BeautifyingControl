#include "Bc_flatpanel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

FlatPanel::FlatPanel(QWidget *parent)
	: QWidget(parent)
{
	initUi();
}

FlatPanel::~FlatPanel()
{

}

void FlatPanel::initUi()
{
	QPushButton *btn1 = new QPushButton(QString(QStringLiteral("测试按钮")));
	QPushButton *btn2 = new QPushButton(QString(QStringLiteral("测试按钮")));
	QPushButton *btn3 = new QPushButton(QString(QStringLiteral("测试按钮")));
	QPushButton *btn4 = new QPushButton(QString(QStringLiteral("测试按钮")));

	FlatUI::Instance()->setPushButtonQss(btn1, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");
	FlatUI::Instance()->setPushButtonQss(btn2, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
	FlatUI::Instance()->setPushButtonQss(btn3, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
	FlatUI::Instance()->setPushButtonQss(btn4, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

	QHBoxLayout *lay1 = new QHBoxLayout;
	lay1->addWidget(btn1);
	lay1->addWidget(btn2);
	lay1->addWidget(btn3);
	lay1->addWidget(btn4);

	QLineEdit *lineEdit1 = new QLineEdit;
	QLineEdit *lineEdit2 = new QLineEdit;
	QLineEdit *lineEdit3 = new QLineEdit;
	QLineEdit *lineEdit4 = new QLineEdit;

	FlatUI::Instance()->setLineEditQss(lineEdit1, "#DCE4EC", "#34495E");
	FlatUI::Instance()->setLineEditQss(lineEdit2, "#DCE4EC", "#1ABC9C");
	FlatUI::Instance()->setLineEditQss(lineEdit3, "#DCE4EC", "#3498DB");
	FlatUI::Instance()->setLineEditQss(lineEdit4, "#DCE4EC", "#E74C3C");

	QHBoxLayout *lay2 = new QHBoxLayout;
	lay2->addWidget(lineEdit1);
	lay2->addWidget(lineEdit2);
	lay2->addWidget(lineEdit3);
	lay2->addWidget(lineEdit4);

	QProgressBar *bar1 = new QProgressBar;
	QProgressBar *bar2 = new QProgressBar;

	bar1->setFixedHeight(25);
	bar2->setFixedHeight(25);

	bar1->setValue(30);
	bar2->setValue(80);

	FlatUI::Instance()->setProgressBarQss(bar1, "#E8EDF2", "#E74C3C");
	FlatUI::Instance()->setProgressBarQss(bar2, "#E8EDF2", "#1ABC9C");

	QSlider *slider1 = new QSlider(Qt::Horizontal);
	QSlider *slider2 = new QSlider(Qt::Horizontal);

	slider1->setValue(45);
	slider2->setValue(90);

	FlatUI::Instance()->setSliderQss(slider1, "#E8EDF2", "#1ABC9C", "#1ABC9C");
	FlatUI::Instance()->setSliderQss(slider2, "#E8EDF2", "#E74C3C", "#E74C3C");

	QRadioButton *rBtn1 = new QRadioButton(QString(QStringLiteral("语文")));
	QRadioButton *rBtn2 = new QRadioButton(QString(QStringLiteral("英语")));
	QRadioButton *rBtn3 = new QRadioButton(QString(QStringLiteral("数学")));
	QRadioButton *rBtn4 = new QRadioButton(QString(QStringLiteral("历史")));

	FlatUI::Instance()->setRadioButtonQss(rBtn1, "#D7DBDE", "#34495E");
	FlatUI::Instance()->setRadioButtonQss(rBtn2, "#D7DBDE", "#1ABC9C");
	FlatUI::Instance()->setRadioButtonQss(rBtn3, "#D7DBDE", "#3498DB");
	FlatUI::Instance()->setRadioButtonQss(rBtn4, "#D7DBDE", "#E74C3C");

	QHBoxLayout *lay3 = new QHBoxLayout;
	lay3->addWidget(rBtn1);
	lay3->addWidget(rBtn2);
	lay3->addWidget(rBtn3);
	lay3->addWidget(rBtn4);

	QCheckBox *checkBox1 = new QCheckBox(QString(QStringLiteral("语文")));
	QCheckBox *checkBox2 = new QCheckBox(QString(QStringLiteral("英语")));
	QCheckBox *checkBox3 = new QCheckBox(QString(QStringLiteral("数学")));
	QCheckBox *checkBox4 = new QCheckBox(QString(QStringLiteral("历史")));

	FlatUI::Instance()->setCheckBoxQss(checkBox1, "#D7DBDE", "#34495E");
	FlatUI::Instance()->setCheckBoxQss(checkBox2, "#D7DBDE", "#1ABC9C");
	FlatUI::Instance()->setCheckBoxQss(checkBox3, "#D7DBDE", "#3498DB");
	FlatUI::Instance()->setCheckBoxQss(checkBox4, "#D7DBDE", "#E74C3C");

	QHBoxLayout *lay4 = new QHBoxLayout;
	lay4->addWidget(checkBox1);
	lay4->addWidget(checkBox2);
	lay4->addWidget(checkBox3);
	lay4->addWidget(checkBox4);

	QScrollBar *scrollBar = new QScrollBar(Qt::Horizontal);

	FlatUI::Instance()->setScrollBarQss(scrollBar, "#606060", "#34495E", "#1ABC9C", "#E74C3C");

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addLayout(lay2);
	layout->addWidget(bar1);
	layout->addWidget(bar2);
	layout->addWidget(slider1);
	layout->addWidget(slider2);
	layout->addLayout(lay3);
	layout->addLayout(lay4);
	layout->addWidget(scrollBar);
	layout->setContentsMargins(20, 20, 20, 20);

	setLayout(layout);
}