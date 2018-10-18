#ifndef BC_CODEAREAPANEL_H
#define BC_CODEAREAPANEL_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

#include "../Bc-others/Bc_codearea.h"

class CodeAreaPanel : public QWidget
{
	Q_OBJECT

public:
	explicit CodeAreaPanel(QWidget *parent = Q_NULLPTR);
	~CodeAreaPanel();

private:
	QPushButton *flushBtn;
	QPushButton *checkBtn;
	QLineEdit   *lineEdit;

	CodeArea    *ca;
};

#endif // BC_CODEAREAPANEL_H
