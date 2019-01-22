#include "QSection.h"

QSection::QSection(QWidget *parent, IMAGE_NT_HEADERS* pNt)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();

	IMAGE_SECTION_HEADER* pScnHdr = NULL;
	// 使用宏来找到区段头数组的首地址
	pScnHdr = IMAGE_FIRST_SECTION(pNt);
	// 得到区段头的个数
	DWORD scnHdrCount = pNt->FileHeader.NumberOfSections;
	for (DWORD i = 0; i < scnHdrCount; i++)
	{
		// new一个新的节点
		QTreeWidgetItem* item = new QTreeWidgetItem();

		// 名称
		char* Name = (char*)pScnHdr[i].Name;
		QString NameQString(Name);
		item->setText(0, NameQString);
		// 内存中的偏移
		LPTSTR szBuffer1 = new TCHAR[100];
		DWORD VirtualAddress = pScnHdr[i].VirtualAddress;
		wsprintf(szBuffer1, L"%Xh", VirtualAddress);
		QString VirtualAddressQString = QString::fromWCharArray(szBuffer1);
		item->setText(1, VirtualAddressQString);
		// 内存中的大小
		LPTSTR szBuffer2 = new TCHAR[100];
		DWORD VirtualSize = pScnHdr[i].Misc.VirtualSize;
		wsprintf(szBuffer2, L"%Xh", VirtualSize);
		QString VirtualSizeQString = QString::fromWCharArray(szBuffer2);
		item->setText(2, VirtualSizeQString);
		// 文件中的偏移
		LPTSTR szBuffer3 = new TCHAR[100];
		DWORD PointerToRawData = pScnHdr[i].PointerToRawData;
		wsprintf(szBuffer3, L"%Xh", PointerToRawData);
		QString PointerToRawDataQString = QString::fromWCharArray(szBuffer3);
		item->setText(3, PointerToRawDataQString);
		// 文件中的大小
		LPTSTR szBuffer4 = new TCHAR[100];
		DWORD SizeOfRawData = pScnHdr[i].SizeOfRawData;
		wsprintf(szBuffer4, L"%Xh", SizeOfRawData);
		QString SizeOfRawDataQString = QString::fromWCharArray(szBuffer4);
		item->setText(4, SizeOfRawDataQString);
		// 标志
		LPTSTR szBuffer5 = new TCHAR[100];
		DWORD Characteristics = pScnHdr[i].Characteristics;
		wsprintf(szBuffer5, L"%Xh", Characteristics);
		QString CharacteristicsQString = QString::fromWCharArray(szBuffer5);
		item->setText(5, CharacteristicsQString);

		// 添加节点
		ui.treeWidget->addTopLevelItem(item);
		// 释放堆空间
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

// 初始化对话框
void QSection::updateMain()
{
	// 禁止最大化按钮
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());
}

// 重写虚函数keyPressEvent
void QSection::keyPressEvent(QKeyEvent *event)
{
	// Esc键 隐藏窗口
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}
