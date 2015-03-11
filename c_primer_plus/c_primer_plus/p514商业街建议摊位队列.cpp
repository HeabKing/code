// �����嵥 17.9
#pragma c9x on
#define _QUE_H_

// �ڴ˲���item���͵Ķ���
typedef struct item
{
	long arrive;  // һλ�˿ͼ�����е�ʱ��
	int processtime;  // �ù˿���Ҫ����ѯʱ��
}Item;

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

#include <stdio.h>
#include <stdlib.h>

static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
	if (QueueIsFull(pq))
		return false;
	
	Node * pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))  // ��Ŀλ�ڶ����׶�
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->items++;

	return true;
}

static void CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;
	if (QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->rear = NULL;
	return true;
}

static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}

void EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

#include <stdio.h>
#include <stdlib.h>  // rand() srand()
#include <time.h>    // time()
#define MIN_PER_HR 60.0

bool newcustomer(double x);  // ���¹˿͵�����?

Item custormertime(long when);  // ���ù˿Ͳ���

int main(void)
{
	Queue line;
	Item temp;    // �����¹˿͵�����
	int hours;    // ģ���Сʱ��
	int perhour;  // ÿ��Сʱ�˿͵�ƽ����
	long cycle, cyclelimit;  // ѭ��������, ���������Ͻ�
	long turnaways = 0;   // ������������ܹ˿���
	long customers = 0;   // ��������еĹ˿���
	long served = 0;      // ��ģ���ڼ�õ�����Ĺ˿���
	long sum_line = 0;    // �ۼƵĶ��г���
	int wait_time = 0;    // �ӵ�ǰ��Sigmund���е�ʱ��
	double min_per_cust;  // �˿͵�����ƽ�����ʱ��
	long line_wait = 0;   // �����ۼƵȴ���ʱ��

	InitializeQueue(&line);
	srand(time(0));  // �����ʼ��rand()
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation(ģ��) hours: ");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customer per hour: ");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)  // һ��ѭ��ʱһ���ӵ����
	{
		if (newcustomer(min_per_cust))  // ����й˿͵���
		{
			if (QueueIsFull(&line))  // ��������, ���ܼ���
				turnaways++;
			else  // �����п���, ���Լ���
			{
				customers++;
				temp = custormertime(cycle);  // ����������˵����(��ѯ��ʱ��, ����ʱ��) cycle�Ǳ��˿���ʱ���뿪ʼ�ķ�����
				EnQueue(temp, &line);  // �����˼��������
			}
		}
		if (wait_time <= 0 && !QueueIsEmpty(&line))  // ���sigmund���в��Ҷ����������ڵȴ�
		{
			DeQueue(&temp, &line);  // �Ѷ��׵���ȥ��
			wait_time = temp.processtime;
			line_wait += cycle - temp.arrive;  // ���ڵ�ʱ��-����ʱ�������������ѯ���˵ȴ���ʱ��(��ѯʱ���ʱ�䲻�����ȴ�ʱ��)
			served++;
		}
		if (wait_time > 0)  // һ��ѭ��һ����, ��ѯ��һ���ӹ�ȥ��
			wait_time--;
		sum_line += QueueItemCount(&line);  // ÿһ���ӵĶ����������ӽ�ȥ, �����ƽ��ÿ���Ӷ��г��ڶ����˵�״̬
	}

	if (customers > 0)
	{
		printf("customers accepted: %ld\n", customers);
		printf("   customers served: %ld\n", served);  // customer - served ���Ƕ����еȺ���˵ĸ���
		printf("      turnaways: %ld\n", turnaways);
		printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf(" average wait time: %.2f minutes\n", (double)line_wait / served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&line);
	puts("Bye!");

	return 0;
}

// x�ǹ˿͵�����ʱ����(�����)
// �����һ�������й˿���, �򷵻�true
bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

// when�ǹ˿͵�����ʱ��
// ��������һ��Item�ṹ, �ýṹ�Ĺ˿͵���ʱ������Ϊwhen
// ��Ҫ����ѯʱ������Ϊһ����Χ��1-3֮������ֵ
Item custormertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}