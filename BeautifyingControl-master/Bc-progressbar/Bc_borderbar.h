#ifndef BORDERBAR_H
#define BORDERBAR_H

#include <QWidget>
#include <QPen>

#define RADIAN 360 * 16
#define DRAWTEXT(painter, pen, font)	\
								{	\
		font.setPixelSize(width()/4);	\
		painter.setFont(font);	\
		pen.setColor(textColor());	\
		painter.setPen(pen);	\
		painter.drawText(0, 0, width(), height(), Qt::AlignCenter,	\
						 QString::number(100 * percentage()) + "%");	\
								}	\

class BaseWidget : public QWidget
{
	Q_OBJECT
public:
	explicit BaseWidget(QWidget *parent = 0);
	explicit BaseWidget(int _currentValue, int _maxValue, QWidget *parent = 0);
	virtual ~BaseWidget() {}

	qreal percentage();				//	获取当前值与最大值的比例..

	inline int currentValue() const { return m_currentValue; }
	inline int maxValue() const { return m_maxValue; }

	QColor backgroundColor() const;
	void setBackgroundColor(const QColor &backgroundColor);

	QColor foregroundColor() const;
	void setForegroundColor(const QColor &foregroundColor);

	QColor textColor() const;
	void setTextColor(const QColor &testColor);

signals:
	void done();

	public slots:
	void setCurrentValue(int currentValue);
	void setMaxValue(int maxValue);
	void setCurrentValue(qreal value);

protected:
	virtual void paintEvent(QPaintEvent *);

private:
	int m_currentValue, m_maxValue;
	QColor m_backgroundColor;
	QColor m_foregroundColor;
	QColor m_textColor;
};

class BorderBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit BorderBar(QWidget *parent = 0);
	explicit BorderBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~BorderBar() {}

	QFont font() const;
	void setFont(const QFont &font);

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);

private:
	QFont m_font;
	QPen m_pen;
};

class BorderSectorBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit BorderSectorBar(QWidget *parent = 0);
	explicit BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~BorderSectorBar() {}

	QFont font() const;
	void setFont(const QFont &font);

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);

private:
	QPen m_pen;
	QFont m_font;
};

class CircelBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit CircelBar(QWidget *parent = 0);
	explicit CircelBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~CircelBar() {}

	QFont font() const;
	void setFont(const QFont &font);

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);

private:
	QFont m_font;
	QPen m_pen;
};

class HorizontalBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit HorizontalBar(QWidget *parent = 0);
	explicit HorizontalBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~HorizontalBar() {}

	QFont font() const;
	void setFont(const QFont &font);

	inline bool drag() const { return m_drag; }
	inline void setDrag(bool drag) { m_drag = drag; }
	inline bool cursorChange() const { return m_cursorChange; }
	inline void setCursorChange(bool cursorChange) { m_cursorChange = cursorChange; }

	Qt::CursorShape normalCursor() const;
	void setNormalCursor(const Qt::CursorShape &normalCursor);

	Qt::CursorShape enterCursor() const;
	void setEnterCursor(const Qt::CursorShape &enterCursor);

signals:
	void currentValueChanged(int);

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);

	// 进度条拖动...
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);

	// 鼠标样式..
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);

private:
	QPen m_pen;
	QFont m_font;

	bool m_drag;		//	控制进度条是否可以拖动.. 默认不可拖动
	bool m_isPressed;	//	鼠标是否按下..

	// 鼠标正常和进入样式..
	bool m_cursorChange;		//	鼠标样式是否改变..
	Qt::CursorShape m_normalCursor;
	Qt::CursorShape m_enterCursor;
};

#endif // BORDERBAR_H
