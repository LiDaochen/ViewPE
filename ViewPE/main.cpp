#include "ViewPE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// 确保在主窗口隐藏的状态下，关闭子窗口程序不退出
	a.setQuitOnLastWindowClosed(false);
	ViewPE w;
	w.show();
	return a.exec();
}
