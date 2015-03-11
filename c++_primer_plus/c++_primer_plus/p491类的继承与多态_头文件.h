// һ�����������˻����� �����ǲ���͸֧�û� �������ǿ���͸֧���û�
// ��̬: ����ĳ�Ա��������������д�����˲�ͬ������  ������һ���������͵�����ͬʱ�����ܹ���ʾ�������ָ��, ����Ƕ�̬��
// ע��: ���Ҫ�����������¶������ķ���, ͨ��Ӧ�ý����෽������Ϊ���, �������򽫻���ݶ������Ͷ��������û�ָ���������ѡ�񷽷��汾, Ϊ��������һ������������Ҳ��һ�ֹ���
// ��������ЩԤ�ڻᱻ��д�ĺ�������Ϊ�麯�� // �����಻�̳л���Ĺ��캯��, ���Խ����캯�������麯��Ҳûʲô����
// ͨ��Ӧ��Ϊ�����ṩһ������������, ��ʹ��������Ҫ��������, Ҳ��������, �������������һ���ռ��Ч�ʶ���
// �����������3�������麯��, ����������ֻ��д��һ��, ��ô�����������ᱻ����, �����ཫ���޷�ʹ������
#ifndef BEASS_H_
#define BEASS_H_
#include <string>
// Brass Account Class
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;  // ���
public:
	Brass(const std::string & a = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);  // ����
	virtual void Withdraw(double amt);  // ȡ���
	double Balance() const;
	virtual void ViewAcct() const;  // �鿴�˻�����  // ����Ϊ�鷽��(virtual method)
	virtual ~Brass() {};  // �ڻ���������Ϊ�鷽�������������оͻ��Զ���Ϊ�鷽��, ������������������һ�²��Ǹ��õذ취, �鷽���͸�Animal������������Bird��Ķ����ʱ����Ե���Bird����д����һ��
	// ����������һ������������, ����Ϊ�˱�֤�ͷ�����������ʱ����ȷ�ĵ�����������
};

class BrassPlus : public Brass
{
private:
	double maxLoan;  // ���͸֧���
	double rate;  // ��Ϣ��
	double owesBank;  // Ƿ����
public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct()const;  // ��д����ĳ�Ա����
	virtual void Withdraw(double amt);  // ��д����ĳ�Ա����
	void ResetMax(double m){maxLoan = m;}  // ͷ�ļ��е�������������
	void ResetRate(double r){rate = r;}
	void ResetOwes(){owesBank = 0;}
};

#endif