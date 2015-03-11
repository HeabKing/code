#include "P036 MainWindow.h"
#include <QApplication>
#include <QSplashScreen>	// �������ڳ���֮ǰ��ʾһ��ͼƬ

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QSplashScreen * splash = new QSplashScreen;
	splash->setPixmap(QPixmap("images/begin.jpeg"));
	splash->show();

	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	splash->showMessage(QObject::tr("Setting up the main window..."), topRight, Qt::white);

	MainWindow * mainwindow = new MainWindow;

	splash->showMessage(QObject::tr("Loading modules..."));	// ����ģ���б�...

	//loadModules();

	splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);	// ��������...

	//establishConnections();

	mainwindow->show();
	splash->finish(mainwindow);
	delete splash;
	return app.exec();
}