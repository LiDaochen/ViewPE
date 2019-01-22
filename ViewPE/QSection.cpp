#include "QSection.h"

QSection::QSection(QWidget *parent, IMAGE_NT_HEADERS* pNt)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();

	IMAGE_SECTION_HEADER* pScnHdr = NULL;
	// ʹ�ú����ҵ�����ͷ������׵�ַ
	pScnHdr = IMAGE_FIRST_SECTION(pNt);
	// �õ�����ͷ�ĸ���
	DWORD scnHdrCount = pNt->FileHeader.NumberOfSections;
	for (DWORD i = 0; i < scnHdrCount; i++)
	{
		// newһ���µĽڵ�
		QTreeWidgetItem* item = new QTreeWidgetItem();

		// ����
		char* Name = (char*)pScnHdr[i].Name;
		QString NameQString(Name);
		item->setText(0, NameQString);
		// �ڴ��е�ƫ��
		LPTSTR szBuffer1 = new TCHAR[100];
		DWORD VirtualAddress = pScnHdr[i].VirtualAddress;
		wsprintf(szBuffer1, L"%Xh", VirtualAddress);
		QString VirtualAddressQString = QString::fromWCharArray(szBuffer1);
		item->setText(1, VirtualAddressQString);
		// �ڴ��еĴ�С
		LPTSTR szBuffer2 = new TCHAR[100];
		DWORD VirtualSize = pScnHdr[i].Misc.VirtualSize;
		wsprintf(szBuffer2, L"%Xh", VirtualSize);
		QString VirtualSizeQString = QString::fromWCharArray(szBuffer2);
		item->setText(2, VirtualSizeQString);
		// �ļ��е�ƫ��
		LPTSTR szBuffer3 = new TCHAR[100];
		DWORD PointerToRawData = pScnHdr[i].PointerToRawData;
		wsprintf(szBuffer3, L"%Xh", PointerToRawData);
		QString PointerToRawDataQString = QString::fromWCharArray(szBuffer3);
		item->setText(3, PointerToRawDataQString);
		// �ļ��еĴ�С
		LPTSTR szBuffer4 = new TCHAR[100];
		DWORD SizeOfRawData = pScnHdr[i].SizeOfRawData;
		wsprintf(szBuffer4, L"%Xh", SizeOfRawData);
		QString SizeOfRawDataQString = QString::fromWCharArray(szBuffer4);
		item->setText(4, SizeOfRawDataQString);
		// ��־
		LPTSTR szBuffer5 = new TCHAR[100];
		DWORD Characteristics = pScnHdr[i].Characteristics;
		wsprintf(szBuffer5, L"%Xh", Characteristics);
		QString CharacteristicsQString = QString::fromWCharArray(szBuffer5);
		item->setText(5, CharacteristicsQString);

		// ��ӽڵ�
		ui.treeWidget->addTopLevelItem(item);
		// �ͷŶѿռ�
		delete[] szBuffer1;
		delete[] szBuffer2;
		delete[] szBuffer3;
		delete[] szBuffer4;
		delete[] szBuffer5;
	}
}

QSection::~QSection()
{
}

// ��ʼ���Ի���
void QSection::updateMain()
{
	// ��ֹ��󻯰�ť
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// ��ֹ�϶����ڴ�С
	setFixedSize(this->width(), this->height());
}

// ��д�麯��keyPressEvent
void QSection::keyPressEvent(QKeyEvent *event)
{
	// Esc�� ���ش���
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}
