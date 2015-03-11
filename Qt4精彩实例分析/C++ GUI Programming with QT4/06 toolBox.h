// ����: 2014-08-27 13:24:55

#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QToolBox>		// �ṩһ����״�Ĳ������, ����ͨ��QToolBoxʵ��һ�ֳ���Ч��
#include <QToolButton>	// �ṩһ�ֿ��ٷ��������ѡ����İ�ť, ͨ���ڹ�����ʹ��
#include <QGroupBox>
#include <QLayout>
class Drawer: public QToolBox
{
	Q_OBJECT
public:
	inline Drawer(QWidget * parent = nullptr, Qt::WindowFlags f = 0);
	inline ~Drawer(){}

	QToolButton * toolButton1_1;
	QToolButton * toolButton1_2;
	QToolButton * toolButton1_3;
	QToolButton * toolButton1_4;
	QToolButton * toolButton1_5;
	QToolButton * toolButton2_1;
	QToolButton * toolButton2_2;
	QToolButton * toolButton3_1;
	QToolButton * toolButton3_2;

private:
	inline void newButton(QToolButton * &);
};

Drawer::Drawer(QWidget * parent, Qt::WindowFlags f): QToolBox(parent, f)
{
	setWindowTitle(tr("My QQ"));

	QGroupBox * groupBox1 = new QGroupBox;	// ��Ӧÿ������
	newButton(toolButton1_1);				// ��Ӧ�����ڵ�ÿ����ť
	newButton(toolButton1_2);
	newButton(toolButton1_3);
	newButton(toolButton1_4);
	newButton(toolButton1_5);

	QVBoxLayout * layout1 = new QVBoxLayout(groupBox1);
	layout1->setMargin(10);
	layout1->setAlignment(Qt::AlignHCenter);
	layout1->addWidget(toolButton1_1);
	layout1->addWidget(toolButton1_2);
	layout1->addWidget(toolButton1_3);
	layout1->addWidget(toolButton1_4);
	layout1->addWidget(toolButton1_5);
	layout1->addStretch();

	QGroupBox * groupBox2 = new QGroupBox;
	newButton(toolButton2_1);
	newButton(toolButton2_2);
	
	QVBoxLayout * layout2 = new QVBoxLayout(groupBox2);
	layout2->setMargin(10);						// �������ʾ���
	layout2->setAlignment(Qt::AlignHCenter);	// �������ʾλ��
	layout2->addWidget(toolButton2_1);
	layout2->addWidget(toolButton2_2);
	layout2->addStretch();	// ����ռλ��, ʹ�����а�ť�ܿ��϶���, �������������С�仯ʱ, ��ť�������仯

	this->addItem((QWidget *)groupBox1, tr("my friends"));
	this->addItem((QWidget *)groupBox2, tr("my classmates"));
}

inline void Drawer::newButton(QToolButton * & tb)
{
	tb = new QToolButton;
	tb->setText(tr("panda"));					// �����ڰ�ť������
	tb->setIcon(QPixmap("images/panda.png"));	// ͼ��
	tb->setIconSize(QSize(100, 100));			// ��С
	tb->setAutoRaise(true);						// ������뿪ʱ, ��ť�Զ��ָ��ɵ���״̬
	tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
						// Qt::ToolButtonIconOnly: ֻ��ʾͼ��
						// Qt::ToolButtonTextOnly: ֻ��ʾ����
						// Qt::ToolButtonTextBesideIcon: ������ʾ��ͼ���Ա�
						// Qt::ToolButtonTextUnderIcon:  ������ʾ��ͼ������
}
#endif