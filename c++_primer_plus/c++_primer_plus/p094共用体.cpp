// c primer plus�г�֮Ϊ����
// ���ڹ�����ÿ��ֻ�ܴ洢һ��ֵ, ������������㹻�Ŀռ����������ĳ�Աֵ, ����, ������ĳ���Ϊ������Ա�ĳ���;
// ���������;֮һ��, ��������ʵ�����ֻ��߸���ĸ�ʽ��ʱ��(���ǲ���ͬʱʹ��), ���Խ�ʡ�ռ�;
#include <iostream>
using namespace std;
int main(void)
{
	union one4all
	{
		int int_val;
		long long_val;
		double double_val;
	};
	one4all pail;
	pail.int_val = 15;  // store an int
	cout << pail.int_val << endl;
	cout << pail.long_val << endl;  // ��ʹ����д����long_val����֮ǰҲû�и�����ֵ, ��һ�����15
	pail.double_val = 1.38;  // store an double
	cout << pail.double_val << endl;

	return 0;
}