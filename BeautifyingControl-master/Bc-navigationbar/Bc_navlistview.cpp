﻿#include "bc_navlistview.h"
#include <QPainter>
#include <QFile>
#include <qdom.h>

NavDelegate::NavDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
	nav = (NavListView *)parent;
}

NavDelegate::~NavDelegate()
{

}

QSize NavDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toUInt();

	if (node->level == 1) {
		return QSize(50, 35);
	} else {
		return QSize(50, 28);
	}
}

void NavDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	painter->setRenderHint(QPainter::Antialiasing);
	NavModel::TreeNode *node = (NavModel::TreeNode *)index.data(Qt::UserRole).toUInt();

	//绘制背景
	QColor colorBg;

	if (option.state & QStyle::State_Selected) {
		colorBg = nav->getColorBgSelected();
	} else if (option.state & QStyle::State_MouseOver) {
		colorBg = nav->getColorBgHover();
	} else {
		colorBg = nav->getColorBgNormal();
	}

	painter->fillRect(option.rect, colorBg);

	//绘制+-伸缩图片
	if (node->children.size() != 0) {
		QPixmap pix(18, 16);
		pix.fill(Qt::transparent);
		QPainter p(&pix);
		p.setRenderHint(QPainter::Antialiasing);
		int penWidth = 2;

		//根据采用的背景色判断
		QColor icoColorSelected;
		QColor icoColorNormal;
		QColor icoColorHover;

		if (nav->getIcoColorBg()) {
			icoColorSelected = nav->getColorBgNormal();
			icoColorNormal = nav->getColorBgSelected();
			icoColorHover = nav->getColorBgNormal();
		} else {
			icoColorSelected = nav->getColorTextSelected();
			icoColorNormal = nav->getColorTextNormal();
			icoColorHover = nav->getColorTextHover();
		}

		if (nav->getIcoStyle() == NavListView::IcoStyle_Cross) {
			p.setBrush(Qt::NoBrush);

			if (option.state & QStyle::State_Selected) {
				p.setPen(QPen(icoColorSelected, penWidth));
			} else if (option.state & QStyle::State_MouseOver) {
				p.setPen(QPen(icoColorHover, penWidth));
			} else {
				p.setPen(QPen(icoColorNormal, penWidth));
			}

			//绘制+-线条图片
			if (node->collapse) {
				p.drawLine(QPointF(8, 8), QPointF(18, 8));
				p.drawLine(QPointF(12, 4), QPointF(12, 12));
			} else {
				p.drawLine(QPointF(8, 8), QPointF(18, 8));
			}
		} else if (nav->getIcoStyle() == NavListView::IcoStyle_Triangle) {
			p.setPen(Qt::NoPen);

			if (option.state & QStyle::State_Selected) {
				p.setBrush(icoColorSelected);
			} else if (option.state & QStyle::State_MouseOver) {
				p.setBrush(icoColorHover);
			} else {
				p.setBrush(icoColorNormal);
			}

			QVector<QPointF> points;

			//绘制三角形图片
			if (node->collapse) {
				points.append(QPointF(6, 4));
				points.append(QPointF(6, 12));
				points.append(QPointF(16, 8));
			} else {
				points.append(QPointF(6, 4));
				points.append(QPointF(18, 4));
				points.append(QPointF(12, 10));
			}

			p.drawPolygon(points);
		}

		QPixmap img(pix);
		QRect targetRect = option.rect;
		targetRect.setWidth(16);
		targetRect.setHeight(16);
		QPoint c = option.rect.center();
		c.setX(13);
		targetRect.moveCenter(c);
		painter->drawPixmap(targetRect, img, img.rect());
	}

	//绘制竖线条
	if (node->level == 2 && nav->getVerLineVisible()) {
		if (option.state & QStyle::State_Selected || option.state & QStyle::State_MouseOver) {
			painter->fillRect(QRectF(QPointF(option.rect.x(), option.rect.y()), 
				QPointF(option.rect.x() + nav->getWidthVerLine() - 2, option.rect.y() + option.rect.height())),
				nav->getVerColorLine());
		}
	}

	//绘制三角形图片
	if (node->level == 2) {
		if (option.state & QStyle::State_Selected || option.state & QStyle::State_MouseOver) {
			QVector<QPointF> points;
			points.append(QPointF(option.rect.x() + option.rect.width(), option.rect.y() + option.rect.height() / 2 - 5));
			points.append(QPointF(option.rect.x() + option.rect.width(), option.rect.y() + option.rect.height() / 2 + 5));
			points.append(QPointF(option.rect.x() + option.rect.width() - 5, option.rect.y() + option.rect.height() / 2));

			QPainterPath path;
			path.addPolygon(QPolygonF(points));
			painter->fillPath(path, QColor(255, 255, 255));
		}
	}

	//绘制条目文字
	QColor colorText;

	if (option.state & QStyle::State_Selected) {
		colorText = nav->getColorTextSelected();
	} else if (option.state & QStyle::State_MouseOver) {
		colorText = nav->getColorTextHover();
	} else {
		colorText = nav->getColorTextNormal();
	}

	painter->setPen(QPen(colorText));

	//绘制文字离左边的距离
	int margin = 30;

	if (node->level == 2) {
		margin = 50;
	}

	QRect rect = option.rect;
	rect.setWidth(rect.width() - margin);
	rect.setX(rect.x() + margin);

	QFont normalFont("Microsoft Yahei", 7);
	painter->setFont(normalFont);
	painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());

	if (!node->icon.isEmpty()) {
		QPixmap pix_icon(node->icon);
		painter->drawPixmap(QRect(rect.x() - 20, rect.y()+(rect.height()-15)/2, 15, 15), pix_icon.scaled(15, 15, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	}

	//绘制分隔符线条
	if (nav->getLineVisible()) {
		painter->setPen(QPen(nav->getColorLine(), 1));

		if (node->level == 1 || (node->level == 2 && node->theLast)) {
			painter->drawLine(QPointF(option.rect.x(), option.rect.y() + option.rect.height()),
			                  QPointF(option.rect.x() + option.rect.width(), option.rect.y() + option.rect.height()));
		}
	}

	//绘制提示信息
	QString recordInfo = node->info;

	//如果不需要显示提示信息或者提示信息为空则返回
	if (!nav->getInfoVisible() || recordInfo.isEmpty()) {
		return;
	}

	QPen decorationPen((option.state & QStyle::State_Selected || option.state & QStyle::State_MouseOver) ? nav->getColorBgSelected() : nav->getColorTextSelected());
	QBrush decorationBrush((option.state & QStyle::State_Selected || option.state & QStyle::State_MouseOver) ? nav->getColorTextSelected() : nav->getColorBgSelected());
	QFont decorationFont("Microsoft Yahei", 6);
	painter->setFont(decorationFont);

	//绘制提示信息背景
	QRect decoration = option.rect;
	decoration.setHeight(16);
	decoration.moveCenter(option.rect.center());
	decoration.setLeft(option.rect.right() - 45);
	decoration.setRight(option.rect.right() - 5);

	painter->setPen(decorationPen);
	QPainterPath path;
	path.addRoundedRect(decoration, 8, 8);
	painter->fillPath(path, decorationBrush);

	//如果是数字则将超过99的数字显示成 99+
	if (recordInfo.toInt() > 99) {
		recordInfo = "99+";
	}

	//如果显示的提示信息长度超过4则将多余显示成省略号..
	if (recordInfo.length() > 4) {
		recordInfo = recordInfo.mid(0, 4) + "..";
	}

	painter->drawText(decoration, Qt::AlignCenter, recordInfo);
}


NavModel::NavModel(QObject *parent)
	: QAbstractListModel(parent)
{

}

NavModel::~NavModel()
{
	for (std::vector<TreeNode *>::iterator it = treeNode.begin(); it != treeNode.end();) {
		for (std::list<TreeNode *>::iterator child = (*it)->children.begin(); child != (*it)->children.end();) {
			delete(*child);
			child = (*it)->children.erase(child);
		}

		delete(*it);
		it = treeNode.erase(it);
	}
}

void NavModel::readData(QString path)
{
	QFile xml(path);

	if (!xml.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}

	QDomDocument doc;

	if (!doc.setContent(&xml, false)) {
		return;
	}

	treeNode.clear();
	listNode.clear();

	QDomNode root = doc.documentElement().firstChildElement("layout");
	QDomNodeList children = root.childNodes();

	for (int i = 0; i != children.count(); ++i) {
		QDomElement nodeInfo = children.at(i).toElement();
		TreeNode *node = new TreeNode;
		node->icon = nodeInfo.attribute("icon");
		node->label = nodeInfo.attribute("label");
		node->collapse = nodeInfo.attribute("collapse").toInt();
		node->info = nodeInfo.attribute("info");
		node->level = 1;

		QDomNodeList secondLevel = nodeInfo.childNodes();

		for (int j = 0; j != secondLevel.count(); ++j) {
			QDomElement secNodeInfo = secondLevel.at(j).toElement();
			TreeNode *secNode = new TreeNode;
			secNode->icon = secNodeInfo.attribute("icon");
			secNode->label = secNodeInfo.attribute("label");
			secNode->info = secNodeInfo.attribute("info"); 
			secNode->collapse = false;
			secNode->level = 2;
			secNode->theLast = (j == secondLevel.count() - 1 && i != children.count() - 1);
			node->children.push_back(secNode);
		}

		treeNode.push_back(node);
	}

	refreshList();
	beginResetModel();
	endResetModel();
}

void NavModel::setData(QStringList listItem)
{
	int count = listItem.count();

	if (count == 0) {
		return;
	}

	treeNode.clear();
	listNode.clear();

	//listItem格式: 标题|父节点标题(父节点为空)|是否展开|提示信息
	for (int i = 0; i < count; i++) {
		QString item = listItem.at(i);
		QStringList list = item.split("|");

		if (list.count() < 4) {
			continue;
		}

		//首先先将父节点即父节点标题为空的元素加载完毕
		QString title = list.at(0);
		QString fatherTitle = list.at(1);
		QString collapse = list.at(2);
		QString info = list.at(3);

		if (fatherTitle.isEmpty()) {
			TreeNode *node = new TreeNode;
			node->label = title;
			node->collapse = collapse.toInt();
			node->info = info;
			node->level = 1;

			//查找该父节点是否有对应子节点,有则加载
			for (int j = 0; j < count; j++) {
				QString secItem = listItem.at(j);
				QStringList secList = secItem.split("|");

				if (secList.count() < 4) {
					continue;
				}

                QString secTitle = secList.at(0);
                QString secFatherTitle = secList.at(1);
                QString secInfo = secList.at(3);

				if (secFatherTitle == title) {
					TreeNode *secNode = new TreeNode;
					secNode->label = secTitle;
					secNode->info = secInfo;
					secNode->collapse = false;
					secNode->level = 2;
					secNode->theLast = (j == count - 1);
					node->children.push_back(secNode);
				}
			}

			treeNode.push_back(node);
		}
	}

	refreshList();
	beginResetModel();
	endResetModel();
}

int NavModel::rowCount(const QModelIndex &parent) const
{
	return listNode.size();
}

QVariant NavModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) {
		return QVariant();
	}

	if (index.row() >= listNode.size() || index.row() < 0) {
		return QVariant();
	}

	if (role == Qt::DisplayRole) {
		return listNode[index.row()].label;
	} else if (role == Qt::UserRole) {
		return (unsigned int)(listNode[index.row()].treeNode);
	}

	return QVariant();
}

