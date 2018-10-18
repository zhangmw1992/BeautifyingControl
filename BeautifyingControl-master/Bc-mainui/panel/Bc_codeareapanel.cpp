#include "Bc_codeareapanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

CodeAreaPanel::CodeAreaPanel(QWidget *parent)
	: QWidget(parent)
{
	ca = new CodeArea;
	ca->setFixedSize(120, 30);

	flushBtn = new QPushButton(QString(QStringLiteral("刷新")));
	connect(flushBtn, &QPushButton::clicked, this, [&](){ ca->replaceCodePic(); });

	QHBoxLayout *lay1 = new QHBoxLayout;
	lay1->addStretch(0);
	lay1->addWidget(ca);
	lay1->addWidget(flushBtn);
	lay1->addStretch(0);

	lineEdit = new QLineEdit;
	lineEdit->setFixedSize(120, 30);

	checkBtn = new QPushButton(QString(QStringLiteral("验证")));
	connect(checkBtn, &QPushButton::clicked, this, [&](){
		bool isOk = ca->checkCode(lineEdit->text());

		QMessageBox message(QMessageBox::NoIcon, "code check", QString("This is %1").arg(isOk == true ? "ok" : "error"), QMessageBox::Yes, NULL);
		message.exec();
	});
	
	QHBoxLayout *lay2 = new QHBoxLayout;
	lay2->addStretch(0);
	lay2->addWidget(lineEdit);
	lay2->addWidget(checkBtn);
	lay2->addStretch(0);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(lay1);
	layout->addLayout(lay2);
	layout->addStretch(0);
	layout->setSpacing(30);
	layout->setContentsMargins(40, 40, 40, 40);
	setLayout(layout);
}

CodeAreaPanel::~CodeAreaPanel()
{

}
