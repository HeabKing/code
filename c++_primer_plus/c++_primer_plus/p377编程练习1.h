// ��Ϊ��ϰ�� 10.9 (5) Ϊ�����ϰ1�ṩ��ͷ�ļ�
#include <cstring>
class BankAccount
{
private:
	char name[40];
	char acctnum[25];
	double balance;
public:
	BankAccount(const char * client = "no name", const char * num = "no num", double bal = 0.0);  // �����ʱ��Ͳ��ü���Ĭ�ϲ�����
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};