void NavModel::refreshList()
{
	listNode.clear();

	for (std::vector<TreeNode *>::iterator it = treeNode.begin(); it != treeNode.end(); ++it) {
		ListNode node;
		node.label = (*it)->label;
		node.treeNode = *it;

		listNode.push_back(node);

		if ((*it)->collapse) {
			continue;
		}

		for (std::list<TreeNode *>::iterator child = (*it)->children.begin(); child != (*it)->children.end(); ++child) {
			ListNode node;
			node.label = (*child)->label;
			node.treeNode = *child;
			node.treeNode->theLast = false;
			listNode.push_back(node);
		}

		if (!listNode.empty()) {
			listNode.back().treeNode->theLast = true;
		}
	}
}

void NavModel::collapse(const QModelIndex &index)
{
	TreeNode *node = listNode[index.row()].treeNode;

	if (node->children.size() == 0) {
		return;
	}

	node->collapse = !node->collapse;
	refreshList();

	if (!node->collapse) {
		beginInsertRows(QModelIndex(), index.row() + 1, index.row() + node->children.size());
		endInsertRows();
	} else {
		beginRemoveRows(QModelIndex(), index.row() + 1, index.row() + node->children.size());
		endRemoveRows();
	}
}


NavListView::NavListView(QWidget *parent)
	: QListView(parent)
{
	infoVisible = true;
	lineVisible = true;
	verLineVisible = true;
	icoColorBg = false;

	widthVerLine = 5;

	style = NavListView::IcoStyle_Cross;

	colorLine = QColor(126, 127, 134);
	colorVerLine = QColor(0, 187, 158);

	colorBgNormal = QColor(57, 61, 73);
	colorBgSelected = QColor(20, 20, 20);
	colorBgHover = QColor(20, 20, 20);

	colorTextNormal = QColor(255, 255, 255);
	colorTextSelected = QColor(255, 255, 255);
	colorTextHover = QColor(255, 255, 255);

	this->setMouseTracking(true);
	model = new NavModel(this);
	delegate = new NavDelegate(this);
	connect(this, SIGNAL(clicked(QModelIndex)), model, SLOT(collapse(QModelIndex)));
}

