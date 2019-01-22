#include "QDataDirectory.h"

QDataDirectory::QDataDirectory(QWidget *parent, IMAGE_NT_HEADERS* pNt)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();

	// 找到扩展头
	IMAGE_OPTIONAL_HEADER pOptional = pNt->OptionalHeader;
	PIMAGE_DATA_DIRECTORY pData = pOptional.DataDirectory;

	// Export
	LPTSTR szBuffer0A = new TCHAR[100];
	LPTSTR szBuffer0B = new TCHAR[100];
	DWORD ExportRVA = pData[0].VirtualAddress;
	DWORD ExportSize = pData[0].Size;
	wsprintf(szBuffer0A, L"%Xh", ExportRVA);
	wsprintf(szBuffer0B, L"%Xh", ExportSize);
	QString ExportRVAQString = QString::fromWCharArray(szBuffer0A);
	QString ExportSizeQString = QString::fromWCharArray(szBuffer0B);
	ui.RVAExport->setText(ExportRVAQString);
	ui.SizeExport->setText(ExportSizeQString);

	// Import
	LPTSTR szBuffer1A = new TCHAR[100];
	LPTSTR szBuffer1B = new TCHAR[100];
	DWORD ImportRVA = pData[1].VirtualAddress;
	DWORD ImportSize = pData[1].Size;
	wsprintf(szBuffer1A, L"%Xh", ImportRVA);
	wsprintf(szBuffer1B, L"%Xh", ImportSize);
	QString ImportRVAQString = QString::fromWCharArray(szBuffer1A);
	QString ImportSizeQString = QString::fromWCharArray(szBuffer1B);
	ui.RVAImport->setText(ImportRVAQString);
	ui.SizeImport->setText(ImportSizeQString);

	// Resource
	LPTSTR szBuffer2A = new TCHAR[100];
	LPTSTR szBuffer2B = new TCHAR[100];
	DWORD ResourceRVA = pData[2].VirtualAddress;
	DWORD ResourceSize = pData[2].Size;
	wsprintf(szBuffer2A, L"%Xh", ResourceRVA);
	wsprintf(szBuffer2B, L"%Xh", ResourceSize);
	QString ResourceRVAQString = QString::fromWCharArray(szBuffer2A);
	QString ResourceSizeQString = QString::fromWCharArray(szBuffer2B);
	ui.RVAResource->setText(ResourceRVAQString);
	ui.SizeResource->setText(ResourceSizeQString);

	// Exception
	LPTSTR szBuffer3A = new TCHAR[100];
	LPTSTR szBuffer3B = new TCHAR[100];
	DWORD ExceptionRVA = pData[3].VirtualAddress;
	DWORD ExceptionSize = pData[3].Size;
	wsprintf(szBuffer3A, L"%Xh", ExceptionRVA);
	wsprintf(szBuffer3B, L"%Xh", ExceptionSize);
	QString ExceptionRVAQString = QString::fromWCharArray(szBuffer3A);
	QString ExceptionSizeQString = QString::fromWCharArray(szBuffer3B);
	ui.RVAException->setText(ExceptionRVAQString);
	ui.SizeException->setText(ExceptionSizeQString);

	// Security
	LPTSTR szBuffer4A = new TCHAR[100];
	LPTSTR szBuffer4B = new TCHAR[100];
	DWORD SecurityRVA = pData[4].VirtualAddress;
	DWORD SecuritySize = pData[4].Size;
	wsprintf(szBuffer4A, L"%Xh", SecurityRVA);
	wsprintf(szBuffer4B, L"%Xh", SecuritySize);
	QString SecurityRVAQString = QString::fromWCharArray(szBuffer4A);
	QString SecuritySizeQString = QString::fromWCharArray(szBuffer4B);
	ui.RVASecurity->setText(SecurityRVAQString);
	ui.SizeSecurity->setText(SecuritySizeQString);

	// BaseRelocationTable
	LPTSTR szBuffer5A = new TCHAR[100];
	LPTSTR szBuffer5B = new TCHAR[100];
	DWORD BaseRelocationTableRVA = pData[5].VirtualAddress;
	DWORD BaseRelocationTableSize = pData[5].Size;
	wsprintf(szBuffer5A, L"%Xh", BaseRelocationTableRVA);
	wsprintf(szBuffer5B, L"%Xh", BaseRelocationTableSize);
	QString BaseRelocationTableRVAQString = QString::fromWCharArray(szBuffer5A);
	QString BaseRelocationTableSizeQString = QString::fromWCharArray(szBuffer5B);
	ui.RVABaseRelocationTable->setText(BaseRelocationTableRVAQString);
	ui.SizeBaseRelocationTable->setText(BaseRelocationTableSizeQString);

	// DebugDirectory
	LPTSTR szBuffer6A = new TCHAR[100];
	LPTSTR szBuffer6B = new TCHAR[100];
	DWORD DebugDirectoryRVA = pData[6].VirtualAddress;
	DWORD DebugDirectorySize = pData[6].Size;
	wsprintf(szBuffer6A, L"%Xh", DebugDirectoryRVA);
	wsprintf(szBuffer6B, L"%Xh", DebugDirectorySize);
	QString DebugDirectoryRVAQString = QString::fromWCharArray(szBuffer6A);
	QString DebugDirectorySizeQString = QString::fromWCharArray(szBuffer6B);
	ui.RVADebugDirectory->setText(DebugDirectoryRVAQString);
	ui.SizeDebugDirectory->setText(DebugDirectorySizeQString);

	// CopyrightOrArchitectureSpecificData
	LPTSTR szBuffer7A = new TCHAR[100];
	LPTSTR szBuffer7B = new TCHAR[100];
	DWORD CopyrightRVA = pData[7].VirtualAddress;
	DWORD CopyrightSize = pData[7].Size;
	wsprintf(szBuffer7A, L"%Xh", CopyrightRVA);
	wsprintf(szBuffer7B, L"%Xh", CopyrightSize);
	QString CopyrightRVAQString = QString::fromWCharArray(szBuffer7A);
	QString CopyrightSizeQString = QString::fromWCharArray(szBuffer7B);
	ui.RVACopyright->setText(CopyrightRVAQString);
	ui.SizeCopyright->setText(CopyrightSizeQString);

	// GlobalPtr
	LPTSTR szBuffer8A = new TCHAR[100];
	LPTSTR szBuffer8B = new TCHAR[100];
	DWORD GlobalPtrRVA = pData[8].VirtualAddress;
	DWORD GlobalPtrSize = pData[8].Size;
	wsprintf(szBuffer8A, L"%Xh", GlobalPtrRVA);
	wsprintf(szBuffer8B, L"%Xh", GlobalPtrSize);
	QString GlobalPtrRVAQString = QString::fromWCharArray(szBuffer8A);
	QString GlobalPtrSizeQString = QString::fromWCharArray(szBuffer8B);
	ui.RVAGlobalPtr->setText(GlobalPtrRVAQString);
	ui.SizeGlobalPtr->setText(GlobalPtrSizeQString);

	// TLSDirectory
	LPTSTR szBuffer9A = new TCHAR[100];
	LPTSTR szBuffer9B = new TCHAR[100];
	DWORD TLSDirectoryRVA = pData[9].VirtualAddress;
	DWORD TLSDirectorySize = pData[9].Size;
	wsprintf(szBuffer9A, L"%Xh", TLSDirectoryRVA);
	wsprintf(szBuffer9B, L"%Xh", TLSDirectorySize);
	QString TLSDirectoryRVAQString = QString::fromWCharArray(szBuffer9A);
	QString TLSDirectorySizeQString = QString::fromWCharArray(szBuffer9B);
	ui.RVATLSDirectory->setText(TLSDirectoryRVAQString);
	ui.SizeTLSDirectory->setText(TLSDirectorySizeQString);

	// LoadConfigurationDirectory
	LPTSTR szBuffer10A = new TCHAR[100];
	LPTSTR szBuffer10B = new TCHAR[100];
	DWORD LoadConfigurationDirectoryRVA = pData[10].VirtualAddress;
	DWORD LoadConfigurationDirectorySize = pData[10].Size;
	wsprintf(szBuffer10A, L"%Xh", LoadConfigurationDirectoryRVA);
	wsprintf(szBuffer10B, L"%Xh", LoadConfigurationDirectorySize);
	QString LoadConfigurationDirectoryRVAQString = QString::fromWCharArray(szBuffer10A);
	QString LoadConfigurationDirectorySizeQString = QString::fromWCharArray(szBuffer10B);
	ui.RVALoadConfigurationDirectory->setText(LoadConfigurationDirectoryRVAQString);
	ui.SizeLoadConfigurationDirectory->setText(LoadConfigurationDirectorySizeQString);

	// BoundImportDirectory
	LPTSTR szBuffer11A = new TCHAR[100];
	LPTSTR szBuffer11B = new TCHAR[100];
	DWORD BoundImportDirectoryRVA = pData[11].VirtualAddress;
	DWORD BoundImportDirectorySize = pData[11].Size;
	wsprintf(szBuffer11A, L"%Xh", BoundImportDirectoryRVA);
	wsprintf(szBuffer11B, L"%Xh", BoundImportDirectorySize);
	QString BoundImportDirectoryRVAQString = QString::fromWCharArray(szBuffer11A);
	QString BoundImportDirectorySizeQString = QString::fromWCharArray(szBuffer11B);
	ui.RVABoundImportDirectory->setText(BoundImportDirectoryRVAQString);
	ui.SizeBoundImportDirectory->setText(BoundImportDirectorySizeQString);

	// ImportAddressTable
	LPTSTR szBuffer12A = new TCHAR[100];
	LPTSTR szBuffer12B = new TCHAR[100];
	DWORD ImportAddressTableRVA = pData[12].VirtualAddress;
	DWORD ImportAddressTableSize = pData[12].Size;
	wsprintf(szBuffer12A, L"%Xh", ImportAddressTableRVA);
	wsprintf(szBuffer12B, L"%Xh", ImportAddressTableSize);
	QString ImportAddressTableRVAQString = QString::fromWCharArray(szBuffer12A);
	QString ImportAddressTableSizeQString = QString::fromWCharArray(szBuffer12B);
	ui.RVAImportAddressTable->setText(ImportAddressTableRVAQString);
	ui.SizeImportAddressTable->setText(ImportAddressTableSizeQString);

	// DelayLoadImportDescriptors
	LPTSTR szBuffer13A = new TCHAR[100];
	LPTSTR szBuffer13B = new TCHAR[100];
	DWORD DelayLoadImportDescriptorsRVA = pData[13].VirtualAddress;
	DWORD DelayLoadImportDescriptorsSize = pData[13].Size;
	wsprintf(szBuffer13A, L"%Xh", DelayLoadImportDescriptorsRVA);
	wsprintf(szBuffer13B, L"%Xh", DelayLoadImportDescriptorsSize);
	QString DelayLoadImportDescriptorsRVAQString = QString::fromWCharArray(szBuffer13A);
	QString DelayLoadImportDescriptorsSizeQString = QString::fromWCharArray(szBuffer13B);
	ui.RVADelayLoadImportDescriptors->setText(DelayLoadImportDescriptorsRVAQString);
	ui.SizeDelayLoadImportDescriptors->setText(DelayLoadImportDescriptorsSizeQString);

	// COMRuntimedescriptor
	LPTSTR szBuffer14A = new TCHAR[100];
	LPTSTR szBuffer14B = new TCHAR[100];
	DWORD COMRuntimedescriptorRVA = pData[14].VirtualAddress;
	DWORD COMRuntimedescriptorSize = pData[14].Size;
	wsprintf(szBuffer14A, L"%Xh", COMRuntimedescriptorRVA);
	wsprintf(szBuffer14B, L"%Xh", COMRuntimedescriptorSize);
	QString COMRuntimedescriptorRVAQString = QString::fromWCharArray(szBuffer14A);
	QString COMRuntimedescriptorSizeQString = QString::fromWCharArray(szBuffer14B);
	ui.RVACOMRuntimedescriptor->setText(COMRuntimedescriptorRVAQString);
	ui.SizeCOMRuntimedescriptor->setText(COMRuntimedescriptorSizeQString);

	// Reserved
	LPTSTR szBuffer15A = new TCHAR[100];
	LPTSTR szBuffer15B = new TCHAR[100];
	DWORD ReservedRVA = pData[15].VirtualAddress;
	DWORD ReservedSize = pData[15].Size;
	wsprintf(szBuffer15A, L"%Xh", ReservedRVA);
	wsprintf(szBuffer15B, L"%Xh", ReservedSize);
	QString ReservedRVAQString = QString::fromWCharArray(szBuffer15A);
	QString ReservedSizeQString = QString::fromWCharArray(szBuffer15B);
	ui.RVAReserved->setText(ReservedRVAQString);
	ui.SizeReserved->setText(ReservedSizeQString);

	// 释放堆空间
	delete[] szBuffer0A;
	delete[] szBuffer0B;
	delete[] szBuffer1A;
	delete[] szBuffer1B;
	delete[] szBuffer2A;
	delete[] szBuffer2B;
	delete[] szBuffer3A;
	delete[] szBuffer3B;
	delete[] szBuffer4A;
	delete[] szBuffer4B;
	delete[] szBuffer5A;
	delete[] szBuffer5B;
	delete[] szBuffer6A;
	delete[] szBuffer6B;
	delete[] szBuffer7A;
	delete[] szBuffer7B;
	delete[] szBuffer8A;
	delete[] szBuffer8B;
	delete[] szBuffer9A;
	delete[] szBuffer9B;
	delete[] szBuffer10A;
	delete[] szBuffer10B;
	delete[] szBuffer11A;
	delete[] szBuffer11B;
	delete[] szBuffer12A;
	delete[] szBuffer12B;
	delete[] szBuffer13A;
	delete[] szBuffer13B;
	delete[] szBuffer14A;
	delete[] szBuffer14B;
	delete[] szBuffer15A;
	delete[] szBuffer15B;
}

QDataDirectory::~QDataDirectory()
{
}

// 初始化对话框
void QDataDirectory::updateMain()
{
	// 禁止最大化按钮
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());
}

// 重写虚函数keyPressEvent
void QDataDirectory::keyPressEvent(QKeyEvent *event)
{
	// Esc键 隐藏窗口
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}
