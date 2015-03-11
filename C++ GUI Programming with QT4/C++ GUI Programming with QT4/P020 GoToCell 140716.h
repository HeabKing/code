#ifndef P020_GOTOCELL_140716_H
#define P020_GOTOCELL_140716_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class GoToCellDialog;

// ����д����ķ�ʽʵ��Qt�������ɵĶԻ������
namespace Ui
{
	class Ui_GoToCell
	{
	public:
		QLabel		* label;
		QLineEdit	* lineEdit;
		QPushButton	* okButton;
		QPushButton * cancelButton;
		QHBoxLayout	* HLayoutUp;
		QHBoxLayout	* HLayoutDown;
		QVBoxLayout * VLayout;

		void setupUi(QWidget * GoToCellDialog)
		{	
			// ˮƽ����: label lineEdit
			label		= new QLabel;
			lineEdit	= new QLineEdit;
			HLayoutUp	= new QHBoxLayout;

			label->setBuddy(lineEdit);

			HLayoutUp->addWidget(label);
			HLayoutUp->addWidget(lineEdit);

			// ˮƽ����: okButton cancelButton
			okButton	= new QPushButton;
			cancelButton= new QPushButton;
			HLayoutDown = new QHBoxLayout;
			
			HLayoutDown->addStretch();
			HLayoutDown->addWidget(okButton);
			HLayoutDown->addWidget(cancelButton);

			// ��ֱ����: HLayoutUp HLayoutDown
			VLayout		= new QVBoxLayout(GoToCellDialog);

			VLayout->addLayout(HLayoutUp);
			VLayout->addLayout(HLayoutDown);

			retranslateUi(GoToCellDialog);
		}

		void retranslateUi(QWidget * GoToCellDialog)
		{
			GoToCellDialog->setWindowTitle("GoToCell");
			label->setText("&CellLocation: ");
			okButton->setText("Ok");
			cancelButton->setText("Calcel");
		}
	};

	class GoToCellDialog : public Ui_GoToCell{};
}

// ʵ����������Ĳ���֮��� �ź� - �� ��ϵ
#include <QDialog>	// �������Qdialog��ǰ��, Ui::GoToCellDialog�ں��
class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
	Q_OBJECT;
public:
	inline GoToCellDialog(QWidget * parent = nullptr);
private slots:
	inline void enableOkButton();
};

#include <QValidator>
GoToCellDialog::GoToCellDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	okButton->setEnabled(false);
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	lineEdit->setValidator(new QRegExpValidator(regExp, this));	// validator ��֤��
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableOkButton()));  // ע��: ����textChanged(const QString &)�еò����������, ��ʹ�ڱ��������Ǳ����Բ��õĲ���
}

void GoToCellDialog::enableOkButton()
{
	okButton->setEnabled(true);
}

#endif