// �����嵥 10.3
// ���ʹ��       ������û����������!!!!!!!!!!
#include <iostream>
#include "p343��ʶ��.h"
int main()
{
	Stock fluffy_the_cat;  // ��������ÿ���������Լ��Ĵ洢�ռ�, ���ڴ洢���ڲ����������Ա; ����ͬһ��������ж�����ͬһ���෽��, ��ÿ�ַ���ֻ��һ������
						  // ��oop��, ���ó�Ա��������Ϊ������Ϣ, ��˽�ͬ������Ϣ���͸�������ͬ�Ķ��󽫵���ͬһ������, ���Ƿ�����������������ͬ�Ķ���
		// ���û���ṩ�κεĹ��캯��, ��c++�Զ��ṩĬ�ϵĹ��캯��, ����Ĭ�Ϲ��캯������ʽ�汾, �����κι���, ����stock����˵Ĭ�ϵĹ��캯����������:Stock::Stock(){}

	fluffy_the_cat.acquire("NanoSmart", 20, 12.5);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(300000, 40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(300000, 0.125);
	fluffy_the_cat.show();

	return 0;
}