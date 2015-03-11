// p373��ʼ p377����

// ��֮ADT(abstract data type, ������������)

#ifndef ջ_H_
#define ջ_H_

typedef unsigned long Item;	// ����ʹ�õ���Item������unsigned long, �����Ҫduobleջ��ṹ���͵�ջ, ��ֻ���޸�typedef���, �������ͷ������屣�ֲ���;

class Stack
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int	 top;	// top ָ��ջ���Ŀ�λ��
public:
	Stack();
	bool isEmpty() const;
	bool isFull()  const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif