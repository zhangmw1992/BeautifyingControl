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

	sn1->addItem(QStringLiteral("����һ"));
	sn1->addItem(QStringLiteral("���ڶ�"));
	sn1->addItem(QStringLiteral("������"));
	sn1->addItem(QStringLiteral("������"));
	sn1->addItem(QStringLiteral("������"));
	sn1->addItem(QStringLiteral("������"));
	sn1->addItem(QStringLiteral("������"));
	sn1->addItem(QStringLiteral("���ڰ�"));

	sn2->setBarRadious(5);
	sn2->setItemRadious(5);
	sn2->setItemStartColor(QColor(254, 176, 42));
	sn2->setItemEndColor((QColor(225, 156, 37)));
	sn2->addItem(QStringLiteral("��һ��"));
	sn2->addItem(QStringLiteral("�ڶ���"));
	sn2->addItem(QStringLiteral("������"));
	sn2->addItem(QStringLiteral("���Ĵ�"));
	sn2->addItem(QStringLiteral("�����"));
	sn2->addItem(QStringLiteral("������"));
	sn2->addItem(QStringLiteral("���ߴ�"));
	sn2->addItem(QStringLiteral("�ڰ˴�"));

	sn3->setBarRadious(10);
	sn3->setItemRadious(10);
	sn3->setItemStartColor(QColor(255, 0, 0));
	sn3->setItemEndColor((QColor(225, 20, 10)));
	sn3->addItem(QStringLiteral("��һ��"));
	sn3->addItem(QStringLiteral("�ڶ���"));
	sn3->addItem(QStringLiteral("������"));
	sn3->addItem(QStringLiteral("������"));
	sn3->addItem(QStringLiteral("������"));
	sn3->addItem(QStringLiteral("������"));
	sn3->addItem(QStringLiteral("������"));
	sn3->addItem(QStringLiteral("�ڰ���"));

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
	sn4->addItem(QStringLiteral("ϵͳ����"));
	sn4->addItem(QStringLiteral("��¼��ѯ"));
	sn4->addItem(QStringLiteral("ѧ������"));
	sn4->addItem(QStringLiteral("��ʦ����"));
	sn4->addItem(QStringLiteral("�ƿ�ˢ��"));
	sn4->addItem(QStringLiteral("����ͳ��"));
	sn4->addItem(QStringLiteral("�û��Ƴ�"));

	sn5->setBarRadious(5);
	sn5->setItemRadious(5);
	sn5->setSpace(20);
	sn5->setItemStartColor(QColor(254, 176, 42));
	sn5->setItemEndColor((QColor(225, 156, 37)));
	sn5->setOrientation(Qt::Vertical);
	sn5->addItem(QStringLiteral("ϵͳ����"));
	sn5->addItem(QStringLiteral("��¼��ѯ"));
	sn5->addItem(QStringLiteral("ѧ������"));
	sn5->addItem(QStringLiteral("��ʦ����"));
	sn5->addItem(QStringLiteral("�ƿ�ˢ��"));
	sn5->addItem(QStringLiteral("����ͳ��"));
	sn5->addItem(QStringLiteral("�û��Ƴ�"));

	sn6->setBarRadious(5);
	sn6->setItemRadious(5);
	sn6->setSpace(20);
	sn6->setItemStartColor(QColor(255, 0, 0));
	sn6->setItemEndColor((QColor(225, 20, 10)));
	sn6->setOrientation(Qt::Vertical);
	sn6->addItem(QStringLiteral("ϵͳ����"));
	sn6->addItem(QStringLiteral("��¼��ѯ"));
	sn6->addItem(QStringLiteral("ѧ������"));
	sn6->addItem(QStringLiteral("��ʦ����"));
	sn6->addItem(QStringLiteral("�ƿ�ˢ��"));
	sn6->addItem(QStringLiteral("����ͳ��"));
	sn6->addItem(QStringLiteral("�û��Ƴ�"));

	sn7->setBarRadious(5);
	sn7->setItemRadious(5);
	sn7->setSpace(20);
	sn7->setItemStartColor(QColor(191, 65, 249));
	sn7->setItemEndColor((QColor(187, 83, 217)));
	sn7->setOrientation(Qt::Vertical);
	sn7->addItem(QStringLiteral("ϵͳ����"));
	sn7->addItem(QStringLiteral("��¼��ѯ"));
	sn7->addItem(QStringLiteral("ѧ������"));
	sn7->addItem(QStringLiteral("��ʦ����"));
	sn7->addItem(QStringLiteral("�ƿ�ˢ��"));
	sn7->addItem(QStringLiteral("����ͳ��"));
	sn7->addItem(QStringLiteral("�û��Ƴ�"));

	sn8->setBarRadious(5);
	sn8->setItemRadious(5);
	sn8->setSpace(20);
	sn8->setItemStartColor(QColor(62, 139, 6));
	sn8->setItemEndColor((QColor(40, 139, 28)));
	sn8->setOrientation(Qt::Vertical);
	sn8->addItem(QStringLiteral("ϵͳ����"));
	sn8->addItem(QStringLiteral("��¼��ѯ"));
	sn8->addItem(QStringLiteral("ѧ������"));
	sn8->addItem(QStringLiteral("��ʦ����"));
	sn8->addItem(QStringLiteral("�ƿ�ˢ��"));
	sn8->addItem(QStringLiteral("����ͳ��"));
	sn8->addItem(QStringLiteral("�û��Ƴ�"));

	sn1->moveToFirst();
	sn2->moveToFirst();
	sn3->moveToFirst();
	sn4->moveToFirst();
	sn5->moveToFirst();
	sn6->moveToFirst();
	sn7->moveToFirst();
	sn8->moveToFirst();

	QPushButton *btn1 = new QPushButton(QStringLiteral("��һ��"));
	QPushButton *btn2 = new QPushButton(QStringLiteral("ĩһ��"));
	QPushButton *btn3 = new QPushButton(QStringLiteral("��һ��"));
	QPushButton *btn4 = new QPushButton(QStringLiteral("��һ��"));

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

	QCheckBox *checkBox = new QCheckBox(QStringLiteral("�����ƶ�"));
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
