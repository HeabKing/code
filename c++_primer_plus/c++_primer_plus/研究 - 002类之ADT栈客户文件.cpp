#include <iostream>
#include <cctype>
#include "�о� - 002��֮ADTջ.h"

int main(void)
{
	using namespace std;

	Stack	st;
	char	ch;
	unsigned long po;

	cout << "a> Push	b> Pop		c> Quit\n";
	while (cin >>ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n');
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << "����һ��int��:\n";
			cin >> po;
			if (st.isFull())
				cout << "ջ�Ѿ�����, ѹ��ʧ��!\n";
			else
				st.push(po);
			break;

		case 'p':
		case 'P':
			if (st.isEmpty())
				cout << "ջ���ǿյ�, ����ʧ��!\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " ������!\n";
			}
			break;
		}
		cout << "a> Push	b> Pop		c> Quit\n";
	}

	cout << "Bye\n";

	return 0;
}