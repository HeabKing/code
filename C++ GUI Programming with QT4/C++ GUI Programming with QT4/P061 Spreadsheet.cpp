#include "P073 Cell.h"
#include "P060 Spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget * parent) : QTableWidget(parent)
{
	autoRecalc = true;
	setItemPrototype(new Cell);	// ͨ�������, �û��ڵ�Ԫ������һЩ�ı���ʱ��, QTableWidget�����Զ�����һ��QTableWidgetItem��������Щ�ļ�, ��������Cell�����QTableWidgetItem, �����ͨ���ڹ��캯���е���setItemPrototype()�����, ʵ����QTableWidget����ÿ����Ҫ�����ʱ��Ѵ��ݵ�����ԭ�͵���ʽ��¡����
	setSelectionMode(ContiguousSelection);	// ����򵥾���ѡ��򷽷�
	
	connect(this, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(somethingChanged()));
					// itemChanged��QTableWidget�е��ź�

	clear();	// ���µ������ĳߴ��С���������б���
}

void Spreadsheet::clear()
{
	setRowCount(0);
	setColumnCount(0);
	setRowCount(RowCount);
	setColumnCount(ColumnCount);

	for (int i = 0; i < ColumnCount; ++i)
	{
		QTableWidgetItem * item = new QTableWidgetItem;
		item->setText(QString(QChar('A' + i)));
		setHorizontalHeaderItem(i, item);
	}
	setCurrentCell(0, 0);
}

Cell * Spreadsheet::cell(int row, int column) const	// ����ָ�����к��з���һ��Cell���� ��������QTableWidget::item()����һ��, ֻ����������һ��Cellָ�������һ��QTableWidgetItemָ��
{
	return static_cast<Cell *>(item(row, column));
}

QString Spreadsheet::text(int row, int column) const	// ���ظ�����Ԫ���е��ı�
{
	Cell * c = cell(row, column);
	if (c)
		return c->text();
	else
		return "";
}

QString Spreadsheet::formula(int row, int column) const
{
	Cell * c = cell(row, column);
	if (c)
		return c->formula();
	else
		return "";
}

void Spreadsheet::setFormula(int row, int column, const QString & formula)	// �������ڸ�����Ԫ��Ĺ�ʽ
{
	Cell * c = cell(row, column);
	if (!c)	// ����õ�Ԫ���Ѿ�����һ��Cell����, ��ôֱ��ʹ����, ���򴴽�һ���µ�Cell�����ҵ���QTableWidget::setItem()�������뵽����
	{
		c = new Cell;
		setItem(row, column, c);
	}
	c->setFormula(formula);	// ���õ�Ԫ���Լ���setFormula()����
}

QString Spreadsheet::currentLocation() const	// ���ص�ǰ��Ԫ���λ��
{
	return QChar('A' + currentColumn()) + QString::number(currentRow() + 1);
}

QString Spreadsheet::currentFormula() const	// ���ص�ǰ��Ԫ��ʽ
{
	return formula(currentRow(), currentColumn());
}

void Spreadsheet::somethingChanged()
{
	if (autoRecalc)	// ���������"Auto-Recalculate"(�Զ����¼���), ��ôsomethingChanged()˽�в۾ͻ����¼������������Ʊ����
		recalculate();
	emit modified();
}

#include <QFile>
#include <QMessageBox>
#include <QApplication>
bool Spreadsheet::writeFile(const QString & fileName)
{
	QFile file(fileName);	// ʹ�ø������ļ�������һ��QFile����
	if (!file.open(QIODevice::WriteOnly))	// ʹ��open()���������������ļ�
	{
		QMessageBox::warning(this, tr("Spreadsheet"), 
			tr("Cannot write file %1:\n%2")
			.arg(file.fileName()
			.arg(file.errorString())));
		return false;
	}
	QDataStream out(&file);	// ����һ��QDataStream����, ��������file����ʹ�øö����������	
							// QDataStream�ȿ���֧��C++��������, Ҳ����֧�ֶ���Qt����, ���﷨ģ���˱�׼C++��<iostream>�е��﷨
	out.setVersion(QDataStream::Qt_4_3);	// ʹ�õ��ǵھŰ�����Ʊ�ʾ����

	out << quint32(MagicNumber);	// ��ΪC++�Ļ��������ڲ�ͬƽ̨�Ͽ��ܻ��в�ͬ��С, �������Щ����ǿ��ת�����˹̶���С
		// SpreadsheetӦ�ó�����ļ���ʽ��һ��32λ����(MagicNumber, 0x7F51c883����һ�����ֵ)��Ϊ�ļ��Ŀ�ʼ, ����ȷ���ļ��ĸ�ʽ
		// Ȼ�������������ݿ�, ÿһ�����ݿ鶼����������һ����Ԫ���е���, �к͹�ʽ
		// ��Щ���ݵ�ȷ�ж����Ʊ�ʾ������QDataStream����

	QApplication::setOverrideCursor(Qt::WaitCursor);	// �������֮ǰ, ��Ӧ�ó���Ĺ��ĳɵȴ����
	for (int row = 0; row <RowCount; ++row)
	{
		for (int column = 0; column < ColumnCount; ++column)
		{
			QString str = formula(row, column);
			if (!str.isEmpty())
			{
				out << quint16(row) << quint16(column) << str;
			}
		}
	}
	QApplication::restoreOverrideCursor();	// ��������������, �ָ���ͨ���
	return true;	// �������, �ļ���QFile��������������Զ��ر�
}

bool Spreadsheet::readFile(const QString & fileName)
{
	QFile file(fileName);	// ��ȡһ���ļ�
	if (!file.open(QIODevice::ReadOnly))	// ֻ�����ļ�
	{
		QMessageBox::warning(this, tr("Spreadsheet"),
			tr("Cannot read file %1:\n%2.")
			.arg(file.fileName())
			.arg(file.errorString()));
		return false;
	}
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_4_3);

	quint32 magic;
	in >> magic;
	if (magic != MagicNumber)
	{
		QMessageBox::warning(this, tr("Spreadsheet"),
			tr("The file is not a Spreadsheet file."));
		return false;
	}
	clear();

	quint16 row;
	quint16 column;
	QString str;

	QApplication::setOverrideCursor(Qt::WaitCursor);
	while (!in.atEnd())
	{
		in >> row >> column >> str;
		setFormula(row, column, str);
	}
	QApplication::restoreOverrideCursor();
	return true;
}