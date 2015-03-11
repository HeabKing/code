#include <iostream>
#include "�о� - 008���̬public�̳�֮�����˻���.h"
int main(void)
{
	using std::cout;
	using std::endl;

		// ����ֱ��ʹ�ö���

	Brass Brass1("Brass1", 381299, 4000.00);
	BrassPlus BrassPlus1("BrassPlus1", 382288, 3000.00);

	Brass1.ViewAcct();
	cout << endl;

	BrassPlus1.ViewAcct();
	cout << endl;

	cout << "���˻�BrassPlus1���� $1000: \n";
	BrassPlus1.Deposit(1000.00);
	cout << "�������: $" << Brass1.GetBalance() << endl << endl;

	cout << "��Brass1��ȡ�� $4200:\n";
	Brass1.Withdraw(4200);
	cout << "�������: $" << Brass1.GetBalance() << endl << endl;

	cout << "��BrassPlus1��ȡ�� $4200:\n";
	BrassPlus1.Withdraw(4200);
	BrassPlus1.ViewAcct();
	cout << endl << endl;

		// ���ڶ�̬

	using std::cin;
	const int CLIENTS = 2;

	Brass * pBrass[CLIENTS];
	std::string temp;
	long		tempnum;
	double		tempbal;
	char		kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "����ͻ�����: ";
		getline(cin, temp);
		cout << "����ͻ����˺�: ";
		cin >> tempnum;
		cout << "������: $";
		cin >> tempbal;
		cout << "1. ��ͭ�˻�	2. ��ͭ�˻�\n��ѡ��: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "������ 1 �� 2: ";
		if (kind == '1')
			pBrass[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "����͸֧�޶�: $";
			cin >> tmax;
			cout << "��������: ";
			cin >> trate;
			pBrass[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n');
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		pBrass[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete pBrass[i];
	}
	
	cout << "Done!\n";

	return 0;
}