//#include <QtGui>
#include "P027 sortdialog.h"
SortDialog::SortDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);	// ��ʼ������

	secondaryGroupBox->hide();	// ���ظ߼�ѡ��
	tertiaryGroupBox->hide();
	layout()->setSizeConstraint(QLayout::SetFixedSize);	// �̶��Ի���Ĵ�С constraint Լ�� fixed �̶���
		// ����һ��, ���־ͻḺ���ض���Ի����С��ְ��, ���һ�����ʾ�������ش��ڲ�����ʱ���Զ��ض�������Ի���Ĵ�С

	SetColumnRange('A', 'Z');	// ����۸��ݵ����Ʊ������ѡ����г�ʼ����Ͽ�����
}

void SortDialog::SetColumnRange(QChar first, QChar last)
{
	primaryColumnCombo->clear();
	secondaryColumnCombo->clear();
	tertiaryColumnCombo->clear();

	secondaryColumnCombo->addItem(tr("None"));
	tertiaryColumnCombo->addItem(tr("None"));
	primaryColumnCombo->setMinimumSize(secondaryColumnCombo->sizeHint());	// sizeHint()�������ز���ϵͳ��ͼ��ͬ��"����"��С

	QChar ch = first;
	while (ch <= last)
	{
		primaryColumnCombo->addItem(QString(ch));
		secondaryColumnCombo->addItem(QString(ch));
		tertiaryColumnCombo->addItem(QString(ch));
		ch = ch.unicode() + 1;
	}
}