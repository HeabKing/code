#include <QApplication>
#include <QPainter>
#include <QString>
#include <QWidget>
#include <QPaintEvent>

class MyWidget : public QWidget
{
private:
	QString str;
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
	
}

void MyWidget::paintEvent(QPaintEvent *)
{
	QPainter P(this);
	str.append("0");// β�����һ��"0"
	str.append(1);	// ����ʲôЧ����û��
	str.append("1");
	str.setNum(2);	// ��ԭ�������ж�������
	str += "3";

	str.sprintf("%s%d%ld", "4", 5, 6);	// ��C++��sprintf������ͬ�ĸ�ʽ˵����
	str += QString("%1%3%5").arg(7).arg("8").arg('9');	// arg()�����غ������Դ��������������
		// ��Ƚ�sprintf, argͨ����һ�����õĽ������, ��Ϊ�������Ͱ�ȫ��, ��ȫ֧��Unicode����, ����������������%n����������������

	str += QString::number(10);	// ͨ��ʹ��QString::number()��̬����, ������ת��Ϊ�ַ���
	
	bool isTo;	// ���ַ���ת��������
	int n = str.toInt(&isTo);
	if (isTo)
		P.drawText(200, 20, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(n));
	str += "pp";
	n = str.toInt(&isTo);
	if (!isTo)	// ת��ʧ��, nֵ��Ϊ0
		P.drawText(200, 40, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, QString::number(n));

	P.drawText(20, 20, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	for (QString::const_iterator i = str.begin(); i != str.end(); ++i)
	{
		static int j = 0;
		P.drawText(300, 20 * ++j, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, *i);
	}
		
		// ��ȡ�ַ����ض�λ�õ��Ӵ�

	str += str.mid(0, 2);	// mid(int1, int2)  ��������int1�ǿ�ʼλ��, int2���Ӵ��ĳ���
	P.drawText(20, 40, 100, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	str += str.mid(0);		// ���ʡ�Եڶ�������, mid()���������ڸ���λ�ÿ�ʼ���ַ���ĩ�˽������Ӵ�
	P.drawText(20, 60, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	
	P.drawText(40, 80, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str.left(2) + str.right(4));	// left(n) ����Ǯn���ַ���Ϊ�Ӵ�, right(n) �������n���ַ���Ϊ�Ӵ�

		// �����Ӵ�

	int index = str.indexOf("pp");	// ���س���"pp"��λ��
	if (index != -1)				// ���"pp"������, ����-1
		P.drawText(40, 100, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str.mid(index));
	int index2 = str.indexOf("pp", index + 2);	// �ڶ������������˿�ʼ���ҵ�λ��
	P.drawText(40, 120, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str.mid(index2));
	// startsWith() endsWith() ����ַ����Ƿ���ĳ���ַ�����ʼ���߽���

		// �ַ����滻

	str.replace(1, 3, "k");	// ������1�ǿ�ʼ��λ��, 3��һ��Ҫ�滻��Ԫ�ظ���
	P.drawText(20, 140, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	// ��str�����е�"pp"�滻��"hhh"
	str.replace("pp", "hhh");
	P.drawText(20, 160, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	// ɾ��λ��2��ʼ�ĳ���Ϊ3���ַ���
	str.remove(2, 3);
	P.drawText(20, 180, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	// �ڵ�һ��0ǰ�����fc
	str.insert(2, "fc");
	P.drawText(20, 200, 200, 20, Qt::AlignLeft | Qt::AlignVCenter, str);
	// ɾ�����ߵĿո�(eg: �ո��, �Ʊ��, ���з�...)str.trimmed();
	// �������Ŀո�ĳ�һ���ո��str.simpliefied()
	// QString::split()��һ���ַ����ֳ�QStringList�Ӵ�
		// QString str = "da xiong ge ge";
		// QStrngList words = str.split(" ");

	// ��QStringת��Ϊconst char *
		// str.toAscii()����str.toLatin1()����, ���Ƿ���QByteArray, ����QBateArray::data()��QByteArray::constData(), ��QByteArrayת����const char *
		// eg: printf("User: %s\n", str.toAscill().data());
		// ����ʹ�ú�qPrintableִ����toAscii().constData()��ͬ�Ĺ���
	// QByteArray������ʽ����QString�е���ͬ, �����ڴ洢ԭʼ�Ķ����������Լ�8λ������ı��ַ����ǳ����� , Ϊ�˷���, QByteArray�Զ���֤"���һ����֮�����"��Ϊ"\0"
}