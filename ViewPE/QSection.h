#pragma once

#include <QWidget>
#include "ui_QSection.h"
#include <QKeyEvent>
#include <windows.h>

class QSection : public QWidget
{
	Q_OBJECT

public:
	QSection(QWidget *parent = Q_NULLPTR, IMAGE_NT_HEADERS* pNt = NULL);
	~QSection();

private:
	Ui::QSection ui;
	void updateMain();
	void keyPressEvent(QKeyEvent *event);
};
