#include <QApplication>
#include <QDialog>
#include "ui_P020  GoToCell.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	Ui::GoToCellDialog ui;
	QDialog * dialog = new QDialog;
	ui.setupUi(dialog);
	dialog->show();

	return app.exec();
}