#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ViewPE.h"
#include "QAbout.h"
#include "QDosHeader.h"
#include "QFileHeader.h"
#include "QOptionalHeader.h"
#include "QSection.h"
#include "QImport.h"
#include "QDataDirectory.h"
#include "GBK.h"
#include <QLineEdit>
#include <QFileDialog>
#include <windows.h>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QtGui>
#include <locale.h>
#include <string>
#include <commctrl.h>
#include <atlstr.h>
using namespace std;

class ViewPE : public QMainWindow
{
	Q_OBJECT

public:
	ViewPE(QWidget *parent = Q_NULLPTR);

private:
	Ui::ViewPEClass ui;
	QLineEdit* m_lineEdit;
	QFileHeader* m_fileHeaderWin;
	QOptionalHeader* m_optionalHeaderWin;
	QSection* m_sectionWin;
	QDataDirectory* m_dataWin;
	QImport* m_importWin;
	IMAGE_DOS_HEADER* m_pDos;
	IMAGE_NT_HEADERS* m_pNt;
	LPBYTE m_pBuff;
	bool isShowToolBar;
	bool isShowStatusbar;
	// 是否正在拖动
	bool m_dragging;
	// 拖动开始前的鼠标位置
	QPoint m_startPosition;
	// 窗体的原始位置
	QPoint m_framePosition;
	void UpdataMain();
	QSystemTrayIcon m_sysTray;
	void closeEvent(QCloseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void dragEnterEvent(QDragEnterEvent *event);
	virtual void dropEvent(QDropEvent *event);
	BOOL IsWow64();
	HWND FindTrayWnd();
	void EnumNotifyWindow(HWND hWnd);
	VOID ParsePE(QString filePath);
	VOID ClearWidgets();

private slots:
	void actionAbout();
	void actionQuit();
	void actionOpenFile();
	void actionToolBar();
	void actionStatusBar();
	void OnSystemtrayClicked(QSystemTrayIcon::ActivationReason reason);
	void actionOpenSystemTray();
	void actionDosHeader();
	void actionFileHeader();
	void actionOptionalHeader();
	void actionDataDirectory();
	void actionSectionTable();
	void actionImport();
};
