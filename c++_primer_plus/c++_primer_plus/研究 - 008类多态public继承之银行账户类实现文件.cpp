#include <iostream>
#include "�о� - 008���̬public�̳�֮�����˻���.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass methods
Brass::Brass(const string & s, long an, double bal) : strFullName(s)
{
	lAccNum		= an;
	dbBalance	= bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Error: Negative deposit not allowed; Deposit is cancelled.\n";
	else
		dbBalance += amt;
}

void Brass::Withdraw(double amt)
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amount must be positive; Withdrawal canceled.\n";
	else if (amt <= dbBalance)
		dbBalance -= amt;
	else
		cout << "Error: Withdrawal amount of $" << amt
			 << " exceeds your balance.\n"
			 << "Withdrawal canceled.\n";
	restore(initialState, prec);
}

void Brass::ViewAcct() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << strFullName << endl;
	cout << "Account Number: " << lAccNum << endl;
	cout << "Balance: $" << dbBalance << endl;
	restore(initialState, prec);
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	dbMaxLoan	= ml;
	dbOwesBank	= 0.0;
	dbRate		= r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
	dbMaxLoan	= ml;
	dbOwesBank	= 0.0;
	dbRate		= r;
}

// ��д redefine hoe ViewAcct() works
void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	
	Brass::ViewAcct();  // ��ʾ������Ϣ
	cout << "Maximum loan: $" << dbMaxLoan << endl;
	cout << "Owed to bank: $" << dbOwesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * dbRate << "%\n";

	restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt)
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = GetBalance();  // �����˻����balance����, ����û��������������д�÷���, ���Կ��Բ����������������
	if (amt <= bal)  // �������ȡ����д��
		Brass::Withdraw(amt);
	else if (amt <= bal + dbMaxLoan - dbOwesBank)  // ���͸֧������Χ��
	{
		double advance = amt - bal;  // ���д����
		dbOwesBank += advance * (1.0 + dbRate);  // Ƿ���е�Ǯ
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * dbRate << endl;

		//=========== �������� ==========
		Deposit(advance);  
		Brass::Withdraw(amt); 
		//=================================
	}
	else  // ������͸֧��Χ
		cout << "Error: Credit limit exceeded. Transaction cancelled.\n";

	restore(initialState, prec);
}

format setFormat()
{
	// set up ###.## format
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}