// ����: 2014-08-21 13:43:55
// ��������: һ��������дstream�ĵ�����, �ṩ�˱�Ҫ�ĳ�����, ʹ�ü��̵��������Ǹ�Ⱥ��, ���ܴ��ж�ȡ����;

// ����: �ӱ�׼�����ȡ������������, ����, �����Ǵ�ӡ����Ļ
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> coll;
	// read all words from the standard input
	// - source: all strings until end-of-file(or error)
	// - destination: coll(inserting)
	copy(istream_iterator<string>(cin),	// start of source	// ����һ���ɴ�"��׼������cin"��ȡ���ݵ�stream iterator, <string>��ʾר�Ŷ�ȡ�����ͱ��Ԫ��, ��ЩԪ��ͨ��operator>>����ȡ����, ��˵��㷨��ͼ������һ��Ԫ��ʱ, Istream iterators�ͻὫ������ͼת��Ϊ�����ж�: cin >> string;
		istream_iterator<string>(),		// end of source	// ����Istream iterators��default���캯��, ����һ������"����������"�ĵ�����, �������������: �㲻���ٴ��ж�ȡ�κζ���
		back_inserter(coll));			// destination

	// sort elements
	sort(coll.begin(), coll.end());

	// print all elements without duplicates(����, �ӱ�, �ظ�)
	// - source: coll
	// - destination: standard output(without newline between elements)
	unique_copy(coll.begin(), coll.end(),		// unique_copy����copy�ظ�ֵ
		ostream_iterator<string>(cout, "\n"));	// ����һ��output stream iterator, ͸��operator<<��coutд��string, cout֮��ĵڶ�������(���п���)��������ΪԪ��֮��ķָ��� 
}