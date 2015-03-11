				// ��̬���м̳�
//	��̬:	��������������ȷ���Լ���ʵ�ַ�ʽ ����, �������������û������ʱ����û����show(), ��������������������ʱ��, ���õ����������show();
//			Ҫ��ʵ�ֶ�̬, �����ַ���:	1. �������������¶�����෽��.	2. ʹ���麯��.
//	�麯��:	��������������¶������ķ���, ͨ��Ӧ�ý����෽������Ϊ�麯��, �����������ݶ������Ͷ������������ͻ�ָ��������ѡ�񷽷��汾;
//			Ϊ��������һ�������������ǹ��ʹ���, �����಻�̳л���Ĺ��캯��, ���Թ��캯��Ϊ�麯��û����;
//			����������������غ���, ������֮��д��һ��, ��ô���������ᱻ����, �����ཫ���޷�ʹ������;
//			�ڻ�������Ϊ�麯���ĺ�������������Զ���Ϊ�麯��;

#ifndef BRASS_H_
#define BRASS_H_
#include <string>

class Brass	// ��ͭ�˻�
{
private:
	std::string	strFullName;
	long		lAccNum;
	double		dbBalance;	// ���
public:
	Brass(const std::string & str = "NoBrass", long an = -1, double bal = 0.0);
	void Deposit(double amt);			// ����
	virtual void Withdraw(double amt);	// ȡ���
	double GetBalance() const { return dbBalance; }
	virtual void ViewAcct() const;		// �鿴����
	virtual ~Brass(){}	// �ڻ���������Ϊ�麯��������������Զ�����Ϊ�麯��, ������ü���virtual
	// ����������һ������������, ����Ϊ�˱�֤�ͷ�����������ʱ����ȷ�ĵ�����������
	// ������������������, ��ֻ���ö�Ӧ��ָ�����͵���������, ���ڱ�����, ����ζ��ֻ��Brass����������������, ��ʹָ��ָ�����һ��BrassPlus����;
};

class BrassPlus : public Brass
{
private:
	double dbMaxLoan;	// ���͸֧���
	double dbRate;		// ����
	double dbOwesBank;	// Ƿ����
public:
	BrassPlus(const std::string & str = "NoBrassPlus", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;		// ��д�����麯��
	virtual void Withdraw(double amt);	// ��д�����麯��
	void ResetMax(double m) { dbMaxLoan = m; }
	void ResetRate(double r) { dbRate = r; }
	void ResetOwes() { dbOwesBank = 0; };
};

#endif