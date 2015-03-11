// ����: 2014-08-21 16:57:07
// �㷨������̬���������Щ��������, �е���֮Ϊ���п���, �е���֮Ϊ��Ҫ, ��������������ָ����Ѱ����, ����������ĳ�ֲ���, �Ա㽫�����е�Ԫ��ת������һ������
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include "print.hpp"
using namespace std;
#define Version 2
// function that prints the passed argument
#if Version == 1
void print(int elem)
{
	cout << elem << ' ';
}
#elif Version == 2
int square(int value)
{
	return value * value;
}
#endif
int main()
{
#if Version == 1
	vector<int> coll;
	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	// print all elements
	for_each(coll.begin(), coll.end(), print);
	cout << endl;
#elif Version == 2
	std::set<int>		coll1;
	std::vector<int>	coll2;
	// insert elements from 1 to 9 into coll1
	for (int i = 1; i < 10; i++)
		coll1.insert(i);
	PRINT_ELEMENTS(coll1, "initialized: ");
	// transform each element from coll1 to coll2
	// - square transformed values
	std::transform(coll1.begin(), coll1.end(),	// source
		std::back_inserter(coll2),				// destination
		square);								// operator
	PRINT_ELEMENTS(coll2, "squared: ");
#endif
}