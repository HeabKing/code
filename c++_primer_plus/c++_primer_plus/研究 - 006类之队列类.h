#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
	long	arrive;
	int		processtime;
public:
	Customer(){arrive = processtime = 0;}

	void	Set(long when);
	long	GetWhen()	const {return arrive;}
	int		ptime()		const {return processtime;};
};

typedef Customer Item;

class Queue
{
private:
	typedef struct Node	{Item item; Node * next;} *link;	// ���������ṹ����, privateֻ��������ʹ��, publicҪͨ�������������ʹ��
	enum {Q_SIZE = 10};
	link	front;
	link	rear;
	int		itemsNum;
	const int qsize;	// ������һ������, �ڶ����ʱ������ʼ��, ͨ�������캯��ʹ�ó�ʼ���б�ʵ��

		// ��ʼ���б����:

	Queue(const Queue & q) : qsize(0){}
			// ����Queue(const Queue & q)������ʱ��: 1. ��������������ݳ�Ա���������ڴ�(������4��);	2. ������뵽��������, ʹ�ó��淽ʽ��ֵ�洢���ڴ���;
			// ���, ��ִ�е����캯����֮ǰ, ����������ʱ�Գ���qsize���г�ʼ��; ʵ�����������﷨�����ֽг�Ա��ʼ���б�( : qsize(0));
			// ע��:
			//		1. ֻ�й��캯������ʹ�����ֳ�ʼ���б��﷨;
			//		2. ����ʹ�������﷨���������Ա:	(1). �Ǿ�̬const���Ա	(2). ������Ϊ���õ����Ա(��Ϊ������const��������, ֻ���ڱ�������ʱ����г�ʼ��)
			//		3. ���ʹ�������﷨�����:	���ڱ�����������ĳ�Ա��˵, ʹ�ó�Ա��ʼ���б��Ч�ʸ���;

		// �Դ������ʱ�ò�����Ĭ�����ɵĺ����Ĵ���

	Queue & operator=(const Queue & q){return *this;}

			// �ڱ�����, Ĭ�ϵ�ת�����캯���͸�ֵ������Ǵ����, ����������ʱҲ�ò���ʵ�����ת�����캯������ȸ��Ƹ�ֵ�����, �������ｫ��������Ϊprivate���͵ĺ���, �Է�ֹ�����ʹ��;
			// ��������3������:
			//		1. �������˱������Զ����ɵ�Ĭ�Ϸ�������;
			//		2. ��Ϊ��Щ������˽�е�, ���Բ��ܱ��㷺ʹ��;
			//		3. �ڶ���������������Ƶ���ʱ, ���ַ���������;
			//		ps: C++11�ṩ����һ�ֽ��÷����ķ�ʽ -- ʹ�ùؼ���delete

public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool	isEmpty()	const	{return itemsNum == 0;};
	bool	isFull()	const	{return itemsNum == qsize;};
	int		iQueueCount()const	{return itemsNum;};
	bool	isEnQueue(const Item &item);
	bool	isDeQueue(Item & item);
};

#endif