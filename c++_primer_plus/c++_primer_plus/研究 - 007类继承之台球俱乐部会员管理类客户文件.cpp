#include <iostream>
#include "007�о� - ��̳�̨֮����ֲ���Ա������.h"

int main(void)
{
		// �������

	//using std::cout;
	//TableTennisPlayer P1("He", "Shixiong", true);	// �����������캯����ʱ��ʹ�õ���const string &, ����д�����"He"(const char *),
	//												// const ���ÿ���������ʱ����, ����, ������Զ�����string��ת�����캯��, ��C-����ַ���ת��Ϊstring����
	//												// Ȼ�����ｫ�Ƕ���ʱ����������;
	//TableTennisPlayer P2("Hello", "C++", false);
	//P1.ShowName();
	//if (P1.GetisHasTable())
	//	cout << " : has a table.\n";
	//else
	//	cout << " : hasn't a table.\n";
	//P2.ShowName();
	//if (P2.GetisHasTable())
	//	cout << " : has a table.\n";
	//else
	//	cout << " : hasn't a table.\n";

		// ���������

	using std::cout;
	using std::endl;
	TableTennisPlayer P1("TableTennisPlayer", "Base", false);
	RatedPlayer P2(1140, "RatedPlayer", "Derive", true);

	P2.ShowName();
	if (P2.GetisHasTable())
		cout << " : has a table.\n";
	else
		cout << " : hasn't a table.\n";

	P1.ShowName();
	if (P1.GetisHasTable())
		cout << " : has a table.\n";
	else
		cout << " : hasn't a table.\n";

	cout << "Name : ";
	P2.ShowName();
	cout << "; " << P2.GetRating() << endl;

	RatedPlayer P3(1212, P1);
	cout << "Name : ";
	P3.ShowName();
	cout << "; " << P3.GetRating() << endl;

	RatedPlayer P4(20140511, P3);	// �����漰������֮��Ķ�̬, ����P3��һ��������, ����������TablePlayer(TablePlayer &)��;
	cout << "Name : ";
	P4.ShowName();
	cout << "; " << P4.GetRating() << endl;

	return 0;
}