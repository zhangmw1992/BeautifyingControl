#include "Bc_slidernavigationpanel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

SliderNavigationPanel::SliderNavigationPanel(QWidget *parent)
	: QWidget(parent)
{
	sn1 = new SlideNavigation;
	sn2 = new SlideNavigation;
	sn3 = new SlideNavigation;

	QVBoxLayout *lay1 = new QVBoxLayout;
	lay1->addWidget(sn1);
	lay1->addWidget(sn2);
	lay1->addWidget(sn3);
	lay1->setSpacing(10);

	sn1->addItem(QStringLiteral("星期一"));
	sn1->addItem(QStringLiteral("星期二"));
	sn1->addItem(QStringLiteral("星期三"));
	sn1->addItem(QStringLiteral("星期四"));
	sn1->addItem(QStringLiteral("星期五"));
	sn1->addItem(QStringLiteral("星期六"));
	sn1->addItem(QStringLiteral("星期日"));
	sn1->addItem(QStringLiteral("星期八"));

	sn2->setBarRadious(5);
	sn2->setItemRadious(5);
	sn2->setItemStartColor(QColor(254, 176, 42));
	sn2->setItemEndColor((QColor(225, 156, 37)));
	sn2->addItem(QStringLiteral("第一次"));
	sn2->addItem(QStringLiteral("第二次"));
	sn2->addItem(QStringLiteral("第三次"));
	sn2->addItem(QStringLiteral("第四次"));
	sn2->addItem(QStringLiteral("第五次"));
	sn2->addItem(QStringLiteral("第六次"));
	sn2->addItem(QStringLiteral("第七次"));
	sn2->addItem(QStringLiteral("第八次"));

	sn3->setBarRadious(10);
	sn3->setItemRadious(10);
	sn3->setItemStartColor(QColor(255, 0, 0));
	sn3->setItemEndColor((QColor(225, 20, 10)));
	sn3->addItem(QStringLiteral("第一名"));
	sn3->addItem(QStringLiteral("第二名"));
	sn3->addItem(QStringLiteral("第三名"));
	sn3->addItem(QStringLiteral("第四名"));
	sn3->addItem(QStringLiteral("第五名"));
	sn3->addItem(QStringLiteral("第六名"));
	sn3->addItem(QStringLiteral("第七名"));
	sn3->addItem(QStringLiteral("第八名"));

	sn4 = new SlideNavigation;
	sn5 = new SlideNavigation;
	sn6 = new SlideNavigation;
	sn7 = new SlideNavigation;
	sn8 = new SlideNavigation;

	QHBoxLayout *lay2 = new QHBoxLayout;
	lay2->addWidget(sn4);
	lay2->addWidget(sn5);
	lay2->addWidget(sn6);
	lay2->addWidget(sn7);
	lay2->addWidget(sn8);

	sn4->setBarRadious(5);
	sn4->setItemRadious(5);
	sn4->setSpace(20);
	sn4->setOrientation(Qt::Vertical);
	sn4->addItem(QStringLiteral("系统设置"));
	sn4->addItem(QStringLiteral("记录查询"));
	sn4->addItem(QStringLiteral("学生管理"));
	sn4->addItem(QStringLiteral("教师管理"));
	sn4->addItem(QStringLiteral("制卡刷卡"));
	sn4->addItem(QStringLiteral("数据统计"));
	sn4->addItem(QStringLiteral("用户推出"));

	sn5->setBarRadious(5);
	sn5->setItemRadious(5);
	sn5->setSpace(20);
	sn5->setItemStartColor(QColor(254, 176, 42));
	sn5->setItemEndColor((QColor(225, 156, 37)));
	sn5->setOrientation(Qt::Vertical);
	sn5->addItem(QStringLiteral("系统设置"));
	sn5->addItem(QStringLiteral("记录查询"));
	sn5->addItem(QStringLiteral("学生管理"));
	sn5->addItem(QStringLiteral("教师管理"));
	sn5->addItem(QStringLiteral("制卡刷卡"));
	sn5->addItem(QStringLiteral("数据统计"));
	sn5->addItem(QStringLiteral("用户推出"));

	sn6->setBarRadious(5);
	sn6->setItemRadious(5);
	sn6->setSpace(20);
	sn6->setItemStartColor(QColor(255, 0, 0));
	sn6->setItemEndColor((QColor(225, 20, 10)));
	sn6->setOrientation(Qt::Vertical);
	sn6->addItem(QStringLiteral("系统设置"));
	sn6->addItem(QStringLiteral("记录查询"));
	sn6->addItem(QStringLiteral("学生管理"));
	sn6->addItem(QStringLiteral("教师管理"));
	sn6->addItem(QStringLiteral("制卡刷卡"));
	sn6->addItem(QStringLiteral("数据统计"));
	sn6->addItem(QStringLiteral("用户推出"));

	sn7->setBarRadious(5);
	sn7->setItemRadious(5);
	sn7->setSpace(20);
	sn7->setItemStartColor(QColor(191, 65, 249));
	sn7->setItemEndColor((QColor(187, 83, 217)));
	sn7->setOrientation(Qt::Vertical);
	sn7->addItem(QStringLiteral("系统设置"));
	sn7->addItem(QStringLiteral("记录查询"));
	sn7->addItem(QStringLiteral("学生管理"));
	sn7->addItem(QStringLiteral("教师管理"));
	sn7->addItem(QStringLiteral("制卡刷卡"));
	sn7->addItem(QStringLiteral("数据统计"));
	sn7->addItem(QStringLiteral("用户推出"));

	sn8->setBarRadious(5);
	sn8->setItemRadious(5);
	sn8->setSpace(20);
	sn8->setItemStartColor(QColor(62, 139, 6));
	sn8->setItemEndColor((QColor(40, 139, 28)));
	sn8->setOrientation(Qt::Vertical);
	sn8->addItem(QStringLiteral("系统设置"));
	sn8->addItem(QStringLiteral("记录查询"));
	sn8->addItem(QStringLiteral("学生管理"));
	sn8->addItem(QStringLiteral("教师管理"));
	sn8->addItem(QStringLiteral("制卡刷卡"));
	sn8->addItem(QStringLiteral("数据统计"));
	sn8->addItem(QStringLiteral("用户推出"));

	sn1->moveToFirst();
	sn2->moveToFirst();
	sn3->moveToFirst();
	sn4->moveToFirst();
	sn5->moveToFirst();
	sn6->moveToFirst();
	sn7->moveToFirst();
	sn8->moveToFirst();

	QPushButton *btn1 = new QPushButton(QStringLiteral("第一个"));
	QPushButton *btn2 = new QPushButton(QStringLiteral("末一个"));
	QPushButton *btn3 = new QPushButton(QStringLiteral("上一个"));
	QPushButton *btn4 = new QPushButton(QStringLiteral("下一个"));

	QComboBox *box = new QComboBox;
	box->addItem("0");
	box->addItem("1");
	box->addItem("2");
	box->addItem("3");
	box->addItem("4");
	box->addItem("5");
	box->addItem("6");
	box->addItem("7");
	box->setCurrentIndex(0);

	QCheckBox *checkBox = new QCheckBox(QStringLiteral("按键移动"));
	checkBox->setChecked(true);

	QHBoxLayout *lay3 = new QHBoxLayout;
	lay3->addWidget(btn1);
	lay3->addWidget(btn2);
	lay3->addWidget(btn3);
	lay3->addWidget(btn4);
	lay3->addWidget(box);
	lay3->addWidget(checkBox);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addLayout(lay2);
	layout->addLayout(lay3);
	layout->setSpacing(30);
	layout->setContentsMargins(20, 40, 20, 40);
	setLayout(layout);

	connect(btn1, &QPushButton::clicked, this, [&](){
		sn1->moveToFirst();
		sn2->moveToFirst();
		sn3->moveToFirst();
		sn4->moveToFirst();
		sn5->moveToFirst();
		sn6->moveToFirst();
		sn7->moveToFirst();
		sn8->moveToFirst();
	});

	connect(btn2, &QPushButton::clicked, this, [&](){
		sn1->moveToLast();
		sn2->moveToLast();
		sn3->moveToLast();
		sn4->moveToLast();
		sn5->moveToLast();
		sn6->moveToLast();
		sn7->moveToLast();
		sn8->moveToLast();
	});

	connect(btn3, &QPushButton::clicked, this, [&](){
		sn1->moveToPrevious();
		sn2->moveToPrevious();
		sn3->moveToPrevious();
		sn4->moveToPrevious();
		sn5->moveToPrevious();
		sn6->moveToPrevious();
		sn7->moveToPrevious();
		sn8->moveToPrevious();
	});

	connect(btn4, &QPushButton::clicked, this, [&](){
		sn1->moveToNext();
		sn2->moveToNext();
		sn3->moveToNext();
		sn4->moveToNext();
		sn5->moveToNext();
		sn6->moveToNext();
		sn7->moveToNext();
		sn8->moveToNext();
	});

	connect(box, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [&](int index){
		sn1->moveTo(index);
		sn2->moveTo(index);
		sn3->moveTo(index);
		sn4->moveTo(index);
		sn5->moveTo(index);
		sn6->moveTo(index);
		sn7->moveTo(index);
		sn8->moveTo(index);
	});

	connect(checkBox, &QCheckBox::toggled, this, [&](bool enable){
		sn1->setEnableKeyMove(enable);
		sn2->setEnableKeyMove(enable);
		sn3->setEnableKeyMove(enable);
		sn4->setEnableKeyMove(enable);
		sn5->setEnableKeyMove(enable);
		sn6->setEnableKeyMove(enable);
		sn7->setEnableKeyMove(enable);
		sn8->setEnableKeyMove(enable);
	});
}

SliderNavigationPanel::~SliderNavigationPanel()
{

}
