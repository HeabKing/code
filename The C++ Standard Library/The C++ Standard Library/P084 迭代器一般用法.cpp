// ����: 2014-08-20 13:33:56
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<char> coll;

	// append elements  from 'a' to 'z'
	for (char c = 'a'; c <= 'z'; ++c)
		coll.push_back(c);

	// print all elements 
	// - iterator over all elements
	list<char>::const_iterator pos;	// ������Ƕ������list<char>������
		// ������������һ��"ָ�������еĲ��ɱ�Ԫ��"�ĵ�����

	for (pos = coll.begin(); pos != coll.end(); ++pos)	// ʹ�õ�����
		cout << *pos << ' ';
	cout << endl;
}