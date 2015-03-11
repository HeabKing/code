#ifndef �����嵥_15_5
#define �����嵥_15_5

template <class Item>
class QueueTP
{
private:
	enum{Q_SIZE = 10};  // Ĭ�϶��еĳ���
	// Node ��һ��Ƕ�׵��ඨ��
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i) : item(i), next(nullptr){} 
	};
	Node * front;        // ͷָ��
	Node * rear;         // βָ��
	int items;           // ���ڵ���Ŀ��Ŀ
	const int qsize;     // ������Ŀ����   ??? �ѵ�const����Ҳ����������������Ȼ���ʼ����ʱ�����ֵ ???
	QueueTP(const QueueTP & q) : qsize(0) {}
	QueueTP & operator=(const QueueTP & q) {return *this;}
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const {return items == 0;}
	bool isfull() const {return items == qsize;}
	int queuecount() const {return items;}
	bool enqueue(const Item & item);  // ����Ŀ
	bool dequeue(Item & item);        // ����Ŀ
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template<class Item>
QueueTP<Item>::~QueueTP()
{  // ����ֻ��Ҫ���ٶ��е��ڴ������, ջ�е��Զ�����
	Node * temp;
	while (front != nullptr)  // ������ǿն���
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class Item>
bool QueueTP<Item>::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node(item);  // ����node, �����ù��캯�����г�ʼ��
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<class Item>
bool QueueTP<Item>::dequeue(Item & item)
{
	if (front == nullptr)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		return rear = nullptr;
	return true;
}

#endif

// �����嵥 15.6
#include <iostream>
#include <string>

int main(void)
{
	using std::string;
	using std::cin;
	using std::cout;

	QueueTP<string> cs(5);  // ����һ�����Ԫ�صĶ���
	string temp;

	while (!cs.isfull())
	{
		cout << "Please enter your name, you will be served in the order of arrival.\n name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full, Processing begins!\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}

	return 0;
}