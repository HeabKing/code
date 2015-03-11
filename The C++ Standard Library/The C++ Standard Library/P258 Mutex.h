// ֻ��Ҫ���໯QThread��������ʵ������run()�����Ϳ�����
#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QPushButton>
#include <QDialog>
#include <QCloseEvent>
#include <QLayout>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>

#include <QMutex>
// QMutex��: �ṩһ�ֱ���һ����������һ�δ���ķ���, �����Ϳ���ÿ��ֻ��һ���̶߳�ȡ��;
	// ������ṩ��һ��lock()��������ס������(mutex), ����������ǽ�����, ��ô��ǰ�߳̾�����ռ�ò�������, ����, ��ǰ�߳̾ͻᱻ����, ֱ������������������̶߳�������Ϊֹ;

class Thread : public QThread
{
public: 
	inline Thread(const QString & fileName);
	inline void setMessage(const QString & message) { messageStr = message; }
	inline void stop();
		// QThread�ṩ��һ��terminate()����, �ú���������һ���̻߳������е�ʱ�����ֹ��������, ���ǲ��Ƽ�ʹ��terminate(), ��Ϊ��������ʱֹͣ�߳�ִ�ж���������߳�������յĻ���;��������ʹ��stopped������stop()�����ǱȽϰ�ȫ��

protected:
	inline void run();
private:
	QMutex			mutex;		// # 1
	QFile			file;
	QString			messageStr;
	volatile bool	stopped;	// ����Ϊ��ʧ�Ա���
};

class ThreadDialog : public QDialog
{
	Q_OBJECT
public:
	inline ThreadDialog(QWidget * parent = nullptr);

protected:
	inline void closeEvent(QCloseEvent * e);

private slots:
	inline void startOrStopThreadA();
	inline void startOrStopThreadB();

private:
	Thread threadA;
	Thread threadB;

	QPushButton * threadAButton;
	QPushButton * threadBButton;
	QPushButton * quitButton;
};

Thread::Thread(const QString & fileName) : file(fileName)
{
	stopped = false;

	if (!file.open(QIODevice::WriteOnly))
		QMessageBox::warning(nullptr, tr("ERROR"), tr((QString("Cannot open the file %1\n%2").arg(fileName).arg(file.errorString())).toStdString().c_str()));
}

void Thread::run()	// �ڿ�ʼִ���̵߳�ʱ��, �ͻ����run()����, ֻҪstopped������Ϊfalseֵ, ���������һֱ�����̨��ӡ�����������Ϣ, �������뿪run()����ʱ�ͻ���ֹ�߳�
{
	//QApplication::setOverrideCursor(Qt::WaitCursor);
	QTextStream out(&file);
	forever	// # 2
	{
		mutex.lock();
		if (stopped)
		{
			stopped = false;
			mutex.unlock();
			break;
		}
		mutex.unlock();
		out << qPrintable(messageStr);
	}
	out << "\n";
}

void Thread::stop()
{
	mutex.lock();	// # 3
	stopped = true;
	mutex.unlock();
}

ThreadDialog::ThreadDialog(QWidget * parent): QDialog(parent), threadA("P255 B.txt"), threadB("P255 B.txt")
{
	threadA.setMessage("A");	// �õ�һ���߳��ظ���ӡ��ĸ"A"
	threadB.setMessage("B");	// �õڶ����߳��ظ���ӡ��ĸ"B"

	threadAButton	= new QPushButton(tr("Start A"));
	threadBButton	= new QPushButton(tr("Start B"));
	quitButton		= new QPushButton(tr("Quit"));
	quitButton->setDefault(true);
	connect(threadAButton, SIGNAL(clicked()), this, SLOT(startOrStopThreadA()));
	connect(threadBButton, SIGNAL(clicked()), this, SLOT(startOrStopThreadB()));
	connect(quitButton,	   SIGNAL(clicked()), qApp, SLOT(quit()));

	QHBoxLayout * hLayout = new QHBoxLayout(this);
	hLayout->addWidget(threadAButton);
	hLayout->addWidget(threadBButton);
	hLayout->addWidget(quitButton);
	// ....
}

void ThreadDialog::startOrStopThreadA()
{
	if (threadA.isRunning())
	{
		threadA.stop();
		threadAButton->setText(tr("Start A"));
	}
	else
	{
		threadA.start();
		threadAButton->setText(tr("Stop A"));
	}
}

void ThreadDialog::startOrStopThreadB()
{
	if (threadB.isRunning())
	{
		threadB.stop();
		threadBButton->setText(tr("Start B"));
	}
	else
	{
		threadB.start();
		threadBButton->setText(tr("Stop B"));
	}
}

void ThreadDialog::closeEvent(QCloseEvent * e)
{
	threadA.stop();
	threadB.stop();
	threadA.wait();
	threadB.wait();
	e->accept();
}

#endif