#include "QAbout.h"

QAbout::QAbout(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// 隐藏问号按钮
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());
}

QAbout::~QAbout()
{
}
