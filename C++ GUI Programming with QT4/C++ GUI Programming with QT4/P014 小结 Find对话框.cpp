// ����FindDialog��Ķ������Q_OBJECT��, �����qmake���ɵ�makefile�����Զ�����һЩ����moc�Ĺ���, moc����ָQt��Ԫ���������, ��meta-object compiler
// Ϊ��ʹmoc�ܹ���������, ������ඨ���ʵ���ļ��з���������ŵ�ͷ�ļ���, ��moc���ɵĴ����������ͷ�ļ�, ���һ����һЩ�����C++����
#include <QApplication>	// ÿ��Qt�඼��һ�������ͬ��(�Ҵ�д)��ͷ�ļ�
#include "P010 FindDialog.h"
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);	// ����һ��QApplication����, ������������Ӧ�ó������õ�����Դ
	FindDialog * dialog = new FindDialog;
	dialog->show();	// ʹ���ڲ����ɼ�, �������ڲ�����ʱ��, ��ǩͨ�������ص�, ����������ǿ����ȶ����������, Ȼ������ʾ����, �Ӷ������˴��ڲ�������˸����
	return app.exec();	// ��Ӧ�ó���Ŀ���Ȩ���ݸ�Qt, ��ʱ��������ʱ��ѭ��״̬, ����һ�ֵȴ�ģʽ, �����Ⱥ��û�����
}
//	Qt�Ƿǳ�����, ���������ⴰ�ڲ�����������������