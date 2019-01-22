#include "QFileHeader.h"

QFileHeader::QFileHeader(QWidget *parent, IMAGE_NT_HEADERS* pNt)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();
	// �ҵ��ļ�ͷ
	IMAGE_FILE_HEADER pFile = pNt->FileHeader;

	// Machine
	LPTSTR szBuffer1 = new TCHAR[100];
	WORD Machine = pFile.Machine;
	wsprintf(szBuffer1, L"%Xh", Machine);
	QString MachineQString = QString::fromWCharArray(szBuffer1);
	ui.machineEdit->setText(MachineQString);

	// NumberOfSections
	LPTSTR szBuffer2 = new TCHAR[100];
	WORD NumberOfSections = pFile.NumberOfSections;
	wsprintf(szBuffer2, L"%Xh", NumberOfSections);
	QString NumberOfSectionsQString = QString::fromWCharArray(szBuffer2);
	ui.NumberOfSecEdit->setText(NumberOfSectionsQString);

	// TimeDateStamp
	LPTSTR szBuffer3 = new TCHAR[100];
	DWORD TimeDateStamp = pFile.TimeDateStamp;
	wsprintf(szBuffer3, L"%Xh", TimeDateStamp);
	QString TimeDateStampQString = QString::fromWCharArray(szBuffer3);
	ui.TimeDateEdit->setText(TimeDateStampQString);

	// PointerToSymbolTable
	LPTSTR szBuffer4 = new TCHAR[100];
	DWORD PointerToSymbolTable = pFile.PointerToSymbolTable;
	wsprintf(szBuffer4, L"%Xh", PointerToSymbolTable);
	QString PointerToSymbolTableQString = QString::fromWCharArray(szBuffer4);
	ui.PointerEdit->setText(PointerToSymbolTableQString);

	// NumberOfSymbols
	LPTSTR szBuffer5 = new TCHAR[100];
	DWORD NumberOfSymbols = pFile.NumberOfSymbols;
	wsprintf(szBuffer5, L"%Xh", NumberOfSymbols);
	QString NumberOfSymbolsQString = QString::fromWCharArray(szBuffer5);
	ui.NumberOfSymEdit->setText(NumberOfSymbolsQString);

	// SizeOfOptionalHeader
	LPTSTR szBuffer6 = new TCHAR[100];
	WORD SizeOfOptionalHeader = pFile.SizeOfOptionalHeader;
	wsprintf(szBuffer6, L"%Xh", SizeOfOptionalHeader);
	QString SizeOfOptionalHeaderQString = QString::fromWCharArray(szBuffer6);
	ui.SizeOpEdit->setText(SizeOfOptionalHeaderQString);

	// Characteristics
	LPTSTR szBuffer7 = new TCHAR[100];
	WORD Characteristics = pFile.Characteristics;
	wsprintf(szBuffer7, L"%Xh", Characteristics);
	QString CharacteristicsQString = QString::fromWCharArray(szBuffer7);
	ui.CharacterEdit->setText(CharacteristicsQString);

	// �ͷŶѿռ�
	delete[] szBuffer1;
	delete[] szBuffer2;
	delete[] szBuffer3;
	delete[] szBuffer4;
	delete[] szBuffer5;
	delete[] szBuffer6;
	delete[] szBuffer7;
}

QFileHeader::~QFileHeader()
{
}

// ��ʼ���Ի���
void QFileHeader::updateMain()
{
	// ��ֹ��󻯰�ť
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// ��ֹ�϶����ڴ�С
	setFixedSize(this->width(), this->height());
}

// ��д�麯��keyPressEvent
void QFileHeader::keyPressEvent(QKeyEvent *event)
{
	// Esc�� ���ش���
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}
