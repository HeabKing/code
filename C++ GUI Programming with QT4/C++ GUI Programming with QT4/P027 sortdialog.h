// ���������ݴ���һ��sortdialog.h�ļ�
#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>  
#include "ui_P027 sortdialog.h"
//#include "GeneratedFiles/ui_P027 sortdialog.h"
class SortDialog : public QDialog, public Ui::SortDialog
{
	Q_OBJECT;
public:
	SortDialog(QWidget * parent = nullptr);
	void SetColumnRange(QChar first, QChar last);
};

#endif