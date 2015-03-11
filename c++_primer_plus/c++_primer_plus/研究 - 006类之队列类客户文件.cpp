#include <iostream>
#include <cstdlib>
#include <ctime>
#include "�о� - 006��֮������.h"
const int MIN_PER_HR = 60;

bool isNewCustomer(double x)	// ����xΪƽ����һ���˿�����Ҫ������
{
	return (std::rand() * x / RAND_MAX < 1);
}

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand((unsigned long)std::time(0));

	cout << "���е���󳤶�: ";
	int qs;
	cin >> qs;
	Queue line(qs);	// ����һ������

	cout << "����ģ���Сʱ��: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;	// ģ��ķ�����

	cout << "����ÿСʱƽ���ж��ٸ��˿�: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;	// ƽ��ÿ��������һ���˿�
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;	// ���ܾ��Ĺ˿���
	long customers = 0;	// �˿͵�����
	long served = 0;	// ��������������
	long sum_line = 0;
	int wait_time = 0;	// ĳλ�˿͵ķ���ʱ��
	long line_wait = 0;	// ÿλ���շ���Ĺ˿����ȴ�ʱ����ܺ�

		// ��ʼģ��

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
			// �Ƿ�Ϊ�������ӳ���

		if (isNewCustomer(min_per_cust))	// ������¹˿�����
		{
			if (line.isFull())
				turnaways++;
			else
			{
				customers++;
				temp.Set(cycle);	// ���浽����ʱ��
				line.isEnQueue(temp);	// ���˿ͷ������
			}
		}

			// �Ƿ�Ϊ���м�С����

		if (wait_time <= 0 && !line.isEmpty())	// ������˿ͽ�������������˵ȴ����շ���
		{
			line.isDeQueue(temp);	// ��һ���˿Ϳ�ʼ���ܷ���
			wait_time = temp.ptime();	// ��¼���˿ͽ��շ����ʱ��
			line_wait += cycle - temp.GetWhen();	// ����ӵ�������ʼ���ܷ���֮��ĵȴ�ʱ��
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.iQueueCount();
	}

	if (customers > 0)
	{
		cout << "�˿���: " << customers << endl;
		cout << "�����˷���Ĺ˿���: " << served << endl;
		cout << "���ܾ��Ĺ˿���: " << turnaways << endl;
		cout << "ƽ�����д�С: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "�˿͵�ƽ���ȴ�ʱ��: " << (double)line_wait / served << " minuties.\n";
	}
	else
		cout << "û�й˿�.\n";
	cout << "Done!\n";

	return 0;
}