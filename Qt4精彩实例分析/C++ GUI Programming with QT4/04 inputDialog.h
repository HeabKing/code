// ����: 2014-08-26 17:05:05
// ��׼����Ի���:		һ����ʾ��ǩ, һ������ؼ�, һ��OK��ť��һ��Cancel��ť
//		(1)	�ṩ�������������ݵ�����
//			�ַ���(QLineEdit)	int(QSpinBox)	double(QSpinBox)	�����б��(QComboBox)
#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QInputDialog>

class InputDlg: public QDialog
{
	Q_OBJECT
public:
	inline InputDlg();

public:
	QPushButton * nameButton;
	QPushButton * sexButton;
	QPushButton * ageButton;
	QPushButton * statureButton;

	QLabel * label1;
	QLabel * label2;
	QLabel * label3;
	QLabel * label4;
	QLabel * nameLabel;
	QLabel * sexLabel;
	QLabel * ageLabel;
	QLabel * statureLabel;
private slots:
	inline void slotName();
	inline void slotSex();
	inline void slotAge();
	inline void slotStature();
};

InputDlg::InputDlg()
{
	setWindowTitle(tr("InputDialog"));

	// ����������ǩ����
	label1 = new QLabel(tr("Name: "));
	label2 = new QLabel(tr("Sex: "));
	label3 = new QLabel(tr("Age: "));
	label4 = new QLabel(tr("Stature: "));
	// ����������ʾ��ǩ
	nameLabel = new QLabel("LiMing");
	nameLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	sexLabel = new QLabel("male");
	sexLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	ageLabel = new QLabel("26");
	ageLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	statureLabel = new QLabel("175");
	statureLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	// ���������޸İ�ť
	nameButton = new QPushButton;
	nameButton->setIcon(QIcon("images/edit.png"));
	sexButton = new QPushButton;
	sexButton->setIcon(QIcon("images/edit.png"));
	ageButton = new QPushButton;
	ageButton->setIcon(QIcon("images/edit.png"));
	statureButton = new QPushButton;
	statureButton->setIcon(QIcon("images/edit.png"));
	// ���ֹ���
	QGridLayout * layout = new QGridLayout(this);
	layout->addWidget(label1, 0, 0);
	layout->addWidget(nameLabel, 0, 1);
	layout->addWidget(nameButton, 0, 2);
	
	layout->addWidget(label2, 1, 0);
	layout->addWidget(sexLabel, 1, 1);
	layout->addWidget(sexButton, 1, 2);

	layout->addWidget(label3, 2, 0);
	layout->addWidget(ageLabel, 2, 1);
	layout->addWidget(ageButton, 2, 2);

	layout->addWidget(label4, 3, 0);
	layout->addWidget(statureLabel, 3, 1);
	layout->addWidget(statureButton, 3, 2);

	connect(nameButton, SIGNAL(clicked()), this, SLOT(slotName()));
	connect(sexButton, SIGNAL(clicked()), this, SLOT(slotSex()));
	connect(ageButton, SIGNAL(clicked()), this, SLOT(slotAge()));
	connect(statureButton, SIGNAL(clicked()), this, SLOT(slotStature()));
}

void InputDlg::slotName()
{
	bool ok;
	QString name = QInputDialog::getText(	// QInputDialog�ı�׼�ַ�������Ի���
		this,				// ������
		tr("User Name"),	// ����
		tr("Please input new name: "),		// ��ʾ��ǩ��ʾ����
		QLineEdit::Normal,	// ָ��QLineEdit�ؼ�������ģʽ
		nameLabel->text(),	// QLineEdit��Ĭ�ϳ��ֵ�����		
		&ok);				// Ok => true, Cancel => false
	if (ok && !name.isEmpty())
		nameLabel->setText(name);
}

void InputDlg::slotSex()
{
	QStringList list;
	list << tr("male") << tr("female");
	bool ok;
	QString sex = QInputDialog::getItem(this, tr("Sex"),	// ��Ŀѡ��Ի���
		tr("Please select sex: "), 
		list,	// ָ��QComboBox�ؼ�����ʾ�Ŀ�ѡ��Ŀ, Ϊһ��QStringList����
		0,		// ָ���Ի��򵯳�ʱQComboBoxĬ��ѡ�����Ŀ���
		false,	// ָ��QComboBox�ؼ�����ʾ�������Ƿ�ɱ༭
		&ok);
	if (ok)
		sexLabel->setText(sex);
}

void InputDlg::slotAge()
{
	bool ok;
	int age = QInputDialog::getInt(this, tr("UerAge"), 
		tr("Please input age: "), 
		ageLabel->text().toInt(),	// ָ��QSpinBox�ؼ���Ĭ����ʾֵ
		0,		// ָ��QSpinBox�ؼ�����Сֵ
		150,	// ���ֵ
		1,		// ����ֵ
		&ok
		//WindowFlags f = 0		// ָ����׼����Ի���Ĵ����ʶ
		);
	if (ok)
		ageLabel->setText(QString(tr("%1")).arg(age));
}

void InputDlg::slotStature()
{
	bool ok;
	double d = QInputDialog::getDouble(this, tr("Stature"), 
		tr("Please input stature: "), 175.00,/*Ĭ��*/ 0, 230.00/*��Χ*/, 1.5/*����ֵ*/, &ok);
	if (ok)
		statureLabel->setText(QString(tr("%1")).arg(d));
}

#endif