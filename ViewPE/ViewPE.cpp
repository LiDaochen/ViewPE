#include "ViewPE.h"

ViewPE::ViewPE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	UpdataMain();
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(actionAbout()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(actionQuit()));
	connect(ui.actionOpenFile, SIGNAL(triggered()), this, SLOT(actionOpenFile()));
	connect(ui.actionStatusBar, SIGNAL(triggered()), this, SLOT(actionStatusBar()));
	connect(ui.actionToolBar, SIGNAL(triggered()), this, SLOT(actionToolBar()));
	connect(ui.actionOpenMainDlg, SIGNAL(triggered()), this, SLOT(actionOpenSystemTray()));
	connect(ui.actionDosHeader, SIGNAL(triggered()), this, SLOT(actionDosHeader()));
	connect(ui.actionFileHeader, SIGNAL(triggered()), this, SLOT(actionFileHeader()));
	connect(ui.actionOptionalHeader, SIGNAL(triggered()), this, SLOT(actionOptionalHeader()));
	connect(ui.actionSectionHeader, SIGNAL(triggered()), this, SLOT(actionSectionTable()));
	connect(ui.actionImportDescriptor, SIGNAL(triggered()), this, SLOT(actionImport()));
	connect(ui.actionDataDirectory, SIGNAL(triggered()), this, SLOT(actionDataDirectory()));
	connect(&m_sysTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnSystemtrayClicked(QSystemTrayIcon::ActivationReason)));
}

// 初始化对话框
void ViewPE::UpdataMain()
{
	/* 防多开 */
	HANDLE hMutex = CreateMutex(NULL, TRUE, TEXT("OBSMutex"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		setlocale(LC_ALL, "chs");
		EnumNotifyWindow(FindTrayWnd());
		CloseHandle(hMutex);
		ExitProcess(0);
		return;
	}

	// 向工具栏里面加入编辑框
	m_lineEdit = new QLineEdit();
	// 设置编辑框位只读
	m_lineEdit->setReadOnly(true);
	// 加入工具栏
	ui.mainToolBar->insertWidget(ui.actionOpenFile, m_lineEdit);

	// 禁止最大化按钮
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());

	// 初始化变量
	isShowStatusbar = true;
	isShowToolBar = true;
	m_dragging = false;
	// 设置可接受文件拖拽的属性
	this->setAcceptDrops(true);

	/*  系统托盘  */
	// 设置提示文字 
	m_sysTray.setToolTip("ViewPE");
	// 设置托盘图标
	m_sysTray.setIcon(QIcon(":/Tray/Resources/tray.png"));
	// 设置托盘菜单
	QMenu* menu = new QMenu();
	// 添加打开主面板
	menu->addAction(ui.actionOpenMainDlg);
	// 添加分隔符
	menu->addSeparator();
	// 添加关于软件
	menu->addAction(ui.actionAbout);
	// 添加退出程序
	menu->addAction(ui.actionQuit);
	// 设置右键菜单
	m_sysTray.setContextMenu(menu);
	// 显示托盘菜单
	m_sysTray.show();

	// 把以下几个按钮置为不可用状态
	ui.actionDosHeader->setEnabled(false);
	ui.actionFileHeader->setEnabled(false);
	ui.actionOptionalHeader->setEnabled(false);
	ui.actionDataDirectory->setEnabled(false);
	ui.actionSectionHeader->setEnabled(false);
	ui.actionImportDescriptor->setEnabled(false);
}

// 以下三个函数主要是实现当有一个程序打开时，再次尝试打开程序，模拟点击系统托盘图标，使运行的程序主窗口显示出来
// 判断系统是否为64位系统
BOOL ViewPE::IsWow64()
{
	typedef VOID(WINAPI *LPFN_GetNativeSystemInfo)(__out LPSYSTEM_INFO lpSystemInfo);
	LPFN_GetNativeSystemInfo fnGetNativeSystemInfo = (LPFN_GetNativeSystemInfo)GetProcAddress(GetModuleHandleW(L"kernel32"), "GetNativeSystemInfo");
	if (fnGetNativeSystemInfo)
	{
		SYSTEM_INFO stInfo = { 0 };
		fnGetNativeSystemInfo(&stInfo);
		if (stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64
			|| stInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			return TRUE;
		}
	}
	return FALSE;
}

