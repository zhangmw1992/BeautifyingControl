#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>

#include "../Bc-navigationbar/Bc_navlistview.h"
#include "../Bc-progressbar/Bc_dynamicprogressbar.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
    void onClicked(const QModelIndex &index);

protected:
	void initUi();
	void initLayout();
	void initConnection();

	void initMap();

private:
	NavListView    *navListView;

	QStackedWidget *stackedWidget;

	QMap<QString, int> objMap;
};

#endif // MAINWINDOW_H
