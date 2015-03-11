// �Զ��崰�ڲ���
#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H

#include <QSpinBox>

class QRegExpValidator;

class HexSpinBox : public QSpinBox
{
	Q_OBJECT;
public:
	HexSpinBox(QWidget * parent = nullptr);

protected:	// ����ʵ��QSpinBox�е������麯��
	inline QValidator::State validate(QString & text, int & pos) const;	// state �涨 ���� ����
	inline int valueFromText(const QString & text) const;
	inline QString textFromValue(int value) const;

private:
	QRegExpValidator * validator;
};

HexSpinBox::HexSpinBox(QWidget * parent) : QSpinBox(parent)
{
	setRange(0, 255);	// 0x00 - 0xff	// ����΢����ķ�ΧΪ 0 - 255
	validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);	// ����һ��������, ���ø�����Ϊthis
}

QValidator::State HexSpinBox::validate(QString & text, int & pos) const
{
	return validator->validate(text, pos);
}
	// �˺�����QSpinBox����	���: 1. Invalid(��Ч) 2. Intermediate(������Ч) 3. Acceptable(�ɽ���)

QString HexSpinBox::textFromValue(int value) const
{
	return QString::number(value, 16).toUpper();	// ��һ������ת����һ���ַ���
		// 16 ��ζ�Ű�����ת����Сд��ʽ��ʮ�������ַ���
}

int HexSpinBox::valueFromText(const QString & text) const
{
	bool ok;
	return text.toInt(&ok, 16);	// ���ַ���ת��������ֵ
		// ���û��ڱ�������������һ��ֵ���Ұ���Enterʱ, QSpinBox�ͻ������
		// ���������Ч��ʮ��������, �Ͱ�ok���ó�false, ������toInt()����һ��0, �����м�����, ��������϶���Ч
}

#endif