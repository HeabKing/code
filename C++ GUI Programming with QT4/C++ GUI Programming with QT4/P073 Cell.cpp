#include "P073 Cell.h"
Cell::Cell()
{
	setDirty();	// ����������Ϊdirty
		// ����û�б�Ҫ���ݸ�����, ��ΪsetItem()�ѵ�Ԫ����뵽һ��QTableWidget�е�ʱ��, QTableWidget�����Զ�����ӵ������Ȩ
}

QTableWidgetItem * Cell::clone() const	// ��QTableWidget��Ҫ����һ���µĵ�Ԫ���ʱ��, ����, ���û���һ����ǰû��ʹ�ù��Ŀհ׵�Ԫ���п�ʼ��������ʱ, ���ͻ����clone()���� ���ݸ�QTableWidget::setItemPrototype()�е�ʵ��������Ҫ��¡����, ���Ƕ���Cell����, ��Ա���ĸ����Ѿ�����������Ҫ, ��������ֻ��Ҫ����C++�Զ�������Ĭ�ϸ��ƹ��캯���Ϳ��Դ����µ�Cellʵ����
{
	return new Cell(*this);
}

void Cell::setFormula(const QString & formula)	// ���õ�Ԫ���еĹ�ʽ
{
	setData(Qt::EditRole, formula);	// Qt::EditRole �༭��ɫ������Щ��Ҫ�༭��������, Qt::DisplayRole ��ʾ����������Щ��Ҫ��ʾ�������� ͨ����������ߵ����ݶ���һ����, ������Cell����, �༭��ɫ��Ӧ�ڵ�Ԫ��Ĺ�ʽ, ��ʾ��ɫ��Ӧ�ڵ�Ԫ���ֵ(�Թ�ʽ��ֵ��Ľ��);
}

QString Cell::formula() const	// ���»�ø����EditRole����
{
	return data(Qt::EditRole).toString();
}

void Cell::setData(int role, const QVariant & value)	// ������µĹ�ʽ, �Ϳ��԰�cacheIsDirty����Ϊtrue, ��ȷ������һ�ε���text()��ʱ��������¼���õ�Ԫ�� ���ܶ�Cellʵ���е�Spreadsheet::text()������text(), ������Cell��û�ж���text()����, ���text()������һ����QTableWidgetItem�ṩ�ļ�㺯���൱�ڵ���data(Qt::DisplayRole).toString()
{
	QTableWidgetItem::setData(role, value);
	if (role == Qt::EditRole)
		setDirty();
}

void Cell::setDirty()	// �Ե�Ԫ���ֵǿ�ƽ������¼���
{
	cacheIsDirty = true;	// �򵥵İ�cacheIsDirty����Ϊtrue, �����ζ��cachedValue����������ֵ, �����б�Ҫ, ���򲻻�ִ�����¼������
}

QVariant Cell::data(int role) const
{
	if (role == Qt::DisplayRole)	// ʹ��Qt::DisplayRole�����������, ���ص����Ʊ������Ӧ����ʾ���ı�
	{		// Cell::value()����һ��QVariantֵ, QVariant���Դ洢��ͬ���͵�ֵ, ����double��QString, �����ṩ��һЩ�ɱ���ת��Ϊ�������ͱ�����һЩ���� �����һ��������doubleֵ�ñ�������toString()���Բ���һ����ʾ���doubleֵ���ַ��� ʹ��Ĭ�Ϲ��캯��������QVariant��һ��"��Ч"����
		if (value().isValid())	// ʹ��value()���㵥Ԫ���ֵ, ���ֵ����Ч�ķ���"####"
			return value().toString();
		else
			return "####";
	} else if (role == Qt::TextAlignmentRole)	// ���ʹ��Qt::TextAlignmentRole�����������, ����һ�����ʵĶ��뷽ʽ
	{
		if (value().type() == QVariant::String)
			return int(Qt::AlignLeft | Qt::AlignVCenter);
		else
			return int(Qt::AlignRight | Qt::AlignVCenter);
	}
	else	// ���ʹ��Qt::EditRole�����������, ���ص�Ԫ���еĹ�ʽ
		return QTableWidgetItem::data(role);
}

