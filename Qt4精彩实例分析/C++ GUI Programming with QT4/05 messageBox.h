// ����: 2014-08-27 12:07:45
// ������Ϣ��: 
//		1.	Question��Ϣ��, Information��Ϣ��, Warning��Ϣ��, Critical(���ؾ���)��Ϣ��
//			�÷���ͬС��, һ�����һ����ʾ��Ϣ, һ��ͼ���Լ����ɰ�ť
//		2.	About��Ϣ��, AboutQt��Ϣ��, Custom(�Զ���)��Ϣ��

#ifndef INFORMATIONBOX_H
#define INFORMATIONBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QMessageBox>

class MessageBox: public QWidget
{
	Q_OBJECT
private:
	QPushButton * questionButton;
	QPushButton * informationButton;
	QPushButton * warningButton;
	QPushButton * criticalButton;
	QPushButton * aboutButton;
	QPushButton * aboutQtButton;
	QPushButton * customButton;
	QGridLayout * layout;
public:
	inline MessageBox();
private slots:
	inline void slotQuestion();
	inline void slotInformation();
	inline void slotAboutQt();
	inline void slotCustom();
};

MessageBox::MessageBox()
{
	questionButton		= new QPushButton("Question");
	informationButton	= new QPushButton("Information");
	warningButton		= new QPushButton("Warning");
	criticalButton		= new QPushButton("Critical");
	aboutButton			= new QPushButton("About");
	aboutQtButton		= new QPushButton("AboutQt");
	customButton		= new QPushButton("Custom");
	layout				= new QGridLayout(this);

	layout->addWidget(questionButton, 0, 0);
	layout->addWidget(informationButton, 0, 1);
	layout->addWidget(warningButton, 1, 0);
	layout->addWidget(criticalButton, 1, 1);
	layout->addWidget(aboutButton, 2, 0);
	layout->addWidget(aboutQtButton, 2, 1);
	layout->addWidget(customButton, 3, 0);

	connect(questionButton, SIGNAL(clicked()), this, SLOT(slotQuestion()));
	connect(informationButton, SIGNAL(clicked()), this, SLOT(slotInformation()));
	connect(aboutQtButton, SIGNAL(clicked()), this, SLOT(slotAboutQt()));
	connect(customButton, SIGNAL(clicked()), this, SLOT(slotCustom()));
}

void MessageBox::slotQuestion()
{
	auto okOrCancel = QMessageBox::question(
		this,		// ������
		"Question",	// ������
		tr("It's end of document, search from begin?"),	// ��ʾ����
		QMessageBox::Ok | QMessageBox::Cancel,			// ��Ϣ���г��ֵİ�ť, Ĭ����QMessageBox::Ok
		QMessageBox::Ok);	// ��Ϣ����ֵ�ʱ��, ������Ok��ť��
}

void MessageBox::slotInformation()
{
	QMessageBox::information(this, "Information", tr("anything you want tell user"));
	return;
}

void MessageBox::slotAboutQt()
{
	QMessageBox::aboutQt(this, "AboutQt");
}

void MessageBox::slotCustom()
{
	QMessageBox customMsgBox;
	customMsgBox.setWindowTitle("Custom Message Box");
	QPushButton * lockButton	= customMsgBox.addButton(tr("Lock"), QMessageBox::ActionRole/*��ť���͵�����*/);
	QPushButton * unlockButton  = customMsgBox.addButton(tr("Unlock"), QMessageBox::ActionRole);
	QPushButton * cancelButton	= customMsgBox.addButton(QMessageBox::Cancel);	// ���һ����׼��ť
	customMsgBox.setIconPixmap(QPixmap("images/panda.png"));
	customMsgBox.setText("This is a custom message box");
	customMsgBox.exec();	// ����exec()��ʾ���Զ�����Ϣ��

	if (customMsgBox.clickedButton() == lockButton);	// ...���lock�������
}

#endif