// 获取窗口句柄
HWND ViewPE::FindTrayWnd()
{
	HWND hWnd = NULL;
	hWnd = FindWindow(L"Shell_TrayWnd", NULL);
	hWnd = FindWindowEx(hWnd, NULL, L"TrayNotifyWnd", NULL);
	hWnd = FindWindowEx(hWnd, NULL, L"SysPager", NULL);
	hWnd = FindWindowEx(hWnd, NULL, L"ToolbarWindow32", NULL);
	return hWnd;
}

void ViewPE::EnumNotifyWindow(HWND hWnd)
{
	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);

	HANDLE hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, dwProcessId);
	if (hProcess == NULL){
		return;
	}
	LPVOID pBun = VirtualAllocEx(hProcess, 0, sizeof(RECT), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	LPVOID lAddress = VirtualAllocEx(hProcess, 0, 4096, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (lAddress == NULL){
		return;
	}
	DWORD lTextAdr = 0;
	BYTE buff[1024] = { 0 };
	TCHAR ptb[256] = { 0 };
	CString strTile;
	HWND hMainWnd = NULL;
	RECT rccc;
	int nDataOffset = sizeof(TBBUTTON) - sizeof(INT_PTR) - sizeof(DWORD_PTR);
	int nStrOffset = 18;
	if (IsWow64()){
		nDataOffset += 4;
		nStrOffset += 6;
	}
	GetWindowRect(hWnd, &rccc);

	//获取图标个数
	int lButton = SendMessage(hWnd, TB_BUTTONCOUNT, 0, 0);
	for (int i = 0; i < lButton; i++) {
		SendMessage(hWnd, TB_GETITEMRECT, i, (LPARAM)pBun);
		SendMessage(hWnd, TB_GETBUTTON, i, (LPARAM)lAddress);
		//读坐标
		ReadProcessMemory(hProcess, pBun, (LPVOID)ptb, sizeof(RECT), 0);
		//读文本地址
		ReadProcessMemory(hProcess, (LPVOID)((DWORD)lAddress + nDataOffset), &lTextAdr, 4, 0);
		if (lTextAdr != -1) {
			//读文本
			ReadProcessMemory(hProcess, (LPCVOID)lTextAdr, buff, 1024, 0);
			strTile = (WCHAR *)buff + nStrOffset + MAX_PATH;
			if (wcscmp(strTile, L"ViewPE"))
			{
				continue;
			}
			SendMessage(hWnd, WM_LBUTTONDBLCLK, i, 0);
			break;
		}
	}
	VirtualFreeEx(hProcess, pBun, 4096, MEM_DECOMMIT);
	VirtualFreeEx(hProcess, lAddress, 4096, MEM_RELEASE);
	CloseHandle(hProcess);
}

// 菜单关于按钮事件处理函数
void ViewPE::actionAbout()
{
	QAbout dlg(this);
	dlg.exec();
}

// 菜单退出按钮事件处理函数
void ViewPE::actionQuit()
{
	QApplication::exit();
}

// 菜单打开文件按钮事件处理函数
void ViewPE::actionOpenFile()
{
	// 选择要打开的文件
	QString filePath = QFileDialog::getOpenFileName(this, GBK::ToUnicode("选择文件"));
	// 为空时表示用户取消了操作，没有选中任何的文件
	if (filePath.length() > 0)
	{
		// 判断选择的文件是不是exe 或者 dll
		if (filePath.right(4) != ".exe" && filePath.right(4) != ".dll")
		{
			MessageBox(0, L"您选择的不是PE文件！", L"提示", 0);
			ClearWidgets();
			return;
		}
		// 设置文件路径到单行文本框
		m_lineEdit->setText(filePath);
		// 把几个按钮置为可用状态
		ui.actionDosHeader->setEnabled(true);
		ui.actionFileHeader->setEnabled(true);
		ui.actionOptionalHeader->setEnabled(true);
		ui.actionDataDirectory->setEnabled(true);
		ui.actionSectionHeader->setEnabled(true);
		ui.actionImportDescriptor->setEnabled(true);
		ParsePE(filePath);
	}
}

// 菜单查看工具栏按钮事件处理函数
void ViewPE::actionToolBar()
{
	if (isShowToolBar)
	{
		// 标志位置为false
		isShowToolBar = false;
		// 图标设置为不可见
		ui.actionToolBar->setIconVisibleInMenu(false);
		// 隐藏工具栏
		ui.mainToolBar->hide();
	}
	else
	{
		// 标志位置为真
		isShowToolBar = true;
		// 图标设置为可见
		ui.actionToolBar->setIconVisibleInMenu(true);
		// 显示工具栏
		ui.mainToolBar->show();
	}
}

// 菜单查看状态栏按钮事件处理函数
void ViewPE::actionStatusBar()
{
	if (isShowStatusbar)
	{
		// 标志位置为false
		isShowStatusbar = false;
		// 图标设置为不可见
		ui.actionStatusBar->setIconVisibleInMenu(false);
		// 隐藏状态栏
		ui.statusBar->setVisible(false);
	}
	else
	{
		// 标志位置为真
		isShowStatusbar = true;
		// 图标设置为可见
		ui.actionStatusBar->setIconVisibleInMenu(true);
		// 显示状态栏
		ui.statusBar->setVisible(true);
	}
}

// 重新虚函数closeEvent
void ViewPE::closeEvent(QCloseEvent *event)
{
	this->hide();
	event->ignore();
}

// 重写虚函数keyPressEvent
void ViewPE::keyPressEvent(QKeyEvent *event)
{
	// Ctrl + O 打开文件
	if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_O)
	{
		actionOpenFile();
	}
	// Esc键 隐藏窗口
	else if (event->key() == Qt::Key_Escape)
	{
		this->hide();
	}
}

