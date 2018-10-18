#include "Bc_dynamicprogressbar.h"
#include <QPainter>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>

DynamicProgressBar::DynamicProgressBar(QWidget *parent)
	: QWidget(parent)
{
	taichi1 = new TaiChiWait;
	taichi2 = new TaiChiWait;

	taichi1->setFrontColor(QColor(97, 117, 118));
	taichi1->setBackColor(QColor(255, 107, 107));
	taichi2->setFrontColor(QColor(24, 189, 155));
	taichi2->setBackColor(Qt::white);
	taichi2->setClockwiseRotate(false);

	circle1 = new CircleWait;
	circle2 = new CircleWait;

	circle1->setColor(QColor(253, 120, 120));
	circle2->setColor(QColor(46, 194, 163));
	circle2->setClockwiseRotate(false);

	pie1 = new PieWait;
	pie2 = new PieWait;

	pie1->setFrontColor(QColor(255, 107, 107));
	pie1->setBackColor(QColor(97, 117, 118));
	pie2->setFrontColor(QColor(24, 189, 155));
	pie2->setBackColor(Qt::white);
	pie2->setClockwiseRotate(false);

	line1 = new LineWait;
	line2 = new LineWait;

	line1->setColor(QColor(253, 132, 132));
	line2->setColor(QColor(46, 194, 164));
	line2->setClockwiseRotate(false);

	donut1 = new DonutWait;
	donut2 = new DonutWait;

	donut1->setFrontColor(QColor(255, 107, 107));
	donut1->setBackColor(QColor(97, 117, 118));
	donut2->setFrontColor(QColor(24, 189, 155));
	donut2->setBackColor(Qt::white);
	donut2->setClockwiseRotate(false);

	zoomCircle1 = new ZoomCircleWait;
	zoomCircle2 = new ZoomCircleWait;
	zoomCircle3 = new ZoomCircleWait;

	zoomCircle1->setColor(QColor(255, 107, 107));
	zoomCircle1->setZoomDelta(5);
	zoomCircle2->setColor(QColor(24, 189, 155));
	zoomCircle2->setMinRadious(25);
	zoomCircle2->setZoomDelta(5);
	zoomCircle2->setZoomOut(true);
	zoomCircle3->setColor(QColor(24, 189, 155));
	zoomCircle3->setMinRadious(25);
	zoomCircle3->setRadious(50);
	zoomCircle3->setZoomDelta(5);
	zoomCircle3->setZoomOut(true);

	QHBoxLayout *lay1 = new QHBoxLayout;
	lay1->addWidget(taichi1);
	lay1->addWidget(circle1);
	lay1->addWidget(pie1);
	lay1->addWidget(line1);
	lay1->addWidget(donut1);
	lay1->addWidget(zoomCircle1);

	QHBoxLayout *lay2 = new QHBoxLayout;
	lay2->addWidget(zoomCircle2);
	lay2->addWidget(zoomCircle3);

	QHBoxLayout *lay3 = new QHBoxLayout;
	lay3->addWidget(taichi2);
	lay3->addWidget(circle2);
	lay3->addWidget(pie2);
	lay3->addWidget(line2);
	lay3->addWidget(donut2);
	lay3->addLayout(lay2);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addLayout(lay3);
	layout->setContentsMargins(20, 20, 20, 300);
	setLayout(layout);
}

DynamicProgressBar::~DynamicProgressBar()
{

}


CircleWait::CircleWait(QWidget *parent)
	: QWidget(parent)
	, m_color(Qt::black)
	, m_clockwiseRotate(true)
	, m_rotateDelta(36)
	, m_rotateAngle(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void CircleWait::setColor(QColor color)
{
	if (color != m_color) {
		m_color = color;
		update();
	}
}

void CircleWait::setClockwiseRotate(bool clockwise)
{
	if (clockwise != m_clockwiseRotate) {
		m_clockwiseRotate = clockwise;
		update();
	}
}

void CircleWait::setRotateDelta(int delta)
{
	if (delta != m_rotateDelta) {
		m_rotateDelta = delta;
		update();
	}
}

void CircleWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	p.rotate(m_rotateAngle);
	drawCircleWait(p);
	m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
	m_rotateAngle %= 360;
}

void CircleWait::drawCircleWait(QPainter &p)
{
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	p.save();
	p.setPen(Qt::NoPen);
	QColor color = m_color;
	for (int i = 0; i <= 10; ++i) {
		color.setAlphaF(1.0*i / 10);
		p.setBrush(QBrush(color));
		p.drawEllipse(30, -10, 20, 20);
		p.rotate(36);
	}
	p.restore();
}


