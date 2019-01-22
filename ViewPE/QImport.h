#pragma once

#include <QWidget>
#include "ui_QImport.h"
#include <QKeyEvent>
#include <windows.h>
#include <QVariant>

class QImport : public QWidget
{
	Q_OBJECT

public:
	QImport(QWidget *parent = Q_NULLPTR, IMAGE_NT_HEADERS* pNt = NULL, LPBYTE pBuff = NULL);
	~QImport();

private:
	Ui::QImport ui;
	void updateMain();
	void keyPressEvent(QKeyEvent *event);
	DWORD rva2foa(IMAGE_NT_HEADERS* pNt, DWORD dwRva);
	IMAGE_NT_HEADERS* m_pNt;
	LPBYTE m_pBuff;

private slots:
	void OnBtnTreeItem(QTreeWidgetItem *item, int column);
};
