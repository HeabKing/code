// �����ϰ 10.10 (5) �ͻ��ļ�
#include <iostream>
#include "p378�����ϰ5.h"

int main()
{
	using namespace std;
	Stack st;
	Item cus[10];

	for (int i = 0; i < 10; i++)
	{
		cout << "��������(�����˳�): ";
		if (cin.getline(cus[i].fullname, 35) 
			&& cus[i].fullname[0] != '\0')
		{
			cout << "����۸�: ";
			cin >> cus[i].payment;
			while (cin.get() != '\n');
			if (!st.add(cus[i]))
				break;
		}
		else
			break;
	}
	st.show();
	st.de();
	st.show();
	st.de();
	st.show();

	return 0;
}