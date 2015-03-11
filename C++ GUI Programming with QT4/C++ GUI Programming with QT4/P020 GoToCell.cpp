#include <QtGui>
#include "P020 GoToCell.h"
GoToCellDialog::GoToCellDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);	// ��ʼ������	�������û��ӿ��Ժ�, setupUi()�������Զ�����Щ����on_objectName_signalName()�������������������Ӧ��objectName��signalName()�ź����ӵ�һ��, ������on_lineEdit_textChanged ��

	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");	// ����������һ������������������ķ�Χ: ����һ����д����Сд����ĸ, ��߸���һ����ΧΪ1-9������, ����ٸ�0��1������2��0-9������;
												// Qt�ṩ���������õļ�������: QIntValidator, QDoubleValidator��QRegExpValidator.
	lineEdit->setValidator(new QRegExpValidator(regExp, this));	// ͨ����this���ݸ�QRegExpValidator�Ĺ��캯��, ʹ����ΪGoToCellDialog�����һ���Ӷ���, �����Ժ�Ͳ��õ����й�ɾ��QRegExpValidator��������, ��ɾ�����ĸ�����ʱ, ��Ҳ���Զ�ɾ��
																// Qt�ĸ�-�Ӷ����������QObject��ʵ�ֵ�, ������һ�������󴴽�һ���Ӷ���(һ�����ڲ���, һ�������, �����������������)ʱ, ������������Ӷ�����ӵ��Լ����Ӷ����б���, ��ɾ������������ʱ��, ��������Ӷ����б��һ�ɾ��ÿһ���Ӷ���, Ȼ��, ��Щ�Ӷ�����ȥɾ�������Լ��������Ӷ���  ���Ҷ��ڴ��ڲ���, ������������һ�㺬��: �Ӵ��ڲ�������ʾ�����ĸ���������������, ��ɾ����������󲿼�ʱ, �����Ӷ������ڴ�����ʧ, ������Ҳ������Ļ����ʧ6

	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));		// accept()�رնԻ���, ���Ի��򷵻صĽ����������ΪQDialog::Accepted(��ֵ����1)
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));	// reject()�رնԻ���, ����ֵΪQDialog::Rejected(��ֵΪ0)
}

void GoToCellDialog::on_lineEdit_textChanged()	// ��������������ζ��setUi()�������Ὠ��������ʾ���ź�-�����ӹ�ϵ: connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(on_lineEdit_textChanged()));
{
	okButton->setEnabled(lineEdit->hasAcceptableInput());	// hasAcceptableInput()��ʹ���ڹ��캯�������õļ�������жϱ����������ݵ���Ч��
}