// 以下三个函数主要是实现整体可拖动窗口
// 重写mouseMoveEvent虚函数
void ViewPE::mouseMoveEvent(QMouseEvent * event)
{
	// 只响应左键
	if (event->buttons() & Qt::LeftButton)
	{
		if (m_dragging)
		{
			// delta 相对偏移量, 
			QPoint delta = event->globalPos() - m_startPosition;
			// 新位置：窗体原始位置  + 偏移量
			move(m_framePosition + delta);
		}
	}
	QWidget::mouseMoveEvent(event);
}

// 重写mousePressEvent虚函数
void ViewPE::mousePressEvent(QMouseEvent * event)
{
	// 只响应左键
	if (event->button() == Qt::LeftButton)
	{
		// 标志位置为真
		m_dragging = true;
		// 记录下鼠标当前的位置（相对于屏幕左上角）
		m_startPosition = event->globalPos();
		// 记录下窗口当前的位置（相对于屏幕左上角）
		m_framePosition = frameGeometry().topLeft();
	}
	QWidget::mousePressEvent(event);
}

// 重写mouseReleaseEvent虚函数
void ViewPE::mouseReleaseEvent(QMouseEvent * event)
{
	// 标志位置为假
	m_dragging = false;
	QWidget::mouseReleaseEvent(event);
}

// 以下两个函数主要是实现文件拖拽
// 重写dragEnterEvent虚函数
void ViewPE::dragEnterEvent(QDragEnterEvent *event)
{
	event->acceptProposedAction();
}

