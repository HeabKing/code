#include <QWidget>
#include <QEvent>
#include <QPainter>
#include <QApplication>

class Ticker : public QWidget
{
private:
	QString text;
	int		timeId;
	int		offset;
public:
	Ticker(QWidget * parent = nullptr);
	
	QString getText() { return text; }
	void	setText(const QString & t) { text = t; }
protected:
	void paintEvent(QPaintEvent *);
	void timerEvent(QTimerEvent *);	// �ж�ʱ����ʱ���˻�����������(��ʱ���¼�)
	void showEvent(QShowEvent *) { timeId = startTimer(50); }
	void hideEvent(QHideEvent *) { killTimer(timeId); timeId = 0; }
		// �������ڹ��캯����startTimer(), ����ֻ�д��ڲ���ʵ�ʿɼ���ʱ��, ���б�Ҫ����Qt�����Ķ�ʱ���¼�����Щ��Դ
};

int main(int argc, char ** argv)
{
	QApplication App(argc, argv);
	Ticker * T = new Ticker;

	T->show();
	return App.exec();
}

Ticker::Ticker(QWidget * parent) : QWidget(parent)
{
	offset = 0;
	timeId = 0;
}

void Ticker::paintEvent(QPaintEvent *)
{
	QPainter painter(this);	// this���´�ʱ���豸������ϢҲ�����˽�ȥ

	painter.drawText(20, 20, 50, 50, Qt::AlignLeft | Qt::AlignVCenter, getText());
}

void Ticker::timerEvent(QTimerEvent * e)
{
	if (e->timerId() == timeId)
	{
		setText(QString::number(offset++));
		update();	// ʹ�ÿͻ�����Ч, ����WM_PAINT��Ϣ
	}
	else
		QWidget::timerEvent(e);
}