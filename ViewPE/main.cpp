#include "ViewPE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// ȷ�������������ص�״̬�£��ر��Ӵ��ڳ����˳�
	a.setQuitOnLastWindowClosed(false);
	ViewPE w;
	w.show();
	return a.exec();
}
