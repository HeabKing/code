// �����ϰ 10.10 (8) ʵ���ļ�
#include "p378�����ϰ8.h"
#include <iostream>

List::List()
{
	top = 0;
}

bool List::add(Item n)
{
	if (top >= LEN)
		std::cout << "�б��Ѿ�����\n";
	else
	{
		list[top++] = n;
		return true;
	}
	return false;
}

bool List::isempty() const
{
	return top == 0;
}

bool List::isfull() const
{
	return top == LEN;
}

void List::visit(void (*pf)(Item &))
{
	if (top > 0)
		for (int i = 0; i < top; i++)
			(*pf)(list[i]);
	else
		std::cout << "�б��ǿյ�, �޷�ִ�е�ǰ����.\n";
}

void List::show() const
{
	if (isempty())
		std::cout << "�б��ǿյ�\n";
	else
		for (int i = 0; i < top; i++)
			std::cout << list[i] << std::endl;
}