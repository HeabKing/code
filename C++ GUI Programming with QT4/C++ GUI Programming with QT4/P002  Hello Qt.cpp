#include <QApplication>	// ÿ��Qt�඼��һ��ͬ��ͷ�ļ�
#include <QLabel>
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);	// ��������Ӧ�ó����õ�����Դ
	QLabel * label = new QLabel("<h3>Hello <font size = 20 color = red>Qt!</font></h3>");	  // ����һ�����ڲ���
	label->show();	// ʹ��ɼ�, �����Ĵ��ڲ���Ĭ�������ص�
	return app.exec();	// ��Ӧ�ó���Ŀ���Ȩ���ݸ�Qt, ��ʱ��������¼�ѭ��״̬, �ȴ��û�����
}