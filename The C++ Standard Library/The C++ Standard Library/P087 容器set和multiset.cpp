// ����: 2014-08-20 13:34:57

// �����multiset��set���÷�һ��
#include <iostream>
#include <set>
#include <algorithm>
#include <functional>	// for �º���std::greater<>
int main()
{
	// type of the collection
	//typedef std::set<int> IntSet;

	std::set<int> coll;

	// insert elements from  1 to 6 in arbitrary(�����) order
	// - value1 gets inserted twice
	coll.insert(3);	// ��Ԫ�ػ������������Զ����嵽��ȷ��λ��
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);	// repeat	// �����ظ���Ԫ�ز�û�гɹ���ӽ�ȥ
	coll.insert(6);
	coll.insert(2);

	// pirnt all elements
	// - iterate over all elements
	for (decltype(coll.cbegin()) pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;

	// ʹ�÷º����ı��������
	std::set<int, std::greater<int> > coll2;	// std::greater<int> ��һ���º���
	for (decltype(coll.cbegin()) pos = coll.begin(); pos != coll.end(); ++pos)
		coll2.insert(*pos);
	for (decltype(coll2.cbegin()) pos = coll2.begin(); pos != coll2.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;
}