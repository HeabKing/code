// ����: 2014-08-20 11:40:19
// deque(double-ended queue����д), ˫����, ˫�˶���, ���������˷�չ, ��˲�����β����ͷ������Ԫ�ض�ʮ��Ѹ��, ���м䰲��Ԫ�رȽϷ�ʱ

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	deque<float> coll;

	// insert elements from 1.1 to 6.6 each at the front
	for (int i = 0; i <= 6; ++i)
		coll.push_front(i * 1.1);
	// print all elements followed by a space
	for (decltype(coll.size()) i = 0; i < coll.size(); ++i)
		cout << coll[i] << " ";
	cout << endl;

	vector<int> v;
	// v.push_front(1);	// vectorû�и���push_front()��Ա����....
		// ͨ��, STL����ֻ�ṩ�߱�����ʱ��Ч�ܵĳ�Ա����, ����Է�ֹ����Ա�������ܺܲ�ĺ���;
}