#pragma once

#include <QWidget>
#include "ui_QDataDirectory.h"
#include <QKeyEvent>
#include <windows.h>

class QDataDirectory : public QWidget
{
	Q_OBJECT

public:
	QDataDirectory(QWidget *parent = Q_NULLPTR, IMAGE_NT_HEADERS* pNt = NULL);
	~QDataDirectory();

private:
	Ui::QDataDirectory ui;
	void updateMain();
	void keyPressEvent(QKeyEvent *event);
};
