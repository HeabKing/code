// �����嵥 10.9 ʵ���ļ�
#include <iostream>
#include "p365thisָ��.h"

const int STKS = 4;
int main()
{
// create an array of initialized object
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boff Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};	// ��ʼ����������ķ�����: ����ʹ��Ĭ�Ϲ��캯����������Ԫ��, Ȼ�������еĹ��캯����������ʱ����, Ȼ����ʱ��������ݸ��Ƶ���Ӧ��Ԫ����, ���, Ҫ������������, ����������Ĭ�Ϲ��캯��
	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

// set pointer to first element
	const Stock * top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

// now top points to the most valuable holding
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;

	return 0;
}