// ����: 2014-08-21 14:14:43
// ���������: ����������ת���ɵݼ�����
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> coll;
	// insert elements from 1 to 9
	for (int i = 0; i <= 9; ++i)
		coll.push_back(i);
	// print all element in reverse order
	copy(coll.rbegin(), coll.rend(), ostream_iterator<int>(cout, " "));
		// rbegin()����һ����coll�����reverse iterator, �������������Ϊ"��Ⱥ��coll��Ԫ���������"�����
		// rbegin()ָ��Ⱥ���Ľ�βλ��(Ҳ�������һ��Ԫ�ص�λ��)
		// rend()���ص�reverse iterators����һ��"��β"λ��, ֻ���������෴, ָ���������ڵ�һ��Ԫ�ص�ǰһ��λ��

	cout << endl;
}