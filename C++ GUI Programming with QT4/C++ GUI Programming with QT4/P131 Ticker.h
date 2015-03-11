// ��ʱ���¼���һ�ֵͼ��¼�, ���������Ҫ�����ʱ��, ���ֶ����ж�ʱ���ĸ��ٽ����ú��鷳, ���������, ͨ����Ϊ�򵥵ķ�ʽ��Ϊÿһ����ʱ���ֱ𴴽�һ��QTimer����, QTimer����ÿһ��ʱ��������timerout()�ź�, QTimerҲ�ṩ��һ���ǳ�����Ľӿ�, �����ڵ�������ʱ��(ֻ����һ�εĶ�ʱ��), ���������(P122)�п���������
#ifndef TICKER_H
#define TICKER_H

#include <QWidget>
#include <QPainter>
#include <QEvent>

class Ticker : public QWidget
{
	Q_OBJECT;
	//Q_PROPERTY(QString text READ text WRITE setText);

public:
	inline Ticker(QWidget * parent = nullptr);
	
	inline void setText(const QString & newText);
	inline QString text() const { return myText; }
	inline QSize sizeHint() const;

protected:
	inline void paintEvent(QPaintEvent * e);
	inline void timerEvent(QTimerEvent * e);
	inline void showEvent(QShowEvent * e);
	inline void hideEvent(QHideEvent * e);

private:
	QString myText;
	int offset;
	int myTimerId;
};

Ticker::Ticker(QWidget * parent) : QWidget(parent)
{
	offset		= 0;
	myTimerId	= 0;	// ��ʱ��IDͨ���Ƿ�0��, ���Կ���ʹ��0����ʼ������ʾ��ʱ��û������
}

void Ticker::setText(const QString & newText)
{
	myText = newText;
	update();			// ǿ��ִ���ػ涯��
	updateGeometry();	// ֪ͨ��Ticker���ڲ�����������Ⲽ�ֹ�����, ��ʾ�ô��ڲ����Ĵ�С�����˱仯
}

QSize Ticker::sizeHint() const
{
	return fontMetrics().size(0, text());	// 0 ��һ����ʶ��, �򵥵��ַ�������Ҫ��, ���ֻ������һ��0ֵ
}

void Ticker::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	int textWidth = fontMetrics().width(text());	// �����ַ����Ŀ��
	if (textWidth < 1)
		return;
	int x = -offset;
	while (x < width())
	{
		painter.drawText(x, 0, textWidth, height(), Qt::AlignLeft | Qt::AlignVCenter, text());
		x += textWidth;
	}
}

void Ticker::showEvent(QShowEvent *)	// �������ڹ��캯����startTimer(), ����ֻ�д��ڲ���ʵ�ʿɼ���ʱ��, ���б�Ҫ����Qt�����Ķ�ʱ���¼�����Щ��Դ
{
	myTimerId = startTimer(30);	// ������ʱ��, ���ض�ʱ��ID
}

void Ticker::timerEvent(QTimerEvent * e)
{
	if (e->timerId() == myTimerId)
	{
		++offset;
		if (offset >= fontMetrics().width(text()))
			offset = 0;
		scroll(-1, 0);	// �Ѵ��ڲ����������������һ������	����update()Ҳ����, ����scroll()�����Ч��, ��Ϊ��ֻ�Ǽ��ƶ���Ļ���Ѿ����ڵ����ز���ֻ��������ڲ���������ʾ�������һ�������¼�(��ʱ, ֻ��һ��1���س��Կ�ȵ�������);
	}
	else
		QWidget::timerEvent(e);	// ����������ǹ�ע���Ǹ���ʱ��, ������������
}

void Ticker::hideEvent(QHideEvent *)
{
	killTimer(myTimerId);
	myTimerId = 0;
}

#endif