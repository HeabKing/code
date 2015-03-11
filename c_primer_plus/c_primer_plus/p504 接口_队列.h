// �����嵥 17.6
#pragma c9x on
#ifndef _QUE_H_
#define _QUE_H_

// �ڴ˲���item���͵Ķ���
typedef int Item;

#define MAXQUEUE 10

typedef struct node
{
	struct node * next;
	Item item;
}Node;

typedef struct queue
{
	Node * front;  // ָ�������ָ��
	Node * rear;   // ָ�����βָ��
	int items;     // ��������Ŀ�ĸ���
}Queue;

void InitializeQueue(Queue * pq);

bool QueueIsFull(const Queue * pq);

bool QueueIsEmpty(const Queue * pq);

int QueueItemCount(const Queue * pq);

bool EnQueue(Item item, Queue * pq);

bool DeQueue(Item * pitem, Queue * pq);

void EmptyTheQueue(Queue * pq);

#endif