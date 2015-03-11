#include <QPushButton>
#include "P020  GoToCell.h"
GoToCellDialog::GoToCellDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	lineEdit->setValidator(new QRegExpValidator(regExp, this));	// validator ��֤��
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(reject()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}