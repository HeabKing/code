// ������� (abstract base class)ABC ��������̳�ΪABC���: ֻ����ӿ�, ���漰ʵ��
// ����������ٰ���һ�����麯��(= 0)
// ��ѳ����������������(������ڼ̳е�ʱ��ʹ�õ���class A : virtual class B {};)
#ifndef �������13_11
#define �������13_11
#include <iostream>
#include <string>

class AcctABC  // �������麯��ʹ����Ϊ�˳������
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}  // ר���ṩ�������������ı����private��Ա�ı�������, ���ֱ�ӽ��������������ΪprotectedҪ��, ��Ϊ���������˽�г�Աֻ�м����ӿ��ܱ��ⲿ����
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;
	double Balance () const {return balance;}
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC(){}  // ��֤����������ȷ��ִ��˳��
};

class Brass : public AcctABC
{
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal){}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass(){}
};

class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void RestMax(double m){maxLoan = m;}
	void RestRate(double r){rate = r;}
	void RestOwes(){owesBank = 0;}
};
#endif