// �����ϰ 9.8 (1) ��׼�� 01
#include <iostream>
#include <cstring>
#include "p338�����ϰ1_��׼��.h"

int setgolf(golf & g)
{
	std::cout << "Please enter golfer's full name: ";
	std::cin.getline(g.fullname, Len);  // cin.getline();��ȡһ��, ����'\0'�滻'\n', ���ķ���ֵΪcin����
	if (g.fullname[0] == '\0')
		return 0;
	std::cout << "Please enter handicap for " << g.fullname << ": ";
	while (!(std::cin >> g.handicap))
	{
		std::cin.clear();  // ???
		std::cout << "Please enter an integer: ";
	}
	while (std::cin.get() != '\n')
		continue;
	return 1;
}
void setgolf(golf & g, const char * name, int hc)
{
	std::strcpy(g.fullname, name);
	g.handicap = hc;
}
void handicap(golf & g, int hc)
{
	g.handicap = hc;
}
void showgolf(const golf & g)
{
	std::cout << "Golfer:   " << g.fullname << "\n";
	std::cout << "Handicap: " << g.handicap << "\n\n";
}