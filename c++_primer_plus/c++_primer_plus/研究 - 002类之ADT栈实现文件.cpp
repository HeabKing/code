#include "�о� - 002��֮ADTջ.h"

Stack::Stack()
{
	top = 0;	// ָ��ջ���Ŀ�λ��
}

bool Stack::isEmpty() const
{
	return top == 0;
}

bool Stack::isFull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (top < MAX)
		items[top++] = item;
	else
		return false;
	return true;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
		item = items[--top];
	else
		return false;
	return false;
}