#ifndef BC_BORDERBARPANEL_H
#define BC_BORDERBARPANEL_H

#include <QWidget>

#include "../Bc-progressbar/Bc_borderbar.h"

class BorderBarPanel : public QWidget
{
	Q_OBJECT
public:
	explicit BorderBarPanel(QWidget *parent = Q_NULLPTR);
	~BorderBarPanel();

protected:
	void paintEvent(QPaintEvent *event);

private:
	BorderBar *m_borderBar;
	BorderSectorBar *m_borderSectorBar;
	CircelBar *m_circeBar;
	HorizontalBar *m_horizontalBar;
};

#endif // BC_BORDERBARPANEL_H
