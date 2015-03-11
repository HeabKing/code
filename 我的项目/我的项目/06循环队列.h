// ����ʵ�� ѭ������ ���ڶ����ܳ��̶���������������
const int MAXSIZE = 10;
typedef int QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;	// ͷָ��
	int rear;	// βָ��	�����в�Ϊ�� ָ�����βԪ�ص���һ��λ��
}SqQueue;

// ��ʼ��һ������
bool InitQueue(SqQueue * Q)
{
	Q->front	= 0;
	Q->rear		= 0;
	return true;
}

// ����еĳ���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// �������δ��, �����Ԫ��eΪQ�µĶ�βԪ��
bool EnQueue(SqQueue * Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	// ���������ж�
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;	// rear ָ������ƶ�һλ, ���������, ��ת������ͷ��
	return true;
}

bool DeQueue(SqQueue * Q, QElemType * e)
{
	if (Q->front == Q->rear)	// ����Ϊ��
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;	// front ָ������ƶ�һ��λ��, ����������, ��ת������ͷ��
	return true;
}

#include <iostream>
void ShowQueue(const SqQueue * Q)
{
	if (Q->front == Q->rear)	// ����Ϊ��
		std::cout << "�����ǿյ�!\n";
	for (int i = Q->front;  i != Q->rear; i = ++i % MAXSIZE)
		std::cout << Q->data[i] << " ";
	std::cout << std::endl;
}