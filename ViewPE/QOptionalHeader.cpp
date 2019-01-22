#include "QOptionalHeader.h"

QOptionalHeader::QOptionalHeader(QWidget *parent, IMAGE_NT_HEADERS* pNt)
	: QWidget(parent)
{
	ui.setupUi(this);
	updateMain();
	// 找到文件头
	IMAGE_OPTIONAL_HEADER pOptional = pNt->OptionalHeader;

	// Magic
	LPTSTR szBuffer1 = new TCHAR[100];
	WORD Magic = pOptional.Magic;
	wsprintf(szBuffer1, L"%Xh", Magic);
	QString MagicQString = QString::fromWCharArray(szBuffer1);
	ui.Magic->setText(MagicQString);

	// MajorLinkerVersion
	LPTSTR szBuffer2 = new TCHAR[100];
	BYTE MajorLinkerVersion = pOptional.MajorLinkerVersion;
	wsprintf(szBuffer2, L"%Xh", MajorLinkerVersion);
	QString MajorLinkerVersionQString = QString::fromWCharArray(szBuffer2);
	ui.MajorLinkerVersion->setText(MajorLinkerVersionQString);

	// MinorLinkerVersion
	LPTSTR szBuffer3 = new TCHAR[100];
	BYTE MinorLinkerVersion = pOptional.MinorLinkerVersion;
	wsprintf(szBuffer3, L"%Xh", MinorLinkerVersion);
	QString MinorLinkerVersionQString = QString::fromWCharArray(szBuffer3);
	ui.MinorLinkerVersion->setText(MinorLinkerVersionQString);

	// SizeOfCode
	LPTSTR szBuffer4 = new TCHAR[100];
	DWORD SizeOfCode = pOptional.SizeOfCode;
	wsprintf(szBuffer4, L"%Xh", SizeOfCode);
	QString SizeOfCodeQString = QString::fromWCharArray(szBuffer4);
	ui.SizeOfCode->setText(SizeOfCodeQString);

	// SizeOfInitializedData
	LPTSTR szBuffer5 = new TCHAR[100];
	DWORD SizeOfInitializedData = pOptional.SizeOfInitializedData;
	wsprintf(szBuffer5, L"%Xh", SizeOfInitializedData);
	QString SizeOfInitializedDataQString = QString::fromWCharArray(szBuffer5);
	ui.SizeOfInitializedData->setText(SizeOfInitializedDataQString);

	// SizeOfUninitializedData
	LPTSTR szBuffer6 = new TCHAR[100];
	DWORD SizeOfUninitializedData = pOptional.SizeOfUninitializedData;
	wsprintf(szBuffer6, L"%Xh", SizeOfUninitializedData);
	QString SizeOfUninitializedDataQString = QString::fromWCharArray(szBuffer6);
	ui.SizeOfUninitializedData->setText(SizeOfUninitializedDataQString);

	// AddressOfEntryPoint
	LPTSTR szBuffer7 = new TCHAR[100];
	DWORD AddressOfEntryPoint = pOptional.AddressOfEntryPoint;
	wsprintf(szBuffer7, L"%Xh", AddressOfEntryPoint);
	QString AddressOfEntryPointQString = QString::fromWCharArray(szBuffer7);
	ui.AddressOfEntryPoint->setText(AddressOfEntryPointQString);

	// BaseOfCode
	LPTSTR szBuffer8 = new TCHAR[100];
	DWORD BaseOfCode = pOptional.BaseOfCode;
	wsprintf(szBuffer8, L"%Xh", BaseOfCode);
	QString BaseOfCodeQString = QString::fromWCharArray(szBuffer8);
	ui.BaseOfCode->setText(BaseOfCodeQString);

	// BaseOfData
	LPTSTR szBuffer9 = new TCHAR[100];
	DWORD BaseOfData = pOptional.BaseOfData;
	wsprintf(szBuffer9, L"%Xh", BaseOfData);
	QString BaseOfDataQString = QString::fromWCharArray(szBuffer9);
	ui.BaseOfData->setText(BaseOfDataQString);

	// ImageBase
	LPTSTR szBuffer10 = new TCHAR[100];
	DWORD ImageBase = pOptional.ImageBase;
	wsprintf(szBuffer10, L"%Xh", ImageBase);
	QString ImageBaseQString = QString::fromWCharArray(szBuffer10);
	ui.ImageBase->setText(ImageBaseQString);

	// SectionAlignment
	LPTSTR szBuffer11 = new TCHAR[100];
	DWORD SectionAlignment = pOptional.SectionAlignment;
	wsprintf(szBuffer11, L"%Xh", SectionAlignment);
	QString SectionAlignmentQString = QString::fromWCharArray(szBuffer11);
	ui.SectionAlignment->setText(SectionAlignmentQString);

	// FileAlignment
	LPTSTR szBuffer12 = new TCHAR[100];
	DWORD FileAlignment = pOptional.FileAlignment;
	wsprintf(szBuffer12, L"%Xh", FileAlignment);
	QString FileAlignmentQString = QString::fromWCharArray(szBuffer12);
	ui.FileAlignment->setText(FileAlignmentQString);

	// MajorOperatingSystemVersion
	LPTSTR szBuffer13 = new TCHAR[100];
	WORD MajorOperatingSystemVersion = pOptional.MajorOperatingSystemVersion;
	wsprintf(szBuffer13, L"%Xh", MajorOperatingSystemVersion);
	QString MajorOperatingSystemVersionQString = QString::fromWCharArray(szBuffer13);
	ui.MajorOperatingSystemVersion->setText(MajorOperatingSystemVersionQString);

	// MinorOperatingSystemVersion
	LPTSTR szBuffer14 = new TCHAR[100];
	WORD MinorOperatingSystemVersion = pOptional.MinorOperatingSystemVersion;
	wsprintf(szBuffer14, L"%Xh", MinorOperatingSystemVersion);
	QString MinorOperatingSystemVersionQString = QString::fromWCharArray(szBuffer14);
	ui.MinorOperatingSystemVersion->setText(MinorOperatingSystemVersionQString);

	// MajorImageVersion
	LPTSTR szBuffer15 = new TCHAR[100];
	WORD MajorImageVersion = pOptional.MajorImageVersion;
	wsprintf(szBuffer15, L"%Xh", MajorImageVersion);
	QString MajorImageVersionQString = QString::fromWCharArray(szBuffer15);
	ui.MajorImageVersion->setText(MajorImageVersionQString);

	// MinorImageVersion
	LPTSTR szBuffer16 = new TCHAR[100];
	WORD MinorImageVersion = pOptional.MinorImageVersion;
	wsprintf(szBuffer16, L"%Xh", MinorImageVersion);
	QString MinorImageVersionQString = QString::fromWCharArray(szBuffer16);
	ui.MinorImageVersion->setText(MinorImageVersionQString);

	// MajorSubsystemVersion
	LPTSTR szBuffer17 = new TCHAR[100];
	WORD MajorSubsystemVersion = pOptional.MajorSubsystemVersion;
	wsprintf(szBuffer17, L"%Xh", MajorSubsystemVersion);
	QString MajorSubsystemVersionQString = QString::fromWCharArray(szBuffer17);
	ui.MajorSubsystemVersion->setText(MajorSubsystemVersionQString);

	// MinorSubsystemVersion
	LPTSTR szBuffer18 = new TCHAR[100];
	WORD MinorSubsystemVersion = pOptional.MinorSubsystemVersion;
	wsprintf(szBuffer18, L"%Xh", MinorSubsystemVersion);
	QString MinorSubsystemVersionQString = QString::fromWCharArray(szBuffer18);
	ui.MinorSubsystemVersion->setText(MinorSubsystemVersionQString);

	// Win32VersionValue
	LPTSTR szBuffer19 = new TCHAR[100];
	DWORD Win32VersionValue = pOptional.Win32VersionValue;
	wsprintf(szBuffer19, L"%Xh", Win32VersionValue);
	QString Win32VersionValueQString = QString::fromWCharArray(szBuffer19);
	ui.Win32VersionValue->setText(Win32VersionValueQString);

	// SizeOfImage
	LPTSTR szBuffer20 = new TCHAR[100];
	DWORD SizeOfImage = pOptional.SizeOfImage;
	wsprintf(szBuffer20, L"%Xh", SizeOfImage);
	QString SizeOfImageQString = QString::fromWCharArray(szBuffer20);
	ui.SizeOfImage->setText(SizeOfImageQString);

	// SizeOfHeaders
	LPTSTR szBuffer21 = new TCHAR[100];
	DWORD SizeOfHeaders = pOptional.SizeOfHeaders;
	wsprintf(szBuffer21, L"%Xh", SizeOfHeaders);
	QString SizeOfHeadersQString = QString::fromWCharArray(szBuffer21);
	ui.SizeOfHeaders->setText(SizeOfHeadersQString);

	// CheckSum
	LPTSTR szBuffer22 = new TCHAR[100];
	DWORD CheckSum = pOptional.CheckSum;
	wsprintf(szBuffer22, L"%Xh", CheckSum);
	QString CheckSumQString = QString::fromWCharArray(szBuffer22);
	ui.CheckSum->setText(CheckSumQString);

	// Subsystem
	LPTSTR szBuffer23 = new TCHAR[100];
	WORD Subsystem = pOptional.Subsystem;
	wsprintf(szBuffer23, L"%Xh", Subsystem);
	QString SubsystemQString = QString::fromWCharArray(szBuffer23);
	ui.Subsystem->setText(SubsystemQString);

	// DllCharacteristics
	LPTSTR szBuffer24 = new TCHAR[100];
	WORD DllCharacteristics = pOptional.DllCharacteristics;
	wsprintf(szBuffer24, L"%Xh", DllCharacteristics);
	QString DllCharacteristicsQString = QString::fromWCharArray(szBuffer24);
	ui.DllCharacteristics->setText(DllCharacteristicsQString);

	// SizeOfStackReserve
	LPTSTR szBuffer25 = new TCHAR[100];
	DWORD SizeOfStackReserve = pOptional.SizeOfStackReserve;
	wsprintf(szBuffer25, L"%Xh", SizeOfStackReserve);
	QString SizeOfStackReserveQString = QString::fromWCharArray(szBuffer25);
	ui.SizeOfStackReserve->setText(SizeOfStackReserveQString);

	// SizeOfStackCommit
	LPTSTR szBuffer26 = new TCHAR[100];
	DWORD SizeOfStackCommit = pOptional.SizeOfStackCommit;
	wsprintf(szBuffer26, L"%Xh", SizeOfStackCommit);
	QString SizeOfStackCommitQString = QString::fromWCharArray(szBuffer26);
	ui.SizeOfStackCommit->setText(SizeOfStackCommitQString);

	// SizeOfHeapReserve
	LPTSTR szBuffer27 = new TCHAR[100];
	DWORD SizeOfHeapReserve = pOptional.SizeOfHeapReserve;
	wsprintf(szBuffer27, L"%Xh", SizeOfHeapReserve);
	QString SizeOfHeapReserveQString = QString::fromWCharArray(szBuffer27);
	ui.SizeOfHeapReserve->setText(SizeOfHeapReserveQString);

	// SizeOfHeapCommit
	LPTSTR szBuffer28 = new TCHAR[100];
	DWORD SizeOfHeapCommit = pOptional.SizeOfHeapCommit;
	wsprintf(szBuffer28, L"%Xh", SizeOfHeapCommit);
	QString SizeOfHeapCommitQString = QString::fromWCharArray(szBuffer28);
	ui.SizeOfHeapCommit->setText(SizeOfHeapCommitQString);

	// LoaderFlags
	LPTSTR szBuffer29 = new TCHAR[100];
	DWORD LoaderFlags = pOptional.LoaderFlags;
	wsprintf(szBuffer29, L"%Xh", LoaderFlags);
	QString LoaderFlagsQString = QString::fromWCharArray(szBuffer29);
	ui.LoaderFlags->setText(LoaderFlagsQString);

	// NumberOfRvaAndSizes
	LPTSTR szBuffer30 = new TCHAR[100];
	DWORD NumberOfRvaAndSizes = pOptional.NumberOfRvaAndSizes;
	wsprintf(szBuffer30, L"%Xh", NumberOfRvaAndSizes);
	QString NumberOfRvaAndSizesQString = QString::fromWCharArray(szBuffer30);
	ui.NumberOfRvaAndSizes->setText(NumberOfRvaAndSizesQString);

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
	delete[] szBuffer20;
	delete[] szBuffer21;
	delete[] szBuffer22;
	delete[] szBuffer23;
	delete[] szBuffer24;
	delete[] szBuffer25;
	delete[] szBuffer26;
	delete[] szBuffer27;
	delete[] szBuffer28;
	delete[] szBuffer29;
	delete[] szBuffer30;
}

QOptionalHeader::~QOptionalHeader()
{
}

// 初始化对话框
void QOptionalHeader::updateMain()
{
	// 禁止最大化按钮
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	// 禁止拖动窗口大小
	setFixedSize(this->width(), this->height());
}

// 重写虚函数keyPressEvent
void QOptionalHeader::keyPressEvent(QKeyEvent *event)
{
	// Esc键 隐藏窗口
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}
