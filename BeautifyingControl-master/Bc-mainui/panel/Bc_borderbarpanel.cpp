#include "Bc_borderbarpanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>

BorderBarPanel::BorderBarPanel(QWidget *parent)
	: QWidget(parent)
{
	m_borderBar = new BorderBar(0, 100, this);
	m_borderSectorBar = new BorderSectorBar(this);
	m_circeBar = new CircelBar(this);

	m_horizontalBar = new HorizontalBar(this);
	m_horizontalBar->setFixedHeight(30);			//	最好设置一下这里..
	m_horizontalBar->setDrag(true);					//	设置可拖动..
	m_horizontalBar->setCursorChange(true);			//	进入控件改变鼠标样式..

	m_borderBar->setCurrentValue(45);
	m_borderSectorBar->setCurrentValue(45);
	m_circeBar->setCurrentValue(45);
	m_horizontalBar->setCurrentValue(45);

	connect(m_horizontalBar, &HorizontalBar::currentValueChanged, this, [&](int value){
		m_borderBar->setCurrentValue(value);
		m_borderSectorBar->setCurrentValue(value);
		m_circeBar->setCurrentValue(value);
	});

	QHBoxLayout *lay1 = new QHBoxLayout;
	lay1->addWidget(m_borderBar);
	lay1->addWidget(m_borderSectorBar);
	lay1->addWidget(m_circeBar);
	lay1->setSpacing(80);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addWidget(m_horizontalBar);
	layout->setContentsMargins(30, 40, 30, 300);
	setLayout(layout);
}

BorderBarPanel::~BorderBarPanel()
{

}

void BorderBarPanel::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.fillRect(rect(), QColor("#5f8aa4"));
}
