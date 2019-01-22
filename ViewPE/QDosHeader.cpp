#include "QDosHeader.h"

QDosHeader::QDosHeader(QWidget *parent, IMAGE_DOS_HEADER* pDos)
	: QDialog(parent)
{
	ui.setupUi(this);
	// 隐藏问号按钮
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());

	// e_magic
	LPTSTR szBuffer1 = new TCHAR[100];
	WORD e_magic = pDos->e_magic;
	wsprintf(szBuffer1, L"%Xh", e_magic);
	QString e_magicQString = QString::fromWCharArray(szBuffer1);
	ui.e_magicEdit->setText(e_magicQString);

	// e_cblp
	LPTSTR szBuffer2 = new TCHAR[100];
	WORD e_cblp = pDos->e_cblp;
	wsprintf(szBuffer2, L"%Xh", e_cblp);
	QString e_cblpQString = QString::fromWCharArray(szBuffer2);
	ui.e_cblpEdit->setText(e_cblpQString);

	// e_cp
	LPTSTR szBuffer3 = new TCHAR[100];
	WORD e_cp = pDos->e_cp;
	wsprintf(szBuffer3, L"%Xh", e_cp);
	QString e_cpQString = QString::fromWCharArray(szBuffer3);
	ui.e_cpEdit->setText(e_cpQString);

	// e_crlc
	LPTSTR szBuffer4 = new TCHAR[100];
	WORD e_crlc = pDos->e_crlc;
	wsprintf(szBuffer4, L"%Xh", e_crlc);
	QString e_crlcQString = QString::fromWCharArray(szBuffer4);
	ui.e_crlcEdit->setText(e_crlcQString);

	// e_cparhdr
	LPTSTR szBuffer5 = new TCHAR[100];
	WORD e_cparhdr = pDos->e_cparhdr;
	wsprintf(szBuffer5, L"%Xh", e_cparhdr);
	QString e_cparhdrQString = QString::fromWCharArray(szBuffer5);
	ui.e_cparhdrEdit->setText(e_cparhdrQString);

	// e_minalloc
	LPTSTR szBuffer6 = new TCHAR[100];
	WORD e_minalloc = pDos->e_minalloc;
	wsprintf(szBuffer6, L"%Xh", e_minalloc);
	QString e_minallocQString = QString::fromWCharArray(szBuffer6);
	ui.e_minallocEdit->setText(e_minallocQString);

	// e_maxalloc
	LPTSTR szBuffer7 = new TCHAR[100];
	WORD e_maxalloc = pDos->e_maxalloc;
	wsprintf(szBuffer7, L"%Xh", e_maxalloc);
	QString e_maxallocQString = QString::fromWCharArray(szBuffer7);
	ui.e_maxallocEdit->setText(e_maxallocQString);

	// e_ss
	LPTSTR szBuffer8 = new TCHAR[100];
	WORD e_ss = pDos->e_ss;
	wsprintf(szBuffer8, L"%Xh", e_ss);
	QString e_ssQString = QString::fromWCharArray(szBuffer8);
	ui.e_ssEdit->setText(e_ssQString);

	// e_sp
	LPTSTR szBuffer9 = new TCHAR[100];
	WORD e_sp = pDos->e_sp;
	wsprintf(szBuffer9, L"%Xh", e_sp);
	QString e_spQString = QString::fromWCharArray(szBuffer9);
	ui.e_spEdit->setText(e_spQString);

	// e_csum
	LPTSTR szBuffer10 = new TCHAR[100];
	WORD e_csum = pDos->e_csum;
	wsprintf(szBuffer10, L"%Xh", e_csum);
	QString e_csumQString = QString::fromWCharArray(szBuffer10);
	ui.e_csumEdit->setText(e_csumQString);

	// e_ip
	LPTSTR szBuffer11 = new TCHAR[100];
	WORD e_ip = pDos->e_ip;
	wsprintf(szBuffer11, L"%Xh", e_ip);
	QString e_ipQString = QString::fromWCharArray(szBuffer11);
	ui.e_ipEdit->setText(e_ipQString);

	// e_cs
	LPTSTR szBuffer12 = new TCHAR[100];
	WORD e_cs = pDos->e_cs;
	wsprintf(szBuffer12, L"%Xh", e_cs);
	QString e_csQString = QString::fromWCharArray(szBuffer12);
	ui.e_csEdit->setText(e_csQString);

	// e_lfarlc
	LPTSTR szBuffer13 = new TCHAR[100];
	WORD e_lfarlc = pDos->e_lfarlc;
	wsprintf(szBuffer13, L"%Xh", e_lfarlc);
	QString e_lfarlcQString = QString::fromWCharArray(szBuffer13);
	ui.e_lfarlcEdit->setText(e_lfarlcQString);

	// e_ovno
	LPTSTR szBuffer14 = new TCHAR[100];
	WORD e_ovno = pDos->e_ovno;
	wsprintf(szBuffer14, L"%Xh", e_ovno);
	QString e_ovnoQString = QString::fromWCharArray(szBuffer14);
	ui.e_ovnoEdit->setText(e_ovnoQString);

	// e_res[4]
	LPTSTR szBuffer15 = new TCHAR[100];
	WORD e_res0 = pDos->e_res[0];
	WORD e_res1 = pDos->e_res[1];
	WORD e_res2 = pDos->e_res[2];
	WORD e_res3 = pDos->e_res[3];
	wsprintf(szBuffer15, L"%X%X%X%Xh", e_res0, e_res1, e_res2, e_res3);
	QString e_resQString = QString::fromWCharArray(szBuffer15);
	ui.e_res4Edit->setText(e_resQString);

	// e_oemid
	LPTSTR szBuffer16 = new TCHAR[100];
	WORD e_oemid = pDos->e_oemid;
	wsprintf(szBuffer16, L"%Xh", e_oemid);
	QString e_oemidQString = QString::fromWCharArray(szBuffer16);
	ui.e_oemidEdit->setText(e_oemidQString);

	// e_oeminfo
	LPTSTR szBuffer17 = new TCHAR[100];
	WORD e_oeminfo = pDos->e_oeminfo;
	wsprintf(szBuffer17, L"%Xh", e_oeminfo);
	QString e_oeminfoQString = QString::fromWCharArray(szBuffer17);
	ui.e_oeminfoEdit->setText(e_oeminfoQString);

	// e_res2[10]
	LPTSTR szBuffer18 = new TCHAR[100];
	WORD e_res20 = pDos->e_res2[0];
	WORD e_res21 = pDos->e_res2[1];
	WORD e_res22 = pDos->e_res2[2];
	WORD e_res23 = pDos->e_res2[3];
	WORD e_res24 = pDos->e_res2[4];
	WORD e_res25 = pDos->e_res2[5];
	WORD e_res26 = pDos->e_res2[6];
	WORD e_res27 = pDos->e_res2[7];
	WORD e_res28 = pDos->e_res2[8];
	WORD e_res29 = pDos->e_res2[9];
	wsprintf(szBuffer18, L"%X%X%X%X%X%X%X%X%X%Xh", e_res20, e_res21, e_res22, e_res23, e_res24, e_res25, e_res26, e_res27, e_res28, e_res29);
	QString e_res2QString = QString::fromWCharArray(szBuffer18);
	ui.e_res2Edit->setText(e_res2QString);

	// e_lfanew
	LPTSTR szBuffer19 = new TCHAR[100];
	LONG e_lfanew = pDos->e_lfanew;
	wsprintf(szBuffer19, L"%Xh", e_lfanew);
	QString e_lfanewQString = QString::fromWCharArray(szBuffer19);
	ui.e_lfanewEdit->setText(e_lfanewQString);

	// 释放堆空间
	delete[] szBuffer1;
	delete[] szBuffer2;
	delete[] szBuffer3;
	delete[] szBuffer4;
	delete[] szBuffer5;
	delete[] szBuffer6;
	delete[] szBuffer7;
	delete[] szBuffer8;
	delete[] szBuffer9;
	delete[] szBuffer10;
	delete[] szBuffer11;
	delete[] szBuffer12;
	delete[] szBuffer13;
	delete[] szBuffer14;
	delete[] szBuffer15;
	delete[] szBuffer16;
	delete[] szBuffer17;
	delete[] szBuffer18;
	delete[] szBuffer19;
}

QDosHeader::~QDosHeader()
{
}
