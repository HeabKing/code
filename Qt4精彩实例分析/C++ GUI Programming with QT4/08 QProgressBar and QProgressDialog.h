// ����: 2014-09-11 13:26:12
// QProcessBar: minimum, maximum���ֵ��Сֵ, format %p% �ٷֱ�(Ĭ��) %v ��ǰ����ֵ %m �ܵĲ���ֵ invertedAppearance������ʾ
// QProcessDialog: minimum, maximum		minimumDuration�������Ի������ǰ�ĵȴ�ʱ��
#ifndef QH08
#define QH08
#include <QLayout>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>

class Progress: public QDialog
{
	Q_OBJECT
public:
	inline Progress(QWidget * parent = nullptr, Qt::WindowFlags f = 0);
	inline ~Progress(){}
	
	QLabel		* numLabel;
	QLineEdit	* numLineEdit;
	QLabel		* typeLabel;
	QComboBox	* typeComboBox;

	QProgressBar * progressBar;
	QPushButton	 * startPushButton;

private slots:
	//inline void slotStart();	
};

Progress::Progress(QWidget * parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	QFont font("ZYSong18030", 12);
	setFont(font);

	setWindowTitle("08 Process");

	numLabel	= new QLabel(tr("FileNum: "));
	numLineEdit = new QLineEdit;
	numLineEdit->setText(tr("10"));

	QGridLayout * layout = new QGridLayout(this);
	layout->addWidget(numLabel, 0, 0);
	layout->addWidget(numLineEdit, 0, 1);


}
#endif