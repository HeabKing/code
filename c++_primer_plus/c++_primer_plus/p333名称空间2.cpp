// �����嵥 9.13 �ļ�3
#include <iostream>
#include "p331���ƿռ�ʾ��.h"
void other(void);
void another(void);
int main(void)
{
	using debts::Debt;
	using debts::showDebt;  // ֻ�����˺���������, ���, �������������, ��һ��using�������������еİ汾
		// ��ȻDebt��showDebt��ʹ����Person����, ���ǲ��ص����κ�Person����, ��Ϊdebt���ƿռ���һ������pers���ƿռ��using����ָ��

	Debt golf = {{"Benny", "Goatsniff"}, 120.0};
	showDebt(golf);
	other();
	another();

	return 0;
}
void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;  // ����һ�ֲ�̫�õķ���, ����һ������ָ����������ƿռ� 
		// ����debts�е�using����ָ�����pers���ƿռ�, ���other()��������ʹ��Person���ͺ�showPerson()����
	Person dg = {"Doodles", "Glister"};  // debts�ռ��а�����pers, pers��������Person
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);

	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);
	cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
	return;
}
void another(void)
{
	using pers::Person;
	Person collector = {"Milo", "Rightshift"};
	pers::showPerson(collector);
	std::cout << std::endl;
}