DonutWait::DonutWait(QWidget *parent)
	: QWidget(parent)
	, m_frontColor(Qt::yellow)
    , m_backColor(Qt::black)
    , m_clockwiseRotate(true)
    , m_rotateDelta(36)
    , m_rotateAngle(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void DonutWait::setFrontColor(QColor color)
{
	if (color != m_frontColor) {
		m_frontColor = color;
		update();
	}
}

void DonutWait::setBackColor(QColor color)
{
	if (color != m_backColor) {
		m_backColor = color;
		update();
	}
}

void DonutWait::setClockwiseRotate(bool clockwise)
{
	if (clockwise != m_clockwiseRotate) {
		m_clockwiseRotate = clockwise;
		update();
	}
}

void DonutWait::setRotateDelta(int delta)
{
	if (delta != m_rotateDelta) {
		m_rotateDelta = delta;
		update();
	}
}

void DonutWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
	p.rotate(m_rotateAngle);
	drawDonutWait(p);
	m_rotateAngle %= 360;
}

void DonutWait::drawDonutWait(QPainter &p)
{
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	int outRadious = 50;
	int inRadious = 30;
	QString valueStr = QString("%1%").arg(QString::number(qAbs(1.0*m_rotateAngle / 360 * 100), 'f', 0));
	QRectF outRect(-outRadious, -outRadious, 2 * outRadious, 2 * outRadious);
	QRectF inRect(-inRadious, -inRadious, 2 * inRadious, 2 * inRadious);
	p.save();
	p.setPen(Qt::NoPen);
	// 画外圆
	p.setBrush(QBrush(m_backColor));
	p.drawEllipse(outRect);
	p.setBrush(QBrush(m_frontColor));
	p.drawPie(outRect, 0, 60 * 16);
	// 画遮罩
	p.setBrush(palette().window().color());
	p.drawEllipse(inRect);
	// 画文字
	p.rotate(-m_rotateAngle);
	QFont f = p.font();
	f.setBold(true);
	p.setFont(f);
	p.setPen(m_frontColor);
	p.drawText(inRect, Qt::AlignCenter, valueStr);

	p.restore();
}


LineWait::LineWait(QWidget *parent)
	: QWidget(parent)
	, m_color(Qt::black)
	, m_clockwiseRotate(true)
	, m_rotateDelta(36)
	, m_rotateAngle(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void LineWait::setColor(QColor color)
{
	if (color != m_color) {
		m_color = color;
		update();
	}
}

void LineWait::setClockwiseRotate(bool clockwise)
{
	if (clockwise != m_clockwiseRotate) {
		m_clockwiseRotate = clockwise;
		update();
	}
}

void LineWait::setRotateDelta(int delta)
{
	if (delta != m_rotateDelta) {
		m_rotateDelta = delta;
		update();
	}
}

void LineWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	p.rotate(m_rotateAngle);
	drawLineWait(p);
	m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
	m_rotateAngle %= 360;
}

void LineWait::drawLineWait(QPainter &p)
{
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	p.save();
	p.setPen(Qt::NoPen);
	QColor color = m_color;
	for (int i = 0; i <= 10; ++i) {
		color.setAlphaF(1.0*i / 10);
		p.setBrush(QBrush(color));
		p.drawRoundedRect(50 * 2 / 5, -3, 50 * 3 / 5, 6, 2, 2);
		p.rotate(36);
	}
	p.restore();
}


PieWait::PieWait(QWidget *parent)
	: QWidget(parent)
	, m_frontColor(Qt::black)
	, m_backColor(Qt::white)
	, m_clockwiseRotate(true)
	, m_rotateDelta(36)
	, m_rotateAngle(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void PieWait::setFrontColor(QColor color)
{
	if (color != m_frontColor) {
		m_frontColor = color;
		update();
	}
}

void PieWait::setBackColor(QColor color)
{
	if (color != m_backColor) {
		m_backColor = color;
		update();
	}
}

void PieWait::setClockwiseRotate(bool clockwise)
{
	if (clockwise != m_clockwiseRotate) {
		m_clockwiseRotate = clockwise;
		update();
	}
}

void PieWait::setRotateDelta(int delta)
{
	if (delta != m_rotateDelta) {
		m_rotateDelta = delta;
		update();
	}
}

void PieWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	p.rotate(m_rotateAngle);
	drawPieWait(p);
	m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
	m_rotateAngle %= 360;
}

