#include <iostream>
#include <cstdlib>
#include <ctime>
#include "015�Կɸı��С��ջģ���ʵ�ַ�����̽��_ͷ�ļ�.h"
int main()
{
	int temp = -1;
	Stack<int> a(8);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	
	a.pop(temp);
	std::cout << temp << "��ɾ��\n";
	/*a.pop(temp);
	cout << temp << "��ɾ��\n";
	a.pop(temp);
	cout << temp << "��ɾ��\n";
	a.pop(temp);
	cout << temp << "��ɾ��\n";
	a.pop(temp);
	cout << temp << "��ɾ��\n";
	a.pop(temp);
	cout << temp << "��ɾ��\n";
	a.pop(temp);*/
	return 0;
}