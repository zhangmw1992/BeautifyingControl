#include "Bc_borderbar.h"
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>

BaseWidget::BaseWidget(QWidget *parent)
	: QWidget(parent)
	, m_currentValue(0)
	, m_maxValue(100)
	, m_backgroundColor("#5f8aa4")
	, m_foregroundColor("#a6becd")
	, m_textColor("#5f8aa4")
{
	resize(100, 100);
}

BaseWidget::BaseWidget(int _currentValue, int _maxValue, QWidget *parent)
	: QWidget(parent)
	, m_currentValue(_currentValue)
	, m_maxValue(_maxValue)
	, m_backgroundColor("#5f8aa4")
	, m_foregroundColor("#a6becd")
	, m_textColor("#5f8aa4")
{
	resize(100, 100);
}

qreal BaseWidget::percentage()
{
	return (qreal)m_currentValue / m_maxValue;
}

void BaseWidget::setCurrentValue(int currentValue)
{
	if (currentValue >= m_maxValue)
		m_currentValue = m_maxValue;
	else if (currentValue <= 0)
		m_currentValue = 0;
	else
		m_currentValue = currentValue;

	update();
}

void BaseWidget::setMaxValue(int maxValue)
{
	m_maxValue = maxValue;
	update();
}

void BaseWidget::setCurrentValue(qreal value)
{
	setCurrentValue(int(value * m_maxValue));
}

void BaseWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QStyleOption opt;
	opt.init(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

QColor BaseWidget::backgroundColor() const
{
	return m_backgroundColor;
}

void BaseWidget::setBackgroundColor(const QColor &backgroundColor)
{
	m_backgroundColor = backgroundColor;
}

QColor BaseWidget::foregroundColor() const
{
	return m_foregroundColor;
}

void BaseWidget::setForegroundColor(const QColor &foregroundColor)
{
	m_foregroundColor = foregroundColor;
}

QColor BaseWidget::textColor() const
{
	return m_textColor;
}

void BaseWidget::setTextColor(const QColor &textColor)
{
	m_textColor = textColor;
}


BorderBar::BorderBar(QWidget *parent) :
	BaseWidget(parent)
	, m_font()
	, m_pen()
{
	setTextColor(QColor("lightgray"));
	setMinimumSize(50, 50);
}

BorderBar::BorderBar(int _currentValue, int _maxValue, QWidget *parent)
	: BaseWidget(_currentValue, _maxValue, parent)
	, m_font()
	, m_pen()
{
	setTextColor(QColor("lightgray"));
	setMinimumSize(50, 50);
}

void BorderBar::paintEvent(QPaintEvent *)
{
	QRectF rect(2, 2, width()-4, height()-4);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setBrush(backgroundColor());
	painter.setPen(Qt::NoPen);
	painter.drawEllipse(rect);
	painter.setBrush(Qt::NoBrush);

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(4);
	painter.setPen(m_pen);

	painter.drawArc(rect, 0.25 * RADIAN, -percentage() * RADIAN);	//	+： 逆时针 -： 顺时针
	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void BorderBar::resizeEvent(QResizeEvent * /*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont BorderBar::font() const
{
	return m_font;
}

void BorderBar::setFont(const QFont &font)
{
	m_font = font;
}


BorderSectorBar::BorderSectorBar(QWidget *parent)
	: BaseWidget(parent)
	, m_pen()
	, m_font()
{
	setTextColor(QColor("#645454"));
	setMinimumSize(50, 50);
}

BorderSectorBar::BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent)
	: BaseWidget(_currentValue, _maxValue, parent)
	, m_pen()
	, m_font()
{
	setTextColor(QColor("#645454"));
	setMinimumSize(50, 50);
}

void BorderSectorBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF rect(2, 2, width() - 4, height() - 4);
	qreal _percentage = percentage();
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setPen(Qt::NoPen);
	painter.setBrush(backgroundColor());
	painter.drawEllipse(rect);

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(2);
	painter.setPen(m_pen);
	painter.drawEllipse(rect);

	if (_percentage)
	{
		painter.setBrush(foregroundColor());
		painter.drawPie(8, 8, width() - 16, height() - 16, 0.25 * RADIAN,
			-_percentage * RADIAN);		//	+： 逆时针 -： 顺时针
	}
	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void BorderSectorBar::resizeEvent(QResizeEvent * /*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
		s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont BorderSectorBar::font() const
{
	return m_font;
}

void BorderSectorBar::setFont(const QFont &font)
{
	m_font = font;
}


CircelBar::CircelBar(QWidget *parent)
	: BaseWidget(parent)
	, m_font()
	, m_pen()
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
	setMinimumSize(50, 50);
}

CircelBar::CircelBar(int _currentValue, int _maxValue, QWidget *parent) 
	: BaseWidget(_currentValue, _maxValue, parent)
	, m_font()
	, m_pen()
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
	setMinimumSize(50, 50);
}

void CircelBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF rect(2, 2, width() - 4, height() - 4);
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setPen(Qt::NoPen);
	painter.setBrush(backgroundColor());
	painter.drawEllipse(rect);

	painter.setBrush(foregroundColor());
	painter.drawPie(rect, 0.25 * RADIAN,
		-percentage() * RADIAN);

	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void CircelBar::resizeEvent(QResizeEvent * /*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
		s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont CircelBar::font() const
{
	return m_font;
}

void CircelBar::setFont(const QFont &font)
{
	m_font = font;
}


HorizontalBar::HorizontalBar(QWidget *parent)
	: BaseWidget(parent)
	, m_pen()
	, m_font()
	, m_isPressed(false)
	, m_cursorChange(false)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);

	// 默认进入区域鼠标样式..
	m_enterCursor = Qt::PointingHandCursor;
	m_normalCursor = Qt::ArrowCursor;
}

HorizontalBar::HorizontalBar(int _currentValue, int _maxValue, QWidget *parent)
	: BaseWidget(_currentValue, _maxValue, parent)
	, m_pen()
	, m_font()
	, m_isPressed(false)
	, m_cursorChange(false)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);

	// 默认进入区域鼠标样式..
	m_enterCursor = Qt::PointingHandCursor;
	m_normalCursor = Qt::ArrowCursor;
}

void HorizontalBar::paintEvent(QPaintEvent *)
{
	qreal _width = width();
	qreal _height = height();
	qreal radius = _height / 2;
	qreal _percentage = percentage();
	QPainter painter(this);
	QRectF rect(2, 2, _width - 4, _height - 4);
	QRectF rectForeground(2, 2, _height + ((_width - _height) * _percentage) - 4, _height - 4);

	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(1);
	painter.setPen(m_pen);
	painter.setBrush(backgroundColor());
	painter.drawRoundedRect(rect, radius, radius);

	painter.setBrush(foregroundColor());
	painter.drawRoundedRect(rectForeground, radius, radius);

	m_pen.setColor(textColor());
	painter.setPen(m_pen);
	painter.setFont(m_font);
	painter.drawText(rectForeground, Qt::AlignRight | Qt::AlignVCenter,
		QString::number(int(_percentage * 100)) + "% ");

}

void HorizontalBar::resizeEvent(QResizeEvent * /* e */)
{
	m_font.setPixelSize(height() / 2);
}

void HorizontalBar::mousePressEvent(QMouseEvent *e)
{
	if (!m_drag || e->button() != Qt::LeftButton)
		return;

	m_isPressed = true;
	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..
}

void HorizontalBar::mouseReleaseEvent(QMouseEvent *e)
{
	m_isPressed = false;
	if (!m_drag)
		return;

	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..

	emit currentValueChanged(currentValue());
}

void HorizontalBar::mouseMoveEvent(QMouseEvent *e)
{
	if (!m_isPressed)
		return;

	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..
}

void HorizontalBar::enterEvent(QEvent *)
{
	if (m_cursorChange)
		setCursor(m_enterCursor);
}

void HorizontalBar::leaveEvent(QEvent *)
{
	if (m_cursorChange)
		setCursor(m_normalCursor);
}

Qt::CursorShape HorizontalBar::enterCursor() const
{
	return m_enterCursor;
}

void HorizontalBar::setEnterCursor(const Qt::CursorShape &enterCursor)
{
	m_enterCursor = enterCursor;
}

Qt::CursorShape HorizontalBar::normalCursor() const
{
	return m_normalCursor;
}

void HorizontalBar::setNormalCursor(const Qt::CursorShape &normalCursor)
{
	m_normalCursor = normalCursor;
}

QFont HorizontalBar::font() const
{
	return m_font;
}

void HorizontalBar::setFont(const QFont &font)
{
	m_font = font;
}






