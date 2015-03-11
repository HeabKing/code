#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem	// QTableWidgetItem���Ǵ�QObject��������, �������źźͲ�
{
public:
	Cell();

	QTableWidgetItem * clone() const;
	void setData(int role, const QVariant & value);
	QVariant data(int role) const;
	void setFormula(const QString & formula);
	QString formula() const;
	void setDirty();
private:
	QVariant value() const;
	QVariant evalExpression(const QString & str, int & pos) const;
	QVariant evalTerm(const QString & str, int & pos) const;
	QVariant evalFactor(const QString & str, int & pos) const;

	mutable QVariant cachedValue;	// �ѵ�Ԫ���ֵ����ΪQVariant	֮����ʹ��QVariant����Ϊ��Щ��Ԫ����double��ֵ, ��Щ����QString
	mutable bool cacheIsDirty;		// ��������ֵ�������µ�, cacheIsDirty����Ϊtrue
		// mutable �ױ�� ʹ������ؼ���ʹ�ÿ�����const�������޸���
};

#endif