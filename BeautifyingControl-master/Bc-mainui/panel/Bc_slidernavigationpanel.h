#ifndef BC_SLIDERNAVIGATIONPANEL_H
#define BC_SLIDERNAVIGATIONPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>

#include "../Bc-navigationbar/Bc_slidenavigation.h"

class SliderNavigationPanel : public QWidget
{
	Q_OBJECT
public:
	explicit SliderNavigationPanel(QWidget *parent = Q_NULLPTR);
	~SliderNavigationPanel();

private:
	SlideNavigation *sn1;
	SlideNavigation *sn2;
	SlideNavigation *sn3;
	SlideNavigation *sn4;
	SlideNavigation *sn5;
	SlideNavigation *sn6;
	SlideNavigation *sn7;
	SlideNavigation *sn8;
};

#endif // BC_SLIDERNAVIGATIONPANEL_H
