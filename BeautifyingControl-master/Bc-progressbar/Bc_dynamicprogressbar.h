#ifndef BC_DYNAMICPROGRESSBAR_H
#define BC_DYNAMICPROGRESSBAR_H

#include <QWidget>

class CircleWait;
class DonutWait;
class LineWait;
class TaiChiWait;
class ZoomCircleWait;
class PieWait;

class DynamicProgressBar : public QWidget
{
	Q_OBJECT

public:
	DynamicProgressBar(QWidget *parent = Q_NULLPTR);
	~DynamicProgressBar();

private:
	CircleWait      *circle1;
	CircleWait      *circle2;

	DonutWait       *donut1;
	DonutWait       *donut2;
	
	LineWait        *line1;
	LineWait        *line2;

	TaiChiWait      *taichi1;
	TaiChiWait      *taichi2;

	PieWait         *pie1;
	PieWait         *pie2;

	ZoomCircleWait  *zoomCircle1;
	ZoomCircleWait  *zoomCircle2;
	ZoomCircleWait  *zoomCircle3;
};

class CircleWait : public QWidget
{
	Q_OBJECT
public:
	explicit CircleWait(QWidget *parent = 0);

	void setColor(QColor color);
	void setClockwiseRotate(bool clockwise);
	void setRotateDelta(int delta);

protected:
	void paintEvent(QPaintEvent *);
	void drawCircleWait(QPainter& p); // 圆形等待

private:
	QColor m_color;
	bool m_clockwiseRotate;   // 顺时针旋转
	int m_rotateDelta;        // 旋转步进角度
	int m_rotateAngle;        // 旋转角度

	QTimer* m_timer;
};

class DonutWait : public QWidget
{
	Q_OBJECT
public:
	explicit DonutWait(QWidget *parent = 0);

	void setFrontColor(QColor color);
	void setBackColor(QColor color);
	void setClockwiseRotate(bool clockwise);
	void setRotateDelta(int delta);

protected:
	void paintEvent(QPaintEvent *);
	void drawDonutWait(QPainter& p);   // 环形
	void drawText(QPainter& p);

private:
	QColor m_frontColor;      // 前景色
	QColor m_backColor;       // 背景色
	bool m_clockwiseRotate;   // 顺时针旋转
	int m_rotateDelta;        // 旋转步进角度
	int m_rotateAngle;        // 旋转角度

	QTimer* m_timer;
};

class LineWait : public QWidget
{
	Q_OBJECT
public:
	explicit LineWait(QWidget *parent = 0);

	void setColor(QColor color);
	void setClockwiseRotate(bool clockwise);
	void setRotateDelta(int delta);

protected:
	void paintEvent(QPaintEvent *);
	void drawLineWait(QPainter& p);  // 圆形等待

private:
	QColor m_color;
	bool m_clockwiseRotate;   // 顺时针旋转
	int m_rotateDelta;        // 旋转步进角度
	int m_rotateAngle;        // 旋转角度

	QTimer* m_timer;
};

class PieWait : public QWidget
{
	Q_OBJECT
public:
	explicit PieWait(QWidget *parent = 0);

	void setFrontColor(QColor color);
	void setBackColor(QColor color);
	void setClockwiseRotate(bool clockwise);
	void setRotateDelta(int delta);

protected:
	void paintEvent(QPaintEvent *);
	void drawPieWait(QPainter& p);   // 饼状等待图

private:
	QColor m_frontColor;     // 前景色
	QColor m_backColor;      // 背景色
	bool m_clockwiseRotate;  // 顺时针旋转
	int m_rotateDelta;       // 旋转步进角度
	int m_rotateAngle;       // 旋转角度

	QTimer* m_timer;
};

class TaiChiWait : public QWidget
{
	Q_OBJECT
public:
	explicit TaiChiWait(QWidget *parent = 0);

	void setFrontColor(QColor color);
	void setBackColor(QColor color);
	void setClockwiseRotate(bool clockwise);
	void setRotateDelta(int delta);

protected:
	void paintEvent(QPaintEvent *);
	void drawTaiChiWait(QPainter& p);  // 太极

private:
	QColor m_frontColor;      // 前景色
	QColor m_backColor;       // 背景色
	bool m_clockwiseRotate;   // 顺时针旋转
	int m_rotateDelta;        // 旋转步进角度
	int m_rotateAngle;        // 旋转角度

	QTimer* m_timer;
};

class ZoomCircleWait : public QWidget
{
	Q_OBJECT
public:
	explicit ZoomCircleWait(QWidget *parent = 0);

	void setColor(QColor color);
	void setZoomOut(bool zoomOut);
	void setZoomDelta(int delta);
	void setMinRadious(int value);
	void setRadious(int value);

protected:
	void paintEvent(QPaintEvent *);
	void drawZoomCricleWait(QPainter& p);   // 缩放圆

private:
	QColor m_color;     // 前景色
	bool m_zoomOut;     // 是否缩小
	int m_zoomDelta;    // 缩放步进
	int m_radious;      // 当前半径
	int m_minRadious;   // 最小半径

	QTimer* m_timer;

	void fixRaidous(int max);
};

#endif // BC_DYNAMICPROGRESSBAR_H
