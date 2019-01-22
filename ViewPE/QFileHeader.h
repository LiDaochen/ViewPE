#pragma once

#include <QWidget>
#include "ui_QFileHeader.h"
#include <QKeyEvent>
#include <windows.h>

class QFileHeader : public QWidget
{
	Q_OBJECT

public:
	QFileHeader(QWidget *parent = Q_NULLPTR, IMAGE_NT_HEADERS* pNt = NULL);
	~QFileHeader();

private:
	Ui::QFileHeader ui;
	void updateMain();
	void keyPressEvent(QKeyEvent *event);
};
