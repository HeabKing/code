// ����: 2014-08-20 11:27:42
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> coll;

	// append elements with values 1 to 6
	for (int i = 0; i < 6; i++)
		coll.push_back(i);
	// print all elements followed by a space
	for (decltype(coll.size()) i = 0; i < coll.size(); ++i)	// coll.size ����������size_t, ���޷������� decltype(expression) expressionֻ�������ƶ�����, ����������ִ��������ʽ
		cout << coll[i] << ' ';
	cout << endl;
}