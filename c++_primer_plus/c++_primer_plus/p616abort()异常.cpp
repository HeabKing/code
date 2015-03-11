// ������ 2013.12.13.19
// ��ϰ:  2014.08.14.20  # 1
// C++�쳣: �Գ������й������쳣״����һ����Ӧ; # 1
// �쳣����: ����ԱԤ�����������н׶δ����һ��ǿ������Ĺ���, ��ʹ��һ��ָ�������н׶δ����ɲ�ȷ���Ľ��������ϵͳ�϶�����ͬ���ܿط�ʽ���� # 1

#include <iostream>
#include <cstdlib>  // abort()

double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << "Harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to qiut>: ";
	}
	std::cout << "Bye!\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "untenable arguments to hmean()\n";
		std::abort();  // ����ֱ����ֹ����, �����ȷ��ص�main
	}
	return 2.0 * a * b / (a + b);
}