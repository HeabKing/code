// �����ϰ 10.10 �ͻ��ļ�
#include <iostream>
#include "p377�����ϰ2.h"
int main()
{
	Person one;
	Person two("Smaythecraft");
	Person three("Dimwiddy", "Sam");
	
	one.Show();
	one.FormalShow();
	std::cout << std::endl;
	
	two.Show();
	two.FormalShow();
	std::cout << std::endl;
	
	three.Show();
	three.FormalShow();
	std::cout << std::endl;


	return 0;
}