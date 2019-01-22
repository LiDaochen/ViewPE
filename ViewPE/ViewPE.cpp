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

// ��ʼ���Ի���
void ViewPE::UpdataMain()
{
	/* ���࿪ */
	HANDLE hMutex = CreateMutex(NULL, TRUE, TEXT("OBSMutex"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		setlocale(LC_ALL, "chs");
		EnumNotifyWindow(FindTrayWnd());
		CloseHandle(hMutex);
		ExitProcess(0);
		return;
	}

	// �򹤾����������༭��
	m_lineEdit = new QLineEdit();
	// ���ñ༭��λֻ��
	m_lineEdit->setReadOnly(true);
	// ���빤����
	ui.mainToolBar->insertWidget(ui.actionOpenFile, m_lineEdit);

	// ��ֹ��󻯰�ť
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// ��ֹ�϶����ڴ�С
	setFixedSize(this->width(), this->height());

	// ��ʼ������
	isShowStatusbar = true;
	isShowToolBar = true;
	m_dragging = false;
	// ���ÿɽ����ļ���ק������
	this->setAcceptDrops(true);

	/*  ϵͳ����  */
	// ������ʾ���� 
	m_sysTray.setToolTip("ViewPE");
	// ��������ͼ��
	m_sysTray.setIcon(QIcon(":/Tray/Resources/tray.png"));
	// �������̲˵�
	QMenu* menu = new QMenu();
	// ��Ӵ������
	menu->addAction(ui.actionOpenMainDlg);
	// ��ӷָ���
	menu->addSeparator();
	// ��ӹ������
	menu->addAction(ui.actionAbout);
	// ����˳�����
	menu->addAction(ui.actionQuit);
	// �����Ҽ��˵�
	m_sysTray.setContextMenu(menu);
	// ��ʾ���̲˵�
	m_sysTray.show();

	// �����¼�����ť��Ϊ������״̬
	ui.actionDosHeader->setEnabled(false);
	ui.actionFileHeader->setEnabled(false);
	ui.actionOptionalHeader->setEnabled(false);
	ui.actionDataDirectory->setEnabled(false);
	ui.actionSectionHeader->setEnabled(false);
	ui.actionImportDescriptor->setEnabled(false);
}

// ��������������Ҫ��ʵ�ֵ���һ�������ʱ���ٴγ��Դ򿪳���ģ����ϵͳ����ͼ�꣬ʹ���еĳ�����������ʾ����
// �ж�ϵͳ�Ƿ�Ϊ64λϵͳ
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

// ��ȡ���ھ��
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

	//��ȡͼ�����
	int lButton = SendMessage(hWnd, TB_BUTTONCOUNT, 0, 0);
	for (int i = 0; i < lButton; i++) {
		SendMessage(hWnd, TB_GETITEMRECT, i, (LPARAM)pBun);
		SendMessage(hWnd, TB_GETBUTTON, i, (LPARAM)lAddress);
		//������
		ReadProcessMemory(hProcess, pBun, (LPVOID)ptb, sizeof(RECT), 0);
		//���ı���ַ
		ReadProcessMemory(hProcess, (LPVOID)((DWORD)lAddress + nDataOffset), &lTextAdr, 4, 0);
		if (lTextAdr != -1) {
			//���ı�
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

// �˵����ڰ�ť�¼�������
void ViewPE::actionAbout()
{
	QAbout dlg(this);
	dlg.exec();
}

// �˵��˳���ť�¼�������
void ViewPE::actionQuit()
{
	QApplication::exit();
}

// �˵����ļ���ť�¼�������
void ViewPE::actionOpenFile()
{
	// ѡ��Ҫ�򿪵��ļ�
	QString filePath = QFileDialog::getOpenFileName(this, GBK::ToUnicode("ѡ���ļ�"));
	// Ϊ��ʱ��ʾ�û�ȡ���˲�����û��ѡ���κε��ļ�
	if (filePath.length() > 0)
	{
		// �ж�ѡ����ļ��ǲ���exe ���� dll
		if (filePath.right(4) != ".exe" && filePath.right(4) != ".dll")
		{
			MessageBox(0, L"��ѡ��Ĳ���PE�ļ���", L"��ʾ", 0);
			ClearWidgets();
			return;
		}
		// �����ļ�·���������ı���
		m_lineEdit->setText(filePath);
		// �Ѽ�����ť��Ϊ����״̬
		ui.actionDosHeader->setEnabled(true);
		ui.actionFileHeader->setEnabled(true);
		ui.actionOptionalHeader->setEnabled(true);
		ui.actionDataDirectory->setEnabled(true);
		ui.actionSectionHeader->setEnabled(true);
		ui.actionImportDescriptor->setEnabled(true);
		ParsePE(filePath);
	}
}

// �˵��鿴��������ť�¼�������
void ViewPE::actionToolBar()
{
	if (isShowToolBar)
	{
		// ��־λ��Ϊfalse
		isShowToolBar = false;
		// ͼ������Ϊ���ɼ�
		ui.actionToolBar->setIconVisibleInMenu(false);
		// ���ع�����
		ui.mainToolBar->hide();
	}
	else
	{
		// ��־λ��Ϊ��
		isShowToolBar = true;
		// ͼ������Ϊ�ɼ�
		ui.actionToolBar->setIconVisibleInMenu(true);
		// ��ʾ������
		ui.mainToolBar->show();
	}
}

// �˵��鿴״̬����ť�¼�������
void ViewPE::actionStatusBar()
{
	if (isShowStatusbar)
	{
		// ��־λ��Ϊfalse
		isShowStatusbar = false;
		// ͼ������Ϊ���ɼ�
		ui.actionStatusBar->setIconVisibleInMenu(false);
		// ����״̬��
		ui.statusBar->setVisible(false);
	}
	else
	{
		// ��־λ��Ϊ��
		isShowStatusbar = true;
		// ͼ������Ϊ�ɼ�
		ui.actionStatusBar->setIconVisibleInMenu(true);
		// ��ʾ״̬��
		ui.statusBar->setVisible(true);
	}
}

// �����麯��closeEvent
void ViewPE::closeEvent(QCloseEvent *event)
{
	this->hide();
	event->ignore();
}

// ��д�麯��keyPressEvent
void ViewPE::keyPressEvent(QKeyEvent *event)
{
	// Ctrl + O ���ļ�
	if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_O)
	{
		actionOpenFile();
	}
	// Esc�� ���ش���
	else if (event->key() == Qt::Key_Escape)
	{
		this->hide();
	}
}

// ��������������Ҫ��ʵ��������϶�����
// ��дmouseMoveEvent�麯��
void ViewPE::mouseMoveEvent(QMouseEvent * event)
{
	// ֻ��Ӧ���
	if (event->buttons() & Qt::LeftButton)
	{
		if (m_dragging)
		{
			// delta ���ƫ����, 
			QPoint delta = event->globalPos() - m_startPosition;
			// ��λ�ã�����ԭʼλ��  + ƫ����
			move(m_framePosition + delta);
		}
	}
	QWidget::mouseMoveEvent(event);
}

// ��дmousePressEvent�麯��
void ViewPE::mousePressEvent(QMouseEvent * event)
{
	// ֻ��Ӧ���
	if (event->button() == Qt::LeftButton)
	{
		// ��־λ��Ϊ��
		m_dragging = true;
		// ��¼����굱ǰ��λ�ã��������Ļ���Ͻǣ�
		m_startPosition = event->globalPos();
		// ��¼�´��ڵ�ǰ��λ�ã��������Ļ���Ͻǣ�
		m_framePosition = frameGeometry().topLeft();
	}
	QWidget::mousePressEvent(event);
}

// ��дmouseReleaseEvent�麯��
void ViewPE::mouseReleaseEvent(QMouseEvent * event)
{
	// ��־λ��Ϊ��
	m_dragging = false;
	QWidget::mouseReleaseEvent(event);
}

// ��������������Ҫ��ʵ���ļ���ק
// ��дdragEnterEvent�麯��
void ViewPE::dragEnterEvent(QDragEnterEvent *event)
{
	event->acceptProposedAction();
}

// ��дdropEvent�麯��
void ViewPE::dropEvent(QDropEvent *event)
{
	QString name = event->mimeData()->urls().first().toString();
	// �ж�ѡ����ļ��ǲ���exe ���� dll
	if (name.right(4) != ".exe" && name.right(4) != ".dll")
	{
		MessageBox(0, L"��ѡ��Ĳ���PE�ļ���", L"��ʾ", 0);
		ClearWidgets();
		return;
	}
	// ��ǰ���file:///ȥ��
	name.remove(0, 8);
	// �����ļ�·���������ı���
	m_lineEdit->setText(name);
	// �Ѽ�����ť��Ϊ����״̬
	ui.actionDosHeader->setEnabled(true);
	ui.actionFileHeader->setEnabled(true);
	ui.actionOptionalHeader->setEnabled(true);
	ui.actionDataDirectory->setEnabled(true);
	ui.actionSectionHeader->setEnabled(true);
	ui.actionImportDescriptor->setEnabled(true);
	ParsePE(name);
}

// ��굥������˫��ϵͳ���̴�����
void ViewPE::OnSystemtrayClicked(QSystemTrayIcon::ActivationReason reason)
{
	if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
	{
		// ��ʾ������
		this->showNormal();
	}
}

// ������崦����
void ViewPE::actionOpenSystemTray()
{
	this->showNormal();
}

// DOSͷ��ť������
void ViewPE::actionDosHeader()
{
	QDosHeader dlg(this, m_pDos);
	dlg.exec();
}

// �ļ�ͷ��ť������
void ViewPE::actionFileHeader()
{
	// �ļ�ͷ��ģ̬�Ի���
	m_fileHeaderWin = new QFileHeader(this, m_pNt);
	m_fileHeaderWin->setWindowFlags(Qt::Window);
	m_fileHeaderWin->show();
}

// ��չͷ��ť������
void ViewPE::actionOptionalHeader()
{
	// ��չͷ
	m_optionalHeaderWin = new QOptionalHeader(this, m_pNt);
	m_optionalHeaderWin->setWindowFlags(Qt::Window);
	m_optionalHeaderWin->show();
}

// ����Ŀ¼��ť������
void ViewPE::actionDataDirectory()
{
	// ����Ŀ¼��
	m_dataWin = new QDataDirectory(this, m_pNt);
	m_dataWin->setWindowFlags(Qt::Window);
	m_dataWin->show();
}

// ����ͷ��ť������
void ViewPE::actionSectionTable()
{
	// ����ͷ
	m_sectionWin = new QSection(this, m_pNt);
	m_sectionWin->setWindowFlags(Qt::Window);
	m_sectionWin->show();
}

// �����ť������
void ViewPE::actionImport()
{
	// �����
	m_importWin = new QImport(this, m_pNt, m_pBuff);
	m_importWin->setWindowFlags(Qt::Window);
	m_importWin->show();
}

// ����PE�ļ�
VOID ViewPE::ParsePE(QString filePath)
{
	// ��·���� QString תΪ WCHAR*
	const wchar_t * encodedName = reinterpret_cast<const wchar_t *>(filePath.utf16());
	// ���ļ�
	HANDLE hFile = CreateFile(encodedName, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == (HANDLE)-1)
	{
		MessageBox(0, L"���ļ�ʧ�ܣ�", L"��ʾ", 0);
		ClearWidgets();
		return;
	}
	// ��ȡ�ļ���С
	DWORD size = GetFileSize(hFile, NULL);
	// ���뻺����
	LPBYTE pBuff = new BYTE[size];
	DWORD dwRead = 0;
	// ���ļ���������
	ReadFile(hFile, pBuff, size, &dwRead, 0);
	m_pBuff = pBuff;
	// DOSͷ����
	IMAGE_DOS_HEADER* pDos = NULL;
	pDos = (IMAGE_DOS_HEADER*)pBuff;
	m_pDos = pDos;
	if (pDos->e_magic != IMAGE_DOS_SIGNATURE)
	{
		MessageBox(0, L"������Ч��PE�ļ�!", L"��ʾ", 0);
		return;
	}
	// �ҵ�NTͷ
	IMAGE_NT_HEADERS* pNt = NULL;
	pNt = (IMAGE_NT_HEADERS*)(pDos->e_lfanew + pBuff);
	m_pNt = pNt;
	if (pNt->Signature != IMAGE_NT_SIGNATURE)
	{
		MessageBox(0, L"������Ч��PE��ʽ!", L"��ʾ", 0);
		return;
	}
	
	// �ҵ��ļ�ͷ
	IMAGE_FILE_HEADER pFile = pNt->FileHeader;
	// ��������
	LPTSTR szBuffer1 = new TCHAR[100];
	WORD NumberOfSecTions = pFile.NumberOfSections;
	wsprintf(szBuffer1, L"%d��", NumberOfSecTions);
	QString NumberOfSecTionsQString = QString::fromWCharArray(szBuffer1);
	ui.NumberOfSections->setText(NumberOfSecTionsQString);
	// ��չͷ��С
	LPTSTR szBuffer2 = new TCHAR[100];
	WORD SizeOfOptionalHeader = pFile.SizeOfOptionalHeader;
	wsprintf(szBuffer2, L"%Xh", SizeOfOptionalHeader);
	QString SizeOfOptionalHeaderQString = QString::fromWCharArray(szBuffer2);
	ui.SizeOfOptionalHeader->setText(SizeOfOptionalHeaderQString);

	// �ҵ���չͷ
	IMAGE_OPTIONAL_HEADER pOptional = pNt->OptionalHeader;
	// Ĭ�ϼ��ػ�ַ
	LPTSTR szBuffer3 = new TCHAR[100];
	DWORD ImageBase = pOptional.ImageBase;
	wsprintf(szBuffer3, L"%Xh", ImageBase);
	QString ImageBaseQString = QString::fromWCharArray(szBuffer3);
	ui.ImageBase->setText(ImageBaseQString);
	// ������ڵ�
	LPTSTR szBuffer4 = new TCHAR[100];
	DWORD AddressOfEntryPoint = pOptional.AddressOfEntryPoint;
	wsprintf(szBuffer4, L"%Xh", AddressOfEntryPoint);
	QString AddressOfEntryPointQString = QString::fromWCharArray(szBuffer4);
	ui.OEP->setText(AddressOfEntryPointQString);
	// �ڴ��������
	LPTSTR szBuffer5 = new TCHAR[100];
	DWORD SectionAlignment = pOptional.SectionAlignment;
	wsprintf(szBuffer5, L"%Xh", SectionAlignment);
	QString SectionAlignmentQString = QString::fromWCharArray(szBuffer5);
	ui.SectionAlignment->setText(SectionAlignmentQString);
	// �ļ���������
	LPTSTR szBuffer6 = new TCHAR[100];
	DWORD FileAlignment = pOptional.FileAlignment;
	wsprintf(szBuffer6, L"%Xh", FileAlignment);
	QString FileAlignmentQString = QString::fromWCharArray(szBuffer6);
	ui.FileAlignment->setText(FileAlignmentQString);

	// �ͷŶѿռ�
	delete[] szBuffer1;
	delete[] szBuffer2;
	delete[] szBuffer3;
	delete[] szBuffer4;
	delete[] szBuffer5;
	delete[] szBuffer6;
}

// ����ؼ�
VOID ViewPE::ClearWidgets()
{
	// �༭������Ϊ��ֵ
	m_lineEdit->setText("");
	ui.ImageBase->setText("");
	ui.OEP->setText("");
	ui.SectionAlignment->setText("");
	ui.FileAlignment->setText("");
	ui.NumberOfSections->setText("");
	ui.SizeOfOptionalHeader->setText("");
	// �����¼�����ť��Ϊ������״̬
	ui.actionDosHeader->setEnabled(false);
	ui.actionFileHeader->setEnabled(false);
	ui.actionOptionalHeader->setEnabled(false);
	ui.actionDataDirectory->setEnabled(false);
	ui.actionSectionHeader->setEnabled(false);
	ui.actionImportDescriptor->setEnabled(false);
}