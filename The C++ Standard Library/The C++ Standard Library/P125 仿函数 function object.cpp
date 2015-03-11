// ����: 2014-08-23 07:42:21
// ���㷨�ĺ���������һ���Ǻ���, Ҳ��������Ϊ���ƺ���("ʹ��С���Ŵ��ݲ���, ���Ե���ÿ������")�Ķ���, �κζ���, ֻҪ��Ϊ�������, �����Ǹ�����;
// �º������ŵ�:	1. ���Լ��ĳ�Ա�����ͱ���, ����ζ�ŷº���ӵ��״̬(state);
//					2. һ�㺯��, Ψ�����ǵ������겻ͬʱ, �����Ա�ͬ, �º������Լ����ͱ�, ���Խ�������Ϊ����template����������;	   
//					3. �º���ͨ���ٶȱ�һ�㺯����, template��ϸ���ڱ�������Ѿ�ȷ��, ͨ�����ܽ��и��õ��Ż�;
// for_each() ��һ��ģ�庯��, �����Ĳ���û��Ҫ��, ���ݲ���������Ӧ�İ汾����, ����������Ӧ�ô���һ��ֻ��һ��������"����"����Ϊfor_each()����f(elem) ������ʹ��, ������ʹ�÷����޶��˲��������ʹ��·���ʲô���ı�����Ϊ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// simple function boject that prits the passed argument
class PrintInt
{
public:
	void operator() (int elem) const { cout << elem << ' '; }
};

int main()
{
	vector<int> coll;
	// insert elements from 1 to 9
	for (int i = 1; i < 10; i++)
		coll.push_back(i);

	// print all elements
	for_each(coll.begin(), coll.end(), 
		PrintInt());	// PrintInt()����������һ����ʱ����,����for_each()�㷨��һ������
						// template<class Iterator, class Operation> Operator for_each(Iterator act, Iterator end, Operation op) {while(act != end) {op(*act); ++act;} return op;}

	cout << endl;
}