#include <QApplication>
#include "P015 review P014.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);	// ����һ��QApplication����, ������������Ӧ�ó������õ�����Դ
	FindDialog * dialog = new FindDialog;
	dialog->show();	// ʹ���ڲ����ɼ�, �������ڲ�����ʱ��, ��ǩͨ�������ص�, ����������ǿ����ȶ����������, Ȼ������ʾ����, �Ӷ������˴��ڲ�������˸����
	return app.exec();	// ��Ӧ�ó���Ŀ���Ȩ���ݸ�Qt, ��ʱ��������ʱ��ѭ��״̬, ����һ�ֵȴ�ģʽ, �����Ⱥ��û�����
}