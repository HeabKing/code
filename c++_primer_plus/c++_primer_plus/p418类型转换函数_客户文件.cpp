// �����嵥 11.21 �ͻ��ļ�
#include <iostream>
#include "p411����ת��.h"

int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8);  // 9 stone, 2.8 pounds
	double p_wt = poppins;  // implicit(��ʽ��) conversion
		// ��ʽ��ʹ��ת������
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int (poppins) << " pounds.\n";
						// ��ʽ��ʹ��ת������
	return 0;
}