// 重写dropEvent虚函数
void ViewPE::dropEvent(QDropEvent *event)
{
	QString name = event->mimeData()->urls().first().toString();
	// 判断选择的文件是不是exe 或者 dll
	if (name.right(4) != ".exe" && name.right(4) != ".dll")
	{
		MessageBox(0, L"您选择的不是PE文件！", L"提示", 0);
		ClearWidgets();
		return;
	}
	// 把前面的file:///去掉
	name.remove(0, 8);
	// 设置文件路径到单行文本框
	m_lineEdit->setText(name);
	// 把几个按钮置为可用状态
	ui.actionDosHeader->setEnabled(true);
	ui.actionFileHeader->setEnabled(true);
	ui.actionOptionalHeader->setEnabled(true);
	ui.actionDataDirectory->setEnabled(true);
	ui.actionSectionHeader->setEnabled(true);
	ui.actionImportDescriptor->setEnabled(true);
	ParsePE(name);
}

// 鼠标单击或者双击系统托盘处理函数
void ViewPE::OnSystemtrayClicked(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
	{
		// 显示主窗口
		this->showNormal();
	}
}

// 打开主面板处理函数
void ViewPE::actionOpenSystemTray()
{
	this->showNormal();
}

// DOS头按钮处理函数
void ViewPE::actionDosHeader()
{
	QDosHeader dlg(this, m_pDos);
	dlg.exec();
}

// 文件头按钮处理函数
void ViewPE::actionFileHeader()
{
	// 文件头非模态对话框
	m_fileHeaderWin = new QFileHeader(this, m_pNt);
	m_fileHeaderWin->setWindowFlags(Qt::Window);
	m_fileHeaderWin->show();
}

// 扩展头按钮处理函数
void ViewPE::actionOptionalHeader()
{
	// 扩展头
	m_optionalHeaderWin = new QOptionalHeader(this, m_pNt);
	m_optionalHeaderWin->setWindowFlags(Qt::Window);
	m_optionalHeaderWin->show();
}

// 数据目录表按钮处理函数
void ViewPE::actionDataDirectory()
{
	// 数据目录表
	m_dataWin = new QDataDirectory(this, m_pNt);
	m_dataWin->setWindowFlags(Qt::Window);
	m_dataWin->show();
}

// 区段头表按钮处理函数
void ViewPE::actionSectionTable()
{
	// 区段头
	m_sectionWin = new QSection(this, m_pNt);
	m_sectionWin->setWindowFlags(Qt::Window);
	m_sectionWin->show();
}

// 导入表按钮处理函数
void ViewPE::actionImport()
{
	// 导入表
	m_importWin = new QImport(this, m_pNt, m_pBuff);
	m_importWin->setWindowFlags(Qt::Window);
	m_importWin->show();
}

