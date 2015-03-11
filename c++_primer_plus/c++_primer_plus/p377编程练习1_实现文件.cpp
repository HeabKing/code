// �����ϰ 10.10 ʵ���ļ�
#include <iostream>
#include "p377�����ϰ1.h"

BankAccount::BankAccount(const char * client, const char * num, double bal)  // ��ԭ����д��Ĭ�ϲ����Ϳ�����, �����в���д
{
	strncpy(name, client, 39);
	name[39] = '\0';
	strncpy(acctnum, num, 24);
	acctnum[24] = '\0';
	balance = bal;
}

void BankAccount::show(void) const
{
	std::cout << "Name: " << name << std::endl
		<< "Acctnum: " << acctnum << std::endl
		<< "Balance: " << balance << std::endl;
}

void BankAccount::deposit(double cash)
{
	balance -= cash;
}

void BankAccount::withdraw(double cash)
{
	balance += cash;
}