// ����: 2014-8-22 09:33:44
// �ж�ʽ, predicate: ���ز���ֵ�ĺ���, ͨ��������ָ������׼�����Ѱ׼��, ������һ��������������
// һԪ�ж�ʽ: unary predicate	��Ԫ�ж�ʽ: binary predicate
// һԪ�ж�ʽ, �������е���һ��elem���бȽ� find_if()	2.	��Ԫ�ж�ʽ, �������е�������elem���бȽ� sort()
// STLҪ��, �����ͬ��ֵ, predicate����ó���ͬ��ֵ, �⽫��"������ʱ, ��ı��Լ��ڲ�״̬"�ĺ������;
// ����: Ѱ�Ҹ��������ڵĵ�һ������
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>	// for abs()
using namespace std;

// predicate, which returns whether an integer is a prime number (����)
bool isPrime(int number)
{
	// ignore negative sign
	number = abs(number);
	// 0 and 1 are prime numbers
	if (number == 0 || number == 1)
		return true;
	// find divisor(����) that divides without a remainder(����)
	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor);
	// if no divisor greater than 1 is found, it is a prime number
	return divisor == 1;
}

int main()
{
	list<int> coll;
	// insert elements from 24 to 30
	for (int i = 24; i<= 30; ++i)
		coll.push_back(i);

	// search for prime number
	list<int>::iterator pos;
	pos = find_if(coll.begin(), coll.end(), isPrime);	// �ڸ���������Ѱ��ʹ"������һԪ�ж�ʽ"������Ϊtrue�ĵ�һ��Ԫ��, ���û���ҵ�, ���صڶ�������end
	if (pos != coll.end())
		cout << *pos << " is first prime number found \n";
	else
		cout << "no prime number found\n";
}