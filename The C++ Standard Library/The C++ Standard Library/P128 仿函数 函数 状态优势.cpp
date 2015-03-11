// ����: 2014-08-23 08:20:51
// �������г����˷º����ĵ�һ������, ״̬����
// for_each() ��һ��ģ�庯��, �����Ĳ���û��Ҫ��, ���ݲ���������Ӧ�İ汾����, ����������Ӧ�ô���һ��ֻ��һ��������"����"����Ϊfor_each()����f(elem) ������ʹ��, ������ʹ�÷����޶��˲��������ʹ��·���ʲô���ı�����Ϊ
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "print.hpp"
using namespace std;
#define Version 1

#if Version == 1

// ��Ⱥ���е�ÿ��Ԫ�ؼ���һ���̶���ֵ, �����ھ�֪������̶���
void add10(int & elem)
{
	elem += 10;
}
// ��Ⱥ����ÿ��Ԫ�ؼ��ϲ�ͬ�Ĺ̶�ֵ, �����ھ�֪��
template<int theValue>
void add(int & elem, int e)
{
	elem += theValue;
}

int main()
{
	vector<int> coll;
	for (int i = 0; i <= 9; ++i)
		coll.push_back(i);
	PRINT_ELEMENTS(coll, "init: ");
	for_each(coll.begin(), coll.end(), add10);
	PRINT_ELEMENTS(coll, "add10: ");

	for_each(coll.begin(), coll.end(), add<1>);
	PRINT_ELEMENTS(coll, "add<1>: ");
}

#elif 
// function object that adds the value with which it is initialized
class AddValue
{
private:
	int theValue;	// the value to add
public:
	// constructor initializes the value to add
	AddValue(int v) : theValue(v) {}
	// the "function call" for the element adds the value
	void operator()(int & elem) const { elem += theValue; }
};
int main()
{
	list<int> coll;
	// insert elements from 1 to 9
	for (int i = 0; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "initialized: ");

	// add value 10 to each element
	for_each(coll.begin(), coll.end(), 
		AddValue(10));	// ���������ӵ�10, ����ڷǷº�����˵��ֱ�ǲ����ܵ�, ��Ϊ������������ֻ�ܴ���һ��ֵ, �����ֵ��for_each��ӵ�...
	PRINT_ELEMENTS(coll, "after adding 10: ");
	// add value of first element to each element
	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
	PRINT_ELEMENTS(coll, "after adding first element: ");
}
#endif