const QVariant Invalid;
QVariant Cell::value() const	// ���ص�Ԫ���ֵ, ���cacheIsDirty��true, ����Ҫ���¼������ֵ
{
	if (cacheIsDirty)
	{
		cacheIsDirty = false;

		QString formulaStr = formula();
		if (formulaStr.startsWith('\''))	// �ɵ����ſ�ʼ�Ĺ�ʽ��ô������ռ��λ��0, ֵ�Ǵ�λ��1ֱ����� λ�õ�һ���ַ���
			cachedValue = formulaStr.mid(1);
		else if (formulaStr.startsWith('='))// ��ʽ�ɵȺſ�ʼ, ��ô��ʹ�ô�λ��1��ʼ���ַ���, ���ҽ������ܰ���������ո�ȫ���Ƴ�
		{
			cachedValue = Invalid;
			QString expr = formulaStr.mid(1);
			expr.replace(" ", "");
			expr.append(QChar::Null);

			int pos = 0;
			cachedValue = evalExpression(expr, pos);	// ������ʽ��ֵ	pos�����ô���, ����˵����Ҫ�����￪ʼ�����ַ���λ��
			if (expr[pos] != QChar::Null)	// ����evalExpression()֮��, ������ʽ �����ɹ�, ��ô��λ��pos�����ַ�Ӧ����QChar::Null�ַ�
				cachedValue = Invalid;	// ����ʧ��������
		} else
		{
			bool ok;
			double d = formulaStr.toDouble(&ok);	// �����ʽ�����е����Ż��ߵȺſ�ʼ��, ʹ��toDouble()���Ű���ת��Ϊ������
			if (ok)	// ת������, cachedValue���óɽ������
				cachedValue = d;
			else	// ת��������, ��cachedValue����Ϊ�ַ�����ʽ ����, ��ʽ"1.50"�ᵼ��toDouble()��ok���ó�true, ����1.5, ��ʽ"Wold"����okΪfalse, ����0.0
				cachedValue = formulaStr;
		}
	}
	return cachedValue;
}

QVariant Cell::evalExpression(const QString & str, int & pos) const
{
	QVariant result = evalTerm(str, pos);
	while (str[pos] != QChar::Null)
	{
		QChar op = str[pos];
		if (op != '+' && op != '-')
			return result;
		++pos;
		
		QVariant term = evalTerm(str, pos);
		if (result.type() == QVariant::Double && term.type() == QVariant::Double)
		{
			if (op == '+')
				result = result.toDouble() + term.toDouble();
			else
				result = result.toDouble() - term.toDouble();
		} else
			result = Invalid;
	}
	return result;
}

QVariant Cell::evalTerm(const QString & str, int & pos) const
{
	QVariant result = evalFactor(str, pos);
	while (str[pos] != QChar::Null)
	{
		QChar op = str[pos];
		if (op != '*' && op != '/')
			return result;
		++pos;

		QVariant factor = evalFactor(str, pos);
		if (result.type() == QVariant::Double && factor.type() == QVariant::Double)
		{
			if (op == '*')
				result = result.toDouble() * factor.toDouble();
			else
			{
				if (factor.toDouble() == 0.0)
					result = Invalid;
				else
					result = result.toDouble() / factor.toDouble();
			}
		} 
		else
		{
			result = Invalid;
		}
	}
	return result;
}

QVariant Cell::evalFactor(const QString & str, int & pos) const
{
	QVariant result;
	bool negative = false;

	if (str[pos] == '-')
	{
		negative = true;
		++pos;
	}
	if (str[pos] == '(')
	{
		++pos;
		result = evalExpression(str, pos);
		if (str[pos] != ')')
			result = Invalid;
		++pos;
	}
	else
	{
		QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
		QString token;

		while (str[pos].isLetterOrNumber() || str[pos] == '.')
		{
			token += str[pos];
			++pos;
		}
		if (regExp.exactMatch(token))
		{
			int column = token[0].toUpper().unicode() - 'A';
			int row = token.mid(1).toInt() - 1;

			Cell * c = static_cast<Cell *>(tableWidget()->item(row, column));
			if (c)
				result = c->value();
			else
				result = 0.0;
		}
		else
		{
			bool ok;
			result = token.toDouble(&ok);
			if (!ok)
				result = Invalid;
		}
	}
	if (negative)
	{
		if (result.type() == QVariant::Double)
			result = -result.toDouble();
		else
			result = Invalid;
	}
	return result;
}