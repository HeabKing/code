// �Լ��ܽ�
// ���ڷ�Χ��forѭ������һ�ֳ�����ѭ������: ������(��������, ��vector��array)��ÿ��Ԫ��ִ������ͬ�Ĳ���
#include <iostream>
int main()
{
	double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
	// ��ʾ����
	for (double x : prices)
		std::cout << x << std::endl;
	// ��������
	for (double &x : prices) // &x��ʾx�Ǹ����� ����, ���������ý������Ĵ����ܹ��޸����������
	{	
		x = x * 0.80;
		std::cout << x << std::endl; // ����Ϊʲô����x������&x��������ʲô?????
	}
	// ��ʼ���б� // ò�ƻ���֧��???????
	//for (int x : {3, 5, 2, 8, 6})
	//	std::cout << x << " ";
	//std::cout << std::endl;
	return 0;
}