NavListView::~NavListView()
{
	delete model;
	delete delegate;
}

void NavListView::readData(QString xmlPath)
{
	model->readData(xmlPath);
	this->setModel(model);
	this->setItemDelegate(delegate);
}

void NavListView::setData(QStringList listItem)
{
	model->setData(listItem);
	this->setModel(model);
	this->setItemDelegate(delegate);
}

void NavListView::setInfoVisible(bool infoVisible)
{
	this->infoVisible = infoVisible;
}

void NavListView::setLineVisible(bool lineVisible)
{
	this->lineVisible = lineVisible;
}

void NavListView::setVerLineVisible(bool verLineVisible)
{
	this->verLineVisible = verLineVisible;
}

void NavListView::setVerLineWidth(int width)
{
	this->widthVerLine = width;
}

void NavListView::setIcoColorBg(bool icoColorBg)
{
	this->icoColorBg = icoColorBg;
}

void NavListView::setIcoStyle(NavListView::IcoStyle style)
{
	this->style = style;
}

void NavListView::setColorLine(QColor colorLine)
{
	this->colorLine = colorLine;
}

void NavListView::setColorVerLine(QColor colorVerLine)
{
	this->colorVerLine = colorVerLine;
}

void NavListView::setColorBg(QColor colorBgNormal, QColor colorBgSelected, QColor colorBgHover)
{
	this->colorBgNormal = colorBgNormal;
	this->colorBgSelected = colorBgSelected;
	this->colorBgHover = colorBgHover;
}

void NavListView::setColorText(QColor colorTextNormal, QColor colorTextSelected, QColor colorTextHover)
{
	this->colorTextNormal = colorTextNormal;
	this->colorTextSelected = colorTextSelected;
	this->colorTextHover = colorTextHover;
}
