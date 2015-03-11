// 1.	��ʼ����ʱ�����������, ���Ѳ����ӽ�ȥ, �趨�����Ĵ�С����, �趨�������ӵȵ�, �ò����趨paintEvent

#include <QApplication>
#include <QPushButton>
#include <QLayout>

class studyLayout : public QWidget
{
private:
	QHBoxLayout * hLayout;
	QPushButton * okButton;
	QPushButton * cancelButton;
public:
	studyLayout(QWidget * parent = nullptr);
};

int main(int argc, char ** argv)
{
	QApplication App(argc, argv);
	studyLayout * s = new studyLayout;

	s->setGeometry(200, 200, 500, 500);
	s->show();
	s->adjustSize();	// ������ʹ���ϱߵ�setGeometry��λ�ÿ���, ��СʧЧ ���ڴ�С, ����ľ��������һ�����õĴ�С����
	return App.exec();
}

studyLayout::studyLayout(QWidget * parent) : QWidget(parent)
{
	hLayout		= new QHBoxLayout;
	okButton	= new QPushButton(tr("OK"));
	cancelButton= new QPushButton(tr("Cancel"), this);
	okButton->setSizePolicy(QSizePolicy::Maximum, okButton->sizePolicy().verticalPolicy());
	hLayout->addWidget(okButton);
	hLayout->addWidget(cancelButton);
	hLayout->addStretch();
	setLayout(hLayout);
	hLayout->setContentsMargins(20, 50, 20, 50);	// ���ñ߾�, (left, top, right, bottom)
	hLayout->setSpacing(100);	// ���ò���֮��ľ���
}
