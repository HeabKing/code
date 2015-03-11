#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

// ǰ������
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

// ����FindDialog��������ΪQDialog������
class FindDialog : public QDialog
{
	Q_OBJECT;	// !����! ���źźͲ۵��඼д���
public:
	FindDialog(QWidget * parent = nullptr);
signals:
	void findNext(const QString & str, Qt::CaseSensitivity cs);
	void findPrevious(const QString & str, Qt::CaseSensitivity cs);
private slots:
	void findClicked();
	void enableFindButton(const QString & text);
private:
	QLabel		* label;
	QLineEdit	* lineEdit;
	QCheckBox	* caseCheckBox;
	QCheckBox	* backwardCheckBox;
	QPushButton * findButton;
	QPushButton * closeButton;
};

#endif