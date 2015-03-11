// ����: 2014-08-28 14:36:55
// QTableWidget����Ƕ��༭�����ʾ�ؼ�, �����Բ���ؼ�, ��ʾ�ı�
#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include <QTableWidget>
#include <QLabel>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QSpinBox>

class TableWidget: public QTableWidget
{
private:
	QLabel				* LabelPixmap1;
	QTableWidgetItem	* TableWidgetItem1;
	QDateTimeEdit		* DateTimeEdit1;
public:
	TableWidget(QWidget * parent = nullptr);
};

TableWidget::TableWidget(QWidget * parent): QTableWidget(parent)
{
	setWindowTitle("07 The use of QTableWidget");

	// ���ñ���Cell����
	setRowCount(5);
	setColumnCount(5);

	// ��������ͼƬ 
	LabelPixmap1 = new QLabel();
	LabelPixmap1->setPixmap(QPixmap("images/panda.png"));	// ��Label����ͼƬ
	setCellWidget(1, 0, LabelPixmap1);						// ��Label����Cell

	// ���������ı�
	TableWidgetItem1 = new QTableWidgetItem(tr("Tom"));		// ��QTableWidgetItem�����ı�
	setItem(1, 1, TableWidgetItem1);						// ��Item����Cell	// ע��: ������setItem
	
	// ��ӵ��������ؼ�
	DateTimeEdit1 = new QDateTimeEdit();
	DateTimeEdit1->setDateTime(QDateTime::currentDateTime());	// ����Ĭ����ʾ
	DateTimeEdit1->setDisplayFormat("dd/M/yyyy");				// ������ʾ��ʽ
	DateTimeEdit1->setCalendarPopup(true);	// popup ���� calendar ����
	setCellWidget(1, 2, DateTimeEdit1);		// ��ӿؼ�
	
	// ���һ�����ѡ���
	QComboBox * ComboBoxWork1 = new QComboBox();
	ComboBoxWork1->addItem(tr("Worker"));
	ComboBoxWork1->addItem(tr("Farmer"));
	ComboBoxWork1->addItem(tr("Docter"));
	ComboBoxWork1->addItem(tr("Lawyer"));
	ComboBoxWork1->addItem(tr("Soldier"));
	setCellWidget(1, 3, ComboBoxWork1);

	QSpinBox * SpiBoxIncome1 = new QSpinBox();
	SpiBoxIncome1->setRange(1000, 10000);
	setCellWidget(1, 4, SpiBoxIncome1);
}
#endif