// �����嵥 3.9
#include <iostream>
int main()
{
	using namespace std;

	float a = 2.34E+22f;
	float b = a + 1.0f;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "b - a = " << b - a << endl;
	// ����˵b - aӦ��Ϊ1Ȼ����ʵ�Ͻ��Ϊ0, ��������, 
	// 2.34E+22��һ��С���������23λ������, ����1, 
	// �����ڵڶ�ʮ��λ����һ. ��float����ֻ�ܱ�ʾ��
	// ���е�ǰ��λ����ǰ��λ, ����޸ĵڶ�ʮ��λ�����ֵ�������κ�Ӱ��

	return 0;
}