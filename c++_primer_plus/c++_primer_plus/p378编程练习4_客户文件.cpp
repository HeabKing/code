// �����ϰ 10.10 (4) �ͻ��ļ�
#include <iostream>
#include "p378�����ϰ4.h"

int main()
{
	using SALES::Sales;  // �������ƿռ��е�Sales��

	double vals[3] = {2000, 3000, 5000};
	Sales forFiji(vals, 3);
	forFiji.showSales();

	Sales red;
	red.showSales();
	red.setSales();
	red.showSales();

	return 0;
}