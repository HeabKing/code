// ����: 2014-08-21 12:49:37
// �����: C++��׼�����Ԥ�ȶ�������������
// �����͵�����: ���㷨�ĸ�д��ʽ�ĳ��˰���, �����"Ŀ��ռ䲻��"������, һ�������ְ���ʽ������;

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <iterator>	// back_inserter()��ͷ�ļ�
using namespace std;

int main()
{
	list<int> coll1;

	for (int i = 0; i <= 9; ++i)
		coll1.push_back(i);

	// copy the elements of coll1 into coll2 by appending them
	vector<int> coll2;
	copy(coll1.begin(), coll1.end(), back_inserter(coll2));		// ����������!��β��!	�ڲ�����push_back(), ������β�˲���Ԫ��(�˼�"׷��"����), ֻ�����ṩ��push_back()��Ա������������, ������������ó�(vector, deque, list)
	for (auto pos = coll2.begin(); pos != coll2.end(); ++pos)
		cout << *pos << " ";
	cout << endl;

	// copy the elements of coll1 into coll3 by inserting them at the front - reverses the order of the elements
	deque<int> coll3;
	copy(coll1.begin(), coll1.end(), front_inserter(coll3));	// ������������ǰ��, ���ֶ�����ת�˱������Ԫ�ش���, ֻ�����ṩ��push_front()��Ա������������ʹ��(deque, list)
	for (auto pos = coll3.begin(); pos != coll3.end(); ++pos)
		cout << *pos << " ";
	cout << endl;

	// copy elements of coll1 into coll4
	// - only inserter that works for associative collections
	set<int> coll4;
	copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));	// һ���԰�����, ��Ԫ�ز���"��ʼ��ʱ����֮�ڶ�����"��ָλ�õ�ǰ��, �ڲ�����insert(), ����ֵ��λ����Ϊ����, ����STL�������ṩ��insert()����, �����Ψһ�����ڹ���ʽ�������ϵ�һ��Ԥ�ȶ���õ�inserter
		// ��Ȼ�ڹ���ʽ�����в���ָ����λ��, �������λ�þ���ֻ��һ����ʾ��, ��������ȷ����ʲô�ط���ʼ��Ѱ��ȷ�İ���λ��, �����ʾ�Ĳ���ȷ, Ч���ϵı��ֻ��"û����ʾ"�����
	for (auto pos = coll4.begin(); pos != coll4.end(); ++pos)
		cout << *pos << " ";
	cout << endl;

	copy(coll4.begin(), coll4.end(), inserter(coll2, coll2.begin() + 5));
	for (auto pos = coll2.begin(); pos != coll2.end(); ++pos)
		cout << *pos << " ";
	cout << endl;
}