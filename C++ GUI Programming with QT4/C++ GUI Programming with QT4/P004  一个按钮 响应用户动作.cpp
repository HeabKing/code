#include <QApplication>
#include <QPushButton>
int main(int argc, char * argv[])
{
	QApplication App(argc, argv);
	QPushButton * button = new QPushButton("Quit");
	QObject::connect(button, SIGNAL(clicked()), &App, SLOT(quit()));	// ��һ���û��Ķ�����һ�δ�����������
	button->show();
	return App.exec();
}