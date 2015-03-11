// ����: 2014-08-21 16:32:39

// �㷨���Ա�����ıȽ�, ����: list��ʹ��remove�㷨, ��ʱʹ���߿϶��Ǹ�����, ��Ϊremove���Ƴ�list�е�Ԫ�ص�ʱ��, ���ú�ߵ�Ԫ�ظ���ǰ�ߵ�, �ܳ, list��õĳ���ʱ�临�Ӷȵ�ɾ�����Ƶ�Ȼ�޴���...
// �����ָ������㷨���ֺܲ��������, ���ṩ��Ӧ�ĳ�Ա����,����: list::remove()...
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	list<int> coll;
	// insert elements from 6 to 1 and 1 to 6
	for (int i = 0; i < 6; i++)
	{
		coll.push_front(i);
		coll.push_back(i);
	}
	// remove all elements with value 3
	// - poor performace
	coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	// remove all elements with value 4
	// - good performance
	coll.remove(4);
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
}