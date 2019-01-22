#pragma once

#include <QWidget>
#include "ui_QOptionalHeader.h"
#include <QKeyEvent>
#include <windows.h>

class QOptionalHeader : public QWidget
{
	Q_OBJECT

public:
	QOptionalHeader(QWidget *parent = Q_NULLPTR, IMAGE_NT_HEADERS* pNt = NULL);
	~QOptionalHeader();

private:
	Ui::QOptionalHeader ui;
	void updateMain();
	void keyPressEvent(QKeyEvent *event);
};
