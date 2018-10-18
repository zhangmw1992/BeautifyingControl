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

	objMap.insert(QStringLiteral("多彩进度条"), index++);
	stackedWidget->addWidget(new ColorProgressBarPanel);

	objMap.insert(QStringLiteral("多态进度条"), index++);
	stackedWidget->addWidget(new DynamicProgressBar);

	objMap.insert(QStringLiteral("圆环进度条"), index++);
	stackedWidget->addWidget(new RoundProgressBarPanel);

	objMap.insert(QStringLiteral("饰边进度条"), index++);
	stackedWidget->addWidget(new BorderBarPanel);

	objMap.insert(QStringLiteral("滑动导航栏"), index++);
	stackedWidget->addWidget(new SliderNavigationPanel);

	objMap.insert(QStringLiteral("扁平化控件"), index++);
	stackedWidget->addWidget(new FlatPanel);

	objMap.insert(QStringLiteral("验证码控件"), index++);
	stackedWidget->addWidget(new CodeAreaPanel);
}

void MainWindow::onClicked(const QModelIndex &index)
{
	int index_ = objMap.value(index.data().toString());

	if (stackedWidget->currentIndex() != index_) {
		stackedWidget->setCurrentIndex(index_);
	}
}


