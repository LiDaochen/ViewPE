#include "QAbout.h"

QAbout::QAbout(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// �����ʺŰ�ť
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	// ��ֹ�϶����ڴ�С
	setFixedSize(this->width(), this->height());
}

QAbout::~QAbout()
{
}
