// �����ݺͷ����ϳ�һ����Ԫ�����������˵�����, �����������, �ڴ��������ʱ��, �����Զ�����ʹ�ö���Ĺ���;

#ifndef p343��ʼ��_H_
#define p343��ʼ��_H_

#include <string>

	// ������ - һ�������û���ĳ��˾���й�Ʊ����;

class Stock
{
		// ֻ���ù��г�Ա��������Ԫ��������private��Ա(Ĭ�Ϸ��ʷ�ʽ);
		// �����ݷ������˽�в��ֳ�Ϊ��������, ����ֹ�˳���ֱ�ӷ������ݳ�Ա, ������һ�ַ�װ, ��ʵ�ֵ�ϸ�ڷ�װ��˽�в�����;
private:
			// ����ֻ����������Щ����, ��û�и�ֵ, ����û�ж���, Ҳû�з���ռ�, ���Կ��Է���ͷ�ļ���, �ļ����ⲿȫ�ֱ����������ľ������, ��ζ���Ͳ�����;
	std::string company;
	long		shares;		// �ɷ�
	double		share_val;	// �ɼ�
	double		total_val;	// �ܳ��м�ֵ
	
		// ����λ���������еĺ����������Զ���Ϊ��������, ��Ȼ����ͷ�ļ���Ҳ������;
	void set_tot(void){total_val = shares * share_val;}  // ����������ͨ�����������Ƴ��ڲ�����ʵ�ֵĿ��Է���ͷ�ļ�

		// ���к����ṩ�˶���ͳ���֮��Ľӿ�;
public:
	void acquire(const std::string &, long, double);  // acquire����: ��ȡ
	void buy	(long, double);
	void sell	(long, double);
	void update	(double);
	void show	(void);
};

#endif