// 解析PE文件
VOID ViewPE::ParsePE(QString filePath)
{
	// 将路径由 QString 转为 WCHAR*
	const wchar_t * encodedName = reinterpret_cast<const wchar_t *>(filePath.utf16());
	// 打开文件
	HANDLE hFile = CreateFile(encodedName, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == (HANDLE)-1)
	{
		MessageBox(0, L"打开文件失败！", L"提示", 0);
		ClearWidgets();
		return;
	}
	// 获取文件大小
	DWORD size = GetFileSize(hFile, NULL);
	// 申请缓冲区
	LPBYTE pBuff = new BYTE[size];
	DWORD dwRead = 0;
	// 读文件到缓冲区
	ReadFile(hFile, pBuff, size, &dwRead, 0);
	m_pBuff = pBuff;
	// DOS头部分
	IMAGE_DOS_HEADER* pDos = NULL;
	pDos = (IMAGE_DOS_HEADER*)pBuff;
	m_pDos = pDos;
	if (pDos->e_magic != IMAGE_DOS_SIGNATURE)
	{
		MessageBox(0, L"不是有效的PE文件!", L"提示", 0);
		return;
	}
	// 找到NT头
	IMAGE_NT_HEADERS* pNt = NULL;
	pNt = (IMAGE_NT_HEADERS*)(pDos->e_lfanew + pBuff);
	m_pNt = pNt;
	if (pNt->Signature != IMAGE_NT_SIGNATURE)
	{
		MessageBox(0, L"不是有效的PE格式!", L"提示", 0);
		return;
	}
	
	// 找到文件头
	IMAGE_FILE_HEADER pFile = pNt->FileHeader;
	// 区段数量
	LPTSTR szBuffer1 = new TCHAR[100];
	WORD NumberOfSecTions = pFile.NumberOfSections;
	wsprintf(szBuffer1, L"%d个", NumberOfSecTions);
	QString NumberOfSecTionsQString = QString::fromWCharArray(szBuffer1);
	ui.NumberOfSections->setText(NumberOfSecTionsQString);
	// 扩展头大小
	LPTSTR szBuffer2 = new TCHAR[100];
	WORD SizeOfOptionalHeader = pFile.SizeOfOptionalHeader;
	wsprintf(szBuffer2, L"%Xh", SizeOfOptionalHeader);
	QString SizeOfOptionalHeaderQString = QString::fromWCharArray(szBuffer2);
	ui.SizeOfOptionalHeader->setText(SizeOfOptionalHeaderQString);

	// 找到扩展头
	IMAGE_OPTIONAL_HEADER pOptional = pNt->OptionalHeader;
	// 默认加载基址
	LPTSTR szBuffer3 = new TCHAR[100];
	DWORD ImageBase = pOptional.ImageBase;
	wsprintf(szBuffer3, L"%Xh", ImageBase);
	QString ImageBaseQString = QString::fromWCharArray(szBuffer3);
	ui.ImageBase->setText(ImageBaseQString);
	// 程序入口点
	LPTSTR szBuffer4 = new TCHAR[100];
	DWORD AddressOfEntryPoint = pOptional.AddressOfEntryPoint;
	wsprintf(szBuffer4, L"%Xh", AddressOfEntryPoint);
	QString AddressOfEntryPointQString = QString::fromWCharArray(szBuffer4);
	ui.OEP->setText(AddressOfEntryPointQString);
	// 内存对齐粒度
	LPTSTR szBuffer5 = new TCHAR[100];
	DWORD SectionAlignment = pOptional.SectionAlignment;
	wsprintf(szBuffer5, L"%Xh", SectionAlignment);
	QString SectionAlignmentQString = QString::fromWCharArray(szBuffer5);
	ui.SectionAlignment->setText(SectionAlignmentQString);
	// 文件对齐粒度
	LPTSTR szBuffer6 = new TCHAR[100];
	DWORD FileAlignment = pOptional.FileAlignment;
	wsprintf(szBuffer6, L"%Xh", FileAlignment);
	QString FileAlignmentQString = QString::fromWCharArray(szBuffer6);
	ui.FileAlignment->setText(FileAlignmentQString);

	// 释放堆空间
	delete[] szBuffer1;
	delete[] szBuffer2;
	delete[] szBuffer3;
	delete[] szBuffer4;
	delete[] szBuffer5;
	delete[] szBuffer6;
}

// 情况控件
VOID ViewPE::ClearWidgets()
{
	// 编辑框设置为空值
	m_lineEdit->setText("");
	ui.ImageBase->setText("");
	ui.OEP->setText("");
	ui.SectionAlignment->setText("");
	ui.FileAlignment->setText("");
	ui.NumberOfSections->setText("");
	ui.SizeOfOptionalHeader->setText("");
	// 把以下几个按钮置为不可用状态
	ui.actionDosHeader->setEnabled(false);
	ui.actionFileHeader->setEnabled(false);
	ui.actionOptionalHeader->setEnabled(false);
	ui.actionDataDirectory->setEnabled(false);
	ui.actionSectionHeader->setEnabled(false);
	ui.actionImportDescriptor->setEnabled(false);
}