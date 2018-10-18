#ifndef NAVLISTVIEW_H
#define NAVLISTVIEW_H

#include <QStyledItemDelegate>
#include <QAbstractListModel>
#include <QListView>
#include <vector>

class NavListView;

class NavDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	NavDelegate(QObject *parent);
	~NavDelegate();

protected:
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const ;
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
	NavListView *nav;
};

class NavModel : public QAbstractListModel
{
	Q_OBJECT
public:
	NavModel(QObject *parent);
	~NavModel();

public:
	struct TreeNode {
		QString icon;
		QString label;
		int level;
		bool collapse;
		bool theLast;
        QString info;
		std::list<TreeNode *> children;
	};

	struct ListNode {
		QString label;
		TreeNode *treeNode;
	};

protected:
	int rowCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;

private:
	std::vector<TreeNode *> treeNode;
	std::vector<ListNode> listNode;

public slots:
	void readData(QString path);
    void setData(QStringList listItem);
	void collapse(const QModelIndex &index);

private:
	void refreshList();
};

class NavListView : public QListView
{
	Q_OBJECT
public:
	explicit NavListView(QWidget *parent = Q_NULLPTR);
	~NavListView();

	enum IcoStyle { IcoStyle_Cross = 0, IcoStyle_Triangle = 1 };

private:
	NavModel *model;
	NavDelegate *delegate;

    bool infoVisible;           // 是否显示提示信息
	bool lineVisible;           // 是否显示分割线条
	bool verLineVisible;        // 是否显示鼠标选中悬浮线条
	bool icoColorBg;            // 伸缩图片是否使用颜色
	IcoStyle style;             // 图标样式

	int widthVerLine;           // 竖条宽度

	QColor colorLine;           // 线条颜色
	QColor colorVerLine;        // 线条颜色

	QColor colorBgNormal;       // 正常背景色
	QColor colorBgSelected;     // 选中背景色
	QColor colorBgHover;        // 悬停背景色

	QColor colorTextNormal;     // 正常文字颜色
	QColor colorTextSelected;   // 选中文字颜色
	QColor colorTextHover;      // 悬停文字颜色

public:
    bool getInfoVisible() const {
        return infoVisible;
	}

	bool getLineVisible() const {
		return lineVisible;
	}

	bool getVerLineVisible() const {
		return verLineVisible;
	}

	bool getIcoColorBg() const {
		return icoColorBg;
	}

	int getWidthVerLine() const {
		return widthVerLine;
	}

	IcoStyle getIcoStyle() const {
		return style;
	}

	QColor getColorLine() const {
		return colorLine;
	}

	QColor getVerColorLine() const {
		return colorVerLine;
	}

	QColor getColorBgNormal() const {
		return colorBgNormal;
	}

	QColor getColorBgSelected() const {
		return colorBgSelected;
	}

	QColor getColorBgHover() const {
		return colorBgHover;
	}

	QColor getColorTextNormal() const {
		return colorTextNormal;
	}

	QColor getColorTextSelected() const {
		return colorTextSelected;
	}

	QColor getColorTextHover() const {
		return colorTextHover;
	}

public slots:
	// 读取xml文件数据
	void readData(QString xmlPath);
    // 设置数据集合
    void setData(QStringList listItem);

    // 设置是否显示提示信息
    void setInfoVisible(bool infoVisible);

	// 设置是否显示间隔线条
	void setLineVisible(bool lineVisible);

	// 设置是否显示竖线条
	void setVerLineVisible(bool verLineVisible);

	// 设置竖线条宽度
	void setVerLineWidth(int width);

	// 设置伸缩图片是否采用背景色
	void setIcoColorBg(bool icoColorBg);

	// 设置伸缩图片样式
	void setIcoStyle(IcoStyle style);

	// 设置各种前景色背景色选中色
	void setColorLine(QColor colorLine);
	void setColorVerLine(QColor colorVerLine);
	void setColorBg(QColor colorBgNormal, QColor colorBgSelected, QColor colorBgHover);
	void setColorText(QColor colorTextNormal, QColor colorTextSelected, QColor colorTextHover);
};

#endif // NAVLISTVIEW_H
