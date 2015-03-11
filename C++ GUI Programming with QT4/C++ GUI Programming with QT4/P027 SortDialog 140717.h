#ifndef P027_SORTDIALOG_140717_H
#define P027_SORTDIALOG_140717_H

#include <QDialog>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class Ui_SortDialog
{
public:
	// �ܲ���
	QGridLayout * mainGridLayout;	// ���ֻ��Զ������������Ĵ�С���ǲ��������Զ������������Ĵ�С

	// ��һ��Ⱥ��
	QGroupBox	* primaryGroupBox;
	QLabel		* primaryColumnLabel;
	QLabel		* primaryOrderLabel;
	QComboBox	* primaryColumnComboBox;
	QComboBox	* primaryOrderComboBox;
	QGridLayout * primaryGridLayout;
	QSpacerItem * primaryHSpacer;
	// �Ҳఴť
	QPushButton	* okButton;
	QPushButton * cancelButton;
	QPushButton * moreButton;
	QVBoxLayout * VLayout;
	QSpacerItem * VSpacer;
	// һ����֮�����չ��
	QSpacerItem * mainVSpacer;
	// �ڶ���Ⱥ��
	QGroupBox	* secondaryGroupBox;
	QLabel		* secondaryColumnLabel;
	QLabel		* secondaryOrderLabel;
	QComboBox	* secondaryColumnComboBox;
	QComboBox	* secondaryOrderComboBox;
	QGridLayout * secondaryGridLayout;
	QSpacerItem * secondaryHSpacer;

	void setupUi(QDialog * SortDialog)
	{
		mainGridLayout = new QGridLayout(SortDialog);
		//SortDialog->layout()->setSizeConstraint(QLayout::SetFixedSize);
		mainGridLayout->setSizeConstraint(QLayout::SetFixedSize);
		// �̶��Ի���Ĵ�С constraint Լ�� fixed �̶���
		// ����һ��, ���־ͻḺ���ض���Ի����С��ְ��, ���һ�����ʾ�������ش��ڲ�����ʱ���Զ��ض�������Ի���Ĵ�С
		// ��Ҫ������: ���û������Ļ�, �������˵ڶ�Ⱥ���Ժ�, �����ڲ����Զ���С

				// ������һ��Ⱥ��
		
		// ��������
		primaryGroupBox		= new QGroupBox;
		primaryColumnLabel	= new QLabel;
		primaryOrderLabel	= new QLabel;
		primaryColumnComboBox	= new QComboBox;
		primaryOrderComboBox	= new QComboBox;
		primaryGridLayout		= new QGridLayout(primaryGroupBox);
		primaryHSpacer			= new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

		mainGridLayout->addWidget(primaryGroupBox, 0, 0, 1, 1);

		// Grid���ֹ���
		primaryGridLayout->addWidget(primaryColumnLabel, 0, 0, 1, 1);
		primaryGridLayout->addWidget(primaryColumnComboBox, 0, 1, 1, 1);
		primaryGridLayout->addItem(primaryHSpacer, 0, 2, 1, 1);
		primaryGridLayout->addWidget(primaryOrderLabel, 1, 0, 1, 1);
		primaryGridLayout->addWidget(primaryOrderComboBox, 1, 1, 1, 2);		

				// �����Ҳఴť

		// ��������
		okButton		= new QPushButton;
		cancelButton	= new QPushButton;
		moreButton		= new QPushButton;
		VLayout			= new QVBoxLayout;
		VSpacer			= new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

		moreButton->setCheckable(true);	// ��More���ó�һ�����ذ�ť

		// VLayout���ֹ���
		VLayout->addWidget(okButton);
		VLayout->addWidget(cancelButton);
		VLayout->addItem(VSpacer);
		VLayout->addWidget(moreButton);

		mainGridLayout->addLayout(VLayout, 0, 1, 2, 1);

				// ������һ�ڶ�Ⱥ��֮�����չ��

		mainVSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);	// ������С, ������չ
		mainGridLayout->addItem(mainVSpacer, 1, 0, 1, 1);

				// �����ڶ���Ⱥ��
		
		// ��������
		secondaryGroupBox		= new QGroupBox;
		secondaryColumnLabel	= new QLabel;
		secondaryOrderLabel		= new QLabel;
		secondaryColumnComboBox	= new QComboBox;
		secondaryOrderComboBox	= new QComboBox;
		secondaryGridLayout		= new QGridLayout(secondaryGroupBox);
		secondaryHSpacer		= new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

		secondaryGroupBox->setVisible(false);	// ���صڶ���Ⱥ��

		mainGridLayout->addWidget(secondaryGroupBox, 2, 0, 1, 1);

		// Grid���ֹ���
		secondaryGridLayout->addWidget(secondaryColumnLabel, 0, 0, 1, 1);
		secondaryGridLayout->addWidget(secondaryColumnComboBox, 0, 1, 1, 1);
		secondaryGridLayout->addItem(secondaryHSpacer, 0, 2, 1, 1);
		secondaryGridLayout->addWidget(secondaryOrderLabel, 1, 0, 1, 1);
		secondaryGridLayout->addWidget(secondaryOrderComboBox, 1, 1, 1, 2);		

		retranslateUi(SortDialog);

		QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
		QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
		QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
	}

	void retranslateUi(QDialog * SortDialog)
	{
		SortDialog->setWindowTitle("Sort");
		// ��һȺ��
		primaryGroupBox		->setTitle("&Primary Key");
		primaryColumnLabel	->setText("Column: ");
		primaryOrderLabel	->setText("Order: ");

		primaryColumnComboBox->clear();	// �Ƴ�������Ŀ
		primaryColumnComboBox->addItem("None");
		primaryOrderComboBox->clear();
		primaryOrderComboBox->addItem("Ascending");
		primaryOrderComboBox->addItem("Descending");
		// �Ҳఴť
		okButton	->setText("Ok");
		cancelButton->setText("Cancel");
		moreButton	->setText("More");
		// �ڶ�Ⱥ��
		secondaryGroupBox	->setTitle("&Secondary Key");
		secondaryColumnLabel->setText("Column: ");
		secondaryOrderLabel	->setText("Order: ");

		secondaryColumnComboBox->clear();
		for (QChar i = 'A'; i <= 'F'; i.unicode()++)
			secondaryColumnComboBox->addItem(i);
		secondaryOrderComboBox->clear();
		for (QChar i = 'F'; i >= 'A'; i.unicode()--)
			secondaryOrderComboBox->addItem(i);
	}
};

#endif