#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(900, 600);

	initUi();
	initLayout();
	initConnection();
	initMap();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUi()
{
	navListView = new NavListView;
	navListView->setFixedWidth(180);
	navListView->readData(":/Bc-mainui/res/config.xml");

	stackedWidget = new QStackedWidget;
}

void MainWindow::initLayout()
{
	QHBoxLayout *layout = new QHBoxLayout;

	layout->addWidget(navListView);
	layout->addWidget(stackedWidget);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	setLayout(layout);
}

void MainWindow::initConnection()
{
	connect(navListView, &NavListView::clicked, this, &MainWindow::onClicked);
}

void MainWindow::initMap()
{
	int index = 0;

	objMap.insert(QStringLiteral("��ʽ�����"), index++);
	stackedWidget->addWidget(new ColorProgressBarPanel);

	objMap.insert(QStringLiteral("��̬������"), index++);
	stackedWidget->addWidget(new DynamicProgressBar);

	objMap.insert(QStringLiteral("Բ��������"), index++);
	stackedWidget->addWidget(new RoundProgressBarPanel);

	objMap.insert(QStringLiteral("�α߽�����"), index++);
	stackedWidget->addWidget(new BorderBarPanel);

	objMap.insert(QStringLiteral("����������"), index++);
	stackedWidget->addWidget(new SliderNavigationPanel);

	objMap.insert(QStringLiteral("��ƽ���ؼ�"), index++);
	stackedWidget->addWidget(new FlatPanel);

	objMap.insert(QStringLiteral("��֤��ؼ�"), index++);
	stackedWidget->addWidget(new CodeAreaPanel);
}

void MainWindow::onClicked(const QModelIndex &index)
{
	int index_ = objMap.value(index.data().toString());

	if (stackedWidget->currentIndex() != index_) {
		stackedWidget->setCurrentIndex(index_);
	}
}


