// ����: 2014-08-26 13:00:08

#include <QApplication>	// ����Qtͼ�λ�Ӧ�ó���� ������Դ, ��������, ������, �¼�����...
	// ����Qt�ķ�ͼ�λ�Ӧ�ó���, ����Ҫ����<QCoreApplication>

#include <QPushButton>

int main(int argc, char ** argv)	// ���ͼ����ʾ, �¼�����Ĺ���
{
	QApplication app(argc, argv);
	QPushButton b("Hello World!");	// ����û��ָ����ť�ĸ�����, ������Լ�Ϊ������

	b.show();
	QObject::connect(&b, SIGNAL(clicked()), &app, SLOT(quit()));
	return app.exec();
}