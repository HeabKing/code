// ����: 2014-08-21 14:31:25
// Ϊʲôremove()����ɾ��Ԫ��ֻ��ͨ������ߵ�Ԫ�ظ���ǰ��Ԫ����ʵ���Ƴ�:
//		����STLΪ�˻�ȡ����Զ������Ĵ���, ͸��"�Ե�����Ϊ�ӿ�", STL�����ݽṹ���㷨���뿪��, Ȼ��, ������ֻ������"�����е�ĳһλ��"�ĳ������, һ����˵, ���������Լ�����������һ����֪, �κ�"�Ե�����"��������Ԫ�ص��㷨, ���޷�͸��������������������ṩ���κγ�Ա����...(������erase())
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
#define Version 2
int main()
{
	list<int> coll;

	// insert elements from 6 to 1 and  1 to 6
	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	// print all elements of the collection
	cout << "Pre:  ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
#if Version == 1
	// remove all elements with value 3
	remove(coll.begin(), coll.end(), 3);	// û�иı�Ⱥ����Ԫ������, �������5 6��δ�����ǵ�Ԫ��, �����߼��������Ѿ��������Ⱥ������
	// print all elements of the collection
	cout << "Post: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
#elif Version == 2
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);	// ���صľ����µ��߼��ϵĽ�β
	cout << "Post: ";
	copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
	cout << endl;
	// print number of resulting elements
	cout << "number of removed elements: " << distance(end, coll.end()) << endl;
	// remove "removed" elements
	coll.erase(end, coll.end());
	// print all elements of the modified collection
	cout << "Post: ";
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif
	
}