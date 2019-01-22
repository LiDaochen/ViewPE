#include "QImport.h"

QImport::QImport(QWidget *parent, IMAGE_NT_HEADERS* pNt, LPBYTE pBuff)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();
	// 给成员变量赋值
	m_pNt = pNt;
	m_pBuff = pBuff;
	// 1:获取导入表的首地址
	DWORD dwImpTabRva = pNt->OptionalHeader.DataDirectory[1].VirtualAddress;
	// 将RVA转换为FOA
	DWORD dwImpTabFoa = rva2foa(pNt, dwImpTabRva);
	// 得到导入表数组的首地址
	IMAGE_IMPORT_DESCRIPTOR* pImp = (IMAGE_IMPORT_DESCRIPTOR*)(dwImpTabFoa + pBuff);
	// 2:遍历导入表数组，数组以0结尾
	while (pImp->Name != 0)
	{
		// 创建一个节点
		QTreeWidgetItem* item = new QTreeWidgetItem();

		// 2.0 获取导入表DLL的名字
		DWORD dwNameFoa = rva2foa(pNt, pImp->Name);
		char* pDllName = (char*)(dwNameFoa + pBuff);
		// char* 转 QString
		QString DllNameQString(pDllName);
		item->setText(0, DllNameQString);
		// 保存pImp到控件
		QVariant var((int)pImp);
		item->setData(0, Qt::UserRole, var);

		// 2.1 OriginalFirstThunk
		LPTSTR szBuffer1 = new TCHAR[100];
		DWORD OriginalFirstThunk = pImp->OriginalFirstThunk;
		wsprintf(szBuffer1, L"%Xh", OriginalFirstThunk);
		QString OriginalFirstThunkQString = QString::fromWCharArray(szBuffer1);
		item->setText(1, OriginalFirstThunkQString);

		// 2.2 TimeDateStamp
		LPTSTR szBuffer2 = new TCHAR[100];
		DWORD TimeDateStamp = pImp->TimeDateStamp;
		wsprintf(szBuffer2, L"%Xh", TimeDateStamp);
		QString TimeDateStampQString = QString::fromWCharArray(szBuffer2);
		item->setText(2, TimeDateStampQString);

		// 2.3 ForwarderChain
		LPTSTR szBuffer3 = new TCHAR[100];
		DWORD ForwarderChain = pImp->ForwarderChain;
		wsprintf(szBuffer3, L"%Xh", ForwarderChain);
		QString ForwarderChainQString = QString::fromWCharArray(szBuffer3);
		item->setText(3, ForwarderChainQString);

		// 2.4 Name(RVA)
		LPTSTR szBuffer4 = new TCHAR[100];
		DWORD Name = pImp->Name;
		wsprintf(szBuffer4, L"%Xh", Name);
		QString NameQString = QString::fromWCharArray(szBuffer4);
		item->setText(4, NameQString);

		// 2.5 FirstThunk
		LPTSTR szBuffer5 = new TCHAR[100];
		DWORD FirstThunk = pImp->FirstThunk;
		wsprintf(szBuffer5, L"%Xh", FirstThunk);
		QString FirstThunkQString = QString::fromWCharArray(szBuffer5);
		item->setText(5, FirstThunkQString);

		// 添加节点
		ui.treeWidget->addTopLevelItem(item);
		++pImp;

		// 释放堆空间
		delete[] szBuffer1;
		delete[] szBuffer2;
		delete[] szBuffer3;
		delete[] szBuffer4;
		delete[] szBuffer5;
	}

	connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(OnBtnTreeItem(QTreeWidgetItem *, int)));
}

QImport::~QImport()
{
}

// 初始化对话框
void QImport::updateMain()
{
	// 禁止最大化按钮
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());
}

// 重写虚函数keyPressEvent
void QImport::keyPressEvent(QKeyEvent *event)
{
	// Esc键 隐藏窗口
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}

// RVA 转 FOA
DWORD QImport::rva2foa(IMAGE_NT_HEADERS* pNt, DWORD dwRva)
{
	IMAGE_SECTION_HEADER* pScnHdr = (IMAGE_SECTION_HEADER*)
		IMAGE_FIRST_SECTION(pNt);
	for (DWORD i = 0; i < pNt->FileHeader.NumberOfSections; i++)
	{
		if (dwRva >= pScnHdr[i].VirtualAddress &&
			dwRva <= pScnHdr[i].VirtualAddress + pScnHdr[i].SizeOfRawData)
		{
			return dwRva - pScnHdr[i].VirtualAddress + pScnHdr[i].PointerToRawData;
		}
	}
	return -1;
}

