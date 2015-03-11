// ������ 2013.12.13.19
// ��ϰ:  2014.08.14.21  # 1

#include <iostream>
double hmean(double a, double b);
int main()
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try   // ��ʾ���������쳣�Ĵ����, �����һ������catch
		{
			z = hmean(x, y);
		}
		// const char * s�������쳣����������ַ����쳣��ƥ�� ���û��ƥ���Ĭ�Ͼͻ����abort();
		catch (const char * s)  // catch ����쳣���д���
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";
			continue;
		}

		// ��������������쳣, ��û��try���û��ƥ��Ĵ������, Ĭ������»����abort()����, ���ǿ����޸�������Ϊ # 1

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
		throw "bad hmean() arguments: a = -b not allowed";  // �������쳣�ǿ������ַ�����������c++����, ͨ����������
	// throw���������return���, ��Ϊ��Ҳ��ֹ������ִ��, ����throw���ǽ�����Ȩ�������ú���, ���ǵ��³������ź����������к���, ֱ���ҵ�����try��ĺ���, ���һֱ���˶�����main������Ȼһ�ζ�ûƥ���, �ͻᶼ����abort����, ��Ȼ, ����Ĭ����Ϊ�ǿ��Ըı��
	return 2.0 * a * b / (a + b);
}