#include <QApplication>
#include <QPushButton>
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	QPushButton * button = new QPushButton("Quit");	// Ӧ�ó���������ڲ���ʹ�õ���QPushButton������QLabel
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));	// ���û���һ������(������ť)��һ�δ�����������
																		// Qt�Ĵ��ڲ���ͨ�������ź�(signal)������һ���û������Ѿ������˻�����һ��״̬�Ѿ��ı���
																		// ����������ť��clicked()�ź���QApplication�����quit()����������
	button->show();
	return app.exec();
}

// ˵�������Ӧ�û��Ķ���