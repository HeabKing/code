#include <iostream>
#include <string>
#include <cctype>
#include "p569ջģ��_ͷ�ļ���ʵ���ļ�.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Stack<std::string> st;
	// Stack<char *>st; �ǲ��Ե�, ��Ϊ�����������ָ��, û�д������ڱ��������ַ����Ŀռ�, ����ͨ������, ������cin��ͼ�����뱣����ľм�����ʵ��ڴ浥Ԫ��ʱ������
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order,\nP to process a PO, or Q to quit.\n";
	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': cout << "Enter a PO number to add: ";
				  cin >> po;
			      if (st.isfull())
				      cout << "Stack already full.\n";
				  else
					  st.push(po);
				  break;
		case 'p':
		case 'P': if (st.isempty())
					  cout << "Stack already empty.\n";
				  else
				  {
					  st.pop(po);  // po ��ʱΪ������������ʱ�������
					  cout << "PO #" << po << " popped\n";
					  break;
				  }
		}
		cout << "Please enter A to add a purchase order,\nP to process a PO, or Q to quit.\n";
	}
	cout << "Bye.\n";

	return 0;
}