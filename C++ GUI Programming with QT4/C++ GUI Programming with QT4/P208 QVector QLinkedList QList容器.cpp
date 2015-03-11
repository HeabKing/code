#include <QApplication>
#include <QVector>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <vector>
#include <QLinkedList>

class MyWidget : public QWidget
{
private:
	QVector<int>		v;
	std::vector<int>	stdv;
	QLinkedList<QString>linkedList;
public:
	MyWidget(QWidget * parent = nullptr);
protected:
	void paintEvent(QPaintEvent *);
};

int main(int argc, char ** argv)
{
	QApplication App(argc, argv);
	MyWidget M;

	M.show();
	App.exec();
}

MyWidget::MyWidget(QWidget * parent) : QWidget(parent)
{
	v.resize(2);
	//v[0] = 0;		// resize()�ڷ���Ԫ���ڴ��ͬʱ����default���캯����ʼ��
	v.append(2);	// push_back(T);
	v.back() = 2;
	v[1]	 = 1;
	v << 3;

	stdv.resize(3);
	stdv.at(1) = 1;	// QVector������������ֵ
	//stdv << 3;	// ��׼vector��������ô��
	stdv.push_back(3);

	linkedList.append("Clash");
	linkedList.push_back("Ramones");
	QLinkedList<QString>::iterator i = linkedList.begin();
	linkedList.insert(i, "Tote Hosen");
}

void MyWidget::paintEvent(QPaintEvent * e)
{
	QPainter P(this);
	int j = 0;
	// STL���ĵ����� -- ���Խ���㷨
	for (QVector<int>::const_iterator i = v.begin(); i < v.end(); ++i,++j)	// ����������
	{
		P.drawText(20, 20 * j, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(*i));
		P.drawText(50, 20 * j, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(stdv.at(j)));
	}
	j = 0;
	for (QLinkedList<QString>::iterator i = linkedList.begin(); /*j < linkedList.count()*/i != linkedList.end()/*i < linkedList.end()*/; ++i, ++j)
		P.drawText(80, 20 * j, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, *i);
	// java����ֻ�������� -- ����ʹ��
	QLinkedListIterator<QString> i(linkedList);	// java���ĵ�����������ָ����, �����ܹ���λ�ڵ�һ��֮ǰ, ���һ��֮�����������֮��
		// java���ĵ������ڵ�һ��֮ǰ�ͱ���λ��, ��������������һ����, hasNext()����true, next()�������ص������ұߵ���ҽ���������������һ��Чλ��

	while (i.hasNext())
	{
		static int j = 0;
		P.drawText(160, 20 * j++, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, i.next());
	}
	i.toBack();
	while (i.hasPrevious())
	{
		static int j = 0;
		P.drawText(240, 20 * j++, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, i.previous());
	}
	// java���Ķ�д������
	// �Ƴ�v�е�������2
	QMutableVectorIterator<int> i3(v);
	while (i3.hasNext())
	{
		if (i3.next() == 2)	// ������һ��next()�Ժ�, �������Զ�������һλ
			i3.remove();	// �����Ժ���������ɾ������Ϊ2����
	}
	i3.toFront();
	while (i3.hasNext())
	{
		static int j = 0;
		P.drawText(20, 20 * j++ + 130, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(i3.next()));
	}
	// ��v�е�1�ĳ�-1
	i3.toFront();
	while (i3.hasNext())
	{
		if (i3.next() == 1)
			i3.setValue(-1);
	}
	i3.toFront();
	while (i3.hasNext())
	{
		static int j = 0;
		P.drawText(20, 20 * j++ + 260, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(i3.next()));
	}

	// Qt ��ѭ��������ʽ -- foreach ѭ��
	foreach (int i, v)	// foreach α�ؼ��ְ��ձ�׼forѭ��ʵ��, ÿ�ε�����, ��������i��������Ϊһ������, �������еĵ�һ���뿪ʼ����;
		// foreach���ڽ���ѭ��ʱ�Զ�����!һ��!����, ��˼�ʹ�������������޸���������, Ҳ����Ӱ�쵽ѭ��
	{
		static int j = 0;
		P.drawText(20, 20 * j++ + 390, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(i));
	}
}
