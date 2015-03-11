// ����: 2014-08-21 18:33:51
// ��ֵ����������͸�����Ӧ��������������ͼ��չ���˳���(0 - 7�ķ�Χͼ(3λ))
//		-1  0  1    7  0  1
//      -2     2    6     2
//      -3 -4  3    5  4  3
//
//      011 + 001 = 100
//      3 + 1 = 4(unsigned Byte3)
//		3 + 1 = -4(Byte3)
//		ת��: 8 - 4 = 4
#include <iostream>
#include <limits>
using namespace std;
void print(int t)
{
	printf("%11d => ", t);
	for (int i = 0; i < sizeof(int) * 8; i++)	
	{
		if (i % 4 == 0)
			cout << " ";
		cout << ((0x80000000 & t) >> 31);
		t <<= 1;
	}
	cout << endl;
}
int main()
{
	cout << "intMax     =  " << numeric_limits<int>::max() << endl;
	cout << "intMax + 1 = " << numeric_limits<int>::max() + 1 << endl;
	cout << "intMax + 2 = " << numeric_limits<int>::max() + 2 << endl << endl;
	
	cout << "-1(int) = " << unsigned(-1) << "(unsigned int)\n\n";

	print(numeric_limits<int>::max());
	print(numeric_limits<int>::max() + 1);
		// ����˵�� -2147483648�ڲ�����1000 0000 0000 0000 0000 0000 0000 0000 ��ʾ��
	print(numeric_limits<int>::max() + 2);
	print(numeric_limits<int>::max() + 3);

	// δ��ʼ���ı����ڲ��洢��ֵ
	print(-858993460);
}