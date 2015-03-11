// ����: 2014-08-23 12:37:05
// bind2nd(fn, arg)	templateģ�������û��Ҫ��, ����fn�ı�������Ӧ����һ��"����", �ܹ�������������, ���ҵڶ���������������public��, �ܹ���bind2nd��ȡ, �Ӷ��趨arg�Ĳ���ΪfnҪ��ĵڶ�������Ӧ�е�����, ��ʱ, ����bind2nd(arg_left)��ʱ��, bind2nd()�Ϳ��Ե���fn(arg_left, arg)�� 
// bind2nd�ķ���������fn�ķ�������, �������fn�Ľ��
#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include "print.hpp"
using namespace std;
bool f(int){return true;}
int main()
{
	set<int, greater<int> > coll1;	// �����greater<int>֮���Բ���greater<int>()����Ϊ����greater<int>��һ���ṹ������һ����Ū�ɵķº���
	deque<int> coll2;
	// insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i)
		coll1.insert(i);
	PRINT_ELEMENTS(coll1, "initialized: ");

	// transform all elements into coll2 by multiplying 10
	transform(coll1.begin(), coll1.end(), back_inserter(coll2), bind2nd(multiplies<int>(), 10));
		// ��coll1�ڵ�����Ԫ�س���10�Ժ�ת��(����)��coll2��, ����ʹ�������bind2nd
		// transform()�������Լ��ĵ��ĸ������Ǹ��ܽ��ɵ�һ����(Ҳ��������ʵ��Ԫ��)�ı��ʽ, Ȼ������ȴ��Ҫ�ȰѸ�Ԫ�س���10
		// bind2nd(multiplies<int>(), 10) ʹ�ý���multipies<int>����ʱ, ��Ⱥ����Ԫ����Ϊ��һ������, 10��Ϊ�ڶ�������
		// �������: transform()������bind2nd(*pos), bind2nd()����multiplies(*pos, 10)...

	PRINT_ELEMENTS(coll2, "transformed: ");

	// replace value equal to 70 with 42
	replace_if(coll2.begin(), coll2.end(), bind2nd(equal_to<int>(), 70), 42); 
	PRINT_ELEMENTS(coll2, "replaced: ");

	// remove all elements with value less than 50
	coll2.erase(remove_if(coll2.begin(), coll2.end(), bind2nd(less<int>(), 50)), coll2.end());
	PRINT_ELEMENTS(coll2, "removed: ");
}