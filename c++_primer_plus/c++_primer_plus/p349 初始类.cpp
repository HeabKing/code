			// ���ʹ�� �û��������͵�ʹ��
// ������Ϣ: ��OOP��, �������Ա����������������Ϣ;

#include <iostream>
#include "p343 ��ʼ��.h"
int main(void)
{
	Stock fluffy_the_cat;

	fluffy_the_cat.acquire("���ۿƼ�", 20, 12.5);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(3000000, 40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(3000000, 0.125);
	fluffy_the_cat.show();

	return 0;
}