// �����ϰ 10.10 �ͻ��ļ�
#include <iostream>
#include "p377�����ϰ1.h"

int main()
{
	using namespace std;
	BankAccount ba("heshixiong", "84335622", 9999);
	ba.show();
	ba.deposit(88);
	ba.show();
	ba.withdraw(999);
	ba.show();

	return 0;
}