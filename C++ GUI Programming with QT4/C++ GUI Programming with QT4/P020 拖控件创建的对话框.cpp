#define V2

#if defined V1
#include <QApplication>
#include <QDialog>
#include "GeneratedFiles/ui_P020 GoToCell.h"	// qmake����һ��.pro�ļ���һ��makefile�ļ�, qmake�ǳ�����, �������Զ���⵽�û������ļ�P020 GoToCell.ui���ҿ��������ʵ���makefile����������Qt���û����������(user interface compiler, uic), uic���߻ὫP020 GoToCell.ui�ļ�ת����C++���ҽ�ת������洢��ui_P020 GoToCell.h�ļ���
												// ���ɵ�ui_P020 GoToCell.h�ļ��а�����Ui::GoToCellDialog�Ķ���, ������һ����P020 GoToCell.ui�ļ��ȼ۵�C++�ļ�. �����������һЩ��Ա����, ���Ǵ洢�ⴰ���е��Ӵ��ڲ������Ӳ���, �Լ����ڳ�ʼ�������setupUi()����;
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	Ui::GoToCellDialog ui;
	QDialog * dialog = new QDialog;
	ui.setupUi(dialog);	// ���ɵ���û���κλ���, �����ļ���ʹ�øô���ʱ, ���Դ���һ��QDialog����, Ȼ��������ݸ�setupUi����
	dialog->show();

	return app.exec();
}

#elif defined V2

#include <QApplication>
#include "P020 GoToCell.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	GoToCellDialog * dialog = new GoToCellDialog;
	dialog->show();
	return app.exec();
}

#endif