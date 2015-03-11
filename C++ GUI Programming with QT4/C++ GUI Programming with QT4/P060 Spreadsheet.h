#ifndef P060_SPREADSHEET_H
#define P060_SPREADSHEET_H

#include <QTableWidget>	// QTableWidget��һ�����, ������Ч����ά����, �û��ڿյ�Ԫ����������ı���ʱ��, QTableWidget���Զ�����һ�������洢��Щ�ı���QTableWidgetItem
						// QTableWidget��Ԫ�������, �����ı����ı����뷽ʽ, ���洢��QTableWidgetItem��
						// QTableWidgetItem��ͬ��QTableWidget, ������һ�����ڲ���, ����һ�������������
class Cell;	// ������QTableWidgetItem
class SpreadsheetCompare;

class Spreadsheet : public QTableWidget
{
	Q_OBJECT;

private:
	bool autoRecalc;	// �Ƿ����¼����ʶ��

public:
	Spreadsheet(QWidget * parent = nullptr);

	bool autoRecalculate() const { return autoRecalc; } // �������¼����ʶ����״̬
	QString currentLocation() const;	// ���ص�ǰ��Ԫ��λ��
	QString currentFormula() const;		// ���ص�ǰ��Ԫ��ʽ
	QTableWidgetSelectionRange selectedRange() const;
	void clear();
	bool readFile(const QString & fileName);
	bool writeFile(const QString & fileName);
	void sort(const SpreadsheetCompare & compare);

public slots:
	void cut(){};
	void copy(){};
	void paste(){};
	void del(){};
	void selectCurrentRow(){};
	void selectCurrentColumn(){};
	void recalculate(){};
	void setAutoRecalculate(bool recalc){};
	void findNext(const QString & str, Qt::CaseSensitivity cs){};

signals:
	void modified();	// ���û��ڵ�Ԫ��д�붫����ʱ��ͻᷢ������ź�
private slots:
	void somethingChanged();	// �û��ڵ�Ԫ��д�붫��, Spreadsheet����QTableWidget::itemChanged(QTableWidgetItem *), Ȼ��Spreadsheet::somethingChanged()���յ�
								// somethingChanged()��autoRecalc == true��ʱ���Զ����㹫ʽ��ֵ, Ȼ����Spreadsheet::modified()��

private:
	enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };

	Cell * cell(int row, int  column) const;
	QString text(int row, int column) const;	// ���ظ�����Ԫ���е��ı�
	QString formula(int row, int column) const;	// formula ��ʽ
	void setFormula(int row, int column, const QString & formula);
};

#endif