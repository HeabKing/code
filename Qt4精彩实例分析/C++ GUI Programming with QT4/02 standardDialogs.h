// ����: 2014-08-26 13:13:16
#ifndef  STANDARDDIALOG_H
#define  STANDARDDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
class StandardDialogs : public QDialog
{
	Q_OBJECT
public:
	inline StandardDialogs(QWidget * parent, Qt::WindowFlags f = 0);
	inline ~StandardDialogs(){}
public:
	QGridLayout * layout;
	QPushButton * filePushButton;
	QPushButton * colorPushButton;
	QPushButton * fontPushButton;
	QLineEdit	* fileLineEdit;
	QLineEdit	* fontLineEdit;
	QFrame		* colorFrame;
private slots:
	inline void slotOpenFileDlg();
	inline void slotOpenColorDlg();
	inline void slotOpenFontDlg();
};

StandardDialogs::StandardDialogs(QWidget * parent, Qt::WindowFlags f): QDialog(parent, f)
{
	setWindowTitle(tr("Standard Dialogs"));

	layout = new QGridLayout(this);	// �������ֵ�ʱ�����ָ��������

	filePushButton = new QPushButton;
	filePushButton->setText(tr("File Dialog"));

	colorPushButton = new QPushButton(tr("Color Dialog"));

	fontPushButton = new QPushButton;
	fontPushButton->setText(tr("Font Dialog"));

	fileLineEdit = new QLineEdit;

	colorFrame = new QFrame;
	colorFrame->setFrameShape(QFrame::Box);
	colorFrame->setAutoFillBackground(true);	// true: setPalette(QPalette(color)) ���ܹ�Ϊ���趨����ɫ

	fontLineEdit = new QLineEdit(tr("Hello World"));

	layout->addWidget(filePushButton, 0, 0);	
	layout->addWidget(fileLineEdit, 0, 1);	// 0, 1 ��0�е�1�� (y, x)
	layout->addWidget(colorPushButton, 1, 0);
	layout->addWidget(colorFrame, 1, 1);
	layout->addWidget(fontPushButton, 2, 0);
	layout->addWidget(fontLineEdit, 2, 1);

	layout->setMargin(150);	// �˲�������߿�ľ���
	layout->setSpacing(50);	// �β����ڲ����Բ���֮��ľ���

	connect(filePushButton, SIGNAL(clicked()), this, SLOT(slotOpenFileDlg()));
	connect(colorPushButton, SIGNAL(clicked()), this, SLOT(slotOpenColorDlg()));
	connect(fontPushButton, SIGNAL(clicked()), this, SLOT(slotOpenFontDlg()));
}

void StandardDialogs::slotOpenFileDlg()
{
	QString s = QFileDialog::getOpenFileName(	// getOpenFileName() ��̬����, �����ļ��� �� ""(ȡ��)
		this,					// ������
		"open file dialog",		// ����
		"/",					// Ĭ�ϵ�Ŀ¼ ������ļ�������Ĭ��ѡ�е��ļ�
		"C++ files and Head files(*.cpp *.h);;C files(*c)"	// ���ļ����ͽ��й���	(*.cpp *.h)	��ʾ����, ";;" ���������
		// QString * selectedFilter = 0,				// �û�ѡ��Ĺ�����
		// Options options = 0
		);	
	fileLineEdit->setText(s.toLocal8Bit().constData());

			// QFileDialog �ľ�̬����
	// getOpenFileName	����û�ѡ����ļ���
	// getSaveFileName	����û�������ļ���
	// getExistingDirectory	����û�ѡ����Ѵ��ڵ�Ŀ¼��
	// getOpenFileName		����û�ѡ����ļ����б�
}

void StandardDialogs::slotOpenColorDlg()
{
	QColor color = QColorDialog::getColor(Qt::blue);	// ��̬����, ������ɫֵ	����Ϊʲôδָ��������????
	if (color.isValid())	// ����û�ѡ����ȡ��, ��QColor::isValid()����flase;
		colorFrame->setPalette(QPalette(color));
}

void StandardDialogs::slotOpenFontDlg()
{
	bool ok;
	QFont font = QFontDialog::getFont(&ok);	// ��̬����, ��������, �û���Cancel, ����Ĭ������, ok��Ϊfalse
	if (ok)
		fontLineEdit->setFont(font);
}

#endif