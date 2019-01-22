#pragma once

#include <QDialog>
#include "ui_QDosHeader.h"
#include <windows.h>

class QDosHeader : public QDialog
{
	Q_OBJECT

public:
	QDosHeader(QWidget *parent = Q_NULLPTR, IMAGE_DOS_HEADER* pDos = NULL);
	~QDosHeader();

private:
	Ui::QDosHeader ui;
};
