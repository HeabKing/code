#include <QApplication>	// ÿ��Qt�඼��һ�������ͬ��(�Ҵ�д)��ͷ�ļ�
#include <QLabel>
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);	// ����һ��QApplication����, ������������Ӧ�ó������õ�����Դ;
	QLabel *label = new QLabel("<h3><i>Hello </i> <font size = 20 color = red>Qt!</font></h3>");	// ����һ����ʾ"Hello Qt!"��QLabel���ڲ���(widget: windows gadget(�������)), ���ڲ��������û������е�һ�����ӻ�Ԫ��;
	label->show();	// ʹ��QLabel��ǩ�ɼ�, �������ڲ�����ʱ��, ��ǩͨ�������ص�, ����������ǿ����ȶ����������, Ȼ������ʾ����, �Ӷ������˴��ڲ�������˸����;
	return app.exec();	// ��Ӧ�ó���Ŀ���Ȩ���ݸ�Qt, ��ʱ���������¼�ѭ��״̬, ����һ�ֵȴ�ģʽ, �����Ⱥ��û�����;
}
// QT�Ƿǳ�����, ���������ⴰ�ڲ�����������������, ������, �ô��ڲ���QLabel��ΪӦ�ó���Ĵ���;