// 树控件被选中事件处理函数
void QImport::OnBtnTreeItem(QTreeWidgetItem *item, int column)
{
	// 清空所有内容
	ui.treeWidget_2->clear();
	// 初始化变量
	IMAGE_IMPORT_DESCRIPTOR* pImp = NULL;
	IMAGE_THUNK_DATA* pInt = NULL;
	// 从控件获取pImp
	QVariant var = item->data(0, Qt::UserRole);
	pImp = (IMAGE_IMPORT_DESCRIPTOR*)var.toInt();
	DWORD dwIntFoa = rva2foa(m_pNt, pImp->OriginalFirstThunk);
	pInt = (IMAGE_THUNK_DATA*)(dwIntFoa + m_pBuff);
	DWORD ThunkRVA = pImp->OriginalFirstThunk;
	DWORD ThunkOffset = dwIntFoa;

	while (pInt->u1.Function != 0)
	{
		// 创建一个节点
		QTreeWidgetItem* Newitem = new QTreeWidgetItem();

		// 判断导入的方式：序号导入还是名称导入
		if (IMAGE_SNAP_BY_ORDINAL(pInt->u1.Ordinal))
		{
			// ThunkRVA
			LPTSTR szBuffer0 = new TCHAR[100];
			wsprintf(szBuffer0, L"%Xh", ThunkRVA);
			QString ThunkRVAQString = QString::fromWCharArray(szBuffer0);
			Newitem->setText(0, ThunkRVAQString);
			// ThunkOffset
			LPTSTR szBuffer1 = new TCHAR[100];
			wsprintf(szBuffer1, L"%Xh", ThunkOffset);
			QString ThunkOffsetQString = QString::fromWCharArray(szBuffer1);
			Newitem->setText(1, ThunkOffsetQString);
			// ThunkValue
			LPTSTR szBuffer2 = new TCHAR[100];
			DWORD ThunkValue = *(DWORD*)((DWORD)m_pBuff + ThunkOffset);
			wsprintf(szBuffer2, L"%Xh", ThunkValue);
			QString ThunkValueQString = QString::fromWCharArray(szBuffer2);
			Newitem->setText(2, ThunkValueQString);
			// Hint
			Newitem->setText(3, "--");
			// APIName
			LPTSTR szBuffer4 = new TCHAR[100];
			DWORD APIName = pInt->u1.Ordinal & 0xFFFF;
			wsprintf(szBuffer4, L"函数序号：%Xh %dd", APIName, APIName);
			QString APINameQString = QString::fromWCharArray(szBuffer4);
			Newitem->setText(4, APINameQString);
			// 添加节点
			ui.treeWidget_2->addTopLevelItem(Newitem);
			// 数据++
			ThunkRVA += 4;
			ThunkOffset += 4;

			// 释放堆空间
			delete[] szBuffer0;
			delete[] szBuffer1;
			delete[] szBuffer2;
			delete[] szBuffer4;
		}
		else
		{
			IMAGE_IMPORT_BY_NAME* pImpName = 0;
			DWORD dwNameFoa1 = rva2foa(m_pNt, pInt->u1.AddressOfData);
			pImpName = (IMAGE_IMPORT_BY_NAME*)(dwNameFoa1 + m_pBuff);
			// ThunkRVA
			LPTSTR szBuffer0 = new TCHAR[100];
			wsprintf(szBuffer0, L"%Xh", ThunkRVA);
			QString ThunkRVAQString = QString::fromWCharArray(szBuffer0);
			Newitem->setText(0, ThunkRVAQString);
			// ThunkOffset
			LPTSTR szBuffer1 = new TCHAR[100];
			wsprintf(szBuffer1, L"%Xh", ThunkOffset);
			QString ThunkOffsetQString = QString::fromWCharArray(szBuffer1);
			Newitem->setText(1, ThunkOffsetQString);
			// ThunkValue
			LPTSTR szBuffer2 = new TCHAR[100];
			DWORD ThunkValue = *(DWORD*)((DWORD)m_pBuff + ThunkOffset);
			wsprintf(szBuffer2, L"%Xh", ThunkValue);
			QString ThunkValueQString = QString::fromWCharArray(szBuffer2);
			Newitem->setText(2, ThunkValueQString);
			// Hint
			LPTSTR szBuffer3 = new TCHAR[100];
			WORD Hint = pImpName->Hint;
			wsprintf(szBuffer3, L"%Xh", Hint);
			QString HintQString = QString::fromWCharArray(szBuffer3);
			Newitem->setText(3, HintQString);
			// APIName
			char* APIName = pImpName->Name;
			QString APINameQString(APIName);
			Newitem->setText(4, APINameQString);
			// 添加节点
			ui.treeWidget_2->addTopLevelItem(Newitem);
			// 数据++
			ThunkRVA += 4;
			ThunkOffset += 4;

			// 释放堆空间
			delete[] szBuffer0;
			delete[] szBuffer1;
			delete[] szBuffer2;
			delete[] szBuffer3;
		}
		++pInt;
	}
}