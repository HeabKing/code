 // �����嵥 17.6
#pragma c9x on
#ifndef _QUEUE_H_
#define _QUEUE_H_
#define bool int
#define true 1
#define false 0

// �ڴ˴�����item�����Ͷ���
// ����:
typedef int Item;
// ��: typedef struct item {int gumption; int charisma; } Item;

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	Node * front;  // ָ������׵�ָ��
	Node * rear;   // ָ�����β��ָ��
	int items;     // ��������Ŀ�ĸ���
} Queue;

// ����: ��ʼ������
// ����ǰ: pqָ��һ������
// ������: �ö��б���ʼ��Ϊ�ն���
void InitializeQueue (Queue * pq);

// ����: �������Ƿ�����
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
// ������: ����ö�������, �򷵻�true, ���򷵻�false
bool QueueIsFull (const Queue * pq);

// ����: �������Ƿ�Ϊ��
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
// ������: ����ö���Ϊ��, �򷵻�true, ���򷵻�false
bool QueueIsEmpty (const Queue * pq);

// ����: ȷ����������Ŀ�ĸ���
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
// ������: ���ض�������Ŀ�ĸ���
int QueueItemCount (const Queue * pq);

// ����: �����β�����Ŀ
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
//         item��Ҫ��ӵ�����β�˵���Ŀ
// ������: �������δ��, item����ӵ�����β��,
//         ��������true. ���򲻸ı����, ��������false.
bool EnQueue (Item item, Queue * pq);

// ����: �Ӷ����׶�ɾ����Ŀ
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
// ������: ������зǿ�, �����׶˵���Ŀ������
//         ��*pitem, �����Ӷ�����ɾ��,��������true;
//         ����������ʹ����Ϊ��, �Ѷ�������Ϊ�ն���
//         ������п�ʼʱΪ��, ���ı����, ��������false
bool DeQueue (Item * pitem, Queue * pq);

// ����: ��ն���
// ����ǰ: pqָ��һ����ǰ�ѳ�ʼ�����Ķ���
// ������: ���б����
void EmptyTheQueue (Queue * pq);

#endif