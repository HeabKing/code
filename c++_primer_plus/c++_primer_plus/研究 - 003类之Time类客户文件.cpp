#include <iostream>
#include "�о� - 003��֮Time��.h"

int main()
{
	using	std::cout;
	using	std::cin;
	Time	planning(9);
	Time	coding(2, 22);
	Time	fixing(5, 55);
	Time	total;

	cout << "�ƻ�ʱ�� = ";
	planning.Show();

	cout << "���ʱ�� = ";
	coding.Show();

	cout << "׼��ʱ�� = ";
	fixing.Show();

	//total = coding.Sum(fixing);
	//total = coding.operator+(fixing);
		
		// ʹ�� '+' ����������ϱ�����д��
	total = planning.operator+(coding + fixing);	// '+' ����ǵ��ö���, �ұ��ǲ������ݶ���
	cout << "�ܹ�ʱ�� = ";
	total.Show();

		// ʹ�� '*' ʵ�� ���� * double
	cout << "���ʱ�� * 2.2 = ";
	(coding * 2.2).Show();	// �����и�����, ֻ��ʹ�� coding * 2.2 ������ʹ�� 2.2 * coding, ����Ҫ������Ԫ����ʵ��

		// ��Ԫʵ�� double * ����
	cout << "3.3 * ���ʱ�� = ";
		(3.3 * coding).Show();

		// ��Ԫʵ�� "<<"
	cout << total;

	return 0;
}