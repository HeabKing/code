// ����: 2014-08-26 13:10:12
// ��׼�Ի���: �ļ��Ի���, ��ɫ�Ի���, ����Ի���		
// �����Ժ�� QErrorMessage, QInputDialog, QMessageBox, QPrintDialog, QProgressDialog...

#include <QApplication>
#include "02 standardDialogs.h"

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);
	StandardDialogs s(nullptr);

	s.show();
	return app.exec();
}