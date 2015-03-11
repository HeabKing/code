// ����: 2014-08-21 09:21:00
// 1.	ͨ��, �����趨��һ������������յ�, ��������ֻ���趨���, �յ���ɵ�һ�����Ԫ�������жϳ���
// 2.	����ȷ���ڶ�(�Լ�����)������ӵ�е�Ԫ���������ٺ͵�һ�����Ԫ�ظ�����ͬ
// 3.	����ʽ���������ܵ�����д�㷨�Ĳ���Ŀ��
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
	list<int>		coll1;
	vector<int>		coll2;

	// insert elements from 1 to 9
	for (int i = 0; i <= 9; ++i)
		coll1.push_back(i);
	// RUNTIME ERROR:
	// - overwrites nonexisting elements in the destination
	// - Expression: vector iterator not dereferencable
	//copy(coll1.begin(), coll1.end(), coll2.begin());	// ����һ�����Ԫ��ȫ��������Ŀ������
		// �����Ǹ�д����(overwrites)���ǰ������(inserts)
		// ����㹻����, ��дcoll2.end()��ߵĶ�����ʹ������������ -- ����֪������. ��Ȼ, ����ʹ��STL��ȫ�汾ǿ���Լ������������

	coll2.resize(coll1.size());
	copy(coll1.begin(), coll1.end(), coll2.begin());
	if (equal(coll1.begin(), coll1.end(), coll2.begin()))
		for (auto pos = coll2.begin(); pos != coll2.end(); ++pos)
			cout << *pos << ' ';
	cout << endl;

	deque<int> coll3(coll1.size());
	copy(coll1.begin(), coll1.end(), coll3.begin());
	if (equal(coll3.begin(), coll3.end() - 4, coll1.begin()))	// coll1����˫�������, ���� - 4����
		for (auto pos = coll3.begin(); pos != coll3.end(); ++pos)
			cout << *pos << ' ';
	cout << endl;

	if (!equal(coll3.begin(), coll3.end(), coll2.begin() + 4))
		cout << "equal��Ŀ��������Ա�Դ������??" << endl;
}