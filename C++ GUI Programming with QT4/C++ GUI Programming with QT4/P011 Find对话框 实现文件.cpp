#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "P010 FindDialog.h"

FindDialog::FindDialog(QWidget * parent) : QDialog(parent)
{
	label = new QLabel(tr("<font color = blue>Find &what:</font>"));	// tr()���������ǰ����Ƿ�����������Եı��, ��ÿ��QObject�����Լ�������Q_OBJECT��������ж����������������
	lineEdit = new QLineEdit;	// ����Ӧ�ý������ڴ��ݸ����ǵĹ��캯��, ��˵�����������ڲ����ĸ��������������, ��������û�б�Ҫ, ��Ϊ����ϵͳ�������еó���һ�����Ϊ��������ȷ�ĸ�����
	label->setBuddy(lineEdit);	// �����б�������Ϊ��ǩ�Ļ��, ���(buddy)����һ�����ڲ���, �������ڰ��±�ǩ�Ŀ�ݼ�ʱ���ս���, ����, ���û�����ALt + W��ʱ��, ����ͻ��ƶ�������б�����(�ñ�ǩ�Ļ��)��
								// ���û�����õĻ�, ��ôFind &what��ʾ��"&"������

	caseCheckBox = new QCheckBox(tr("Match &case"));	// "&"������ʾ��ݼ�, �����û�����ʹ��Alt + C��ݼ���������, &�����������ƽ���
	backwardCheckBox = new QCheckBox(tr("Search &backword"));

	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);	// ��Find��ť��Ϊ�Ի����Ĭ�ϰ�ť
	findButton->setEnabled(false);	// ����Find��ť, ������һ�����ڲ�����ʱ��, ��ͨ������ʾΪ��ɫ

	closeButton = new QPushButton(tr("Close"));

	// ���û��Ķ�����һ�δ�����������
	// Qt�Ĵ��ڲ���ͨ�������ź�������һ���û������Ѿ�����������һ��״̬�Ѿ��ı���
	// ����źŵĲ������������ӵĲ۵Ĳ�����, ��ô����Ĳ������ᱻ���Ե�
	// �������Ͳ�ƥ��, �źŻ��߲۲�����, �źźͲ۵������а����˲�����, Qt����������������������
	connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));	// ֻҪ�������е��ı������仯, �ͻ����˽�в�enableFindButton(const QString &)
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));	// ���û�����Find��ťʱ, �����findClicked()˽�в�
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));		// ���û�����Closeʱ, �Ի����ر�, close()���Ǵ�QWidget�м̳ж�����, ��������Ĭ����Ϊ���ǰѴ��ڲ������û�����Ұ����������(�����轫��ɾ��);
																		// ����QObject��FindDialog�ĸ�����֮һ, ���Կ���ʡ��connect()����ǰ���QObject::ǰ׺
	QHBoxLayout * topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();	// ���ɷָ���("��չ��"), ������ռ��Find��ť��Close��ť�����µĿհ�����, ��������ȷ����Щ��ť��ȫռ�����������ڲ��ֵ��ϲ��ռ�

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);	// �����Ӳ��ֶ�����ӵ������ֶ�����ʱ, �Ӳ��ֶ�����Զ��ض����Լ��ĸ�����
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);	// �ڴ����ϰ�װ���ֿ�����	������ĵײ�ʵ��������, ��װ�˲��ֵĴ��ڲ������Զ���Ϊ�����ڵĲ����ĸ�����, ���ǻ�������ԭ��, ������һ����Ҫ�Ž�ĳ�������еĴ��ڲ�����ʱ��, ��û�б�ҪΪ����ʾָ����������

	setWindowTitle(tr("Find"));	// ���ñ�������
	setFixedHeight(sizeHint().height());	// �ô��ھ���һ���̶��ĸ߶�, QWidget::sizeHint()�������Է���һ�����ڲ���������ĳߴ�Ĵ�С
}

// �Ի��������õ��Ĳ�
void FindDialog::findClicked()	// ���û�����Find��ť��ʱ��, �ͻ����findClicked()��, �ò۽��ᷢ��findPrevious()����findNext()�ź�;
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
	if (backwardCheckBox->isChecked())
	{
		emit findPrevious(text, cs);	// emit(����)��Qt�еùؼ���, ������Qt��չһ��, ��Ҳ�ᱻC++Ԥ������ת���ɱ�׼��C++����
	}
	else
	{
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString & text)	// ֻҪ�û��ı����б༭���е��ı�, �ͻ����enableFindButton()��, ������б����������ı�, �ò۾ͻ�����Find��ť, �������ͻ����Find��ť
{
	findButton->setEnabled(!text.isEmpty());	// enable	ʹ��, ����		������˵���û���ı�, �Ͳ�����, ���򼤻�Find��ť
}