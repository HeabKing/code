#include <iostream>
#include "p510�������_ͷ�ļ�.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "!Error: Negative deposit not allowed; Deposit is cancelled.\n";
	else
		balance += amt;
}

// ����: virtual void Withdraw(double amt) = 0;
// ����Ϊ���麯���ĺ���Ҳ�����ڱ����н��ж���, (ERROR:)xxxxxx���������������û����д��������Ļ�����ʹ�û����еķ���xxxxx ��ȷ��ԭ�����������������¶����ʱ��������û���ĳ��󷽷�, �����Ϳ��Է��ʻ����������
											// ����, �������б�����д���麯��, ���û����д�Ļ���������һ������������಻��ʵ��������
void AcctABC::Withdraw(double amt)   // ���麯���Ķ���, �ȴ�����������д, ���û����д�Ļ�����ʹ�����
{
	balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "!Error: Withdrawal amount must be positive; Withdrawal canceled.\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);  // ʹ���˻�����󷽷�
	else
		cout << "!Error: Withdrawal amount of $" << amt
			 << " exceeds your balance.\n"
			 << "Withdrawal canceled.\n";
}

void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass Client: " << FullName() << endl;
	cout << "Account Number: "<< AcctNum() << endl;
	cout << "Balace: $" << Balance() << endl;
	Restore(f);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba)  // ��AcctABC���Ҳ�û�ж������AcctABC�Ĺ��캯��(���ƺ���), ϵͳ���Զ�����һ��(���û�ж�̬�����ڴ�Ļ��ⲻ���������)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();

	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Account Number: "<< AcctNum() << endl;
	cout << "Balace: $" << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";

	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();

	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)  // ���͸֧������Χ��
	{
		double advance = amt - bal;  // ���д����
		owesBank += advance * (1.0 + rate);  // Ƿ���е�Ǯ
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;

		//=========== �������� ==========
		Deposit(advance);  
		AcctABC::Withdraw(amt); 
		//=================================
	}
	else  // ������͸֧��Χ
		cout << "Error: Credit limit exceeded. Transaction cancelled.\n";

	Restore(f);
}