void PieWait::drawPieWait(QPainter &p)
{ 
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	p.save();
	p.setPen(Qt::NoPen);
	p.setBrush(QBrush(m_backColor));
	p.drawEllipse(-50, -50, 100, 100);
	p.setBrush(QBrush(m_frontColor));
	p.drawPie(-50, -50, 100, 100, 0 * 16, 60 * 16);
	p.restore();
}


TaiChiWait::TaiChiWait(QWidget *parent)
	: QWidget(parent)
	, m_frontColor(Qt::black)
	, m_backColor(Qt::white)
	, m_clockwiseRotate(true)
	, m_rotateDelta(36)
	, m_rotateAngle(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void TaiChiWait::setFrontColor(QColor color)
{
	if (color != m_frontColor) {
		m_frontColor = color;
		update();
	}
}

void TaiChiWait::setBackColor(QColor color)
{
	if (color != m_backColor) {
		m_backColor = color;
		update();
	}
}

void TaiChiWait::setClockwiseRotate(bool clockwise)
{
	if (clockwise != m_clockwiseRotate) {
		m_clockwiseRotate = clockwise;
		update();
	}
}

void TaiChiWait::setRotateDelta(int delta)
{
	if (delta != m_rotateDelta) {
		m_rotateDelta = delta;
		update();
	}
}

void TaiChiWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	p.rotate(m_rotateAngle);
	drawTaiChiWait(p);
	m_rotateAngle += m_clockwiseRotate ? m_rotateDelta : -m_rotateDelta;
	m_rotateAngle %= 360;
}

void TaiChiWait::drawTaiChiWait(QPainter &p)
{
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	p.save();
	p.setPen(Qt::NoPen);
	p.setBrush(QBrush(m_frontColor));
	p.drawPie(-50, -50, 100, 100, 90 * 16, 180 * 16);
	p.setBrush(QBrush(m_backColor));
	p.drawPie(-50, -50, 100, 100, 270 * 16, 180 * 16);
	p.drawEllipse(-25, -50, 50, 50);
	p.setBrush(QBrush(m_frontColor));
	p.drawEllipse(-25, 0, 50, 50);
	p.drawEllipse(-50 / 8, -50 * 5 / 8, 50 / 4, 50 / 4);
	p.setBrush(QBrush(m_backColor));
	p.drawEllipse(-50 / 8, 50 * 3 / 8, 50 / 4, 50 / 4);
	p.restore();
}


ZoomCircleWait::ZoomCircleWait(QWidget *parent)
	: QWidget(parent)
	, m_color(Qt::black)
	, m_zoomOut(false)
	, m_zoomDelta(5)
	, m_radious(0)
	, m_minRadious(0)
{
	m_timer = new QTimer;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer->start(100);
}

void ZoomCircleWait::setColor(QColor color)
{
	if (color != m_color) {
		m_color = color;
		update();
	}
}

void ZoomCircleWait::setZoomOut(bool zoomOut)
{
	if (zoomOut != m_zoomOut) {
		m_zoomOut = zoomOut;
		update();
	}
}

void ZoomCircleWait::setZoomDelta(int delta)
{
	if (delta != m_zoomDelta) {
		m_zoomDelta = delta;
		update();
	}
}

void ZoomCircleWait::setMinRadious(int value)
{
	if (value > 0 && value != m_minRadious) {
		m_minRadious = value;
		update();
	}
}

void ZoomCircleWait::setRadious(int value)
{
	if (value != m_radious && value > m_minRadious) {
		m_radious = value;
		update();
	}
}

void ZoomCircleWait::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	p.translate(width() / 2, height() / 2);
	int side = qMin(width(), height());
	p.scale(side / 100.0, side / 100.0);

	m_radious += m_zoomDelta;
	fixRaidous(50);
	drawZoomCricleWait(p);
}

void ZoomCircleWait::drawZoomCricleWait(QPainter &p)
{
	// 根据100*100的大小进行画,在paintEvent中进行过缩放
	p.save();
	p.setPen(Qt::NoPen);
	p.setBrush(QBrush(m_color));
	p.drawEllipse(-m_radious, -m_radious, 2 * m_radious, 2 * m_radious);
	p.restore();
}

void ZoomCircleWait::fixRaidous(int max)
{
	if (m_radious < m_minRadious) {
		m_radious = m_minRadious;
		m_zoomDelta = qAbs(m_zoomDelta);
	} else if (m_radious > max) {

		// 半径开始减小
		if (m_zoomOut) {
			m_radious = max;
			m_zoomDelta = -qAbs(m_zoomDelta);
		} else {
			m_radious = m_minRadious;
			m_zoomDelta = qAbs(m_zoomDelta);
		}
	}
}

