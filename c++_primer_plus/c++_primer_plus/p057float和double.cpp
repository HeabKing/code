// �����嵥 3.8
// float �� double �����Լ������ڱ�ʾ����ʱ�����ϵĲ���(����Чλ��)
// ��Чλ��ָ�������������λ, ��31564��Чλ��5��, 32000��Чλ��2��, ��Ϊ�����������뾫ȷ����ǧλ, ���������������൱��ռλ��
// c++��֤float����Чλ����Ϊ32, ������Чλ����Ϊ6, double����Чλ����Ϊ48, ������Чλ����Ϊ15
// c++��֤float double long doubleָ���ķ�Χ������-37 ~ +37
#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	// ͨ��cout��ɾ����β����, ����: ��3333333.250000��ʾΪ3333333.25
	// ����cout.stef()���Ḳ��������Ϊ
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",  \nand ten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << " and a million mint * 10000000000 = ";
	cout << million * mint * 10000000000 <<endl;  // ������16��3, ��֤����15λ����
	cout << sizeof(float);
	return 0;
}