// �����嵥 10.4 ͷ�ļ�
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot(){total_val = shares * share_val;};
public:
// two constructors
	Stock();  // default constructor  // ���ҽ���û�ö����κι��캯��ʱ, �������Ż��ṩĬ�Ϲ��캯��, Ϊ�ඨ���˹��캯����, ����Ա�ͱ���Ϊ���ṩĬ�Ϲ��캯��, ����ṩ�˷�Ĭ�Ϲ��캯��, ����û���ṩĬ�Ϲ��캯��, ��Stock Stock1;���͵������ᱨ��
		// ����Ĭ�Ϲ��캯���ķ�ʽ������: 1. �����еĹ��캯�����в����ṩĬ��ֵ   2. ͨ���������ض�����һ�����캯��---һ��û�в����Ĺ��캯�� Stock(); ����ֻ����һ�����캯��, ��˲���ͬʱʹ�������ַ���
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();  // noisy destructor
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};

#endif